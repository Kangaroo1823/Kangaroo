//
// Created by peter on 17/12/2024.
//

#ifndef ATTACK_TABLES_H
#define ATTACK_TABLES_H

#include <array>
#include <cassert>
#include <vector>

#include "../include/Bit_Board.h"
#include "../include/Address_Attack_Tables.h"
#include "Magic_Numbers.h"
#include "constants_magics.h"

/**********************************************************************************
 * Slider attacks
 *********************************************************************************/




template<Chess_Pieces slider>
/**
 * Generates an attack table for sliding pieces (rooks or bishops) based on their movement
 * patterns on the chessboard. The function precomputes all possible attack bitboards
 * for each position on the board, considering obstacles and movement ranges.
 *
 * @param position The position where the slider is on the board.
 * @tparam slider  Specifies the type of sliding piece (rook or bishop) for which the attack
 *                 table is being created.
 * @return A comprehensive mapping of board positions to their corresponding attack bitboards,
 *         indicating all valid movements for the given piece type at each position.
 */
constexpr std::array<Bitboard, slider == Chess_Pieces::Bishop ? 512 : 4096>
create_attack_table_for(const Square position) {
    const Bitboard mask = get_attack_mask_for_slider<slider>(position);

    const int64_t relevant_bits = Bitcount(mask);
    const std::size_t number_of_masks = static_cast<std::size_t>(1) << static_cast<std::size_t>(relevant_bits);

    std::array<Bitboard, slider == Chess_Pieces::Bishop ? 512 : 4096> attack_table = {0};

    for (std::size_t index = 0; index < number_of_masks; ++index) {
        const Bitboard occupancy = create_occupancy_from_mask(index, mask);
        const Bitboard attack = Kangaroo::create_possible_slider_moves<slider>(occupancy, position);
        auto hashed_index = create_hash_index<slider>(position, occupancy, relevant_bits);

        attack_table[hashed_index] = attack;
    }

    return attack_table;
}


template<Chess_Pieces slider>
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
void create_attack_table(std::vector<Bitboard> &result) {
    using enum Chess_Pieces;

    assert(result.size() >= 64 * (slider == Bishop ? 512 : 4096));

    auto iter = result.begin();
    for (const auto &position: All_Positions) {
        auto r = create_attack_table_for<slider>(position);
        std::ranges::copy(r, iter);
        iter += r.size();
    }
}


/**********************************************************************************
 * Pawn attacks
 *********************************************************************************/

template<Color color>
constexpr Bitboard create_pawn_attacks_for(const Bitboard bitboard) {
    Bitboard attacks = 0ULL;

    if constexpr (color == Color::Black) {
        // color is sequal to black
        attacks = (bitboard >> 7 & not_a_file);
        attacks = attacks | (bitboard >> 9 & not_h_file);
    } else {
        // color is equal to white
        attacks = (bitboard << 7 & not_h_file);
        attacks = attacks | (bitboard << 9 & not_a_file);
    }

    return attacks;
}


template<Color color>
constexpr void create_pawn_attacks(std::vector<Bitboard> &attacks) {
    assert(attacks.size() >= 64);

    for (auto iter = attacks.begin(); const auto &position: All_Positions) {
        *iter = create_pawn_attacks_for<color>(set_bit(0ULL, position));
        ++iter;
    }
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


_ForceInline constexpr void create_king_attacks(std::vector<Bitboard> &attacks) { // -V2009
    assert(attacks.size() >= 64);

    for (auto iter = attacks.begin(); const auto &position: All_Positions) {
        *iter = create_king_attacks_for(set_bit(0ULL, position));
        ++iter;
    }
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

_ForceInline constexpr void create_knight_attacks(std::vector<Bitboard> &attacks) { // -V2009
    assert(attacks.size() >= 64);

    for (auto iter = attacks.begin(); const auto &position: All_Positions) {
        *iter = create_knight_attacks_for(set_bit(0ULL, position));
        ++iter;
    }
}


#endif //ATTACK_TABLES_H
