//
// Created by peter on 02/12/2024.
//

#include <array>                         // for array
#include <cstdint>                       // for int64_t
#include "../include/bitboard.h"         // for set_bit, Bitboard, Position_t
#include "catch2/catch_test_macros.hpp"  // for StringRef, AssertionHandler

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

TEST_CASE("Create Occupation of Mask", "[create_occupation_of_mask]") {
    using enum Position_t;
    Bitboard mask = 0ULL;

    mask = set_bit(mask, A2);
    mask = set_bit(mask, A3);
    mask = set_bit(mask, A4);
    mask = set_bit(mask, B1);
    mask = set_bit(mask, C1);
    mask = set_bit(mask, D1);

    for (unsigned int occupancy = 0; occupancy < 64; occupancy++) {
        // cppcheck-suppress unreadVariable
        const Bitboard board = create_occupancy_of_mask(occupancy, mask);
        REQUIRE(occupancy_test_table[occupancy] == board);
    }
}


Bitboard create_occupation_of_mask_(const unsigned int index, Bitboard mask) {
    Bitboard occupancy = 0ULL;

    const int64_t count = Bitcount(mask);
    for (unsigned int i = 0; i < count; i++) {
        const Bitboard s = SquareOf(mask);
        mask &= mask - 1ULL;
        if (index & 1ULL << i) occupancy |= 1ULL << s;
    }

    return occupancy;
}

TEST_CASE("Create Occupation of Mask2", "[create_occupation_of_mask2]") {
    using enum Position_t;
    Bitboard mask = 0ULL;

    mask = set_bit(mask, A2);
    mask = set_bit(mask, A3);
    mask = set_bit(mask, A4);
    mask = set_bit(mask, B1);
    mask = set_bit(mask, C1);
    mask = set_bit(mask, D1);

    for (unsigned int occupancy = 0; occupancy < 64; occupancy++) {
        // cppcheck-suppress unreadVariable
        const Bitboard board = create_occupancy_of_mask(occupancy, mask);

        // cppcheck-suppress unreadVariable
        const Bitboard board_ = create_occupation_of_mask_(occupancy, mask);

        REQUIRE(board_ == board);
    }
}
