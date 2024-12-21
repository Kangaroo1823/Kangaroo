//
// Created by peter on 17/12/2024.
//

#ifndef ATTACK_TABLES_H
#define ATTACK_TABLES_H

#include <array>
#include <iostream>

#include "bitboard.h"
#include "chess_board.h"
#include "magic_numbers.h"
#include "colors.h"

/**********************************************************************************
 * Slider attacks
 *********************************************************************************/


template<Slider slider>
constexpr std::size_t create_hash_index(const Position &position, const Bitboard &occupancy,
                                        const int64_t &relevant_bits) {
    if constexpr (slider == Slider::bishop) {
        return occupancy * Constants::Bishop_Magic_Numbers[std::to_underlying(position)] >> (64 - relevant_bits);
    } else {
        return occupancy * Constants::Rook_Magic_Numbers[std::to_underlying(position)] >> (64 - relevant_bits);
    }
}


template<Slider slider>
constexpr std::size_t create_magic_hash_index(const Position &position, const Bitboard &occupancy) {
    const std::size_t offset = (slider == Slider::bishop ? 512 : 4096) * std::to_underlying(position);

    const size_t mask = slider == Slider::bishop
                            ? Constants::bishop_attack_masks[std::to_underlying(position)]
                            : Constants::rook_attack_masks[std::to_underlying(position)];

    const int64_t relevant_bits = Bitcount(mask);

    return offset + create_hash_index<slider>(position, occupancy, relevant_bits);
}


template<Slider slider>
/**
 * Computes the attack mask for a sliding piece (rook or bishop) based on its position
 * on the board. The function determines if the slider is a bishop or rook and retrieves
 * the corresponding attack mask from the predefined constants.
 *
 * @param position The position of the sliding piece on the chess board (e.g., A1, B2, etc.).
 * @return The attack mask represented as a Bitboard, defining all possible attack moves
 *         from the given position for the respective slider.
 */
constexpr Bitboard get_attack_mask_for_slider(const Position &position) {
    return slider == Slider::bishop
               ? Constants::bishop_attack_masks[std::to_underlying(position)]
               : Constants::rook_attack_masks[std::to_underlying(position)];
}

template<Slider slider>
constexpr std::array<Bitboard, slider == Slider::bishop ? 512 : 4096>
create_attack_table_for(const Position &position) {
    const Bitboard mask = get_attack_mask_for_slider<slider>(position);

    const int64_t relevant_bits = Bitcount(mask);
    const std::size_t number_of_masks = 1UL << relevant_bits;

    std::array<Bitboard, slider == Slider::bishop ? 512 : 4096> attack_table = {0};

    for (std::size_t index = 0; index < number_of_masks; ++index) {
        const Bitboard occupancy = create_occupancy_from_mask(index, mask);
        const Bitboard attack = create_possible_slider_moves<slider>(occupancy, position);
        auto hashed_index = create_hash_index<slider>(position, occupancy, relevant_bits);

        attack_table[hashed_index] = attack;
    }

    return attack_table;
}


template<Slider slider>
/**
 * Generates and initializes an attack table containing all possible attack patterns
 * for sliding pieces (rooks and bishops) across the chessboard. This function precomputes
 * attack masks for each position and stores them for quick lookup during gameplay.
 *
 * The attack table is a crucial data structure used to optimize move generation for sliding
 * pieces by avoiding recalculating attack patterns repeatedly.
 *
 * @return A data structure representing the precomputed attack patterns for all positions
 *         on the board for sliding pieces.
 */
constexpr std::array<Bitboard, slider == Slider::bishop ? 64 * 512 : 64 * 4096>
create_attack_table() {
    std::array<Bitboard, slider == Slider::bishop ? 64 * 512 : 64 * 4096> result = {0};

    auto iter = result.begin();
    for (const auto &position: All_Positions) {
        auto r = create_attack_table_for<slider>(position);
        std::ranges::copy(r, iter);
        iter += r.size();
    }

    return result;
}

namespace Constants {
    inline constexpr std::array<Bitboard, 64 * 4096> rook_attack_table =
            as_constant(create_attack_table<Slider::rook>());
    inline constexpr std::array<Bitboard, 64 * 512> bishop_attack_table =
            as_constant(create_attack_table<Slider::bishop>());
}


/**********************************************************************************
 * Pawn attacks
 *********************************************************************************/

template<Color color>
constexpr Bitboard create_pawn_attacks_for(const Bitboard bitboard) {
    Bitboard attacks = 0ULL;

    if constexpr (color == Color_t::white) {
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


template<Color color>
constexpr std::array<Bitboard, 64> create_pawn_attacks() {
    std::array<Bitboard, 64> attacks = {};
    for (auto iter = attacks.begin(); const auto &position: All_Positions) {
        *iter = create_pawn_attacks_for<color>(set_bit(0ULL, position));
        iter++;
    }
    return attacks;
}

namespace Constants {
    inline constexpr std::array<Bitboard, 64> white_pawn_attacks = as_constant(create_pawn_attacks<Color::white>());
    inline constexpr std::array<Bitboard, 64> black_pawn_attacks = as_constant(create_pawn_attacks<Color::black>());
}


/**********************************************************************************
 * King attacks
 *********************************************************************************/

constexpr Bitboard create_king_attacks_for(const Bitboard bitboard) {
    Bitboard attacks = 0ULL;

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


constexpr std::array<Bitboard, 64> create_king_attacks() {
    std::array<Bitboard, 64> attacks = {};
    for (auto iter = attacks.begin(); const auto &position: All_Positions) {
        *iter = create_king_attacks_for(set_bit(0ULL, position));
        ++iter;
    }
    return attacks;
}

namespace Constants {
    inline constexpr std::array<Bitboard, 64> king_attacks = as_constant(create_king_attacks());
}

/**********************************************************************************
 * Knight attacks
 *********************************************************************************/


constexpr Bitboard create_knight_attacks_for(const Bitboard bitboard) {
    Bitboard attacks = 0ULL;

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

constexpr std::array<Bitboard, 64> create_knight_attacks() {
    std::array<Bitboard, 64> attacks = {};
    for (auto iter = attacks.begin(); const auto &position: All_Positions) {
        *iter = create_knight_attacks_for(set_bit(0ULL, position));
        ++iter;
    }
    return attacks;
}

namespace Constants {
    inline constexpr std::array<Bitboard, 64> knight_attacks = as_constant(create_knight_attacks());
}


template<Slider slider>
constexpr Bitboard get_attacks_for(const Bitboard occupancy, const Bitboard piece_positions) {
    Bitboard result = 0ULL;

    Bitloop(piece_positions, [&](Bitboard p) {
        auto position = All_Positions[square_of(p)];

        const Bitboard mask = slider == Slider::rook
                                  ? Constants::rook_attack_masks[std::to_underlying(position)]
                                  : Constants::bishop_attack_masks[std::to_underlying(position)];

        const Bitboard masked_occupancy = occupancy & mask;

        const size_t hash_index = create_magic_hash_index<slider>(position, masked_occupancy);

        const Bitboard hash_result = slider == Slider::rook
                      ? Constants::rook_attack_table[hash_index]
                      : Constants::bishop_attack_table[hash_index];

        result |= hash_result;
    });

    return result;
}


template<Color color>
constexpr bool is_square_attacked_by(const Position &position, const Chess_Board *board) {

    using enum Color_t;

    const Bitboard square = set_bit(0ULL, position);

    // check for pawns to attack the given position
    const Bitboard pawn_attacks = create_pawn_attacks_for<color == white ? white : black>(
        color == white ? board->white_pawns : board->black_pawns
    );
    Bitboard attacks = pawn_attacks;

    // check whether the king attacks the given position
    const Bitboard king_attacks = create_king_attacks_for(color == white ? board->white_king : board->black_king);
    attacks |= king_attacks;

    // check whether a knight attacks the given position.
    const Bitboard knight_attacks = create_knight_attacks_for(color == white
                                                            ? board->white_knights
                                                            : board->black_knights);
    attacks |= knight_attacks;

    const Bitboard rook_attacks = get_attacks_for<Slider::rook>(board->all_pieces,
                                                                color == white
                                                                    ? board->white_rooks
                                                                    : board->black_rooks);
    attacks |= rook_attacks;

    const Bitboard bishop_attacks = get_attacks_for<Slider::bishop>(board->all_pieces,
                                                              color == white
                                                                  ? board->white_bishops
                                                                  : board->black_bishops);
    attacks |= bishop_attacks;

    Bitboard queen_attacks = get_attacks_for<Slider_t::bishop>(board->all_pieces,
                                                               color == white
                                                                   ? board->white_queens
                                                                   : board->black_queens);
    queen_attacks |= get_attacks_for<Slider_t::rook>(board->all_pieces,
                                                     color == white ? board->white_queens : board->black_queens);
    attacks |= queen_attacks;

    return (square & attacks) ? true : false;
}


#endif //ATTACK_TABLES_H
