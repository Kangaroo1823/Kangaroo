//
// Created by peter on 09/12/2024.
//

#ifndef BASE_H
#define BASE_H

#ifdef _MSC_VER
#define _ASSUME(cond) __assume(cond)
#define _Compiletime __forceinline static constexpr
#define _NoInline __declspec(noinline)
#define _Inline inline
#define _ForceInline __forceinline
//#define Bitcount(X) __popcnt64(X)
#elif defined(__clang__)
#define _ASSUME(cond) ((cond) ? static_cast<void>(0) : __builtin_unreachable())
#define _Compiletime __attribute__((always_inline)) static constexpr
#define _NoInline __attribute__((noinline))
#define _Inline inline
#define _ForceInline __attribute__((always_inline))
//#define Bitcount(X) static_cast<uint64_t>(__builtin_popcountll(X))
#elif defined(__GNUC__)
#define _ASSUME(cond) ((cond) ? static_cast<void>(0) : __builtin_unreachable())
#define _Compiletime __attribute__((always_inline)) static constexpr
#define _NoInline __attribute__ ((noinline))
#define _Inline inline
#define _ForceInline __attribute__((always_inline)) inline
//#define Bitcount(X) static_cast<uint64_t>(__builtin_popcountll(X))
#else
#define _ASSUME(cond) static_cast<void>(!!(cond))
#define _Compiletime static constexpr
#define _Inline inline
#endif

#endif //BASE_H
