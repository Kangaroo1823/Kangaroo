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
#include <format>
#include <string>          // for string
#include <utility>         // for to_underlying
#include "types.h"



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


/**
 *
 * @param bitboard
 * @return The number of set bits in bitboard
 */
constexpr int64_t Bitcount_(Bitboard bitboard) {
    // initialize the count variable
    int64_t count = 0ULL;

    // loop while there are still some bits set to one in bitboard
    while (bitboard) {
        // increment the count variable
        count++;

        // erase the least significant one bit
        bitboard &= bitboard - 1;
    }

    // return the count
    return count;
}

constexpr int64_t Bitcount(const Bitboard board) {
    if consteval {
        return Bitcount_(board);
    } else {
#ifdef _MSC_VER
        return static_cast<int64_t>(__popcnt64(board));
#elif defined(__clang__)
        return _mm_popcnt_u64(board);
#elif defined(__GNUC__)
        return _mm_popcnt_u64(board);
#endif
    }
}

constexpr Bitboard square_of_(const Bitboard bitboard) {
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
constexpr Bitboard square_of(const Bitboard bitboard) {
    if consteval {
        return square_of_(bitboard);
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

/**
 * Generates a bitboard with a specific occupancy pattern based on the given index and mask.
 *
 * This function creates an occupancy bitboard by iterating through the bits set in the mask
 * and conditionally setting corresponding bits in the resulting occupancy bitboard based on
 * the provided index.
 *
 * @param index A size_t value representing the index used to determine which bits from the mask
 *              are included in the resulting occupancy bitboard.
 * @param mask A Bitboard value representing the mask with bits set to 1 for positions to consider
 *             in the occupancy creation.
 * @return A Bitboard representing the calculated occupancy based on the index and mask.
 */
constexpr Bitboard create_occupation_from_mask_(const std::size_t index, const Bitboard mask ) {
    Bitboard occupancy = 0ULL;
    Bitboard mask_copy = mask;

    const int64_t count = Bitcount(mask_copy);
    for (unsigned int i = 0; i < count; i++) {
        const Bitboard s = square_of(mask_copy);
        mask_copy &= mask_copy - 1ULL;
        if (index & 1ULL << i) occupancy |= 1ULL << s;
    }

    return occupancy;
}

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
constexpr Bitboard create_occupancy_from_mask(const std::size_t index, const Bitboard mask ) {
    if consteval {
        return create_occupation_from_mask_(index, mask);
    } else {
        return _pdep_u64(index, mask);
    }
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
constexpr void Bitloop(const Bitboard x, Fn f) {
    for(Bitboard y = x; y != 0; y = _blsr_u64(y)) {
        f(y);
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

inline std::string format_bitboard(Bitboard bitboard) {
    return std::format("0x{:x}, ", bitboard);
}


#endif //BITBOARD_H
