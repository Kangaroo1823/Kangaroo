//
// Created by peter on 23/12/2024.
//

#ifndef TYPES_H
#define TYPES_H

#include <cstdint>
#include <array>

using MagicNumber = uint64_t;
using Bitboard = uint64_t;
using Move = uint64_t;

using Slider = enum class Slider_t : std::size_t {
    rook = 0,
    bishop = 1,
};

using Chess_Pieces = enum class Chess_Pieces_t : std::size_t {
    white_pawn = 0,
    black_pawn = 1,
    white_knight = 2,
    black_knight = 3,
    white_bishop = 4,
    black_bishop = 5,
    white_rook = 6,
    black_rook = 7,
    white_queen = 8,
    black_queen = 9,
    white_king = 10,
    black_king = 11
};

inline constexpr std::array All_Pieces = {
    Chess_Pieces::white_pawn,
    Chess_Pieces::black_pawn,
    Chess_Pieces::white_knight,
    Chess_Pieces::black_knight,
    Chess_Pieces::white_bishop,
    Chess_Pieces::black_bishop,
    Chess_Pieces::white_rook,
    Chess_Pieces::black_rook,
    Chess_Pieces::white_queen,
    Chess_Pieces::black_queen,
    Chess_Pieces::white_king,
    Chess_Pieces::black_king
};

/**
 * Have a convenient way of naming positions
 */
using Square = enum class Square_t  : std::size_t {
    A1 = 0,
    B1 = 1,
    C1 = 2,
    D1 = 3,
    E1 = 4,
    F1 = 5,
    G1 = 6,
    H1 = 7,
    A2 = 8,
    B2 = 9,
    C2 = 10,
    D2 = 11,
    E2 = 12,
    F2 = 13,
    G2 = 14,
    H2 = 15,
    A3 = 16,
    B3 = 17,
    C3 = 18,
    D3 = 19,
    E3 = 20,
    F3 = 21,
    G3 = 22,
    H3 = 23,
    A4 = 24,
    B4 = 25,
    C4 = 26,
    D4 = 27,
    E4 = 28,
    F4 = 29,
    G4 = 30,
    H4 = 31,
    A5 = 32,
    B5 = 33,
    C5 = 34,
    D5 = 35,
    E5 = 36,
    F5 = 37,
    G5 = 38,
    H5 = 39,
    A6 = 40,
    B6 = 41,
    C6 = 42,
    D6 = 43,
    E6 = 44,
    F6 = 45,
    G6 = 46,
    H6 = 47,
    A7 = 48,
    B7 = 49,
    C7 = 50,
    D7 = 51,
    E7 = 52,
    F7 = 53,
    G7 = 54,
    H7 = 55,
    A8 = 56,
    B8 = 57,
    C8 = 58,
    D8 = 59,
    E8 = 60,
    F8 = 61,
    G8 = 62,
    H8 = 63
};

inline constexpr std::array<Square, 64> All_Positions = {
    Square_t::A1, Square_t::B1, Square_t::C1, Square_t::D1, Square_t::E1, Square_t::F1, Square_t::G1, Square_t::H1,
    Square_t::A2, Square_t::B2, Square_t::C2, Square_t::D2, Square_t::E2, Square_t::F2, Square_t::G2, Square_t::H2,
    Square_t::A3, Square_t::B3, Square_t::C3, Square_t::D3, Square_t::E3, Square_t::F3, Square_t::G3, Square_t::H3,
    Square_t::A4, Square_t::B4, Square_t::C4, Square_t::D4, Square_t::E4, Square_t::F4, Square_t::G4, Square_t::H4,
    Square_t::A5, Square_t::B5, Square_t::C5, Square_t::D5, Square_t::E5, Square_t::F5, Square_t::G5, Square_t::H5,
    Square_t::A6, Square_t::B6, Square_t::C6, Square_t::D6, Square_t::E6, Square_t::F6, Square_t::G6, Square_t::H6,
    Square_t::A7, Square_t::B7, Square_t::C7, Square_t::D7, Square_t::E7, Square_t::F7, Square_t::G7, Square_t::H7,
    Square_t::A8, Square_t::B8, Square_t::C8, Square_t::D8, Square_t::E8, Square_t::F8, Square_t::G8, Square_t::H8
};


using WhiteQueenSideCastle = enum class WhiteQueenSideCastle_t : uint64_t {
    white_queen_side_castle_possible = 1ULL << 0,
    white_queen_side_castle_impossible = 1ULL << 1,
};

using WhiteKingSideCastle = enum class WhiteKingSideCastle_t : uint64_t {
    white_king_side_castle_possible = 1ULL << 0,
    white_king_side_castle_impossible = 1ULL << 1,
};

using BlackQueenSideCastle = enum class BlackQueenSideCastle_t : uint64_t {
    black_queen_side_castle_possible = 1ULL << 0,
    black_queen_side_castle_impossible = 1ULL << 1,
};

using BlackKingSideCastle = enum class BlackKingSideCastle_t : uint64_t {
    black_king_side_castle_possible = 1ULL << 0,
    black_king_side_castle_impossible = 1ULL << 1,
};

using En_Passant = enum class En_Passant_t : uint64_t {
    en_passant_possible = 1ULL << 0,
    en_passant_impossible = 1ULL << 1,
};

using Pin_Masks_Suitable_For = enum class Pin_Masks_Suitable_For_t : uint64_t {
    detecting_pins = 2,
    detecting_check = 1,
};

#endif //TYPES_H
