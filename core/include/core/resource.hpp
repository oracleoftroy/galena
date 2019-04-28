#pragma once

#include <type_traits>
#include <utility>

#include "preprocessor.hpp"

namespace core
{
	namespace resource::opts
	{
		template <bool value>
		struct implicit_conversion : std::bool_constant<value> {};
	}

	// resource_type - helper class for creating raii resources
	//
	// AquirePolicy<T> provides resource with the functions:
	//     static T aquire(...);
	//     static <ignored> release(T);
	//
	// example:
	//
	//	template <typename T>
	//	struct my_resource_impl
	//	{
	//		static int aquire(float x, const char *other) noexcept {
	//			return make_my_resource(x, other);
	//		}
	//
	//		static void release(int x) noexcept {
	//			release_my_resource(x);
	//		}
	//	};
	//
	// implicit_conversion

	template <typename T, template<typename> typename AquirePolicy, typename AllowImplicitConversion = resource::opts::implicit_conversion<false>>
	class resource_type : AquirePolicy<T>
	{
		using Aquire = typename AquirePolicy<T>;
	public:
		template <typename ...Args>
		static resource_type create(Args &&... args) noexcept(noexcept(Aquire::aquire(std::forward<Args>(args)...)))
		{
			return resource_type(Aquire::aquire(std::forward<Args>(args)...));
		}

		resource_type() noexcept(noexcept(T()))
			: value()
		{
		}

		~resource_type()
		{
			Aquire::release(value);
		}

		resource_type(resource_type &&other) noexcept(noexcept(T()) && std::is_nothrow_constructible_v<T>)
			: value(std::exchange(other.value, T()))
		{
		}

		resource_type &operator=(resource_type &&other) noexcept(std::is_nothrow_assignable_v<T> && noexcept(Aquire::release(value)))
		{
			resource_type old(std::move(*this));
			value = std::exchange(other.value, T());
		}

		template <typename U = T>
		explicit operator std::enable_if_t<!AllowImplicitConversion::value, U>() const noexcept { return value; }

		template <typename U = T>
		operator std::enable_if_t<AllowImplicitConversion::value, U>() const noexcept { return value; }

		// non-copyable
		resource_type(const resource_type &other) noexcept = delete;
		resource_type &operator=(const resource_type &other) noexcept = delete;

	private:
		resource_type(T value) noexcept(std::is_nothrow_constructible_v<T>)
			: value(std::move(value))
		{
		}

		T value;
	};
}

#define CORE_GENERATE_RESOURCE(ResourceName, ResourceType, CreateFn, DestroyFn, ...)                            \
    template <typename T>                                                                                       \
    struct CORE_PREPROSSOR_CONCAT(ResourceName, _policy)                                                        \
    {                                                                                                           \
        template <typename ...Args>                                                                             \
        static T aquire(Args&&... args) noexcept(noexcept(CreateFn(std::forward<Args>(args)...)))               \
        {                                                                                                       \
            return CreateFn(std::forward<Args>(args)...);                                                       \
        }                                                                                                       \
                                                                                                                \
        static void release(T value) noexcept(noexcept(DestroyFn(value)))                                       \
        {                                                                                                       \
            DestroyFn(value);                                                                                   \
        }                                                                                                       \
    };                                                                                                          \
    using ResourceName = core::resource_type<ResourceType, CORE_PREPROSSOR_CONCAT(ResourceName, _policy), __VA_ARGS__>

namespace core::detail::test
{
	inline int create_test_resource(int x, [[maybe_unused]]const char *other) noexcept
	{
		return x;
	}

	inline void clean_test_resource([[maybe_unused]] int x) noexcept
	{
	}

	CORE_GENERATE_RESOURCE(my_test_resource, int, create_test_resource, clean_test_resource);

	static_assert(noexcept(my_test_resource::create(42, "whatever")));
	static_assert(std::is_nothrow_default_constructible_v<my_test_resource>);
	static_assert(std::is_nothrow_move_constructible_v<my_test_resource>);
	static_assert(std::is_nothrow_destructible_v<my_test_resource>);
}
