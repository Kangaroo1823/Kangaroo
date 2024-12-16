//
// Created by peter on 01/12/2024.
//

#ifndef BITBOARD_H
#define BITBOARD_H

#ifdef _MSC_VER
#include <intrin0.inl.h>
#include <immintrin.h>
#elif defined(__clang__)
#include <immintrin.h>     // for _pext_u64, _blsr_u64, _pdep_u64, _tzcnt_u64
#include <popcntintrin.h>  // for _mm_popcnt_u64
#elif defined(__GNUC__)
#include <immintrin.h>     // for _pext_u64, _blsr_u64, _pdep_u64, _tzcnt_u64
#include <popcntintrin.h>  // for _mm_popcnt_u64
#endif

#include <array>           // for array
#include <cstddef>         // for size_t
#include <cstdint>         // for int64_t, uint64_t
#include <string>          // for string
#include <utility>         // for to_underlying
#include "base.h"



/** define a 'Bitboard' to be a 64 bit unsigned integer
 */
using Bitboard = uint64_t;

/**
 * Have a convenient way of naming positions
 */
using Position = enum class Position_t  : std::size_t {
    A1 = 0,
    B1 = 1,
    C1 = 2,
    D1 = 3,
    E1 = 4,
    F1 = 5,
    G1 = 6,
    H1 = 7,
    A2 = 8,
    B2 = 9,
    C2 = 10,
    D2 = 11,
    E2 = 12,
    F2 = 13,
    G2 = 14,
    H2 = 15,
    A3 = 16,
    B3 = 17,
    C3 = 18,
    D3 = 19,
    E3 = 20,
    F3 = 21,
    G3 = 22,
    H3 = 23,
    A4 = 24,
    B4 = 25,
    C4 = 26,
    D4 = 27,
    E4 = 28,
    F4 = 29,
    G4 = 30,
    H4 = 31,
    A5 = 32,
    B5 = 33,
    C5 = 34,
    D5 = 35,
    E5 = 36,
    F5 = 37,
    G5 = 38,
    H5 = 39,
    A6 = 40,
    B6 = 41,
    C6 = 42,
    D6 = 43,
    E6 = 44,
    F6 = 45,
    G6 = 46,
    H6 = 47,
    A7 = 48,
    B7 = 49,
    C7 = 50,
    D7 = 51,
    E7 = 52,
    F7 = 53,
    G7 = 54,
    H7 = 55,
    A8 = 56,
    B8 = 57,
    C8 = 58,
    D8 = 59,
    E8 = 60,
    F8 = 61,
    G8 = 62,
    H8 = 63
};

constexpr std::array<Position, 64> All_Positions = {
    Position_t::A1, Position_t::B1, Position_t::C1, Position_t::D1, Position_t::E1, Position_t::F1, Position_t::G1, Position_t::H1,
    Position_t::A2, Position_t::B2, Position_t::C2, Position_t::D2, Position_t::E2, Position_t::F2, Position_t::G2, Position_t::H2,
    Position_t::A3, Position_t::B3, Position_t::C3, Position_t::D3, Position_t::E3, Position_t::F3, Position_t::G3, Position_t::H3,
    Position_t::A4, Position_t::B4, Position_t::C4, Position_t::D4, Position_t::E4, Position_t::F4, Position_t::G4, Position_t::H4,
    Position_t::A5, Position_t::B5, Position_t::C5, Position_t::D5, Position_t::E5, Position_t::F5, Position_t::G5, Position_t::H5,
    Position_t::A6, Position_t::B6, Position_t::C6, Position_t::D6, Position_t::E6, Position_t::F6, Position_t::G6, Position_t::H6,
    Position_t::A7, Position_t::B7, Position_t::C7, Position_t::D7, Position_t::E7, Position_t::F7, Position_t::G7, Position_t::H7,
    Position_t::A8, Position_t::B8, Position_t::C8, Position_t::D8, Position_t::E8, Position_t::F8, Position_t::G8, Position_t::H8
};

constexpr Position rank_file_to_position(const std::size_t rank, const std::size_t file) {
    return All_Positions[rank * 8 + file];
}

constexpr Bitboard set_bit(const Bitboard bitboard, const Position &position) {
    return bitboard | (1ULL << std::to_underlying(position));
}

constexpr Bitboard get_bit(const Bitboard bitboard, const Position &position) {
    return bitboard & (1ULL << std::to_underlying(position));
}

constexpr Bitboard pop_bit(const Bitboard bitboard, const Position &position) {
    return bitboard & ~(1ULL << std::to_underlying(position));
}


constexpr int64_t Bitcount(const Bitboard board) {
#ifdef _MSC_VER
    return static_cast<int64_t>(__popcnt64(board));
#elif defined(__clang__)
    return _mm_popcnt_u64(board);
#elif defined(__GNUC__)
    return _mm_popcnt_u64(board);
#endif

}

constexpr Bitboard fake_tzcnt_u64(const Bitboard bitboard) {
    // count the bits before the first 1 bit.
    const auto b = static_cast<Bitboard>(-static_cast<int64_t>(bitboard));
    return static_cast<Bitboard>(Bitcount((bitboard & b) - 1));
}


/**
 * Computes the index of the least significant set bit in the given bitboard.
 *
 * This function utilizes the _tzcnt_u64 intrinsic to determine the index of
 * the least significant bit that is set to '1' in the bitboard, interpreted as
 * a zero-based position.
 *
 * @param bitboard The bitboard to extract the least significant bit's index from.
 * @return The index of the least significant set bit in the input bitboard.
 */
constexpr Bitboard SquareOf(const Bitboard bitboard) {
    if consteval {
        return fake_tzcnt_u64(bitboard);
    } else {
        return _tzcnt_u64(bitboard);
    }
}

/**
 * Extracts bits from the given bitboard using the specified mask.
 *
 * This function utilizes the _pext_u64 intrinsic to extract bits from the
 * specified bitboard according to the pattern specified by the mask.
 * The bits in the bitboard corresponding to '1's in the mask are
 * extracted to form a densely packed result.
 *
 * @param bitboard The Bitboard from which bits will be extracted.
 * @param mask The Bitboard mask that specifies which bits to extract.
 * @return A Bitboard containing the extracted bits, densely packed.
 */
constexpr Bitboard ExtractMask(const Bitboard bitboard, const Bitboard mask) {
    return _pext_u64(bitboard,mask);
}


template<typename T, std::size_t N>
/**
 * Creates an occupation mask on a bitboard based on the provided index and mask.
 *
 * The function utilizes the parallel bits deposit instruction (_pdep_u64).
 * It maps bits from the index value onto the specified positions in the mask.
 *
 * @param index An unsigned integer representing the index or bit pattern to be mapped onto the mask.
 * @param mask A Bitboard representing the mask where the index bits are to be deposited.
 * @return A Bitboard with the occupation mask applied, effectively storing the mapping of index bits to the mask.
 */
constexpr Bitboard create_occupation_of_mask(const typename std::array<T,N>::size_type index, Bitboard mask ) {
    return _pdep_u64(index, mask);
}

template<typename Fn>
/**
 * @brief Iterates through the bits set in a Bitboard and applies a function to each.
 *
 * This function iterates over each bit that is set (1) in the given Bitboard `x`.
 * During each iteration, the provided callable `f` is invoked with the current bit
 * represented as a Bitboard. The loop operates by successively clearing the least
 * significant set bit using the `_blsr_u64` intrinsic.
 *
 * @tparam Fn The type of the callable object. Must be invokable with a Bitboard.
 * @param x The Bitboard to iterate through. Each set bit (1) in `x` will be visited once.
 * @param f The callable to apply to each set bit. It must accept a single parameter of type Bitboard.
 */
constexpr void Bitloop(Bitboard x, Fn f) {
    for(;x;x=_blsr_u64(x)) {
        f(x);
    }
}



constexpr Bitboard not_a_file = /*
        A  B  C  D  E  F  G  H
    1   0  1  1  1  1  1  1  1
    2   0  1  1  1  1  1  1  1
    3   0  1  1  1  1  1  1  1
    4   0  1  1  1  1  1  1  1
    5   0  1  1  1  1  1  1  1
    6   0  1  1  1  1  1  1  1
    7   0  1  1  1  1  1  1  1
    8   0  1  1  1  1  1  1  1

       bitboard as 64 bit integer: */
       18374403900871474942ULL;

constexpr Bitboard not_ab_file = /*
        A  B  C  D  E  F  G  H
    1   0  0  1  1  1  1  1  1
    2   0  0  1  1  1  1  1  1
    3   0  0  1  1  1  1  1  1
    4   0  0  1  1  1  1  1  1
    5   0  0  1  1  1  1  1  1
    6   0  0  1  1  1  1  1  1
    7   0  0  1  1  1  1  1  1
    8   0  0  1  1  1  1  1  1

       bitboard as 64 bit integer: */
       18229723555195321596ULL;

constexpr Bitboard not_h_file = /*
        A  B  C  D  E  F  G  H
    1   1  1  1  1  1  1  1  0
    2   1  1  1  1  1  1  1  0
    3   1  1  1  1  1  1  1  0
    4   1  1  1  1  1  1  1  0
    5   1  1  1  1  1  1  1  0
    6   1  1  1  1  1  1  1  0
    7   1  1  1  1  1  1  1  0
    8   1  1  1  1  1  1  1  0

       bitboard as 64 bit integer: */
       9187201950435737471ULL;

constexpr Bitboard not_gh_file = /*
        A  B  C  D  E  F  G  H
    1   1  1  1  1  1  1  0  0
    2   1  1  1  1  1  1  0  0
    3   1  1  1  1  1  1  0  0
    4   1  1  1  1  1  1  0  0
    5   1  1  1  1  1  1  0  0
    6   1  1  1  1  1  1  0  0
    7   1  1  1  1  1  1  0  0
    8   1  1  1  1  1  1  0  0

       bitboard as 64 bit integer: */
       4557430888798830399ULL;

void print_bitboard(Bitboard bitboard);
std::string print_position(Position position);

#endif //BITBOARD_H
