//
// Created by peter on 02/12/2024.
//


#include "catch2/catch_test_macros.hpp"
#include "../include/bitboard.h"


/**
 *
 * @param bitboard
 * @return The number of set bits in bitboard
 */
inline int Bitcount_(Bitboard bitboard) {
    // initialize the count variable
    int count = 0;

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

TEST_CASE("Bitcount", "[bitcount]") {

    for (Bitboard i = 0; i < 64; i++) {
        REQUIRE(Bitcount(1ULL << i) == 1);
        REQUIRE(Bitcount_(i) == Bitcount(i));
    }
}

inline Bitboard get_ls1b_index_(Bitboard bitboard) {
    // check if bitboard has bits set. Otherwise, return -1.
    if (bitboard == 0) return -1;

    // count the bits before the first 1 bit.
    return Bitcount((bitboard & -bitboard) -1);
}


TEST_CASE("SquareOf", "[SquareOf]") {
    for (unsigned int i = 0; i < 64; i++) {
        REQUIRE(get_ls1b_index_(1ULL << i) == SquareOf(1ULL << i));
    }
}


TEST_CASE("Set/Get/Pop Bit", "[set_bit]") {
    Bitboard bitboard = 0ULL;
    REQUIRE(set_bit(bitboard, A1) == 1);
    REQUIRE(set_bit(bitboard, H8) == /*
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

    REQUIRE(set_bit(bitboard, E4) == /*
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

    REQUIRE(pop_bit(set_bit(0ULL, E4), E4) == 0);
}

TEST_CASE("Constants", "[constants]") {
    REQUIRE(not_a_file == /*
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
        18374403900871474942ULL);

    REQUIRE(not_ab_file == /*
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
        18229723555195321596ULL);

    REQUIRE(not_h_file == /*
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
        9187201950435737471ULL);

    REQUIRE(not_gh_file == /*
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
        4557430888798830399ULL);
}
