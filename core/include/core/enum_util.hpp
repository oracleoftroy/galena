#pragma once

#include <type_traits>

// for use with enum class bitflags, defines bitwise operators
#define CORE_MAKE_FLAG_ENUM(EnumType)                                                            \
	constexpr EnumType operator~ (EnumType value) noexcept                                       \
	{                                                                                            \
		typedef std::underlying_type_t<EnumType> as_int;                                         \
		return EnumType(~as_int(value));                                                         \
	}                                                                                            \
	                                                                                             \
	constexpr EnumType operator& (EnumType x, EnumType y) noexcept                               \
	{                                                                                            \
		typedef std::underlying_type_t<EnumType> as_int;                                         \
		return EnumType(as_int(x) & as_int(y));                                                  \
	}                                                                                            \
	                                                                                             \
	constexpr EnumType operator| (EnumType x, EnumType y) noexcept                               \
	{                                                                                            \
		typedef std::underlying_type_t<EnumType> as_int;                                         \
		return EnumType(as_int(x) | as_int(y));                                                  \
	}                                                                                            \
	                                                                                             \
	constexpr EnumType operator^ (EnumType x, EnumType y) noexcept                               \
	{                                                                                            \
		typedef std::underlying_type_t<EnumType> as_int;                                         \
		return EnumType(as_int(x) ^ as_int(y));                                                  \
	}                                                                                            \
	                                                                                             \
	template <typename ...EnumTypes>                                                             \
	constexpr EnumType flag_set(EnumType value, EnumType flag, EnumTypes... flags) noexcept      \
	{                                                                                            \
		static_assert((std::is_same_v<EnumType, EnumTypes> && ...));                             \
		return value | (flag | ... | flags);                                                     \
	}                                                                                            \
	                                                                                             \
	template <typename ...EnumTypes>                                                             \
	constexpr EnumType flag_unset(EnumType value, EnumType flag, EnumTypes... flags) noexcept    \
	{                                                                                            \
		static_assert((std::is_same_v<EnumType, EnumTypes> && ...));                             \
		return value & ~(flag | ... | flags);                                                    \
	}                                                                                            \
	                                                                                             \
	constexpr bool flag_all_set(EnumType value, EnumType flag) noexcept                          \
	{                                                                                            \
		return (value & flag) == flag;                                                           \
	}                                                                                            \
	                                                                                             \
	constexpr bool flag_any_set(EnumType value, EnumType flag) noexcept                          \
	{                                                                                            \
		typedef std::underlying_type_t<EnumType> as_int;                                         \
		return as_int(value & flag) != 0;                                                        \
	}                                                                                            \
	                                                                                             \
	static_assert(std::is_enum_v<EnumType>, "type must be an enum")

namespace core::detail::test
{
	enum class test
	{
		a = 0,
		b = 1,
		c = 2,
		d = 4
	};

	CORE_MAKE_FLAG_ENUM(test);

	static_assert(flag_all_set(test::a, test::a));
	static_assert(flag_all_set(test::b, test::b));
	static_assert(flag_all_set(test::b | test::c, test::b));
	static_assert(flag_all_set(test::b | test::c, test::c));
	static_assert(!flag_all_set(test::b | test::c, test::d));
	static_assert(flag_set(test::b, test::c, test::d) == (test::b | test::c | test::d));
	static_assert(flag_unset(flag_set(test::b, test::c, test::d), test::b, test::d) == test::c);

	static_assert(flag_all_set(test::b | test::c, test::b | test::c));
	static_assert(!flag_all_set(test::b, test::b | test::c));
	static_assert(flag_any_set(test::b | test::c, test::b | test::c));
	static_assert(flag_any_set(test::b, test::b | test::c));
}
