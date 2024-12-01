#include <catch2/catch_test_macros.hpp>

#include "../src/Bitboard.h"
#include "../src/colors.h"
#include "../src/pawn_attacks.h"
#include "../src/king_attacks.h"
#include "../src/knight_attacks.h"
#include "catch2/internal/catch_compiler_capabilities.hpp"
#include "catch2/internal/catch_test_registry.hpp"

TEST_CASE("set_bit", "[set_bit]")
 {
    Bitboard bitboard = 0ULL;
    REQUIRE( set_bit(bitboard, A1) == 1 );
    REQUIRE( set_bit(bitboard, H8) == /*
        A  B  C  D  E  F  G  H
    1   0  0  0  0  0  0  0  0
    2   0  0  0  0  0  0  0  0
    3   0  0  0  0  0  0  0  0
    4   0  0  0  0  0  0  0  0
    5   0  0  0  0  0  0  0  0
    6   0  0  0  0  0  0  0  0
    7   0  0  0  0  0  0  0  0
    8   0  0  0  0  0  0  0  1

       bitboard as 64 bit integer: */
       9223372036854775808ULL );

    REQUIRE( set_bit(bitboard, E4) == /*
        A  B  C  D  E  F  G  H
    1   0  0  0  0  0  0  0  0
    2   0  0  0  0  0  0  0  0
    3   0  0  0  0  0  0  0  0
    4   0  0  0  0  1  0  0  0
    5   0  0  0  0  0  0  0  0
    6   0  0  0  0  0  0  0  0
    7   0  0  0  0  0  0  0  0
    8   0  0  0  0  0  0  0  0

       bitboard as 64 bit integer: */
       268435456ULL );

}

TEST_CASE("Constants", "[constants]") {
    REQUIRE( not_a_file == /*
        A  B  C  D  E  F  G  H
    1   0  1  1  1  1  1  1  1
    2   0  1  1  1  1  1  1  1
    3   0  1  1  1  1  1  1  1
    4   0  1  1  1  1  1  1  1
    5   0  1  1  1  1  1  1  1
    6   0  1  1  1  1  1  1  1
    7   0  1  1  1  1  1  1  1
    8   0  1  1  1  1  1  1  1

       bitboard as 64 bit integer: */
       18374403900871474942ULL );

    REQUIRE( not_ab_file == /*
        A  B  C  D  E  F  G  H
    1   0  0  1  1  1  1  1  1
    2   0  0  1  1  1  1  1  1
    3   0  0  1  1  1  1  1  1
    4   0  0  1  1  1  1  1  1
    5   0  0  1  1  1  1  1  1
    6   0  0  1  1  1  1  1  1
    7   0  0  1  1  1  1  1  1
    8   0  0  1  1  1  1  1  1

       bitboard as 64 bit integer: */
       18229723555195321596ULL );

    REQUIRE( not_h_file == /*
        A  B  C  D  E  F  G  H
    1   1  1  1  1  1  1  1  0
    2   1  1  1  1  1  1  1  0
    3   1  1  1  1  1  1  1  0
    4   1  1  1  1  1  1  1  0
    5   1  1  1  1  1  1  1  0
    6   1  1  1  1  1  1  1  0
    7   1  1  1  1  1  1  1  0
    8   1  1  1  1  1  1  1  0

       bitboard as 64 bit integer: */
       9187201950435737471ULL );

    REQUIRE( not_gh_file == /*
        A  B  C  D  E  F  G  H
    1   1  1  1  1  1  1  0  0
    2   1  1  1  1  1  1  0  0
    3   1  1  1  1  1  1  0  0
    4   1  1  1  1  1  1  0  0
    5   1  1  1  1  1  1  0  0
    6   1  1  1  1  1  1  0  0
    7   1  1  1  1  1  1  0  0
    8   1  1  1  1  1  1  0  0

       bitboard as 64 bit integer: */
       4557430888798830399ULL );

}

Bitboard create_pawn_attacks(unsigned int color, const Position position) {

    Bitboard attacks = 0ULL;

    Bitboard bitboard = set_bit(0ULL, position);

    if (color == white) {
        // color = white
        attacks = attacks | bitboard >> 7 & not_a_file;
        attacks = attacks | bitboard >> 9 & not_h_file;
    } else {
        // color = black
        attacks = attacks | bitboard << 7 & not_h_file;
        attacks = attacks | bitboard << 9 & not_a_file;
    }

    return attacks;
}

TEST_CASE("pawn_attacks", "[pawn_attacks]") {

    for (const Color color : All_Colors) {
        for (const Position position : All_Positions) {
            const Bitboard attacks = create_pawn_attacks(color, position);
            REQUIRE(pawn_attacks[color][position] == attacks);
        }
    }

}


Bitboard create_king_attacks(const Position& position) {
    Bitboard attacks = 0ULL;

    Bitboard bitboard = set_bit(attacks, position);

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

TEST_CASE("king_attacks", "[king_attacks]") {
    for (Position position : All_Positions) {
        const Bitboard attacks = create_king_attacks(position);
        REQUIRE(king_attacks[position] == attacks);
    }
}


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
    for (Position position : All_Positions) {
        const Bitboard attacks = create_knight_attacks(position);
        REQUIRE(knight_attacks[position] == attacks);
    }
}
