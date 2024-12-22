//
// Created by peter on 02/12/2024.
//


#include <cstdint>                        // for int64_t
#include <array>                           // for array
#include <utility>                         // for to_underlying

#include "attack_masks.h"
#include "attack_tables.h"
#include "chess_board.h"
#include "colors.h"
#include "../include/bitboard.h"           // for Bitboard, Position, print_...
#include "catch2/catch_test_macros.hpp"    // for StringRef, AssertionHandler

Bitboard create_rook_attack_mask(Position position) {
    Bitboard mask = 0ULL;

    const auto rank = static_cast<int64_t>(std::to_underlying(position) >> 3);
    const auto file = static_cast<int64_t>(std::to_underlying(position) & 7);

    for (int64_t r = rank + 1; r < 7; ++r) mask |= 1ULL << (r * 8 + file);
    for (int64_t f = file + 1; f < 7; ++f) mask |= 1ULL << (rank * 8 + f);
    for (int64_t r = rank - 1; r > 0; --r) mask |= 1ULL << (r * 8 + file);
    for (int64_t f = file - 1; f > 0; --f) mask |= 1ULL << (rank * 8 + f);

    return mask;
}


Bitboard create_bishop_attack_mask(const Position position) {
    Bitboard mask = 0ULL;

    const auto rank = static_cast<int64_t>(std::to_underlying(position) >> 3);
    const auto file = static_cast<int64_t>(std::to_underlying(position) & 7);

    for (int64_t r = rank + 1, f = file + 1; r < 7 && f < 7; ++r, ++f) mask |= 1ULL << (r * 8 + f);
    for (int64_t r = rank + 1, f = file - 1; r < 7 && f > 0; ++r, --f) mask |= 1ULL << (r * 8 + f);
    for (int64_t r = rank - 1, f = file - 1; r > 0 && f > 0; --r, --f) mask |= 1ULL << (r * 8 + f);
    for (int64_t r = rank - 1, f = file + 1; r > 0 && f < 7; --r, ++f) mask |= 1ULL << (r * 8 + f);

    return mask;
}

TEST_CASE("Rooks Attack Masks", "[rook_attack_masks]") {

    // tests for rooks
    for (const Position &position : All_Positions) {
        const Bitboard board = create_rook_attack_mask(position);
        print_bitboard(board);

        REQUIRE(create_attack_mask_for<Slider::rook>(position) == board);
    }

    // tests for bishops
    for (const Position &position : All_Positions) {

        const Bitboard board = create_bishop_attack_mask(position);
        print_bitboard(board);
        REQUIRE(create_attack_mask_for<Slider_t::bishop>(position) == board);
    }
}





