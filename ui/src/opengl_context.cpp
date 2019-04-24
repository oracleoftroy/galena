#include <ui/opengl_context.hpp>

#include "platform_info.hpp"
#include UI_OPENGL_CONTEXT_H

namespace ui
{
	// TODO: Shouldn't we be able to default this in the header?
	// According to https://howardhinnant.github.io/incomplete.html
	// only the destructor and move assignment operator need a complete type for unique_ptr based
	// pimpl, but msvc is complaining if I default the default constructor in the header.
	opengl_context::opengl_context() noexcept = default;
	opengl_context::~opengl_context() noexcept = default;

	opengl_context::opengl_context(std::unique_ptr<opengl_context_data> &&data) noexcept
		: data(std::move(data))
	{
	}

	opengl_context::opengl_context(opengl_context &&other) noexcept = default;
	opengl_context &opengl_context::operator=(opengl_context &&other) noexcept = default;

	glm::ivec2 opengl_context::drawable_size() const noexcept
	{
		return data->drawable_size();
	}

	void opengl_context::make_current() noexcept
	{
		data->make_current();
	}

	void opengl_context::present() noexcept
	{
		data->present();
	}
}
