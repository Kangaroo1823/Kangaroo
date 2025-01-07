//
// Created by peter on 02/12/2024.
//

#ifndef CREATE_POSSIBLE_BISHOP_MOVES_H
#define CREATE_POSSIBLE_BISHOP_MOVES_H

#include "../include/bitboard.h"


template<Slider slider>
constexpr Bitboard create_possible_slider_moves(const Bitboard occupancy, const Square position) {
    Bitboard moves = 0ULL;

    const std::size_t file = std::to_underlying(position) & 7;
    const std::size_t rank = std::to_underlying(position) >> 3;

    if constexpr (slider == Slider::bishop) {
        // slider equals Slider::bishop
        for (std::size_t r = rank + 1, f = file + 1; r < 8 && f < 8; r++, f++) {
            const Square pos = rank_file_to_position(r, f);
            moves = set_bit(moves, pos);
            if (1ULL << std::to_underlying(pos) & occupancy) break;
        }

        for (std::size_t r = rank + 1, f = file; r < 8 && f > 0; r++, f--) {
            const Square pos = rank_file_to_position(r, f - 1);
            moves = set_bit(moves, pos);
            if (1ULL << std::to_underlying(pos) & occupancy) break;
        }

        for (std::size_t r = rank, f = file; r > 0 && f > 0; r--, f--) {
            const Square pos = rank_file_to_position(r - 1, f - 1);
            moves = set_bit(moves, pos);
            if (1ULL << std::to_underlying(pos) & occupancy) break;
        }

        for (std::size_t r = rank, f = file + 1; r > 0 && f < 8; r--, f++) {
            const Square pos = rank_file_to_position(r - 1, f);
            moves = set_bit(moves, pos);
            if (1ULL << std::to_underlying(pos) & occupancy) break;
        }
    } else {
        // slider equals Slider::rook
        for (std::size_t r = rank + 1; r < 8; r++) {
            const Square pos = rank_file_to_position(r, file);
            moves = set_bit(moves, pos);
            if (1ULL << std::to_underlying(pos) & occupancy) break;
        }

        for (std::size_t r = rank; r > 0; r--) {
            const Square pos = rank_file_to_position(r - 1, file);
            moves = set_bit(moves, pos);
            if (1ULL << std::to_underlying(pos) & occupancy) break;
        }

        for (std::size_t f = file + 1; f < 8; f++) {
            const Square pos = rank_file_to_position(rank, f);
            moves = set_bit(moves, pos);
            if (1ULL << std::to_underlying(pos) & occupancy) break;
        }

        for (std::size_t f = file; f > 0; f--) {
            const Square pos = rank_file_to_position(rank, f - 1);
            moves = set_bit(moves, pos);
            if (1ULL << std::to_underlying(pos) & occupancy) break;
        }
    }

    return moves;
}


#endif //CREATE_POSSIBLE_BISHOP_MOVES_H
