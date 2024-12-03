//
// Created by peter on 02/12/2024.
//


#include "catch2/catch_test_macros.hpp"

#include "../include/bitboard.h"
#include "../include/rook_attack_masks.h"

Bitboard create_rook_attack_mask(Position position) {
    Bitboard attacks = 0ULL;

    const int rank = position >> 3;
    const int file = position & 7;

    for (int r = rank + 1; r < 7; ++r) attacks |= 1ULL << r * 8 + file;
    for (int f = file + 1; f < 7; ++f) attacks |= 1ULL << rank * 8 + f;
    for (int r = rank - 1; r > 0; --r) attacks |= 1ULL << r * 8 + file;
    for (int f = file - 1; f > 0; --f) attacks |= 1ULL << rank * 8 + f;

    return attacks;
}

TEST_CASE("Rooks Attack Masks", "[rook_attack_masks]") {

    for (Position position : All_Positions) {
        const Bitboard board = create_rook_attack_mask(position);
        REQUIRE(Constants::rook_attack_masks[position] == board);
    }

}