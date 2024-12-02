//
// Created by peter on 02/12/2024.
//


#include "catch2/catch_test_macros.hpp"

#include "../include/bitboard.h"
#include "../include/bishop_attack_masks.h"

Bitboard create_bishop_attack_mask(Position position) {
    Bitboard attacks = 0ULL;

    const int rank = position >> 3;
    const int file = position & 7;

    int r, f;
    for (r = rank + 1, f = file + 1; r < 7 && f < 7; ++r, ++f) attacks |= 1ULL << r * 8 + f;
    for (r = rank + 1, f = file - 1; r < 7 && f > 0; ++r, --f) attacks |= 1ULL << r * 8 + f;
    for (r = rank - 1, f = file - 1; r > 0 && f > 0; --r, --f) attacks |= 1ULL << r * 8 + f;
    for (r = rank - 1, f = file + 1; r > 0 && f < 7; --r, ++f) attacks |= 1ULL << r * 8 + f;

    return attacks;
}

TEST_CASE("Bishops attack masks", "[bishop_attack_mask]") {
    for (Position position : All_Positions) {
        const Bitboard board = create_bishop_attack_mask(position);
        REQUIRE(bishop_attack_masks[position] == board);
    }
}
