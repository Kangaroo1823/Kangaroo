//
// Created by peter on 02/12/2024.
//


#include "catch2/catch_test_macros.hpp"

#include "../include/bitboard.h"
#include "../include/create_possible_rook_moves.h"

TEST_CASE("Create Possible Rook Moves", "[create_possible_rook_moves]") {

    Position position = E4;
    Bitboard mask = 0ULL;

    mask = set_bit(mask, B4);
    mask = set_bit(mask, G4);
    mask = set_bit(mask, E2);
    mask = set_bit(mask, E7);

    Bitboard board = create_possible_rook_moves(mask, position);

    REQUIRE( board ==
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
