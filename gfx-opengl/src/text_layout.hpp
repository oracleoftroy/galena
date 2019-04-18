#pragma once

#include <string>
#include <memory>

namespace gfx
{
	class font;
	class image;

	enum class font_weight
	{
		thin = 100,
		extra_light = 200,
		light = 300,
		normal = 400,
		medium = 500,
		semi_bold = 600,
		bold = 700,
		extra_bold = 800,
		black = 900
	};

	enum class font_style
	{
		normal,
		italic,
	};

	struct text_style
	{
		text_style() = default;
		text_style(font_weight weight) : weight(weight) {}
		text_style(font_style style) : style(style) {}
		text_style(font_weight weight, font_style style) : weight(weight), style(style) {}

		font_weight weight = font_weight::normal;
		font_style style = font_style::normal;
	};

	class text_layout final
	{
	public:
		explicit text_layout(int dpi = 96);
		~text_layout();

		// TODO: Rethink these (implementation?)
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
		class text_layout_data;
		std::unique_ptr<text_layout_data> data;
	};
}
