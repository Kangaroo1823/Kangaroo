//
// Created by peter on 01/12/2024.
//

#ifndef COLORS_H
#define COLORS_H

#include <array>
#include <cstdlib>


using Piece = enum class Piece_t : std::size_t {
    pawn = 0,
    knight = 1,
    bishop = 2,
    rook = 3,
    queen = 4,
    king = 5,
};

constexpr std::array<Piece_t, 7> All_Pieces = {
    Piece_t::pawn, Piece_t::knight, Piece_t::bishop, Piece_t::rook, Piece_t::queen, Piece_t::king
};

using Color = enum class Color_t : std::size_t {
    white = 0,
    black = 16,
};

constexpr std::array<Color_t, 2> All_Colors = {Color_t::white, Color_t::black};


#endif //COLORS_H
