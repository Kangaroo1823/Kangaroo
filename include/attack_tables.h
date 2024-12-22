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
constexpr std::size_t create_magic_hash_index(const Position &position, const Bitboard &occupancy,
                                              int64_t relevant_bits) {
    const std::size_t offset = (slider == Slider::bishop ? 512 : 4096) * std::to_underlying(position);

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
        // color =black
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
constexpr Bitboard get_attacks_for_position(const Position &position, const Bitboard occupancy) {
    // retrieve the mask for the given piece type and position
    const Bitboard mask = slider == Slider::rook
                              ? Constants::rook_attack_masks[std::to_underlying(position)]
                              : Constants::bishop_attack_masks[std::to_underlying(position)];

    // mask the occupancy to retrieve the relevant data for the computation of the magic hashes.
    const Bitboard masked_occupancy = occupancy & mask;

    // compute the magic hash index for the given piece type and position.
    const size_t hash_index = create_magic_hash_index<slider>(position, masked_occupancy, Bitcount(mask));

    // and retrieve the attacked squares.
    const Bitboard hash_result = slider == Slider::rook
                                     ? Constants::rook_attack_table[hash_index]
                                     : Constants::bishop_attack_table[hash_index];

    return hash_result;
}

template<Slider slider>
constexpr Bitboard get_attacks_for(const Bitboard occupancy, const Bitboard piece_positions) {
    // declare variable to hold the result
    Bitboard result = 0ULL;

    // loop over all set bits
    Bitloop(piece_positions, [&result, &occupancy](Bitboard p) {
        // this is the inner part of the loop. It is being called for each set bit with |p| having its
        // lowest set bit equal to the bit for which the interation was called.

        // compute the position corresponding to the lowest set bit in p; i.e, the position of the chess piece
        // in question.
        auto position = All_Positions[square_of(p)];

        // add the attacked squares (=bits set to 1 (one)) to the result.
        result |= get_attacks_for_position<slider>(position, occupancy);
    });

    return result;
}

template<Color color>
/**
 * @brief Determines all the squares being attacked by a specific color.
 *
 * This function calculates the potential attack pattern for the given piece while
 * taking the board's configuration into account.
 *
 * @param board A representation of the chess board, used to evaluate obstructed or
 *              valid attack paths.
 * @return A Bitboard representing all the squares that the specified piece can attack
 *         from its given position.
 */
constexpr Bitboard attacked_squares_by(const Chess_Board *board) {
    using enum Color_t;

    // create attack mask for pawns
    const Bitboard pawn_attacks = create_pawn_attacks_for<color == white ? white : black>(
        color == white ? board->white_pawns : board->black_pawns
    );

    // create the attack mask for kings
    const Bitboard king_attacks = create_king_attacks_for(color == white ? board->white_king : board->black_king);

    // ... for knights
    const Bitboard knight_attacks = create_knight_attacks_for(color == white
                                                                  ? board->white_knights
                                                                  : board->black_knights);

    // ... for rooks
    const Bitboard rook_attacks = get_attacks_for<Slider::rook>(board->all_pieces,
                                                                color == white
                                                                    ? board->white_rooks
                                                                    : board->black_rooks);

    // ... for bishops
    const Bitboard bishop_attacks = get_attacks_for<Slider::bishop>(board->all_pieces,
                                                                    color == white
                                                                        ? board->white_bishops
                                                                        : board->black_bishops);

    // ... and for queens
    Bitboard queen_attacks = get_attacks_for<Slider_t::bishop>(board->all_pieces,
                                                               color == white
                                                                   ? board->white_queens
                                                                   : board->black_queens);
    queen_attacks |= get_attacks_for<Slider_t::rook>(board->all_pieces,
                                                     color == white ? board->white_queens : board->black_queens);

    const Bitboard attacks = pawn_attacks | knight_attacks | rook_attacks | bishop_attacks | king_attacks |
                             queen_attacks;

    return attacks;
}

template<Color color>
constexpr Bitboard is_position_attacked_by(const Position &position, const Chess_Board *board) {
    using enum Color_t;

    Bitboard attacks = 0ULL;

    // check for pawn attack
    attacks |= (color == white
                    ? Constants::black_pawn_attacks[std::to_underlying(position)]
                    : Constants::white_pawn_attacks[std::to_underlying(position)]) & (color == white
        ? board->white_pawns
        : board->black_pawns);

    // check for knight attack
    attacks |= Constants::knight_attacks[std::to_underlying(position)] & (color == white
                                                                              ? board->white_knights
                                                                              : board->black_knights);

    // check for king attack
    attacks |= Constants::king_attacks[std::to_underlying(position)] & (color == white
                                                                            ? board->white_king
                                                                            : board->black_king);

    // check for bishop and queen attack
    attacks |= get_attacks_for_position<Slider::bishop>(position, board->all_pieces) &
    ((color == white ? board->white_bishops : board->black_bishops) | (color == white
                                                                           ? board->white_queens
                                                                           : board->black_queens));

    // check for rook and queen attack
    attacks |= get_attacks_for_position<Slider::rook>(position, board->all_pieces) &
    ((color == white ? board->white_rooks : board->black_rooks) | (color == white
                                                                       ? board->white_queens
                                                                       : board->black_queens));
    return attacks;
}


#endif //ATTACK_TABLES_H
