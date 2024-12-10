//
// Created by peter on 01/12/2024.
//

#ifndef BITBOARD_H
#define BITBOARD_H

#include <array>
#include <string>
#include <immintrin.h>

#include "base.h"

/** define a 'Bitboard' to be a 64 bit unsigned integer
 */
typedef unsigned long long Bitboard;

/**
 * Have a convenient way of naming positions
 */
typedef enum {
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
} Position;

constexpr std::array<Position, 64> All_Positions = {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8
};

inline Position rank_file_to_position(const unsigned int rank, const unsigned int file) {
    return All_Positions[rank * 8 + file];
}

inline Bitboard set_bit(const Bitboard bitboard, const Position position) {
    return bitboard | (1ULL << position);
}

inline Bitboard get_bit(const Bitboard bitboard, const Position position) {
    return bitboard & (1ULL << position);
}

inline Bitboard pop_bit(const Bitboard bitboard, const Position position) {
    return bitboard & ~(1ULL << position);
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
#define SquareOf(bitboard) _tzcnt_u64(bitboard)

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
#define ExtractMask(bitboard,mask) _pext_u64(bitboard,mask)


/**
 * Iterates over each set bit in a bitboard.
 *
 * @param x The Bitboard to iterate over. For each set bit there will be one iteration over the
 *          following block of commands. Then the bit will be erased, and it will be checked if
 *          there are set bits remaining. If the answer is 'yes' the block will get executed again ...
 *          and so on.
 */
#define Bitloop(x) for(;x;x=_blsr_u64(x))


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
