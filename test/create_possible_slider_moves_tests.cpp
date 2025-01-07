// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by peter on 02/12/2024.
//

#include "../include/bitboard.h"
#include "../tools/create_possible_slider_moves.h"
#include "gtest/gtest.h"

TEST(Move_Generator, create_possible_bishop_moves) {
    using enum Square_t;
    constexpr auto position = E4;
    Bitboard mask = 0ULL;

    mask = set_bit(mask, B7);
    mask = set_bit(mask, G6);
    mask = set_bit(mask, F3);
    mask = set_bit(mask, C2);

    // cppcheck-suppress unreadVariable
    const Bitboard board = create_possible_slider_moves<Slider::bishop>(mask, position);

    ASSERT_EQ(board, /*
    8   0  0  0  0  0  0  0  0
    7   0  1  0  0  0  0  0  0
    6   0  0  1  0  0  0  1  0
    5   0  0  0  1  0  1  0  0
    4   0  0  0  0  0  0  0  0
    3   0  0  0  1  0  1  0  0
    2   0  0  1  0  0  0  0  0
    1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

       bitboard as 64 bit integer: */
       637888545424384ULL );

}


TEST(Move_Generator, create_possible_rook_moves) {
    using enum Square_t;
    constexpr auto position = E4;
    Bitboard mask = 0ULL;

    mask = set_bit(mask, B4);
    mask = set_bit(mask, G4);
    mask = set_bit(mask, E2);
    mask = set_bit(mask, E7);

    // cppcheck-suppress unreadVariable
    const Bitboard board = create_possible_slider_moves<Slider::rook>(mask, position);

    ASSERT_EQ( board,
/*
 8   0  0  0  0  0  0  0  0
 7   0  0  0  0  1  0  0  0
 6   0  0  0  0  1  0  0  0
 5   0  0  0  0  1  0  0  0
 4   0  1  1  1  0  1  1  0
 3   0  0  0  0  1  0  0  0
 2   0  0  0  0  1  0  0  0
 1   0  0  0  0  0  0  0  0
     A  B  C  D  E  F  G  H

    bitboard as 64 bit integer: */
    4521262379438080ULL );

}
