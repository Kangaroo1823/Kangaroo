//
// Created by peter on 02/12/2024.
//

#include "catch2/catch_test_macros.hpp"

#include "../include/bitboard.h"
#include "../include/king_attacks.h"

Bitboard create_king_attacks(const Position& position) {
    Bitboard attacks = 0ULL;

    const Bitboard bitboard = set_bit(attacks, position);

    attacks |= bitboard << 1 & not_a_file;
    attacks |= bitboard << 9 & not_a_file;
    attacks |= bitboard << 8;
    attacks |= bitboard << 7 & not_h_file;

    attacks |= bitboard >> 1 & not_h_file;
    attacks |= bitboard >> 9 & not_h_file;
    attacks |= bitboard >> 8;
    attacks |= bitboard >> 7 & not_a_file;

    return attacks;
}

TEST_CASE("King Attacks", "[king_attacks]") {
    for (Position position : All_Positions) {
        const Bitboard attacks = create_king_attacks(position);
        REQUIRE(king_attacks[position] == attacks);
    }
}
