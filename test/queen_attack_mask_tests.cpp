//
// Created by peter on 02/12/2024.
//


#include "catch2/catch_test_macros.hpp"

#include "../include/bitboard.h"
#include "../include/queen_attack_masks.h"

Bitboard create_queen_attack_mask(Position position) {
    Bitboard attacks = 0ULL;

    const int rank = position >> 3;
    const int file = position & 7;

    int r, f;
    for (r = rank + 1, f = file + 1; r < 7 && f < 7; ++r, ++f) attacks |= 1ULL << r * 8 + f;
    for (r = rank + 1, f = file - 1; r < 7 && f > 0; ++r, --f) attacks |= 1ULL << r * 8 + f;
    for (r = rank - 1, f = file - 1; r > 0 && f > 0; --r, --f) attacks |= 1ULL << r * 8 + f;
    for (r = rank - 1, f = file + 1; r > 0 && f < 7; --r, ++f) attacks |= 1ULL << r * 8 + f;

    for (r = rank + 1; r < 7; ++r) attacks |= 1ULL << r * 8 + file;
    for (f = file + 1; f < 7; ++f) attacks |= 1ULL << rank * 8 + f;
    for (r = rank - 1; r > 0; --r) attacks |= 1ULL << r * 8 + file;
    for (f = file - 1; f > 0; --f) attacks |= 1ULL << rank * 8 + f;

    return attacks;
}


TEST_CASE("Queen Attack Masks", "[Queen_Attack_Masks]") {
    for (Position position : All_Positions) {
        const Bitboard board = create_queen_attack_mask(position);
        REQUIRE(Constants::Queen_Attack_Masks[position] == board);
    }
}