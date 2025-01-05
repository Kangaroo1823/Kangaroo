// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
//
// Created by peter on 17/12/2024.
//

#include <fstream>
#include <iostream>
#include <gtest/gtest.h>

#include "attack_tables.h"
#include "move_generator.h"



/******************************************************************************************
 * Slider attack tests
 *****************************************************************************************/


TEST(Attack_Tables_Generator, slider_attack_test) {
    constexpr Bitboard occupancy = set_bit(0ULL, Position::E7);
    constexpr auto position = Position::E4;

    constexpr Bitboard mask = Constants::rook_attack_masks[std::to_underlying(position)];
    const std::size_t hash_index = create_magic_hash_index<Slider::rook>(position, occupancy, Bitcount(mask));

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

    if (color == Color_t::black) {
        // color_p is equal to black
        attacks = (bitboard >> 7 & not_a_file);
        attacks = attacks | (bitboard >> 9 & not_h_file);
    } else {
        // color_p is equal to white
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
    const auto board = std::make_unique<Kangaroo::Chess_Board>(fen);;

    Kangaroo::print_chess_board(board.get());

    Bitboard result = 0ULL;

    for (std::size_t rank = 0; rank < 8; ++rank) {
        for (std::size_t file = 0; file < 8; ++file) {
            const auto position = rank_file_to_position(7 - rank, file);

            if (const auto r = is_position_attacked_by<color>(position, board.get())) {
                result = set_bit(result, position);
            }
        }
    }

    print_bitboard(result);

    return result;
}

TEST(Attack_Tables_Generator, is_position_attacked_by) {
    using enum Color;

    ASSERT_EQ(0x0000280000000000, is_position_attacked_by_test_rig<white>("8/4p3/5q2/4P3/8/8/8/8 w - - 0 1 "));
    ASSERT_EQ(0x001010ef10101010, is_position_attacked_by_test_rig<white>("8/4p3/8/4R3/5q2/8/8/8 w - - 0 1 "));
    ASSERT_EQ(0x0028440044280000, is_position_attacked_by_test_rig<white>("8/4p3/8/4N3/5q2/8/8/8 w - - 0 1 "));
    ASSERT_EQ(0x8244280028040201, is_position_attacked_by_test_rig<white>("8/4p3/8/4B3/5q2/8/8/8 w - - 0 1 "));
    ASSERT_EQ(0x825438ef38141211, is_position_attacked_by_test_rig<white>("8/4p3/8/4Q3/5q2/8/8/8 w - - 0 1 "));
    ASSERT_EQ(0x0000382838000000, is_position_attacked_by_test_rig<white>("8/4p3/8/4K3/5q2/8/8/8 w - - 0 1 "));

    ASSERT_EQ(0x0000000028000000, is_position_attacked_by_test_rig<black>("8/4P3/8/4p3/5Q2/8/8/8 w - - 0 1 "));
    ASSERT_EQ(0x001010ef10101010, is_position_attacked_by_test_rig<black>("8/4P3/8/4r3/5Q2/8/8/8 w - - 0 1 "));
    ASSERT_EQ(0x0028440044280000, is_position_attacked_by_test_rig<black>("8/4P3/8/4n3/5Q2/8/8/8 w - - 0 1 "));
    ASSERT_EQ(0x8244280028040201, is_position_attacked_by_test_rig<black>("8/4P3/8/4b3/5Q2/8/8/8 w - - 0 1 "));
    ASSERT_EQ(0x825438ef38141211, is_position_attacked_by_test_rig<black>("8/4P3/8/4q3/5Q2/8/8/8 w - - 0 1 "));
    ASSERT_EQ(0x0000382838000000, is_position_attacked_by_test_rig<black>("8/4P3/8/4k3/5Q2/8/8/8 w - - 0 1 "));
}
