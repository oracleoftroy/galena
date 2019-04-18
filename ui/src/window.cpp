#include <ui/window.hpp>
#include <utility>

namespace ui
{
	window::window(void *handle) noexcept
		: handle(handle)
	{
	}

	window::window(window &&other) noexcept
		: handle(std::exchange(other.handle, nullptr))
	{
	}

	window &window::operator=(window &&other) noexcept
	{
		window old(std::move(*this));
		handle = std::exchange(other.handle, nullptr);
		return *this;
	}
}
