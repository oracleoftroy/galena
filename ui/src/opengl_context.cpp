#include <ui/opengl_context.hpp>

#include "platform_info.hpp"
#include UI_OPENGL_CONTEXT_H

namespace ui
{
	opengl_context::opengl_context(std::unique_ptr<opengl_context_data> &&data)
		: data(std::move(data))
	{
	}

	opengl_context::~opengl_context() noexcept = default;

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
