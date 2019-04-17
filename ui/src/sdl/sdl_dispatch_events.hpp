#pragma once

#include <ui/events.hpp>
#include <ui/platform.hpp>

#include "sdl_keyboard.hpp"

#include <SDL2/SDL_events.h>

namespace ui::sdl
{
	template <event_type t>
	struct event_tag
	{
		static const event_type type = t;
	};

	inline void dispatch_event(event_tag<event_type::keyboard>, const platform::event_listener_type &handler, const SDL_Event &e) noexcept
	{
		handler(keyboard_event(from_sdl(e.key.keysym.sym), from_sdl(e.key.keysym.scancode), from_sdl(SDL_Keymod(e.key.keysym.mod)), pressed_state(e.key.state), e.key.repeat));
	}

	inline void dispatch_event(event_tag<event_type::mouse_move>, const platform::event_listener_type &handler, const SDL_Event &e)  noexcept
	{
		handler(mouse_move_event(e.motion.which, {e.motion.x, e.motion.y}, {e.motion.xrel, e.motion.yrel}));
	}

	inline void dispatch_event(event_tag<event_type::mouse_button>, const platform::event_listener_type &handler, const SDL_Event &e) noexcept
	{
		handler(mouse_button_event(e.button.which, e.button.button, pressed_state(e.button.state), e.button.clicks, {e.motion.x, e.motion.y}));
	}

	inline void dispatch_event(event_tag<event_type::mouse_scroll>, const platform::event_listener_type &handler, const SDL_Event &e) noexcept
	{
		handler(mouse_scroll_event(e.wheel.which, {e.wheel.x, e.wheel.y}, mouse_scroll_direction(e.wheel.direction)));
	}

	inline void dispatch_event(event_tag<event_type::controller_analog>, const platform::event_listener_type &handler, const SDL_Event &e) noexcept
	{
		// convert the value of the axis to the range -1.0f to 1.0f
		auto percent = [](Sint16 value)
		{
			return value >= 0
				? value / static_cast<float>(SDL_JOYSTICK_AXIS_MAX)
				: -(value / static_cast<float>(SDL_JOYSTICK_AXIS_MIN));
		};
		handler(controller_analog_event(e.caxis.which, controller_axis(e.caxis.axis), percent(e.caxis.value)	));
	}

	inline void dispatch_event(event_tag<event_type::controller_button>, const platform::event_listener_type &handler, const SDL_Event &e) noexcept
	{
		handler(controller_button_event(e.cbutton.which, controller_button(e.cbutton.button), pressed_state(e.cbutton.state)));
	}

	inline void dispatch_event(event_tag<event_type::text_input>, const platform::event_listener_type &handler, const SDL_Event &e) noexcept
	{
		handler(text_input_event(e.text.text));
	}

	inline void dispatch_events(const platform::event_listener_type &handler, const SDL_Event &event) noexcept
	{
		if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
			dispatch_event(event_tag<event_type::keyboard>(), handler, event);
		else if (event.type == SDL_MOUSEMOTION)
			dispatch_event(event_tag<event_type::mouse_move>(), handler, event);
		else if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP)
			dispatch_event(event_tag<event_type::mouse_button>(), handler, event);
		else if (event.type == SDL_MOUSEWHEEL)
			dispatch_event(event_tag<event_type::mouse_scroll>(), handler, event);
		else if (event.type == SDL_CONTROLLERAXISMOTION)
			dispatch_event(event_tag<event_type::controller_analog>(), handler, event);
		else if (event.type == SDL_CONTROLLERBUTTONDOWN || event.type == SDL_CONTROLLERBUTTONUP)
			dispatch_event(event_tag<event_type::controller_button>(), handler, event);
		else if (event.type == SDL_TEXTINPUT)
			dispatch_event(event_tag<event_type::text_input>(), handler, event);

		//else
		//	LOG_TRACE("Unhandled event");
	}
}
