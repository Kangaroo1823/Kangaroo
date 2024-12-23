//
// Created by peter on 17/12/2024.
//

#include <fstream>
#include <iostream>

#include "attack_tables.h"

#include "gtest/gtest.h"


/******************************************************************************************
 * Slider attack tests
 *****************************************************************************************/


TEST(Attack_Tables_Generator, slider_attack_test) {
    constexpr Bitboard occupancy = set_bit(0ULL, Position::E7);
    constexpr auto position = Position::E4;

    constexpr auto mask = Constants::rook_attack_masks[std::to_underlying(position)];
    constexpr std::size_t hash_index = create_magic_hash_index<Slider::rook>(position, occupancy, Bitcount(mask));

    print_bitboard(Constants::rook_attack_table[hash_index]);

    ASSERT_TRUE(true);
}

/******************************************************************************************
 * king attack tests
 *****************************************************************************************/


Bitboard create_king_attacks_(const Position &position) {
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

TEST(Attack_Tables_Generator, king_attacks) {
    for (const Position &position: All_Positions) {
        // cppcheck-suppress unreadVariable
        const Bitboard attacks = create_king_attacks_(position);
        ASSERT_EQ(create_king_attacks_for(set_bit(0ULL, position)), attacks);
    }
}

/******************************************************************************************
 * Knight attack tests
 *****************************************************************************************/


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

TEST(Attack_Tables_Generator, knight_attacks) {
    for (const Position &position: All_Positions) {
        // cppcheck-suppress unreadVariable
        const Bitboard attacks = create_knight_attacks_(position);
        ASSERT_EQ(create_knight_attacks_for(set_bit(0ULL, position)), attacks);
    }
}

/******************************************************************************************
 * Pawn attack tests
 *****************************************************************************************/

Bitboard create_pawn_attacks_(const Color color, const Position position) {
    Bitboard attacks = 0ULL;

    const Bitboard bitboard = set_bit(0ULL, position);

    if (color == Color_t::white) {
        // color = white
        attacks = (bitboard >> 7 & not_a_file);
        attacks = attacks | (bitboard >> 9 & not_h_file);
    } else {
        // color = black
        attacks = (bitboard << 7 & not_h_file);
        attacks = attacks | (bitboard << 9 & not_a_file);
    }

    return attacks;
}

TEST(Attack_Tables_Generator, pawn_attacks) {
    for (const Position &position: All_Positions) {
        // cppcheck-suppress unreadVariable
        const Bitboard attacks = create_pawn_attacks_(Color::black, position);
        ASSERT_EQ(create_pawn_attacks_for<Color::black>(set_bit(0ULL, position)), attacks);
    }

    for (const Position &position: All_Positions) {
        // cppcheck-suppress unreadVariable
        const Bitboard attacks = create_pawn_attacks_(Color::white, position);
        ASSERT_EQ(create_pawn_attacks_for<Color::white>(set_bit(0ULL, position)), attacks);
    }
}

template<Color color>
Bitboard is_position_attacked_by_test_rig(const std::string_view &fen) {
    std::unique_ptr<Chess_Board> board = create_chess_board_from_fen(fen);

    Bitboard result = 0ULL;

    for (std::size_t rank = 0; rank < 8; ++rank) {
        for (std::size_t file = 0; file < 8; ++file) {
            const auto position = rank_file_to_position(7 - rank, file);

            if (const auto r = is_position_attacked_by<color>(position, board.get())) {
                result = set_bit(result, position);
            }
        }
    }

    return result;
}

TEST(Attack_Tables_Generator, is_position_attacked_by) {
    using enum Color;

    ASSERT_EQ(2621440, is_position_attacked_by_test_rig<white>("8/4p3/8/4P3/5q2/8/8/8 w - - 0 1 "));
    ASSERT_EQ(1157442769150545920, is_position_attacked_by_test_rig<white>("8/4p3/8/4R3/5q2/8/8/8 w - - 0 1 "));
    ASSERT_EQ(44272527353856, is_position_attacked_by_test_rig<white>("8/4p3/8/4N3/5q2/8/8/8 w - - 0 1 "));
    ASSERT_EQ(72625113839191170, is_position_attacked_by_test_rig<white>("8/4p3/8/4B3/5q2/8/8/8 w - - 0 1 "));
    ASSERT_EQ(1230067882989737090, is_position_attacked_by_test_rig<white>("8/4p3/8/4Q3/5q2/8/8/8 w - - 0 1 "));
    ASSERT_EQ(241192927232, is_position_attacked_by_test_rig<white>("8/4p3/8/4K3/5q2/8/8/8 w - - 0 1 "));

    ASSERT_EQ(171798691840, is_position_attacked_by_test_rig<black>("8/4P3/8/4p3/5Q2/8/8/8 w - - 0 1 "));
    ASSERT_EQ(1157442769150545920, is_position_attacked_by_test_rig<black>("8/4P3/8/4r3/5Q2/8/8/8 w - - 0 1 "));
    ASSERT_EQ(44272527353856, is_position_attacked_by_test_rig<black>("8/4P3/8/4n3/5Q2/8/8/8 w - - 0 1 "));
    ASSERT_EQ(72625113839191170, is_position_attacked_by_test_rig<black>("8/4P3/8/4b3/5Q2/8/8/8 w - - 0 1 "));
    ASSERT_EQ(1230067882989737090, is_position_attacked_by_test_rig<black>("8/4P3/8/4q3/5Q2/8/8/8 w - - 0 1 "));
    ASSERT_EQ(241192927232, is_position_attacked_by_test_rig<black>("8/4P3/8/4k3/5Q2/8/8/8 w - - 0 1 "));
}
