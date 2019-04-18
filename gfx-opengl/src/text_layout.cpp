#include "text_layout.hpp"

#pragma warning (disable: 4996)

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H
#include FT_OUTLINE_H
#include FT_SFNT_NAMES_H
#include FT_TRUETYPE_TABLES_H 
#include FT_STROKER_H

#include <hb.h>
#include <hb-ft.h>

#include <unicode/brkiter.h>
#include <unicode/chariter.h>
#include <unicode/uchar.h>

#include <algorithm>
#include <cmath>
#include <limits>
#include <stdexcept>
#include <unordered_map>
#include <utility>
#include <vector>
#include <experimental/filesystem>
using namespace std::string_literals;

#include "image.hpp"
#include "../util/enum.hpp"
#include "../util/logger.hpp"
#include "../util/resource.hpp"

namespace
{
	static const char *ft_error_msg(int error_code);
}

namespace gfx
{
	const double negative_infinity = -std::numeric_limits<double>::infinity();

	struct text_layout_error final : public std::runtime_error
	{
		text_layout_error(const std::string &what) : std::runtime_error(what)
		{
		}
	};

	struct font_info
	{
		font_info(std::string path, std::string family_name, std::string style_name, font_weight weight, font_style style, FT_Face face)
			: path(std::move(path)), family_name(std::move(family_name)), style_name(std::move(style_name)), weight(weight), style(style), face(face)
		{
		}

		std::string path;
		std::string family_name;
		std::string style_name;
		font_weight weight;
		font_style style;

		FT_Face face;
	};

	class font
	{
	public:
		explicit font(std::string family, std::vector<font_info> &&faces) : family(std::move(family)), faces(std::move(faces))
		{
			std::sort(begin(faces), end(faces), [](auto &&face1, auto &&face2)
			{
				return std::tie(face1.weight, face1.style) < std::tie(face2.weight, face2.style);
			});
		}

		const std::string &family_name() const noexcept
		{
			return family;
		}

		FT_Face select_face(const text_style &style) const
		{
			auto min = std::min_element(begin(faces), end(faces), [&](auto &&face1, auto &&face2)
			{
				auto weight = static_cast<int>(style.weight);
				auto dist1 = abs(static_cast<int>(face1.weight) - weight);
				auto dist2 = abs(static_cast<int>(face2.weight) - weight);

				int style1 = style.style != face1.style;
				int style2 = style.style != face2.style;

				return std::tie(dist1, style1) < std::tie(dist2, style2);
			});

			return min->face;
		}

	private:
		std::string family;
		std::vector<font_info> faces;
	};

	class font_cache
	{
	public:
		font_cache();
		~font_cache();

		void scan_directory(const std::string &directory);

		font *find(const std::string &family);

	private:
		FT_Library ft_library;
		std::vector<font> fonts;
	};

	font_cache::font_cache()
	{
		auto error_code = FT_Init_FreeType(&ft_library);
		if (error_code != 0)
		{
			auto msg = ft_error_msg(error_code);
			LOG_ERROR("Failed to init freetype: %s", msg);
			throw text_layout_error(msg);
		}
	}

	font_cache::~font_cache()
	{
		// TODO: Make this movable and properly cleanup faces
		FT_Done_FreeType(ft_library);
	}

	void font_cache::scan_directory(const std::string &directory)
	{
		namespace fs = std::experimental::filesystem;
		fs::directory_iterator file(directory), end;
		FT_Error error_code = 0;

		std::unordered_map<std::string, std::vector<font_info>> family_map;

		for (; file != end; ++file)
		{
			if (!fs::is_regular_file(file->status()))
				continue;

			auto path = file->path().u8string();
			FT_Face face;
			error_code = FT_New_Face(ft_library, path.c_str(), -1, &face);
			if (error_code != 0)
			{
				LOG_WARN("Could not open font %s: %s", path.c_str(), ft_error_msg(error_code));
				continue;
			}

			auto num_faces = face->num_faces;

			FT_Done_Face(face);

			LOG_DEBUG("Caching font %s", path.c_str());

			for (int i = 0; i < num_faces; ++i)
			{
				error_code = FT_New_Face(ft_library, path.c_str(), i, &face);
				if (error_code != 0)
				{
					LOG_WARN("Could not open font face index %d: %s", i, ft_error_msg(error_code));
					FT_Done_Face(face);
					continue;
				}

				if (face->family_name == nullptr || face->style_name == nullptr)
				{
					LOG_WARN("Face \"%s\" is missing information, skipping", path.c_str());
					FT_Done_Face(face);
					continue;
				}

				auto os2 = (TT_OS2*)FT_Get_Sfnt_Table(face, FT_SFNT_OS2);
				if (os2 == nullptr)
				{
					LOG_WARN("Could not open OS/2 table for face \"%s\", skipping", path.c_str());
					FT_Done_Face(face);
					continue;
				}

				font_weight weight = static_cast<font_weight>(os2->usWeightClass);

				bool is_italic = os2->fsSelection & 1;

				LOG_DEBUG("Adding %s %s", face->family_name, face->style_name);
				family_map[face->family_name].emplace_back(
					path,
					face->family_name,
					face->style_name,
					weight,
					is_italic ? font_style::italic : font_style::normal,
					face);
			}
		}

		for (auto &&pair : family_map)
			fonts.emplace_back(pair.first, std::move(pair.second));
	}

	font *font_cache::find(const std::string &family)
	{
		auto fonts_end = end(fonts);
		auto result = std::find_if(begin(fonts), fonts_end, [&](const font &font)
		{
			return font.family_name() == family;
		});

		return result == fonts_end ? nullptr : &*result;
	}

	struct measure_data
	{
		hb_codepoint_t codepoint;
		uint32_t       cluster;

		hb_position_t  x_advance;
		hb_position_t  y_advance;
		hb_position_t  x_offset;
		hb_position_t  y_offset;
	};

	struct run_style
	{
		size_t index;
		size_t length;
		FT_Face face;
		double font_size;
	};

	struct measured_text
	{
		FT_Face face;
		FT_F26Dot6 font_size;
		FT_Size_Metrics metrics;
		std::vector<measure_data> measure;
	};

	struct line
	{
		static_assert(std::numeric_limits<double>::is_iec559, "Negating infinity not guaranteed to work on this platform");
		double ascender = negative_infinity;
		double descender = negative_infinity;
		double line_advance = negative_infinity;

		std::vector<measured_text> text;
	};

	GENERATE_RESOURCE(hb_buffer_resource, hb_buffer_t*, hb_buffer_create, hb_buffer_destroy);
	GENERATE_RESOURCE(hb_font_resource, hb_font_t*, hb_ft_font_create_referenced, hb_font_destroy);

	class text_layout::text_layout_data
	{
	public:
		text_layout_data(int dpi);

		void set_cursor(double x, double y);
		void move_cursor(double offset_x, double offset_y);

		// defaults
		void set_color(float r, float g, float b, float a = 1) noexcept;
		void set_point_size(double point_size) noexcept;
		void set_font_weight(font_weight weight) noexcept;
		void set_font_style(font_style style) noexcept;

		font *find_font(const std::string &family);
		void add_text(font *font, const std::string &text);
		void add_text(font *font, const std::string &text, double point_size);
		void add_text(font *font, const std::string &text, const text_style &style);
		void add_text(font *font, const std::string &text, double point_size, const text_style &style);

		void arrange(int width);
		image render_to_image();
		image render_outline_to_image();

	private:
		double cursor_x = 0, cursor_y = 0, line_advance = 0, last_line_advance = 0;
		float r = 0, g = 0, b = 0, a = 1;
		double point_size = 12;
		int width = -1, height = -1;
		font_weight weight = font_weight::normal;
		font_style style = font_style::normal;
		int dpi;

		FT_Face current_face = nullptr;
		hb_buffer_resource hb_buffer;
		std::unique_ptr<BreakIterator> icu_breaker;
		font_cache cache;

		std::string text;
		std::vector<run_style> styles;

		//		std::vector<run> runs;
		std::vector<line> lines;
	};

	text_layout::text_layout(int dpi)
		: data(std::make_unique<text_layout_data>(dpi))
	{
	}

	text_layout::text_layout_data::text_layout_data(int dpi)
		: dpi(dpi), hb_buffer(hb_buffer_resource::create())
	{
		UErrorCode icu_error = U_ZERO_ERROR;
		icu_breaker.reset(BreakIterator::createLineInstance(Locale::getDefault(), icu_error));
		if (U_FAILURE(icu_error))
		{
			LOG_ERROR("Could not create line break iterator: %s", u_errorName(icu_error));
			throw text_layout_error(u_errorName(icu_error));
		}

		cache.scan_directory("fonts");
	}

	text_layout::~text_layout() = default;

	void text_layout::set_cursor(double x, double y)
	{
		data->set_cursor(x, y);
	}

	void text_layout::text_layout_data::set_cursor(double x, double y)
	{
		cursor_x = x;
		cursor_y = y;
	}

	void text_layout::move_cursor(double offset_x, double offset_y)
	{
		data->move_cursor(offset_x, offset_y);
	}

	void text_layout::text_layout_data::move_cursor(double offset_x, double offset_y)
	{
		cursor_x += offset_x;
		cursor_y += offset_y;
	}

	void text_layout::set_color(float r, float g, float b, float a) noexcept
	{
		data->set_color(r, g, b, a);
	}

	void text_layout::text_layout_data::set_color(float red, float green, float blue, float alpha) noexcept
	{
		r = red;
		g = green;
		b = blue;
		a = alpha;
	}

	void text_layout::set_point_size(double point_size) noexcept
	{
		data->set_point_size(point_size);
	}

	void text_layout::text_layout_data::set_point_size(double new_point_size) noexcept
	{
		point_size = new_point_size;

		if (current_face)
			FT_Set_Char_Size(current_face, lrint(point_size * 64.0), lrint(point_size * 64.0), dpi, dpi);
	}

	void text_layout::set_font_weight(font_weight weight) noexcept
	{
		data->set_font_weight(weight);
	}

	void text_layout::text_layout_data::set_font_weight(font_weight new_weight) noexcept
	{
		weight = new_weight;
	}

	void text_layout::set_font_style(font_style style) noexcept
	{
		data->set_font_style(style);
	}

	void text_layout::text_layout_data::set_font_style(font_style new_style) noexcept
	{
		style = new_style;
	}

	font *text_layout::find_font(const std::string &family)
	{
		return data->find_font(family);
	}

	font *text_layout::text_layout_data::find_font(const std::string &family)
	{
		return cache.find(family);
	}

	void text_layout::add_text(font *font, const std::string &msg)
	{
		data->add_text(font, msg);
	}

	void text_layout::text_layout_data::add_text(font *font, const std::string &msg)
	{
		add_text(font, msg, point_size, text_style(weight, style));
	}

	void text_layout::add_text(font *font, const std::string &msg, double point_size)
	{
		data->add_text(font, msg, point_size);
	}

	void text_layout::text_layout_data::add_text(font *font, const std::string &msg, double font_size)
	{
		add_text(font, msg, font_size, text_style(weight, style));
	}

	void text_layout::add_text(font *font, const std::string &msg, const text_style &style)
	{
		data->add_text(font, msg, style);
	}

	void text_layout::text_layout_data::add_text(font *font, const std::string &msg, const text_style &text_style)
	{
		add_text(font, msg, point_size, text_style);
	}

	void text_layout::add_text(font *font, const std::string &msg, double font_size, const text_style &text_style)
	{
		data->add_text(font, msg, font_size, text_style);
	}

	void text_layout::text_layout_data::add_text(font *font, const std::string &msg, double font_size, const text_style &text_style)
	{
		styles.emplace_back(run_style { text.size(), msg.size(), font->select_face(text_style), font_size});
		this->text += text;
	}

	void text_layout::arrange(int width)
	{
		data->arrange(width);
	}

	void text_layout::text_layout_data::arrange(int line_width)
	{
		double x = 2.0;

		line current_line;

		// Initialize our line breaker
		auto icu_string = UnicodeString::fromUTF8(text);
		icu_breaker->setText(icu_string);
		size_t current_break = icu_breaker->current();
		size_t next_break = current_break;

		for (auto &&run_style : styles)
		{
			// Get all the metrics we need to layout the text

			// Make sure the face is set to the correct size, in points
			auto ft_char_size = lrint(run_style.font_size * 64.0);
			FT_Set_Char_Size(run_style.face, ft_char_size, ft_char_size, dpi, dpi);

			auto face_metrics = run_style.face->size->metrics;
			auto hb_font = hb_font_resource::create(run_style.face);

			// Shape the text using harfbuzz. We will use harfbuzz's metrics rather than the glyph's
			hb_buffer_clear_contents(hb_buffer);
			hb_buffer_add_utf8(hb_buffer, text.c_str(), -1, static_cast<unsigned>(run_style.index), static_cast<int>(run_style.length));
			hb_buffer_guess_segment_properties(hb_buffer);
			hb_shape(hb_font, hb_buffer, nullptr, 0);

			size_t num_glyphs = hb_buffer_get_length(hb_buffer);
			hb_glyph_info_t *glyph_info = hb_buffer_get_glyph_infos(hb_buffer, nullptr);
			hb_glyph_position_t *glyph_pos = hb_buffer_get_glyph_positions(hb_buffer, nullptr);

			auto measure_next_break = [&](size_t glyph_start, size_t end_index)
			{
				double result = 0;
				for (size_t i = glyph_start; i < num_glyphs && glyph_info[i].cluster < end_index; ++i)
					result += glyph_pos[i].x_advance;

				return result / 64.0;
			};

			auto create_measured_text = [&](auto &&face, auto &&font_size, auto &&metrics, size_t start, size_t end)
			{
				measured_text text {face, font_size, metrics};
				text.measure.resize(end - start);
				std::transform(glyph_info + start, glyph_info + end, glyph_pos + start, text.measure.data(), [](auto &&info, auto &&pos)
				{
					return measure_data
					{
						info.codepoint,
						info.cluster,

						pos.x_advance,
						pos.y_advance,
						pos.x_offset,
						pos.y_offset
					};
				});

				return text;
			};

			size_t start = 0;
			for (size_t i = 0; i < num_glyphs; ++i)
			{
				auto codepoint = icu_string.char32At(static_cast<int32_t>(glyph_info[i].cluster));
				bool is_newline = codepoint == '\n';

				// if this glyph is outside the current line break, measure up to the next break.
				// If that will put us outsize our bounds, start a new line
				if (is_newline || glyph_info[i].cluster >= next_break)
				{
					current_break = next_break;
					next_break = icu_breaker->next();

					// This word is too big, wrap
					// TODO: Assumes normal text. What happens if it is a giant blob of text with no breaking points?
					if (is_newline || x + measure_next_break(i, next_break) > width - 2.0)
					{
						// Add the text that fits on this line to the current line.
						if (i != start)
							current_line.text.emplace_back(create_measured_text(run_style.face, ft_char_size, face_metrics, start, i));

						if (current_line.ascender == negative_infinity)
						{
							current_line.ascender = face_metrics.ascender / 64.0;
							current_line.descender = -face_metrics.descender / 64.0;
							current_line.line_advance = face_metrics.height / 64.0;
						}

						// This line is done, save it and reset for the next line
						lines.emplace_back(std::move(current_line));
						current_line = line {};
						current_line.ascender = face_metrics.ascender / 64.0;
						current_line.descender = -face_metrics.descender / 64.0;
						current_line.line_advance = face_metrics.height / 64.0;
						start = i;
						x = 2.0;

						if (is_newline)
						{
							++start;
							continue;
						}
					}
				}

				if (i == 0)
				{
					// record the largest ascender, descender, and line_advance we have seen for this line.
					// When runs using different faces and/or font sizes are on the same line, we want to make sure
					// the baseline is consistent and that we don't stomp over the text.
					current_line.ascender = std::max(current_line.ascender, face_metrics.ascender / 64.0);
					current_line.descender = std::max(current_line.descender, -face_metrics.descender / 64.0);
					current_line.line_advance = std::max(current_line.line_advance, face_metrics.height / 64.0);
				}

				x += glyph_pos[i].x_advance / 64.0;
			}

			if (start != num_glyphs)
				current_line.text.emplace_back(create_measured_text(run_style.face, ft_char_size, face_metrics, start, num_glyphs));
		}

		if (!current_line.text.empty())
			lines.emplace_back(std::move(current_line));

		// calculate this during measure
		double text_height = 0;

		auto first = begin(lines);
		auto end_line = end(lines);
		auto last = end_line - 1;

		for (auto line = first; line != end_line; ++line)
		{
			if (line == first)
				text_height += line->ascender;

			if (line == last)
				text_height += line->descender;
			else
				text_height += line->line_advance;
		}

		width = line_width;
		height = static_cast<int>(ceil(text_height));
	}

	image text_layout::render_to_image()
	{
		return data->render_to_image();
	}

	struct image_data
	{
		uint8_t *start;
		uint8_t *end;
		uint8_t *current;

		size_t width;
	};

	template <typename RenderFunc>
	void render(size_t /* image_width */, size_t /*image_height*/, const std::string &text, std::vector<line> &lines, int dpi, image_data &data, RenderFunc render)
	{
		// TODO: decide whether we want to validate our bounds against the width/height of the image, or remove those parameters
		// We probably should at least assert
		double y = 0;

		auto icu_string = UnicodeString::fromUTF8(text);

		auto first = begin(lines);
		y -= first->descender;

		for (auto &&line : lines)
		{
			double x = 2.0;
			y += line.line_advance;

			for (auto &&run : line.text)
			{
				FT_Set_Char_Size(run.face, run.font_size, run.font_size, dpi, dpi);

				for (auto &&measure : run.measure)
				{
					auto codepoint = icu_string.char32At(static_cast<int32_t>(measure.cluster));
					bool is_newline = codepoint == '\n';
					if (is_newline)
						continue;

					if (FT_Load_Glyph(run.face, measure.codepoint, FT_LOAD_DEFAULT) == 0 && run.face->glyph->format == FT_GLYPH_FORMAT_OUTLINE)
					{
						int gx = lrint(x + (measure.x_offset / 64.0));
						int gy = lrint(y - (measure.y_offset / 64.0));

						FT_Raster_Params params {};
						params.flags = FT_RASTER_FLAG_DIRECT | FT_RASTER_FLAG_AA;
						params.user = &data;

						params.gray_spans = [](int y, int count, const FT_Span *spans, void *user)
						{
							const image_data *data = static_cast<const image_data*>(user);

							uint8_t *scanline = data->current - y * data->width;

							if (scanline < data->start)
								return;

							for (int i = 0; i < count; i++)
							{
								uint8_t color = spans[i].coverage;

								uint8_t *start = scanline + spans[i].x;

								if (start + spans[i].len >= data->end)
									return;

								for (int x = 0; x < spans[i].len; ++x, ++start)
									*start |= color;
							}
						};

						render(run.face->glyph, params, gx, gy);
					}

					x += measure.x_advance / 64.0;
					y -= measure.y_advance / 64.0;
				}
			}
		}
	}

	image text_layout::text_layout_data::render_to_image()
	{
		if (width <= 0)
			throw text_layout_error("Text has not been properly measured");

		size_t image_width = static_cast<size_t>(width);
		size_t image_height = static_cast<size_t>(height);

		std::vector<uint8_t> image(image_width * image_height);
		image_data image_data {image.data(), image.data() + image.size(), nullptr, image_width};

		render(image_width, image_height, text, lines, dpi, image_data, [&image_data](FT_GlyphSlotRec *glyph, FT_Raster_Params &params, int gx, int gy)
		{
			image_data.current = (image_data.start + gy * image_data.width) + gx;

			FT_Outline_Render(glyph->library, &glyph->outline, &params);
		});

		return gfx::image::create(image.data(), static_cast<int>(image_width), static_cast<int>(image_height), 1);
	}

	image text_layout::render_outline_to_image()
	{
		return data->render_outline_to_image();
	}

	image text_layout::text_layout_data::render_outline_to_image()
	{
		if (width <= 0)
			throw text_layout_error("Text has not been properly measured");

		size_t image_width = static_cast<size_t>(width);
		size_t image_height = static_cast<size_t>(height);

		std::vector<uint8_t> image(image_width * image_height);
		image_data image_data {image.data(), image.data() + image.size(), nullptr, image_width};

		render(image_width, image_height, text, lines, dpi, image_data, [&image_data](FT_GlyphSlotRec *glyph, FT_Raster_Params &params, int gx, int gy)
		{
			image_data.current = (image_data.start + gy * image_data.width) + gx;

			FT_Stroker stroker;
			FT_Stroker_New(glyph->library, &stroker);
			FT_Stroker_Set(stroker,
				(int)(1.5 * 64.0),
				FT_STROKER_LINECAP_ROUND,
				FT_STROKER_LINEJOIN_ROUND,
				0);

			FT_Glyph stroked_glyph;
			FT_Get_Glyph(glyph, &stroked_glyph);
			FT_Glyph_StrokeBorder(&stroked_glyph, stroker, false, true);

			FT_Outline *outline = &reinterpret_cast<FT_OutlineGlyph>(stroked_glyph)->outline;
			FT_Outline_Render(stroked_glyph->library, outline, &params);

			FT_Done_Glyph(stroked_glyph);
			FT_Stroker_Done(stroker);
		});

		return gfx::image::create(image.data(), static_cast<int>(image_width), static_cast<int>(image_height), 1);
	}
}

// Generate the freetype error strings so we can get something for logging
#undef FTERRORS_H_
#define FT_ERRORDEF( e, v, s )  { e, s },
#define FT_ERROR_START_LIST     {
#define FT_ERROR_END_LIST       };

const struct
{
	int          err_code;
	const char*  err_msg;
} ft_errors[] =

#include FT_ERRORS_H

namespace
{
	static const char *ft_error_msg(int error_code)
	{
		for (auto &&e : ft_errors)
		{
			if (e.err_code == error_code)
				return e.err_msg;
		}

		return "unknown";
	}
}
