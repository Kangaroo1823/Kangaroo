//
// Created by peter on 02/12/2024.
//

#ifndef ROOK_ATTACK_MASKS_H
#define ROOK_ATTACK_MASKS_H

#include <array>

#include "bitboard.h"

namespace Constants {
    /**
     * @brief Array of 64-bit integers where a bit is set (1) iff a figure there
     * restricts movement of the rook.
     *
     * The array has 64 elements and is indexed by the position of the rook on
     * an otherwise empty chess board. At index 0 it is assumed that the rook is on
     * the square A1, at index 7 the rook is assumed to be at index H1, at index 8
     * the rook is at A2, etc.
     *
     * The array is composed of 64-bit unsigned integers. Each bit represents a
     * square of the chess board. If the bit is set (1), it states that another figure
     * at the corresponding square might restrict further movement of the rook.
     *
     * Note: It is assumed that the rook can capture the other figure, but cannot go any
     * further in the direction.
     *
     * Otherwise, if a figure at that position does not restrict the rooks' movement the
     * corresponding bit is unset (0). Again it is assumed that the rook might move to
     * this square
     */
    static constexpr std::array<Bitboard, 64> rook_attack_masks = {
        /*
    8   0  0  0  0  0  0  0  0
    7   1  0  0  0  0  0  0  0
    6   1  0  0  0  0  0  0  0
    5   1  0  0  0  0  0  0  0
    4   1  0  0  0  0  0  0  0
    3   1  0  0  0  0  0  0  0
    2   1  0  0  0  0  0  0  0
    1   0  1  1  1  1  1  1  0
    A  B  C  D  E  F  G  H

    bitboard as 64 bit integer: */
        0x101010101017e,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  0  0  0  0  0  0
        6   0  1  0  0  0  0  0  0
        5   0  1  0  0  0  0  0  0
        4   0  1  0  0  0  0  0  0
        3   0  1  0  0  0  0  0  0
        2   0  1  0  0  0  0  0  0
        1   0  0  1  1  1  1  1  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x202020202027c,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  1  0  0  0  0  0
        6   0  0  1  0  0  0  0  0
        5   0  0  1  0  0  0  0  0
        4   0  0  1  0  0  0  0  0
        3   0  0  1  0  0  0  0  0
        2   0  0  1  0  0  0  0  0
        1   0  1  0  1  1  1  1  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x404040404047a,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  1  0  0  0  0
        6   0  0  0  1  0  0  0  0
        5   0  0  0  1  0  0  0  0
        4   0  0  0  1  0  0  0  0
        3   0  0  0  1  0  0  0  0
        2   0  0  0  1  0  0  0  0
        1   0  1  1  0  1  1  1  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x8080808080876,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  1  0  0  0
        6   0  0  0  0  1  0  0  0
        5   0  0  0  0  1  0  0  0
        4   0  0  0  0  1  0  0  0
        3   0  0  0  0  1  0  0  0
        2   0  0  0  0  1  0  0  0
        1   0  1  1  1  0  1  1  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x1010101010106e,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  1  0  0
        6   0  0  0  0  0  1  0  0
        5   0  0  0  0  0  1  0  0
        4   0  0  0  0  0  1  0  0
        3   0  0  0  0  0  1  0  0
        2   0  0  0  0  0  1  0  0
        1   0  1  1  1  1  0  1  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x2020202020205e,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  1  0
        6   0  0  0  0  0  0  1  0
        5   0  0  0  0  0  0  1  0
        4   0  0  0  0  0  0  1  0
        3   0  0  0  0  0  0  1  0
        2   0  0  0  0  0  0  1  0
        1   0  1  1  1  1  1  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x4040404040403e,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  1
        6   0  0  0  0  0  0  0  1
        5   0  0  0  0  0  0  0  1
        4   0  0  0  0  0  0  0  1
        3   0  0  0  0  0  0  0  1
        2   0  0  0  0  0  0  0  1
        1   0  1  1  1  1  1  1  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x8080808080807e,
        /*
        8   0  0  0  0  0  0  0  0
        7   1  0  0  0  0  0  0  0
        6   1  0  0  0  0  0  0  0
        5   1  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   0  1  1  1  1  1  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x1010101017e00,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  0  0  0  0  0  0
        6   0  1  0  0  0  0  0  0
        5   0  1  0  0  0  0  0  0
        4   0  1  0  0  0  0  0  0
        3   0  1  0  0  0  0  0  0
        2   0  0  1  1  1  1  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x2020202027c00,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  1  0  0  0  0  0
        6   0  0  1  0  0  0  0  0
        5   0  0  1  0  0  0  0  0
        4   0  0  1  0  0  0  0  0
        3   0  0  1  0  0  0  0  0
        2   0  1  0  1  1  1  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x4040404047a00,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  1  0  0  0  0
        6   0  0  0  1  0  0  0  0
        5   0  0  0  1  0  0  0  0
        4   0  0  0  1  0  0  0  0
        3   0  0  0  1  0  0  0  0
        2   0  1  1  0  1  1  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x8080808087600,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  1  0  0  0
        6   0  0  0  0  1  0  0  0
        5   0  0  0  0  1  0  0  0
        4   0  0  0  0  1  0  0  0
        3   0  0  0  0  1  0  0  0
        2   0  1  1  1  0  1  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x10101010106e00,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  1  0  0
        6   0  0  0  0  0  1  0  0
        5   0  0  0  0  0  1  0  0
        4   0  0  0  0  0  1  0  0
        3   0  0  0  0  0  1  0  0
        2   0  1  1  1  1  0  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x20202020205e00,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  1  0
        6   0  0  0  0  0  0  1  0
        5   0  0  0  0  0  0  1  0
        4   0  0  0  0  0  0  1  0
        3   0  0  0  0  0  0  1  0
        2   0  1  1  1  1  1  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x40404040403e00,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  1
        6   0  0  0  0  0  0  0  1
        5   0  0  0  0  0  0  0  1
        4   0  0  0  0  0  0  0  1
        3   0  0  0  0  0  0  0  1
        2   0  1  1  1  1  1  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x80808080807e00,
        /*
        8   0  0  0  0  0  0  0  0
        7   1  0  0  0  0  0  0  0
        6   1  0  0  0  0  0  0  0
        5   1  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   0  1  1  1  1  1  1  0
        2   1  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x10101017e0100,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  0  0  0  0  0  0
        6   0  1  0  0  0  0  0  0
        5   0  1  0  0  0  0  0  0
        4   0  1  0  0  0  0  0  0
        3   0  0  1  1  1  1  1  0
        2   0  1  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x20202027c0200,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  1  0  0  0  0  0
        6   0  0  1  0  0  0  0  0
        5   0  0  1  0  0  0  0  0
        4   0  0  1  0  0  0  0  0
        3   0  1  0  1  1  1  1  0
        2   0  0  1  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x40404047a0400,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  1  0  0  0  0
        6   0  0  0  1  0  0  0  0
        5   0  0  0  1  0  0  0  0
        4   0  0  0  1  0  0  0  0
        3   0  1  1  0  1  1  1  0
        2   0  0  0  1  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x8080808760800,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  1  0  0  0
        6   0  0  0  0  1  0  0  0
        5   0  0  0  0  1  0  0  0
        4   0  0  0  0  1  0  0  0
        3   0  1  1  1  0  1  1  0
        2   0  0  0  0  1  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x101010106e1000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  1  0  0
        6   0  0  0  0  0  1  0  0
        5   0  0  0  0  0  1  0  0
        4   0  0  0  0  0  1  0  0
        3   0  1  1  1  1  0  1  0
        2   0  0  0  0  0  1  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x202020205e2000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  1  0
        6   0  0  0  0  0  0  1  0
        5   0  0  0  0  0  0  1  0
        4   0  0  0  0  0  0  1  0
        3   0  1  1  1  1  1  0  0
        2   0  0  0  0  0  0  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x404040403e4000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  1
        6   0  0  0  0  0  0  0  1
        5   0  0  0  0  0  0  0  1
        4   0  0  0  0  0  0  0  1
        3   0  1  1  1  1  1  1  0
        2   0  0  0  0  0  0  0  1
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x808080807e8000,
        /*
        8   0  0  0  0  0  0  0  0
        7   1  0  0  0  0  0  0  0
        6   1  0  0  0  0  0  0  0
        5   1  0  0  0  0  0  0  0
        4   0  1  1  1  1  1  1  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x101017e010100,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  0  0  0  0  0  0
        6   0  1  0  0  0  0  0  0
        5   0  1  0  0  0  0  0  0
        4   0  0  1  1  1  1  1  0
        3   0  1  0  0  0  0  0  0
        2   0  1  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x202027c020200,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  1  0  0  0  0  0
        6   0  0  1  0  0  0  0  0
        5   0  0  1  0  0  0  0  0
        4   0  1  0  1  1  1  1  0
        3   0  0  1  0  0  0  0  0
        2   0  0  1  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x404047a040400,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  1  0  0  0  0
        6   0  0  0  1  0  0  0  0
        5   0  0  0  1  0  0  0  0
        4   0  1  1  0  1  1  1  0
        3   0  0  0  1  0  0  0  0
        2   0  0  0  1  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x8080876080800,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  1  0  0  0
        6   0  0  0  0  1  0  0  0
        5   0  0  0  0  1  0  0  0
        4   0  1  1  1  0  1  1  0
        3   0  0  0  0  1  0  0  0
        2   0  0  0  0  1  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x1010106e101000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  1  0  0
        6   0  0  0  0  0  1  0  0
        5   0  0  0  0  0  1  0  0
        4   0  1  1  1  1  0  1  0
        3   0  0  0  0  0  1  0  0
        2   0  0  0  0  0  1  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x2020205e202000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  1  0
        6   0  0  0  0  0  0  1  0
        5   0  0  0  0  0  0  1  0
        4   0  1  1  1  1  1  0  0
        3   0  0  0  0  0  0  1  0
        2   0  0  0  0  0  0  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x4040403e404000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  1
        6   0  0  0  0  0  0  0  1
        5   0  0  0  0  0  0  0  1
        4   0  1  1  1  1  1  1  0
        3   0  0  0  0  0  0  0  1
        2   0  0  0  0  0  0  0  1
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x8080807e808000,
        /*
        8   0  0  0  0  0  0  0  0
        7   1  0  0  0  0  0  0  0
        6   1  0  0  0  0  0  0  0
        5   0  1  1  1  1  1  1  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x1017e01010100,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  0  0  0  0  0  0
        6   0  1  0  0  0  0  0  0
        5   0  0  1  1  1  1  1  0
        4   0  1  0  0  0  0  0  0
        3   0  1  0  0  0  0  0  0
        2   0  1  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x2027c02020200,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  1  0  0  0  0  0
        6   0  0  1  0  0  0  0  0
        5   0  1  0  1  1  1  1  0
        4   0  0  1  0  0  0  0  0
        3   0  0  1  0  0  0  0  0
        2   0  0  1  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x4047a04040400,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  1  0  0  0  0
        6   0  0  0  1  0  0  0  0
        5   0  1  1  0  1  1  1  0
        4   0  0  0  1  0  0  0  0
        3   0  0  0  1  0  0  0  0
        2   0  0  0  1  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x8087608080800,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  1  0  0  0
        6   0  0  0  0  1  0  0  0
        5   0  1  1  1  0  1  1  0
        4   0  0  0  0  1  0  0  0
        3   0  0  0  0  1  0  0  0
        2   0  0  0  0  1  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x10106e10101000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  1  0  0
        6   0  0  0  0  0  1  0  0
        5   0  1  1  1  1  0  1  0
        4   0  0  0  0  0  1  0  0
        3   0  0  0  0  0  1  0  0
        2   0  0  0  0  0  1  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x20205e20202000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  1  0
        6   0  0  0  0  0  0  1  0
        5   0  1  1  1  1  1  0  0
        4   0  0  0  0  0  0  1  0
        3   0  0  0  0  0  0  1  0
        2   0  0  0  0  0  0  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x40403e40404000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  1
        6   0  0  0  0  0  0  0  1
        5   0  1  1  1  1  1  1  0
        4   0  0  0  0  0  0  0  1
        3   0  0  0  0  0  0  0  1
        2   0  0  0  0  0  0  0  1
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x80807e80808000,
        /*
        8   0  0  0  0  0  0  0  0
        7   1  0  0  0  0  0  0  0
        6   0  1  1  1  1  1  1  0
        5   1  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x17e0101010100,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  0  0  0  0  0  0
        6   0  0  1  1  1  1  1  0
        5   0  1  0  0  0  0  0  0
        4   0  1  0  0  0  0  0  0
        3   0  1  0  0  0  0  0  0
        2   0  1  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x27c0202020200,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  1  0  0  0  0  0
        6   0  1  0  1  1  1  1  0
        5   0  0  1  0  0  0  0  0
        4   0  0  1  0  0  0  0  0
        3   0  0  1  0  0  0  0  0
        2   0  0  1  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x47a0404040400,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  1  0  0  0  0
        6   0  1  1  0  1  1  1  0
        5   0  0  0  1  0  0  0  0
        4   0  0  0  1  0  0  0  0
        3   0  0  0  1  0  0  0  0
        2   0  0  0  1  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x8760808080800,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  1  0  0  0
        6   0  1  1  1  0  1  1  0
        5   0  0  0  0  1  0  0  0
        4   0  0  0  0  1  0  0  0
        3   0  0  0  0  1  0  0  0
        2   0  0  0  0  1  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x106e1010101000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  1  0  0
        6   0  1  1  1  1  0  1  0
        5   0  0  0  0  0  1  0  0
        4   0  0  0  0  0  1  0  0
        3   0  0  0  0  0  1  0  0
        2   0  0  0  0  0  1  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x205e2020202000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  1  0
        6   0  1  1  1  1  1  0  0
        5   0  0  0  0  0  0  1  0
        4   0  0  0  0  0  0  1  0
        3   0  0  0  0  0  0  1  0
        2   0  0  0  0  0  0  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x403e4040404000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  1
        6   0  1  1  1  1  1  1  0
        5   0  0  0  0  0  0  0  1
        4   0  0  0  0  0  0  0  1
        3   0  0  0  0  0  0  0  1
        2   0  0  0  0  0  0  0  1
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x807e8080808000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  1  1  1  1  1  0
        6   1  0  0  0  0  0  0  0
        5   1  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x7e010101010100,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  1  1  1  1  1  0
        6   0  1  0  0  0  0  0  0
        5   0  1  0  0  0  0  0  0
        4   0  1  0  0  0  0  0  0
        3   0  1  0  0  0  0  0  0
        2   0  1  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x7c020202020200,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  0  1  1  1  1  0
        6   0  0  1  0  0  0  0  0
        5   0  0  1  0  0  0  0  0
        4   0  0  1  0  0  0  0  0
        3   0  0  1  0  0  0  0  0
        2   0  0  1  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x7a040404040400,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  1  0  1  1  1  0
        6   0  0  0  1  0  0  0  0
        5   0  0  0  1  0  0  0  0
        4   0  0  0  1  0  0  0  0
        3   0  0  0  1  0  0  0  0
        2   0  0  0  1  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x76080808080800,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  1  1  0  1  1  0
        6   0  0  0  0  1  0  0  0
        5   0  0  0  0  1  0  0  0
        4   0  0  0  0  1  0  0  0
        3   0  0  0  0  1  0  0  0
        2   0  0  0  0  1  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x6e101010101000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  1  1  1  0  1  0
        6   0  0  0  0  0  1  0  0
        5   0  0  0  0  0  1  0  0
        4   0  0  0  0  0  1  0  0
        3   0  0  0  0  0  1  0  0
        2   0  0  0  0  0  1  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x5e202020202000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  1  1  1  1  0  0
        6   0  0  0  0  0  0  1  0
        5   0  0  0  0  0  0  1  0
        4   0  0  0  0  0  0  1  0
        3   0  0  0  0  0  0  1  0
        2   0  0  0  0  0  0  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x3e404040404000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  1  1  1  1  1  0
        6   0  0  0  0  0  0  0  1
        5   0  0  0  0  0  0  0  1
        4   0  0  0  0  0  0  0  1
        3   0  0  0  0  0  0  0  1
        2   0  0  0  0  0  0  0  1
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x7e808080808000,
        /*
        8   0  1  1  1  1  1  1  0
        7   1  0  0  0  0  0  0  0
        6   1  0  0  0  0  0  0  0
        5   1  0  0  0  0  0  0  0
        4   1  0  0  0  0  0  0  0
        3   1  0  0  0  0  0  0  0
        2   1  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x7e01010101010100,
        /*
        8   0  0  1  1  1  1  1  0
        7   0  1  0  0  0  0  0  0
        6   0  1  0  0  0  0  0  0
        5   0  1  0  0  0  0  0  0
        4   0  1  0  0  0  0  0  0
        3   0  1  0  0  0  0  0  0
        2   0  1  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x7c02020202020200,
        /*
        8   0  1  0  1  1  1  1  0
        7   0  0  1  0  0  0  0  0
        6   0  0  1  0  0  0  0  0
        5   0  0  1  0  0  0  0  0
        4   0  0  1  0  0  0  0  0
        3   0  0  1  0  0  0  0  0
        2   0  0  1  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x7a04040404040400,
        /*
        8   0  1  1  0  1  1  1  0
        7   0  0  0  1  0  0  0  0
        6   0  0  0  1  0  0  0  0
        5   0  0  0  1  0  0  0  0
        4   0  0  0  1  0  0  0  0
        3   0  0  0  1  0  0  0  0
        2   0  0  0  1  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x7608080808080800,
        /*
        8   0  1  1  1  0  1  1  0
        7   0  0  0  0  1  0  0  0
        6   0  0  0  0  1  0  0  0
        5   0  0  0  0  1  0  0  0
        4   0  0  0  0  1  0  0  0
        3   0  0  0  0  1  0  0  0
        2   0  0  0  0  1  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x6e10101010101000,
        /*
        8   0  1  1  1  1  0  1  0
        7   0  0  0  0  0  1  0  0
        6   0  0  0  0  0  1  0  0
        5   0  0  0  0  0  1  0  0
        4   0  0  0  0  0  1  0  0
        3   0  0  0  0  0  1  0  0
        2   0  0  0  0  0  1  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x5e20202020202000,
        /*
        8   0  1  1  1  1  1  0  0
        7   0  0  0  0  0  0  1  0
        6   0  0  0  0  0  0  1  0
        5   0  0  0  0  0  0  1  0
        4   0  0  0  0  0  0  1  0
        3   0  0  0  0  0  0  1  0
        2   0  0  0  0  0  0  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x3e40404040404000,
        /*
        8   0  1  1  1  1  1  1  0
        7   0  0  0  0  0  0  0  1
        6   0  0  0  0  0  0  0  1
        5   0  0  0  0  0  0  0  1
        4   0  0  0  0  0  0  0  1
        3   0  0  0  0  0  0  0  1
        2   0  0  0  0  0  0  0  1
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x7e80808080808000

    };
}
#endif //ROOK_ATTACK_MASKS_H
