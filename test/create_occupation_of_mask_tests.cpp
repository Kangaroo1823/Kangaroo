// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by peter on 02/12/2024.
//

#include <array>                         // for array
#include "../include/bitboard.h"         // for set_bit, Bitboard, Position_t
#include "gtest/gtest.h"  // for StringRef, AssertionHandler

constexpr std::array<Bitboard, 64> occupancy_test_table = {
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    0ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  1  0  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    2ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  1  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    4ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  1  1  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    6ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    8ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  1  0  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    10ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  1  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    12ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  1  1  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    14ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    256ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  1  0  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    258ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  1  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    260ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  1  1  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    262ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  0  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    264ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  1  0  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    266ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  1  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    268ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  1  1  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    270ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    65536ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  1  0  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    65538ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  1  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    65540ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  1  1  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    65542ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    65544ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  1  0  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    65546ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  1  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    65548ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  1  1  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    65550ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    65792ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  1  0  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    65794ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  1  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    65796ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  1  1  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    65798ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  0  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    65800ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  1  0  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    65802ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  1  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    65804ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  1  1  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    65806ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16777216ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  1  0  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16777218ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  1  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16777220ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  1  1  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16777222ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16777224ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  1  0  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16777226ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  1  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16777228ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  1  1  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16777230ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16777472ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  1  0  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16777474ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  1  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16777476ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  1  1  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16777478ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  0  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16777480ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  1  0  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16777482ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  1  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16777484ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  1  1  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16777486ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16842752ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  1  0  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16842754ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  1  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16842756ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  1  1  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16842758ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16842760ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  1  0  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16842762ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  1  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16842764ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  1  1  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16842766ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16843008ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  1  0  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16843010ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  1  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16843012ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  1  1  0  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16843014ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  0  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16843016ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  1  0  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16843018ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  1  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16843020ULL,
    /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  1  1  1  0  0  0  0
            A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
    16843022ULL
};

TEST(Mask_Generator, create_occupation_of_mask) {
    using enum Square;
    Bitboard mask = 0ULL;

    mask = set_bit(mask, A2);
    mask = set_bit(mask, A3);
    mask = set_bit(mask, A4);
    mask = set_bit(mask, B1);
    mask = set_bit(mask, C1);
    mask = set_bit(mask, D1);

    for (unsigned int occupancy = 0; occupancy < 64; occupancy++) {
        // cppcheck-suppress unreadVariable
        const Bitboard board = create_occupancy_from_mask(occupancy, mask);
        ASSERT_EQ(occupancy_test_table[occupancy], board);
    }
}

TEST(Mask_Generator, create_occupation_of_mask2) {
    using enum Square;
    Bitboard mask = 0ULL;

    mask = set_bit(mask, A2);
    mask = set_bit(mask, A3);
    mask = set_bit(mask, A4);
    mask = set_bit(mask, B1);
    mask = set_bit(mask, C1);
    mask = set_bit(mask, D1);

    for (unsigned int index = 0; index < 64; index++) {
        // cppcheck-suppress unreadVariable
        const Bitboard board = create_occupancy_from_mask(index, mask);

        // cppcheck-suppress unreadVariable
        const Bitboard board_ = create_occupation_from_mask_(index, mask);

        ASSERT_EQ(board_, board);
    }
}
