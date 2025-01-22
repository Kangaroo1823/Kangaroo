// This is an independent project of an individual developer. Dear PVS-Studio, please check_p it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com//
//
// Created by peter on 23/12/2024.
//

#ifndef MOVE_GENERATOR_H
#define MOVE_GENERATOR_H
#include <filesystem>
#include "../include/Board_Status.h"
#include "constants_attacks.h"
#include "../tools/attack_tables.h"
#include "../include/Chess_Board.h"

template<Chess_Pieces slider>
constexpr Bitboard get_attacks_for_position(const Square position, const Bitboard occupancy) {
    // retrieve the mask for the given piece type and position
    const Bitboard mask = slider == Chess_Pieces::Rook
                              ? Constants::rook_attack_masks[std::to_underlying(position)]
                              : Constants::bishop_attack_masks[std::to_underlying(position)];

    // mask the occupancy to retrieve the relevant data for the computation of the magic hashes.
    const Bitboard masked_occupancy = occupancy & mask;

    // compute the magic hash index for the given piece type and position.
    const size_t hash_index = create_magic_hash_index<slider>(position, masked_occupancy, Bitcount(mask));

    // and retrieve the attacked squares.
    const Bitboard hash_result = slider == Chess_Pieces::Rook
                                     ? Constants::rook_attack_table[hash_index]
                                     : Constants::bishop_attack_table[hash_index];

    return hash_result;
}

template<Chess_Pieces slider>
constexpr Bitboard get_attacks_for(const Bitboard occupancy, const Bitboard piece_positions) {
    // declare variable to hold the result
    Bitboard result = 0ULL;

    // loop over all set bits
    Bitloop(piece_positions, p) {
        // this is the inner part of the loop. It is being called for each set bit with |p| having its
        // lowest set bit equal to the bit for which the interation was called.

        // compute the position corresponding to the lowest set bit in p; i.e, the position of the chess piece
        // in question.
        auto position = square_of(p);

        // add the attacked squares (=bits set to 1 (one)) to the result.
        result |= get_attacks_for_position<slider>(position, occupancy);
    }

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
constexpr Bitboard attacked_squares_by(const Kangaroo::Chess_Board *board) {
    using enum Color;
    using enum Chess_Pieces;

    // create attack mask for pawns
    const Bitboard pawn_attacks = create_pawn_attacks_for<color>(bitboard_for(*board, color, Pawn));

    // create the attack mask for kings
    const Bitboard king_attacks = create_king_attacks_for(bitboard_for(*board, color, King));

    // ... for knights
    const Bitboard knight_attacks = create_knight_attacks_for(bitboard_for(*board, color, Knight));

    // ... for rooks
    const Bitboard rook_attacks = get_attacks_for<Chess_Pieces::Rook>(total_pieces_for(*board),
                                                                bitboard_for(*board, color, Rook));

    // ... for bishops
    const Bitboard bishop_attacks = get_attacks_for<Chess_Pieces::Bishop>(total_pieces_for(*board),
                                                                    bitboard_for(*board, color, Bishop));

    // ... and for queens
    Bitboard queen_attacks = get_attacks_for<Chess_Pieces::Bishop>(total_pieces_for(*board),
                                                               bitboard_for(*board,color,Queen));

    queen_attacks |= get_attacks_for<Chess_Pieces::Rook>(total_pieces_for(*board),
                                                     bitboard_for(*board, color, Queen));

    const Bitboard attacks = pawn_attacks | knight_attacks | rook_attacks | bishop_attacks | king_attacks |
                             queen_attacks;

    return attacks;
}

template<Color color>
constexpr Bitboard is_position_attacked_by(const Square position, const Kangaroo::Chess_Board *board) {
    using enum Color;
    using enum Chess_Pieces;

    Bitboard attacks = 0ULL;

    // check_p for Pawn attack
    attacks |= (color == White
                    ? Constants::black_pawn_attacks[std::to_underlying(position)]
                    : Constants::white_pawn_attacks[std::to_underlying(position)]) & (bitboard_for(*board, color, Pawn));

    // check_p for Knight attack
    attacks |= Constants::knight_attacks[std::to_underlying(position)] & (bitboard_for(*board,color,Knight));

    // check_p for King attack
    attacks |= Constants::king_attacks[std::to_underlying(position)] & (bitboard_for(*board,color,King));

    // check_p for Bishop and Queen attack
    attacks |= get_attacks_for_position<Chess_Pieces::Bishop>(position, total_pieces_for(*board)) &
    (bitboard_for(*board, color, Bishop) | bitboard_for(*board, color, Queen));

    // check_p for Rook and Queen attack
    attacks |= get_attacks_for_position<Chess_Pieces::Rook>(position, total_pieces_for(*board)) &
    (bitboard_for(*board, color, Rook) | bitboard_for(*board, color, Queen));
    return attacks;
}



#endif //MOVE_GENERATOR_H
