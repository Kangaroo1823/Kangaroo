#include <catch2/catch_test_macros.hpp>
#include <catch2/internal/catch_preprocessor_internal_stringify.hpp>

#include "../src/bishop_attack_masks.h"
#include "../src/bitboard.h"
#include "../src/colors.h"
#include "../src/pawn_attacks.h"
#include "../src/king_attacks.h"
#include "../src/knight_attacks.h"
#include "../src/queen_attack_masks.h"
#include "../src/rook_attack_masks.h"
#include "catch2/internal/catch_assertion_handler.hpp"
#include "catch2/internal/catch_compiler_capabilities.hpp"
#include "catch2/internal/catch_decomposer.hpp"
#include "catch2/internal/catch_result_type.hpp"
#include "catch2/internal/catch_test_macro_impl.hpp"
#include "catch2/internal/catch_test_registry.hpp"






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

TEST_CASE("King Attacks", "[king_attacks]") {
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
        REQUIRE(rook_attack_masks[position] == board);
    }

}


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


TEST_CASE("Queen Attack Masks", "[queen_attack_masks]") {
    for (Position position : All_Positions) {
        const Bitboard board = create_queen_attack_mask(position);
        REQUIRE(queen_attack_masks[position] == board);
    }
}