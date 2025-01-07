// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com//
//
//
// Created by peter on 02/12/2024.
//


#include <cstdint>                      // for int64_t
#include "../include/bitboard.h"         // for set_bit, Bitcount, E4, Bitboard
#include "gtest/gtest.h"  // for AssertionHandler, operator""...



TEST(Bitboards, bitcount) {
    for (Bitboard i = 0; i < 64; i++) {
        ASSERT_EQ(Bitcount(1ULL << i), 1);
        ASSERT_EQ(Bitcount_(i), Bitcount(i));
    }
}


TEST(Bitboards, square_of) {
    for (unsigned int i = 0; i < 64; i++) {
        ASSERT_EQ(square_of_(1ULL << i), square_of(1ULL << i));
    }
}


TEST(Bitboards, set_bit) {
    // cppcheck-suppress unreadVariable
    Bitboard bitboard = 0ULL;
    // cppcheck-suppress knownConditionTrueFalse
    ASSERT_EQ(set_bit(bitboard, Square::A1), 1);

    // cppcheck-suppress knownConditionTrueFalse
    ASSERT_EQ(set_bit(bitboard, Square::H8), /*
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
    ASSERT_EQ(set_bit(bitboard, Square::E4), /*
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

    ASSERT_EQ(pop_bit(set_bit(0ULL, Square::E4), Square::E4), 0);
}
