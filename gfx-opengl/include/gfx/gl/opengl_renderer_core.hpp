#pragma once

namespace ui { class opengl_context; }
namespace gfx { class renderer; }

namespace gfx::gl
{
	renderer create_opengl_renderer(ui::opengl_context &context) noexcept;
}
