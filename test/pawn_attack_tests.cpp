//
// Created by peter on 02/12/2024.
//


#include <array>                         // for array
#include <utility>                       // for to_underlying
#include "../include/bitboard.h"         // for Bitboard, Position, not_a_file
#include "../include/colors.h"           // for All_Colors, Color, black
#include "../include/pawn_attacks.h"     // for Pawn_Attacks
#include "catch2/catch_test_macros.hpp"  // for StringRef, AssertionHandler

Bitboard create_pawn_attacks(const Color color, const Position position) {

    Bitboard attacks = 0ULL;

    const Bitboard bitboard = set_bit(0ULL, position);

    if (color == Color_t::black) {
        // color = black
        attacks = (bitboard >> 7 & not_a_file);
        attacks = attacks | (bitboard >> 9 & not_h_file);
    } else {
        // color = white
        attacks = (bitboard << 7 & not_h_file);
        attacks = attacks | (bitboard << 9 & not_a_file);
    }

    return attacks;
}

TEST_CASE("Pawn Attacks", "[Pawn_Attacks]") {

    for (const auto &color : All_Colors) {
        for (const Position &position : All_Positions) {
            // cppcheck-suppress unreadVariable
            const Bitboard attacks = create_pawn_attacks(color, position);
            REQUIRE(Constants::Pawn_Attacks[std::to_underlying(color)][std::to_underlying(position)] == attacks);
        }
    }

}