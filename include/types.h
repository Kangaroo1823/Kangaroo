//
// Created by peter on 23/12/2024.
//

#ifndef TYPES_H
#define TYPES_H

using MagicNumber = uint64_t;
using Bitboard = uint64_t;

using Slider = enum class Slider_t : std::size_t {
    rook = 0,
    bishop = 1,
};

/**
 * Have a convenient way of naming positions
 */
using Position = enum class Position_t  : std::size_t {
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

constexpr std::array<Position, 64> All_Positions = {
    Position_t::A1, Position_t::B1, Position_t::C1, Position_t::D1, Position_t::E1, Position_t::F1, Position_t::G1, Position_t::H1,
    Position_t::A2, Position_t::B2, Position_t::C2, Position_t::D2, Position_t::E2, Position_t::F2, Position_t::G2, Position_t::H2,
    Position_t::A3, Position_t::B3, Position_t::C3, Position_t::D3, Position_t::E3, Position_t::F3, Position_t::G3, Position_t::H3,
    Position_t::A4, Position_t::B4, Position_t::C4, Position_t::D4, Position_t::E4, Position_t::F4, Position_t::G4, Position_t::H4,
    Position_t::A5, Position_t::B5, Position_t::C5, Position_t::D5, Position_t::E5, Position_t::F5, Position_t::G5, Position_t::H5,
    Position_t::A6, Position_t::B6, Position_t::C6, Position_t::D6, Position_t::E6, Position_t::F6, Position_t::G6, Position_t::H6,
    Position_t::A7, Position_t::B7, Position_t::C7, Position_t::D7, Position_t::E7, Position_t::F7, Position_t::G7, Position_t::H7,
    Position_t::A8, Position_t::B8, Position_t::C8, Position_t::D8, Position_t::E8, Position_t::F8, Position_t::G8, Position_t::H8
};


using Castle_Flags = enum class Castle_Flags_t : uint64_t {
    white_kingside = 1ULL << 0,
    white_queenside = 1ULL << 1,
    black_kingside = 1ULL << 2,
    black_queenside = 1ULL << 3,
};

using En_Passant_Flags = enum class En_Passant_Flags_t : uint64_t {
    en_passant_possible = 1ULL << 0,
    en_passant_impossible = 1ULL << 1,
};

#endif //TYPES_H
