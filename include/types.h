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

enum class Color : std::size_t {
    white = 0,
    black = 16,
};

constexpr std::array<Color, 2> All_Colors = {Color::white, Color::black};


using Slider = enum class Slider_t : std::size_t {
    rook = 0,
    bishop = 1,
};

enum class Chess_Pieces : std::size_t {
    pawn = 0,
    knight = 1,
    bishop = 2,
    rook = 3,
    queen = 4,
    king = 5
};

inline constexpr std::array All_Pieces = {
    Chess_Pieces::pawn,
    Chess_Pieces::knight,
    Chess_Pieces::bishop,
    Chess_Pieces::rook,
    Chess_Pieces::queen,
    Chess_Pieces::king
};

/**
 * Have a convenient way of naming positions
 */
enum class Square  : std::size_t {
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
    Square::A1, Square::B1, Square::C1, Square::D1, Square::E1, Square::F1, Square::G1, Square::H1,
    Square::A2, Square::B2, Square::C2, Square::D2, Square::E2, Square::F2, Square::G2, Square::H2,
    Square::A3, Square::B3, Square::C3, Square::D3, Square::E3, Square::F3, Square::G3, Square::H3,
    Square::A4, Square::B4, Square::C4, Square::D4, Square::E4, Square::F4, Square::G4, Square::H4,
    Square::A5, Square::B5, Square::C5, Square::D5, Square::E5, Square::F5, Square::G5, Square::H5,
    Square::A6, Square::B6, Square::C6, Square::D6, Square::E6, Square::F6, Square::G6, Square::H6,
    Square::A7, Square::B7, Square::C7, Square::D7, Square::E7, Square::F7, Square::G7, Square::H7,
    Square::A8, Square::B8, Square::C8, Square::D8, Square::E8, Square::F8, Square::G8, Square::H8
};


enum class En_Passant : uint64_t {
    en_passant_possible = 1ULL << 0,
    en_passant_impossible = 1ULL << 1,
};

enum class Pin_Masks_Suitable_For : int64_t {
    detecting_pins = 2,
    detecting_check = 1,
};

enum class Move_Generation_Mode : uint64_t {
    normal_move_generation = 0,
    pin_HV_move_generation = 1,
    pin_D_move_generation = 2,
    check_move_generation = 3,
};

enum class Move_Type : uint64_t {
    Normal = 1,
    Castling = 2,
    En_Passant = 3,
    Promotion = 4,
    Capture = 5,
};


#endif //TYPES_H
