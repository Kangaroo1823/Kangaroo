//
// Created by peter on 02/12/2024.
//

#include <array>                         // for array
#include "../include/bitboard.h"         // for Bitboard, not_a_file, not_h_...
#include "../include/king_attacks.h"     // for king_attacks
#include "catch2/catch_test_macros.hpp"  // for StringRef, AssertionHandler

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
    for (const Position &position : All_Positions) {
        // cppcheck-suppress unreadVariable
        const Bitboard attacks = create_king_attacks(position);
        REQUIRE(Constants::king_attacks[std::to_underlying(position)] == attacks);
    }
}
