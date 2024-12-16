//
// Created by peter on 02/12/2024.
//


#include <array>                         // for array
#include <utility>                       // for to_underlying
#include "../include/bitboard.h"         // for Bitboard, Position, not_a_file
#include "../include/knight_attacks.h"   // for knight_attacks
#include "catch2/catch_test_macros.hpp"  // for StringRef, AssertionHandler

Bitboard create_knight_attacks(Position position) {
    Bitboard attacks = 0ULL;
    Bitboard bitboard = set_bit(0ULL, position);

    // generate knight attacks
    attacks |= bitboard >> 17 & not_h_file;
    attacks |= bitboard >> 15 & not_a_file;
    attacks |= bitboard >> 6 & not_ab_file;
    attacks |= bitboard >> 10 & not_gh_file;

    attacks |= bitboard << 17 & not_a_file;
    attacks |= bitboard << 15 & not_h_file;
    attacks |= bitboard << 6 & not_gh_file;
    attacks |= bitboard << 10 & not_ab_file;
    return attacks;
}

TEST_CASE("Knight Attacks", "[knight_attacks]") {
    for (const Position &position : All_Positions) {
        // cppcheck-suppress unreadVariable
        const Bitboard attacks = create_knight_attacks(position);
        REQUIRE(Constants::knight_attacks[std::to_underlying(position)] == attacks);
    }
}

