#pragma once

namespace ui { class vulkan_context; }
namespace gfx { class renderer; }

namespace gfx::vk
{
	renderer create_vulkan_renderer(ui::vulkan_context& context) noexcept;
}
