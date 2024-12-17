//
// Created by peter on 02/12/2024.
//


#include "catch2/catch_test_macros.hpp"

#include "../include/bitboard.h"
#include "../include/colors.h"
#include "../include/pawn_attacks.h"

extern "C" Bitboard create_pawn_attacks(unsigned int color, const Position position) {

    Bitboard attacks = 0ULL;

    const Bitboard bitboard = set_bit(0ULL, position);

    if (color == black) {
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

    for (const Color color : All_Colors) {
        for (const Position position : All_Positions) {
            const Bitboard attacks = create_pawn_attacks(color, position);
            REQUIRE(Constants::Pawn_Attacks[color][position] == attacks);
        }
    }

}