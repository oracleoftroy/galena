#pragma once

#include <glm/glm.hpp>
#include <string_view>

namespace ui
{
	enum class event_type
	{
		keyboard,

		// used for IME style input, ignore for now
		// text_editing,
		text_input,

		mouse_move,
		mouse_button,
		mouse_scroll,

		controller_analog,
		controller_button,
	};

	class event
	{
	public:
		event(event_type type) : type(type) {}

		const event_type type;

	public:
		event(event &&other) noexcept = delete;
		event(const event &other) noexcept = delete;
		event &operator=(event &&other) noexcept = delete;
		event &operator=(const event &other) noexcept = delete;

	protected:
		~event() noexcept = default;
	};

	enum class keys;
	enum class scancodes;
	enum class modifiers;

	using device_id = uint_least32_t;

	enum class pressed_state
	{
		released,
		pressed,
	};

	class keyboard_event : public event
	{
	public:
		keyboard_event(keys key, scancodes code, modifiers mods, pressed_state state, int repeat)
			: event(event_type::keyboard), key(key), scancode(code), mods(mods), state(state), repeat(repeat)
		{
		}

		const keys key;
		const scancodes scancode;
		const modifiers mods;
		const pressed_state state;
		const int repeat;
	};

	class text_input_event : public event
	{
	public:
		text_input_event(std::string_view text)
			: event(event_type::text_input), text(text)
		{
		}

		const std::string_view text;
	};

	class mouse_move_event : public event
	{
	public:
		mouse_move_event(device_id id, glm::ivec2 position, glm::ivec2 delta)
			: event(event_type::mouse_move), id(id), position(position), delta(delta)
		{
		}

		const device_id id;
		const glm::ivec2 position;
		const glm::ivec2 delta;
	};

	class mouse_button_event : public event
	{
	public:
		mouse_button_event(device_id id, int button, pressed_state state, int clicks, glm::ivec2 position)
			: event(event_type::mouse_button), id(id), button(button), state(state), clicks(clicks), position(position)
		{
		}

		const device_id id;
		const int button;
		const pressed_state state;
		const int clicks;
		const glm::ivec2 position;
	};

	enum class mouse_scroll_direction
	{
		normal,
		flipped
	};

	class mouse_scroll_event : public event
	{
	public:
		mouse_scroll_event(device_id id, glm::ivec2 delta, mouse_scroll_direction direction)
			: event(event_type::mouse_scroll), id(id), delta(delta), direction(direction)
		{
		}

		const device_id id;
		const glm::ivec2 delta;
		const mouse_scroll_direction direction;
	};

	enum class controller_axis
	{
		unknown = -1,
		left_x,
		left_y,

		right_x,
		right_y,

		left_trigger,
		right_trigger,
	};

	class controller_analog_event : public event
	{
	public:
		controller_analog_event(device_id id, controller_axis axis, float value)
			: event(event_type::controller_analog), id(id), axis(axis), value(value)
		{
		}

		const device_id id;
		const controller_axis axis;
		const float value;
	};

	enum class controller_button
	{
		unknown = -1,
		a,
		b,
		x,
		y,
		back,
		guide,
		start,
		left_stick,
		right_stick,
		left_shoulder,
		right_shoulder,
		dpad_up,
		dpad_down,
		dpad_left,
		dpad_right,
	};

	class controller_button_event : public event
	{
	public:
		controller_button_event(device_id id, controller_button button, pressed_state state)
			: event(event_type::controller_button), id(id), button(button), state(state)
		{
		}

		const device_id id;
		const controller_button button;
		const pressed_state state;
	};
}
