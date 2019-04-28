#pragma once

#include <ui/clock.hpp>
#include "log.hpp"

namespace app
{
	class frame_metrics
	{
	public:
		explicit frame_metrics(ui::clock::duration target_frame_rate) noexcept : target_frame_rate(target_frame_rate + target_frame_rate / 2) {}

		void update(ui::clock::duration frame_time) noexcept
		{
			using namespace std::chrono_literals;
			if (frame_count == 0)
				low = high = frame_time;
			else
				std::tie(low, high) = std::minmax({frame_time, low, high});

			duration += frame_time;
			++frame_count;

			if (duration >= 5s)
			{
				auto fps = frame_count / duration.count();
				auto average = duration / frame_count;
				LOG_DEBUG("avg fps: {0} ({1} frames over {2} seconds)", fps, frame_count, duration.count());
				LOG_DEBUG("frame time: high({0}) low({1}) avg({2})", high.count(), low.count(), average.count());

				if (high > target_frame_rate)
					LOG_WARN("frame rate dropped below target");

				// reset
				duration = 0s;
				frame_count = 0;
			}
		}

	private:
		// NOTE: on construction, we add a bit of leeway so that we don't overreport frame drops because of rounding errors
		// This will need to change if we want to use this for anything more important!!
		ui::clock::duration target_frame_rate;
		ui::clock::duration low = std::chrono::seconds(0);
		ui::clock::duration high = std::chrono::seconds(0);
		ui::clock::duration duration = std::chrono::seconds(0);
		size_t frame_count = 0;
	};
}
