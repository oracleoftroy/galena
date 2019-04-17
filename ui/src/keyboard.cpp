#include <ui/keyboard.hpp>
#include <array>
#include <cassert>

namespace ui
{
	const std::string_view to_string(keys key)
	{
		using namespace std::string_view_literals;
		std::string_view result;

		switch (key)
		{
		default:
		case keys::unknown:
			result = "unknown"sv;
			break;
		case keys::enter:
			result = "enter"sv;
			break;
		case keys::escape:
			result = "escape"sv;
			break;
		case keys::backspace:
			result = "backspace"sv;
			break;
		case keys::tab:
			result = "tab"sv;
			break;
		case keys::space:
			result = "space"sv;
			break;
		case keys::exclaim:
			result = "exclaim"sv;
			break;
		case keys::quotedbl:
			result = "quotedbl"sv;
			break;
		case keys::hash:
			result = "hash"sv;
			break;
		case keys::percent:
			result = "percent"sv;
			break;
		case keys::dollar:
			result = "dollar"sv;
			break;
		case keys::ampersand:
			result = "ampersand"sv;
			break;
		case keys::quote:
			result = "quote"sv;
			break;
		case keys::left_paren:
			result = "left_paren"sv;
			break;
		case keys::right_paren:
			result = "right_paren"sv;
			break;
		case keys::asterisk:
			result = "asterisk"sv;
			break;
		case keys::plus:
			result = "plus"sv;
			break;
		case keys::comma:
			result = "comma"sv;
			break;
		case keys::minus:
			result = "minus"sv;
			break;
		case keys::period:
			result = "period"sv;
			break;
		case keys::slash:
			result = "slash"sv;
			break;
		case keys::num_0:
			result = "num_0"sv;
			break;
		case keys::num_1:
			result = "num_1"sv;
			break;
		case keys::num_2:
			result = "num_2"sv;
			break;
		case keys::num_3:
			result = "num_3"sv;
			break;
		case keys::num_4:
			result = "num_4"sv;
			break;
		case keys::num_5:
			result = "num_5"sv;
			break;
		case keys::num_6:
			result = "num_6"sv;
			break;
		case keys::num_7:
			result = "num_7"sv;
			break;
		case keys::num_8:
			result = "num_8"sv;
			break;
		case keys::num_9:
			result = "num_9"sv;
			break;
		case keys::colon:
			result = "colon"sv;
			break;
		case keys::semicolon:
			result = "semicolon"sv;
			break;
		case keys::less:
			result = "less"sv;
			break;
		case keys::equals:
			result = "equals"sv;
			break;
		case keys::greater:
			result = "greater"sv;
			break;
		case keys::question:
			result = "question"sv;
			break;
		case keys::at:
			result = "at"sv;
			break;
		case keys::left_bracket:
			result = "left_bracket"sv;
			break;
		case keys::backslash:
			result = "backslash"sv;
			break;
		case keys::right_bracket:
			result = "right_bracket"sv;
			break;
		case keys::caret:
			result = "caret"sv;
			break;
		case keys::underscore:
			result = "underscore"sv;
			break;
		case keys::backquote:
			result = "backquote"sv;
			break;
		case keys::a:
			result = "a"sv;
			break;
		case keys::b:
			result = "b"sv;
			break;
		case keys::c:
			result = "c"sv;
			break;
		case keys::d:
			result = "d"sv;
			break;
		case keys::e:
			result = "e"sv;
			break;
		case keys::f:
			result = "f"sv;
			break;
		case keys::g:
			result = "g"sv;
			break;
		case keys::h:
			result = "h"sv;
			break;
		case keys::i:
			result = "i"sv;
			break;
		case keys::j:
			result = "j"sv;
			break;
		case keys::k:
			result = "k"sv;
			break;
		case keys::l:
			result = "l"sv;
			break;
		case keys::m:
			result = "m"sv;
			break;
		case keys::n:
			result = "n"sv;
			break;
		case keys::o:
			result = "o"sv;
			break;
		case keys::p:
			result = "p"sv;
			break;
		case keys::q:
			result = "q"sv;
			break;
		case keys::r:
			result = "r"sv;
			break;
		case keys::s:
			result = "s"sv;
			break;
		case keys::t:
			result = "t"sv;
			break;
		case keys::u:
			result = "u"sv;
			break;
		case keys::v:
			result = "v"sv;
			break;
		case keys::w:
			result = "w"sv;
			break;
		case keys::x:
			result = "x"sv;
			break;
		case keys::y:
			result = "y"sv;
			break;
		case keys::z:
			result = "z"sv;
			break;
		case keys::capslock:
			result = "capslock"sv;
			break;
		case keys::f1:
			result = "f1"sv;
			break;
		case keys::f2:
			result = "f2"sv;
			break;
		case keys::f3:
			result = "f3"sv;
			break;
		case keys::f4:
			result = "f4"sv;
			break;
		case keys::f5:
			result = "f5"sv;
			break;
		case keys::f6:
			result = "f6"sv;
			break;
		case keys::f7:
			result = "f7"sv;
			break;
		case keys::f8:
			result = "f8"sv;
			break;
		case keys::f9:
			result = "f9"sv;
			break;
		case keys::f10:
			result = "f10"sv;
			break;
		case keys::f11:
			result = "f11"sv;
			break;
		case keys::f12:
			result = "f12"sv;
			break;
		case keys::printscreen:
			result = "printscreen"sv;
			break;
		case keys::scroll_lock:
			result = "scroll_lock"sv;
			break;
		case keys::pause:
			result = "pause"sv;
			break;
		case keys::insert:
			result = "insert"sv;
			break;
		case keys::home:
			result = "home"sv;
			break;
		case keys::page_up:
			result = "page_up"sv;
			break;
		case keys::del:
			result = "del"sv;
			break;
		case keys::end:
			result = "end"sv;
			break;
		case keys::page_down:
			result = "page_down"sv;
			break;
		case keys::right:
			result = "right"sv;
			break;
		case keys::left:
			result = "left"sv;
			break;
		case keys::down:
			result = "down"sv;
			break;
		case keys::up:
			result = "up"sv;
			break;
		case keys::numlock_clear:
			result = "numlock_clear"sv;
			break;
		case keys::kp_divide:
			result = "kp_divide"sv;
			break;
		case keys::kp_multiply:
			result = "kp_multiply"sv;
			break;
		case keys::kp_minus:
			result = "kp_minus"sv;
			break;
		case keys::kp_plus:
			result = "kp_plus"sv;
			break;
		case keys::kp_enter:
			result = "kp_enter"sv;
			break;
		case keys::kp_1:
			result = "kp_1"sv;
			break;
		case keys::kp_2:
			result = "kp_2"sv;
			break;
		case keys::kp_3:
			result = "kp_3"sv;
			break;
		case keys::kp_4:
			result = "kp_4"sv;
			break;
		case keys::kp_5:
			result = "kp_5"sv;
			break;
		case keys::kp_6:
			result = "kp_6"sv;
			break;
		case keys::kp_7:
			result = "kp_7"sv;
			break;
		case keys::kp_8:
			result = "kp_8"sv;
			break;
		case keys::kp_9:
			result = "kp_9"sv;
			break;
		case keys::kp_0:
			result = "kp_0"sv;
			break;
		case keys::kp_period:
			result = "kp_period"sv;
			break;
		case keys::application:
			result = "application"sv;
			break;
		case keys::power:
			result = "power"sv;
			break;
		case keys::kp_equals:
			result = "kp_equals"sv;
			break;
		case keys::f13:
			result = "f13"sv;
			break;
		case keys::f14:
			result = "f14"sv;
			break;
		case keys::f15:
			result = "f15"sv;
			break;
		case keys::f16:
			result = "f16"sv;
			break;
		case keys::f17:
			result = "f17"sv;
			break;
		case keys::f18:
			result = "f18"sv;
			break;
		case keys::f19:
			result = "f19"sv;
			break;
		case keys::f20:
			result = "f20"sv;
			break;
		case keys::f21:
			result = "f21"sv;
			break;
		case keys::f22:
			result = "f22"sv;
			break;
		case keys::f23:
			result = "f23"sv;
			break;
		case keys::f24:
			result = "f24"sv;
			break;
		case keys::execute:
			result = "execute"sv;
			break;
		case keys::help:
			result = "help"sv;
			break;
		case keys::menu:
			result = "menu"sv;
			break;
		case keys::select:
			result = "select"sv;
			break;
		case keys::stop:
			result = "stop"sv;
			break;
		case keys::again:
			result = "again"sv;
			break;
		case keys::undo:
			result = "undo"sv;
			break;
		case keys::cut:
			result = "cut"sv;
			break;
		case keys::copy:
			result = "copy"sv;
			break;
		case keys::paste:
			result = "paste"sv;
			break;
		case keys::find:
			result = "find"sv;
			break;
		case keys::mute:
			result = "mute"sv;
			break;
		case keys::volume_up:
			result = "volume_up"sv;
			break;
		case keys::volume_down:
			result = "volume_down"sv;
			break;
		case keys::kp_comma:
			result = "kp_comma"sv;
			break;
		case keys::kp_equalsas400:
			result = "kp_equalsas400"sv;
			break;
		case keys::alterase:
			result = "alterase"sv;
			break;
		case keys::sysreq:
			result = "sysreq"sv;
			break;
		case keys::cancel:
			result = "cancel"sv;
			break;
		case keys::clear:
			result = "clear"sv;
			break;
		case keys::prior:
			result = "prior"sv;
			break;
		case keys::return2:
			result = "return2"sv;
			break;
		case keys::separator:
			result = "separator"sv;
			break;
		case keys::out:
			result = "out"sv;
			break;
		case keys::oper:
			result = "oper"sv;
			break;
		case keys::clear_again:
			result = "clear_again"sv;
			break;
		case keys::crsel:
			result = "crsel"sv;
			break;
		case keys::exsel:
			result = "exsel"sv;
			break;
		case keys::kp_00:
			result = "kp_00"sv;
			break;
		case keys::kp_000:
			result = "kp_000"sv;
			break;
		case keys::thousands_separator:
			result = "thousands_separator"sv;
			break;
		case keys::decimal_separator:
			result = "decimal_separator"sv;
			break;
		case keys::currency_unit:
			result = "currency_unit"sv;
			break;
		case keys::currency_subunit:
			result = "currency_subunit"sv;
			break;
		case keys::kp_left_paren:
			result = "kp_left_paren"sv;
			break;
		case keys::kp_right_paren:
			result = "kp_right_paren"sv;
			break;
		case keys::kp_left_brace:
			result = "kp_left_brace"sv;
			break;
		case keys::kp_right_brace:
			result = "kp_right_brace"sv;
			break;
		case keys::kp_tab:
			result = "kp_tab"sv;
			break;
		case keys::kp_backspace:
			result = "kp_backspace"sv;
			break;
		case keys::kp_a:
			result = "kp_a"sv;
			break;
		case keys::kp_b:
			result = "kp_b"sv;
			break;
		case keys::kp_c:
			result = "kp_c"sv;
			break;
		case keys::kp_d:
			result = "kp_d"sv;
			break;
		case keys::kp_e:
			result = "kp_e"sv;
			break;
		case keys::kp_f:
			result = "kp_f"sv;
			break;
		case keys::kp_xor:
			result = "kp_xor"sv;
			break;
		case keys::kp_power:
			result = "kp_power"sv;
			break;
		case keys::kp_percent:
			result = "kp_percent"sv;
			break;
		case keys::kp_less:
			result = "kp_less"sv;
			break;
		case keys::kp_greater:
			result = "kp_greater"sv;
			break;
		case keys::kp_ampersand:
			result = "kp_ampersand"sv;
			break;
		case keys::kp_dblampersand:
			result = "kp_dblampersand"sv;
			break;
		case keys::kp_verticalbar:
			result = "kp_verticalbar"sv;
			break;
		case keys::kp_dblverticalbar:
			result = "kp_dblverticalbar"sv;
			break;
		case keys::kp_colon:
			result = "kp_colon"sv;
			break;
		case keys::kp_hash:
			result = "kp_hash"sv;
			break;
		case keys::kp_space:
			result = "kp_space"sv;
			break;
		case keys::kp_at:
			result = "kp_at"sv;
			break;
		case keys::kp_exclam:
			result = "kp_exclam"sv;
			break;
		case keys::kp_mem_store:
			result = "kp_mem_store"sv;
			break;
		case keys::kp_mem_recall:
			result = "kp_mem_recall"sv;
			break;
		case keys::kp_mem_clear:
			result = "kp_mem_clear"sv;
			break;
		case keys::kp_mem_add:
			result = "kp_mem_add"sv;
			break;
		case keys::kp_mem_subtract:
			result = "kp_mem_subtract"sv;
			break;
		case keys::kp_mem_multiply:
			result = "kp_mem_multiply"sv;
			break;
		case keys::kp_mem_divide:
			result = "kp_mem_divide"sv;
			break;
		case keys::kp_plus_minus:
			result = "kp_plus_minus"sv;
			break;
		case keys::kp_clear:
			result = "kp_clear"sv;
			break;
		case keys::kp_clear_entry:
			result = "kp_clear_entry"sv;
			break;
		case keys::kp_binary:
			result = "kp_binary"sv;
			break;
		case keys::kp_octal:
			result = "kp_octal"sv;
			break;
		case keys::kp_decimal:
			result = "kp_decimal"sv;
			break;
		case keys::kp_hexadecimal:
			result = "kp_hexadecimal"sv;
			break;
		case keys::left_ctrl:
			result = "left_ctrl"sv;
			break;
		case keys::left_shift:
			result = "left_shift"sv;
			break;
		case keys::left_alt:
			result = "left_alt"sv;
			break;
		case keys::left_gui:
			result = "left_gui"sv;
			break;
		case keys::right_ctrl:
			result = "right_ctrl"sv;
			break;
		case keys::right_shift:
			result = "right_shift"sv;
			break;
		case keys::right_alt:
			result = "right_alt"sv;
			break;
		case keys::right_gui:
			result = "right_gui"sv;
			break;
		case keys::mode:
			result = "mode"sv;
			break;
		case keys::audio_next:
			result = "audio_next"sv;
			break;
		case keys::audio_prev:
			result = "audio_prev"sv;
			break;
		case keys::audio_stop:
			result = "audio_stop"sv;
			break;
		case keys::audio_play:
			result = "audio_play"sv;
			break;
		case keys::audio_mute:
			result = "audio_mute"sv;
			break;
		case keys::media_select:
			result = "media_select"sv;
			break;
		case keys::www:
			result = "www"sv;
			break;
		case keys::mail:
			result = "mail"sv;
			break;
		case keys::calculator:
			result = "calculator"sv;
			break;
		case keys::computer:
			result = "computer"sv;
			break;
		case keys::ac_search:
			result = "ac_search"sv;
			break;
		case keys::ac_home:
			result = "ac_home"sv;
			break;
		case keys::ac_back:
			result = "ac_back"sv;
			break;
		case keys::ac_forward:
			result = "ac_forward"sv;
			break;
		case keys::ac_stop:
			result = "ac_stop"sv;
			break;
		case keys::ac_refresh:
			result = "ac_refresh"sv;
			break;
		case keys::ac_bookmarks:
			result = "ac_bookmarks"sv;
			break;
		case keys::brightness_down:
			result = "brightness_down"sv;
			break;
		case keys::brightness_up:
			result = "brightness_up"sv;
			break;
		case keys::display_switch:
			result = "display_switch"sv;
			break;
		case keys::kbd_illum_toggle:
			result = "kbd_illum_toggle"sv;
			break;
		case keys::kbd_illum_down:
			result = "kbd_illum_down"sv;
			break;
		case keys::kbd_illum_up:
			result = "kbd_illum_up"sv;
			break;
		case keys::eject:
			result = "eject"sv;
			break;
		case keys::sleep:
			result = "sleep"sv;
			break;
		case keys::app1:
			result = "app1"sv;
			break;
		case keys::app2:
			result = "app2"sv;
			break;
		case keys::audio_rewind:
			result = "audio_rewind"sv;
			break;
		case keys::audio_fast_forward:
			result = "audio_fast_forward"sv;
			break;
		}

		return result;
	}

	const std::string_view to_string(scancodes code)
	{
		using namespace std::string_view_literals;

		std::string_view result;

		switch (code)
		{
		default:
		case scancodes::unknown:
			result = "unknown"sv;
			break;
		case scancodes::a:
			result = "a"sv;
			break;
		case scancodes::b:
			result = "b"sv;
			break;
		case scancodes::c:
			result = "c"sv;
			break;
		case scancodes::d:
			result = "d"sv;
			break;
		case scancodes::e:
			result = "e"sv;
			break;
		case scancodes::f:
			result = "f"sv;
			break;
		case scancodes::g:
			result = "g"sv;
			break;
		case scancodes::h:
			result = "h"sv;
			break;
		case scancodes::i:
			result = "i"sv;
			break;
		case scancodes::j:
			result = "j"sv;
			break;
		case scancodes::k:
			result = "k"sv;
			break;
		case scancodes::l:
			result = "l"sv;
			break;
		case scancodes::m:
			result = "m"sv;
			break;
		case scancodes::n:
			result = "n"sv;
			break;
		case scancodes::o:
			result = "o"sv;
			break;
		case scancodes::p:
			result = "p"sv;
			break;
		case scancodes::q:
			result = "q"sv;
			break;
		case scancodes::r:
			result = "r"sv;
			break;
		case scancodes::s:
			result = "s"sv;
			break;
		case scancodes::t:
			result = "t"sv;
			break;
		case scancodes::u:
			result = "u"sv;
			break;
		case scancodes::v:
			result = "v"sv;
			break;
		case scancodes::w:
			result = "w"sv;
			break;
		case scancodes::x:
			result = "x"sv;
			break;
		case scancodes::y:
			result = "y"sv;
			break;
		case scancodes::z:
			result = "z"sv;
			break;
		case scancodes::num_1:
			result = "num_1"sv;
			break;
		case scancodes::num_2:
			result = "num_2"sv;
			break;
		case scancodes::num_3:
			result = "num_3"sv;
			break;
		case scancodes::num_4:
			result = "num_4"sv;
			break;
		case scancodes::num_5:
			result = "num_5"sv;
			break;
		case scancodes::num_6:
			result = "num_6"sv;
			break;
		case scancodes::num_7:
			result = "num_7"sv;
			break;
		case scancodes::num_8:
			result = "num_8"sv;
			break;
		case scancodes::num_9:
			result = "num_9"sv;
			break;
		case scancodes::num_0:
			result = "num_0"sv;
			break;
		case scancodes::enter:
			result = "enter"sv;
			break;
		case scancodes::escape:
			result = "escape"sv;
			break;
		case scancodes::backspace:
			result = "backspace"sv;
			break;
		case scancodes::tab:
			result = "tab"sv;
			break;
		case scancodes::space:
			result = "space"sv;
			break;
		case scancodes::minus:
			result = "minus"sv;
			break;
		case scancodes::equals:
			result = "equals"sv;
			break;
		case scancodes::left_bracket:
			result = "left_bracket"sv;
			break;
		case scancodes::right_bracket:
			result = "right_bracket"sv;
			break;
		case scancodes::backslash:
			result = "backslash"sv;
			break;
		case scancodes::non_ushash:
			result = "non_ushash"sv;
			break;
		case scancodes::semicolon:
			result = "semicolon"sv;
			break;
		case scancodes::apostrophe:
			result = "apostrophe"sv;
			break;
		case scancodes::grave:
			result = "grave"sv;
			break;
		case scancodes::comma:
			result = "comma"sv;
			break;
		case scancodes::period:
			result = "period"sv;
			break;
		case scancodes::slash:
			result = "slash"sv;
			break;
		case scancodes::capslock:
			result = "capslock"sv;
			break;
		case scancodes::f1:
			result = "f1"sv;
			break;
		case scancodes::f2:
			result = "f2"sv;
			break;
		case scancodes::f3:
			result = "f3"sv;
			break;
		case scancodes::f4:
			result = "f4"sv;
			break;
		case scancodes::f5:
			result = "f5"sv;
			break;
		case scancodes::f6:
			result = "f6"sv;
			break;
		case scancodes::f7:
			result = "f7"sv;
			break;
		case scancodes::f8:
			result = "f8"sv;
			break;
		case scancodes::f9:
			result = "f9"sv;
			break;
		case scancodes::f10:
			result = "f10"sv;
			break;
		case scancodes::f11:
			result = "f11"sv;
			break;
		case scancodes::f12:
			result = "f12"sv;
			break;
		case scancodes::printscreen:
			result = "printscreen"sv;
			break;
		case scancodes::scroll_lock:
			result = "scroll_lock"sv;
			break;
		case scancodes::pause:
			result = "pause"sv;
			break;
		case scancodes::insert:
			result = "insert"sv;
			break;
		case scancodes::home:
			result = "home"sv;
			break;
		case scancodes::page_up:
			result = "page_up"sv;
			break;
		case scancodes::del:
			result = "del"sv;
			break;
		case scancodes::end:
			result = "end"sv;
			break;
		case scancodes::page_down:
			result = "page_down"sv;
			break;
		case scancodes::right:
			result = "right"sv;
			break;
		case scancodes::left:
			result = "left"sv;
			break;
		case scancodes::down:
			result = "down"sv;
			break;
		case scancodes::up:
			result = "up"sv;
			break;
		case scancodes::numlock_clear:
			result = "numlock_clear"sv;
			break;
		case scancodes::kp_divide:
			result = "kp_divide"sv;
			break;
		case scancodes::kp_multiply:
			result = "kp_multiply"sv;
			break;
		case scancodes::kp_minus:
			result = "kp_minus"sv;
			break;
		case scancodes::kp_plus:
			result = "kp_plus"sv;
			break;
		case scancodes::kp_enter:
			result = "kp_enter"sv;
			break;
		case scancodes::kp_1:
			result = "kp_1"sv;
			break;
		case scancodes::kp_2:
			result = "kp_2"sv;
			break;
		case scancodes::kp_3:
			result = "kp_3"sv;
			break;
		case scancodes::kp_4:
			result = "kp_4"sv;
			break;
		case scancodes::kp_5:
			result = "kp_5"sv;
			break;
		case scancodes::kp_6:
			result = "kp_6"sv;
			break;
		case scancodes::kp_7:
			result = "kp_7"sv;
			break;
		case scancodes::kp_8:
			result = "kp_8"sv;
			break;
		case scancodes::kp_9:
			result = "kp_9"sv;
			break;
		case scancodes::kp_0:
			result = "kp_0"sv;
			break;
		case scancodes::kp_period:
			result = "kp_period"sv;
			break;
		case scancodes::non_usbackslash:
			result = "non_usbackslash"sv;
			break;
		case scancodes::application:
			result = "application"sv;
			break;
		case scancodes::power:
			result = "power"sv;
			break;
		case scancodes::kp_equals:
			result = "kp_equals"sv;
			break;
		case scancodes::f13:
			result = "f13"sv;
			break;
		case scancodes::f14:
			result = "f14"sv;
			break;
		case scancodes::f15:
			result = "f15"sv;
			break;
		case scancodes::f16:
			result = "f16"sv;
			break;
		case scancodes::f17:
			result = "f17"sv;
			break;
		case scancodes::f18:
			result = "f18"sv;
			break;
		case scancodes::f19:
			result = "f19"sv;
			break;
		case scancodes::f20:
			result = "f20"sv;
			break;
		case scancodes::f21:
			result = "f21"sv;
			break;
		case scancodes::f22:
			result = "f22"sv;
			break;
		case scancodes::f23:
			result = "f23"sv;
			break;
		case scancodes::f24:
			result = "f24"sv;
			break;
		case scancodes::execute:
			result = "execute"sv;
			break;
		case scancodes::help:
			result = "help"sv;
			break;
		case scancodes::menu:
			result = "menu"sv;
			break;
		case scancodes::select:
			result = "select"sv;
			break;
		case scancodes::stop:
			result = "stop"sv;
			break;
		case scancodes::again:
			result = "again"sv;
			break;
		case scancodes::undo:
			result = "undo"sv;
			break;
		case scancodes::cut:
			result = "cut"sv;
			break;
		case scancodes::copy:
			result = "copy"sv;
			break;
		case scancodes::paste:
			result = "paste"sv;
			break;
		case scancodes::find:
			result = "find"sv;
			break;
		case scancodes::mute:
			result = "mute"sv;
			break;
		case scancodes::volume_up:
			result = "volume_up"sv;
			break;
		case scancodes::volume_down:
			result = "volume_down"sv;
			break;
		case scancodes::kp_comma:
			result = "kp_comma"sv;
			break;
		case scancodes::kp_equalsas400:
			result = "kp_equalsas400"sv;
			break;
		case scancodes::international1:
			result = "international1"sv;
			break;
		case scancodes::international2:
			result = "international2"sv;
			break;
		case scancodes::international3:
			result = "international3"sv;
			break;
		case scancodes::international4:
			result = "international4"sv;
			break;
		case scancodes::international5:
			result = "international5"sv;
			break;
		case scancodes::international6:
			result = "international6"sv;
			break;
		case scancodes::international7:
			result = "international7"sv;
			break;
		case scancodes::international8:
			result = "international8"sv;
			break;
		case scancodes::international9:
			result = "international9"sv;
			break;
		case scancodes::lang1:
			result = "lang1"sv;
			break;
		case scancodes::lang2:
			result = "lang2"sv;
			break;
		case scancodes::lang3:
			result = "lang3"sv;
			break;
		case scancodes::lang4:
			result = "lang4"sv;
			break;
		case scancodes::lang5:
			result = "lang5"sv;
			break;
		case scancodes::lang6:
			result = "lang6"sv;
			break;
		case scancodes::lang7:
			result = "lang7"sv;
			break;
		case scancodes::lang8:
			result = "lang8"sv;
			break;
		case scancodes::lang9:
			result = "lang9"sv;
			break;
		case scancodes::alterase:
			result = "alterase"sv;
			break;
		case scancodes::sysreq:
			result = "sysreq"sv;
			break;
		case scancodes::cancel:
			result = "cancel"sv;
			break;
		case scancodes::clear:
			result = "clear"sv;
			break;
		case scancodes::prior:
			result = "prior"sv;
			break;
		case scancodes::return2:
			result = "return2"sv;
			break;
		case scancodes::separator:
			result = "separator"sv;
			break;
		case scancodes::out:
			result = "out"sv;
			break;
		case scancodes::oper:
			result = "oper"sv;
			break;
		case scancodes::clear_again:
			result = "clear_again"sv;
			break;
		case scancodes::crsel:
			result = "crsel"sv;
			break;
		case scancodes::exsel:
			result = "exsel"sv;
			break;
		case scancodes::kp_00:
			result = "kp_00"sv;
			break;
		case scancodes::kp_000:
			result = "kp_000"sv;
			break;
		case scancodes::thousands_separator:
			result = "thousands_separator"sv;
			break;
		case scancodes::decimal_separator:
			result = "decimal_separator"sv;
			break;
		case scancodes::currency_unit:
			result = "currency_unit"sv;
			break;
		case scancodes::currency_subunit:
			result = "currency_subunit"sv;
			break;
		case scancodes::kp_left_paren:
			result = "kp_left_paren"sv;
			break;
		case scancodes::kp_right_paren:
			result = "kp_right_paren"sv;
			break;
		case scancodes::kp_left_brace:
			result = "kp_left_brace"sv;
			break;
		case scancodes::kp_right_brace:
			result = "kp_right_brace"sv;
			break;
		case scancodes::kp_tab:
			result = "kp_tab"sv;
			break;
		case scancodes::kp_backspace:
			result = "kp_backspace"sv;
			break;
		case scancodes::kp_a:
			result = "kp_a"sv;
			break;
		case scancodes::kp_b:
			result = "kp_b"sv;
			break;
		case scancodes::kp_c:
			result = "kp_c"sv;
			break;
		case scancodes::kp_d:
			result = "kp_d"sv;
			break;
		case scancodes::kp_e:
			result = "kp_e"sv;
			break;
		case scancodes::kp_f:
			result = "kp_f"sv;
			break;
		case scancodes::kp_xor:
			result = "kp_xor"sv;
			break;
		case scancodes::kp_power:
			result = "kp_power"sv;
			break;
		case scancodes::kp_percent:
			result = "kp_percent"sv;
			break;
		case scancodes::kp_less:
			result = "kp_less"sv;
			break;
		case scancodes::kp_greater:
			result = "kp_greater"sv;
			break;
		case scancodes::kp_ampersand:
			result = "kp_ampersand"sv;
			break;
		case scancodes::kp_dblampersand:
			result = "kp_dblampersand"sv;
			break;
		case scancodes::kp_verticalbar:
			result = "kp_verticalbar"sv;
			break;
		case scancodes::kp_dblverticalbar:
			result = "kp_dblverticalbar"sv;
			break;
		case scancodes::kp_colon:
			result = "kp_colon"sv;
			break;
		case scancodes::kp_hash:
			result = "kp_hash"sv;
			break;
		case scancodes::kp_space:
			result = "kp_space"sv;
			break;
		case scancodes::kp_at:
			result = "kp_at"sv;
			break;
		case scancodes::kp_exclam:
			result = "kp_exclam"sv;
			break;
		case scancodes::kp_mem_store:
			result = "kp_mem_store"sv;
			break;
		case scancodes::kp_mem_recall:
			result = "kp_mem_recall"sv;
			break;
		case scancodes::kp_mem_clear:
			result = "kp_mem_clear"sv;
			break;
		case scancodes::kp_mem_add:
			result = "kp_mem_add"sv;
			break;
		case scancodes::kp_mem_subtract:
			result = "kp_mem_subtract"sv;
			break;
		case scancodes::kp_mem_multiply:
			result = "kp_mem_multiply"sv;
			break;
		case scancodes::kp_mem_divide:
			result = "kp_mem_divide"sv;
			break;
		case scancodes::kp_plus_minus:
			result = "kp_plus_minus"sv;
			break;
		case scancodes::kp_clear:
			result = "kp_clear"sv;
			break;
		case scancodes::kp_clear_entry:
			result = "kp_clear_entry"sv;
			break;
		case scancodes::kp_binary:
			result = "kp_binary"sv;
			break;
		case scancodes::kp_octal:
			result = "kp_octal"sv;
			break;
		case scancodes::kp_decimal:
			result = "kp_decimal"sv;
			break;
		case scancodes::kp_hexadecimal:
			result = "kp_hexadecimal"sv;
			break;
		case scancodes::left_ctrl:
			result = "left_ctrl"sv;
			break;
		case scancodes::left_shift:
			result = "left_shift"sv;
			break;
		case scancodes::left_alt:
			result = "left_alt"sv;
			break;
		case scancodes::left_gui:
			result = "left_gui"sv;
			break;
		case scancodes::right_ctrl:
			result = "right_ctrl"sv;
			break;
		case scancodes::right_shift:
			result = "right_shift"sv;
			break;
		case scancodes::right_alt:
			result = "right_alt"sv;
			break;
		case scancodes::right_gui:
			result = "right_gui"sv;
			break;
		case scancodes::mode:
			result = "mode"sv;
			break;
		case scancodes::audio_next:
			result = "audio_next"sv;
			break;
		case scancodes::audio_prev:
			result = "audio_prev"sv;
			break;
		case scancodes::audio_stop:
			result = "audio_stop"sv;
			break;
		case scancodes::audio_play:
			result = "audio_play"sv;
			break;
		case scancodes::audio_mute:
			result = "audio_mute"sv;
			break;
		case scancodes::media_select:
			result = "media_select"sv;
			break;
		case scancodes::www:
			result = "www"sv;
			break;
		case scancodes::mail:
			result = "mail"sv;
			break;
		case scancodes::calculator:
			result = "calculator"sv;
			break;
		case scancodes::computer:
			result = "computer"sv;
			break;
		case scancodes::ac_search:
			result = "ac_search"sv;
			break;
		case scancodes::ac_home:
			result = "ac_home"sv;
			break;
		case scancodes::ac_back:
			result = "ac_back"sv;
			break;
		case scancodes::ac_forward:
			result = "ac_forward"sv;
			break;
		case scancodes::ac_stop:
			result = "ac_stop"sv;
			break;
		case scancodes::ac_refresh:
			result = "ac_refresh"sv;
			break;
		case scancodes::ac_bookmarks:
			result = "ac_bookmarks"sv;
			break;
		case scancodes::brightness_down:
			result = "brightness_down"sv;
			break;
		case scancodes::brightness_up:
			result = "brightness_up"sv;
			break;
		case scancodes::display_switch:
			result = "display_switch"sv;
			break;
		case scancodes::kbd_illum_toggle:
			result = "kbd_illum_toggle"sv;
			break;
		case scancodes::kbd_illum_down:
			result = "kbd_illum_down"sv;
			break;
		case scancodes::kbd_illum_up:
			result = "kbd_illum_up"sv;
			break;
		case scancodes::eject:
			result = "eject"sv;
			break;
		case scancodes::sleep:
			result = "sleep"sv;
			break;
		case scancodes::app1:
			result = "app1"sv;
			break;
		case scancodes::app2:
			result = "app2"sv;
			break;
		case scancodes::audio_rewind:
			result = "audio_rewind"sv;
			break;
		case scancodes::audio_fastforward:
			result = "audio_fastforward"sv;
			break;
		}

		return result;
	}

	std::string to_string(modifiers mod)
	{
		using namespace std::string_literals;
		using namespace std::string_view_literals;

		if (mod == modifiers::none)
			return "none"s;

		const std::array<std::pair<modifiers, std::string_view>, 15> mods{{
			{modifiers::gui, "gui"sv},
			{modifiers::ctrl, "ctrl"sv},
			{modifiers::alt, "alt"sv},
			{modifiers::shift, "shift"sv},
			{modifiers::left_gui, "left_gui"sv},
			{modifiers::right_gui, "right_gui"sv},
			{modifiers::left_ctrl, "left_ctrl"sv},
			{modifiers::right_ctrl, "right_ctrl"sv},
			{modifiers::left_alt, "left_alt"sv},
			{modifiers::right_alt, "right_alt"sv},
			{modifiers::left_shift, "left_shift"sv},
			{modifiers::right_shift, "right_shift"sv},
			{modifiers::num, "num"sv},
			{modifiers::caps, "caps"sv},
			{modifiers::mode, "mode"sv},
		}};

		// we shouldn't ever get more than 7 modifiers in here because if both the left and right variant are set, we combine
		std::array<std::string_view, 7> keys;
		size_t size = 0;

		for (auto flag : mods)
		{
			if (flag_all_set(mod, flag.first))
			{
				assert(size < keys.size());
				keys[size++] = flag.second;
				mod = flag_unset(mod, flag.first);
			}
		}

		return format("{}", fmt::join(begin(keys), begin(keys) + size, "|"));
	}
}
