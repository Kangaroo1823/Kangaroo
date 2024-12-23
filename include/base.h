//
// Created by peter on 09/12/2024.
//

#ifndef BASE_H
#define BASE_H

#include <functional>
#include <utility>


#ifdef _MSC_VER
#define _ASSUME(cond) __assume(cond)
#define _Compiletime __forceinline static constexpr
#define _NoInline __declspec(noinline)
#define _Inline inline
#define _ForceInline __forceinline
#elif defined(__clang__)
#define _ASSUME(cond) ((cond) ? static_cast<void>(0) : __builtin_unreachable())
#define _Compiletime __attribute__((always_inline)) static constexpr
#define _NoInline __attribute__((noinline))
#define _Inline inline
#define _ForceInline __attribute__((always_inline))
#elif defined(__GNUC__)
#define _ASSUME(cond) ((cond) ? static_cast<void>(0) : __builtin_unreachable())
#define _Compiletime __attribute__((always_inline)) static constexpr
#define _NoInline __attribute__ ((noinline))
#define _Inline inline
#define _ForceInline __attribute__((always_inline)) inline
#else
#define _ASSUME(cond) static_cast<void>(!!(cond))
#define _Compiletime static constexpr
#define _Inline inline
#endif

using Slider = enum class Slider_t : std::size_t {
    rook = 0,
    bishop = 1,
};


/**
 * @brief Returns the given value as a compile-time constant.
 *
 * This function can be used to force evaluation at compile
 * time of its argument
 *
 * @param value The value to be marked as a compile-time constant.
 * @return The input value, as a constant expression.
 */
#if defined(__GNUC__)
consteval auto as_constant(auto value) {
    return value;
}
#endif
//
#if defined(__clang__)
#define as_constant(value) value
//
// template< typename ... Param>
// consteval decltype(auto) as_constant(Param && ... param) {
//     return std::invoke(std::forward<Param>(param)...);
// }
#endif

#endif //BASE_H
