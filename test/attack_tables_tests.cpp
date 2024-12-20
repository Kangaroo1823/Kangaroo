//
// Created by peter on 17/12/2024.
//

#include <fstream>
#include <iostream>

#include "attack_tables.h"

#include "catch2/catch_test_macros.hpp"



Bitboard create_king_attacks_(const Position& position) {
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
        const Bitboard attacks = create_king_attacks_(position);
        REQUIRE(create_king_attacks_for(position) == attacks);
    }
}


Bitboard create_knight_attacks_(Position position) {
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
        const Bitboard attacks = create_knight_attacks_(position);
        REQUIRE(create_knight_attacks_for(position) == attacks);
    }
}



Bitboard create_pawn_attacks_(const Color color, const Position position) {
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
    for (const Position &position: All_Positions) {
        // cppcheck-suppress unreadVariable
        const Bitboard attacks = create_pawn_attacks_(Color::black, position);
        REQUIRE(create_pawn_attacks_for<Color::black>(position) == attacks);
    }

    for (const Position &position: All_Positions) {
        // cppcheck-suppress unreadVariable
        const Bitboard attacks = create_pawn_attacks_(Color::white, position);
        REQUIRE(create_pawn_attacks_for<Color::white>(position) == attacks);
    }

}