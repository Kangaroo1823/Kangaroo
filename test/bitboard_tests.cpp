//
// Created by peter on 02/12/2024.
//


#include <cstdint>                      // for int64_t
#include "../include/bitboard.h"         // for set_bit, Bitcount, E4, Bitboard
#include "catch2/catch_test_macros.hpp"  // for AssertionHandler, operator""...

/**
 *
 * @param bitboard
 * @return The number of set bits in bitboard
 */
inline int64_t Bitcount_(Bitboard bitboard) {
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

TEST_CASE("Bit", "[bit]") {
    for (Bitboard i = 0; i < 64; i++) {
        REQUIRE(Bitcount(1ULL << i) == 1);
        REQUIRE(Bitcount_(i) == Bitcount(i));
    }
}

inline Bitboard get_ls1b_index_(const Bitboard bitboard) {
    // count the bits before the first 1 bit.
    const auto b = static_cast<Bitboard>(-static_cast<int64_t>(bitboard));
    return static_cast<Bitboard>(Bitcount((bitboard & b) - 1));
}


TEST_CASE("SquareOf", "[SquareOf]") {
    for (unsigned int i = 0; i < 64; i++) {
        REQUIRE(get_ls1b_index_(1ULL << i) == SquareOf(1ULL << i));
    }
}


TEST_CASE("Set/Get/Pop Bit", "[set_bit]") {
    // cppcheck-suppress unreadVariable
    Bitboard bitboard = 0ULL;
    // cppcheck-suppress knownConditionTrueFalse
    REQUIRE(set_bit(bitboard, Position::A1) == 1);

    // cppcheck-suppress knownConditionTrueFalse
    REQUIRE(set_bit(bitboard, Position::H8) == /*
        A  B  C  D  E  F  G  H
    1   0  0  0  0  0  0  0  0
    2   0  0  0  0  0  0  0  0
    3   0  0  0  0  0  0  0  0
    4   0  0  0  0  0  0  0  0
    5   0  0  0  0  0  0  0  0
    6   0  0  0  0  0  0  0  0
    7   0  0  0  0  0  0  0  0
    8   0  0  0  0  0  0  0  1

       bitboard as 64 bit integer: */
        9223372036854775808ULL);

    // cppcheck-suppress knownConditionTrueFalse
    REQUIRE(set_bit(bitboard, Position::E4) == /*
        A  B  C  D  E  F  G  H
    1   0  0  0  0  0  0  0  0
    2   0  0  0  0  0  0  0  0
    3   0  0  0  0  0  0  0  0
    4   0  0  0  0  1  0  0  0
    5   0  0  0  0  0  0  0  0
    6   0  0  0  0  0  0  0  0
    7   0  0  0  0  0  0  0  0
    8   0  0  0  0  0  0  0  0

       bitboard as 64 bit integer: */
        268435456ULL);

    REQUIRE(pop_bit(set_bit(0ULL, Position::E4), Position::E4) == 0);
}
