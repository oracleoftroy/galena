#pragma once

#include <chrono>
#include <type_traits>

namespace ui
{
	class clock final
	{
	private:
		// We require a steady clock, so use high_resolution_clock if it is steady, otherwise fallback to steady_clock
		// VC++ and clang alias high_resolution_clock to steady_clock, but gcc uses system_clock
		using steady_clock = std::conditional_t<std::chrono::high_resolution_clock::is_steady, std::chrono::high_resolution_clock, std::chrono::steady_clock>;
		static_assert(steady_clock::is_steady, "The game timer must be steady");

	public:
		using duration = std::chrono::duration<double>;

		clock(duration time_slice) noexcept
			: time_slice(time_slice), time_slice_impl(std::chrono::duration_cast<steady_clock::duration>(time_slice))
		{
		}

		duration update() noexcept
		{
			auto time = steady_clock::now();
			auto frame_duration = time - last_time;
			delta += frame_duration;
			last_time = std::move(time);

			return frame_duration;
		}

		[[nodiscard]]
		bool use_time_slice() noexcept
		{
			if (delta >= time_slice_impl)
			{
				delta -= time_slice_impl;
				return true;
			}

			return false;
		}

	public:
		// the time slice in seconds
		const duration time_slice;

	private:
		// time slice in the native duration of our clock to avoid conversion every frame
		const steady_clock::duration time_slice_impl;
		steady_clock::duration delta = steady_clock::duration::zero();
		steady_clock::time_point last_time = steady_clock::now();
	};
}
