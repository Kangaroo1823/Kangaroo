//
// Created by peter on 02/12/2024.
//

#ifndef BISHOP_ATTACK_MASKS_H
#define BISHOP_ATTACK_MASKS_H

#include <array>

#include "bitboard.h"

namespace Constants {
    /**
     * @brief Array of 64-bit integers where a bit is set (1) iff a figure there
     * restricts movement of the bishop.
     *
     * The array has 64 elements and is indexed by the position of the bishop on
     * an otherwise empty chess board. At index 0 it is assumed that the bishop is on
     * the square A1, at index 7 the bishop is assumed to be at index H1, at index 8
     * the bishop is at A2, etc.
     *
     * The array is composed of 64-bit unsigned integers. Each bit represents a
     * square of the chess board. If the bit is set (1), it states that another figure
     * at the corresponding square might restrict further movement of the bishop.
     *
     * Note: It is assumed that the bishop can capture the other figure, but cannot go any
     * further in the direction.
     *
     * Otherwise, if a figure at that position does not restrict the bishops' movement the
     * corresponding bit is unset (0). Again it is assumed that the bishop might move to
     * this square
     */
    static constexpr std::array<Bitboard, 64> bishop_attack_masks = {
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  1  0
        6   0  0  0  0  0  1  0  0
        5   0  0  0  0  1  0  0  0
        4   0  0  0  1  0  0  0  0
        3   0  0  1  0  0  0  0  0
        2   0  1  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x40201008040200,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  1  0
        5   0  0  0  0  0  1  0  0
        4   0  0  0  0  1  0  0  0
        3   0  0  0  1  0  0  0  0
        2   0  0  1  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x402010080400,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  1  0
        4   0  0  0  0  0  1  0  0
        3   0  0  0  0  1  0  0  0
        2   0  1  0  1  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x4020100a00,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  1  0
        3   0  1  0  0  0  1  0  0
        2   0  0  1  0  1  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x40221400,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  1  0  0  0  0  0  0
        3   0  0  1  0  0  0  1  0
        2   0  0  0  1  0  1  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x2442800,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  1  0  0  0  0  0  0
        4   0  0  1  0  0  0  0  0
        3   0  0  0  1  0  0  0  0
        2   0  0  0  0  1  0  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x204085000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  1  0  0  0  0  0  0
        5   0  0  1  0  0  0  0  0
        4   0  0  0  1  0  0  0  0
        3   0  0  0  0  1  0  0  0
        2   0  0  0  0  0  1  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x20408102000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  0  0  0  0  0  0
        6   0  0  1  0  0  0  0  0
        5   0  0  0  1  0  0  0  0
        4   0  0  0  0  1  0  0  0
        3   0  0  0  0  0  1  0  0
        2   0  0  0  0  0  0  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x2040810204000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  1  0  0
        6   0  0  0  0  1  0  0  0
        5   0  0  0  1  0  0  0  0
        4   0  0  1  0  0  0  0  0
        3   0  1  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x20100804020000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  1  0
        6   0  0  0  0  0  1  0  0
        5   0  0  0  0  1  0  0  0
        4   0  0  0  1  0  0  0  0
        3   0  0  1  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x40201008040000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  1  0
        5   0  0  0  0  0  1  0  0
        4   0  0  0  0  1  0  0  0
        3   0  1  0  1  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x4020100a0000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  1  0
        4   0  1  0  0  0  1  0  0
        3   0  0  1  0  1  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x4022140000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  1  0  0  0  0  0  0
        4   0  0  1  0  0  0  1  0
        3   0  0  0  1  0  1  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x244280000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  1  0  0  0  0  0  0
        5   0  0  1  0  0  0  0  0
        4   0  0  0  1  0  0  0  0
        3   0  0  0  0  1  0  1  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x20408500000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  0  0  0  0  0  0
        6   0  0  1  0  0  0  0  0
        5   0  0  0  1  0  0  0  0
        4   0  0  0  0  1  0  0  0
        3   0  0  0  0  0  1  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x2040810200000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  1  0  0  0  0  0
        6   0  0  0  1  0  0  0  0
        5   0  0  0  0  1  0  0  0
        4   0  0  0  0  0  1  0  0
        3   0  0  0  0  0  0  1  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x4081020400000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  1  0  0  0
        6   0  0  0  1  0  0  0  0
        5   0  0  1  0  0  0  0  0
        4   0  1  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  1  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x10080402000200,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  1  0  0
        6   0  0  0  0  1  0  0  0
        5   0  0  0  1  0  0  0  0
        4   0  0  1  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  1  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x20100804000400,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  1  0
        6   0  0  0  0  0  1  0  0
        5   0  0  0  0  1  0  0  0
        4   0  1  0  1  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  1  0  1  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x4020100a000a00,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  1  0
        5   0  1  0  0  0  1  0  0
        4   0  0  1  0  1  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  1  0  1  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x402214001400,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  1  0  0  0  0  0  0
        5   0  0  1  0  0  0  1  0
        4   0  0  0  1  0  1  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  1  0  1  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x24428002800,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  0  0  0  0  0  0
        6   0  0  1  0  0  0  0  0
        5   0  0  0  1  0  0  0  0
        4   0  0  0  0  1  0  1  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  1  0  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x2040850005000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  1  0  0  0  0  0
        6   0  0  0  1  0  0  0  0
        5   0  0  0  0  1  0  0  0
        4   0  0  0  0  0  1  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  1  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x4081020002000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  1  0  0  0  0
        6   0  0  0  0  1  0  0  0
        5   0  0  0  0  0  1  0  0
        4   0  0  0  0  0  0  1  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x8102040004000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  1  0  0  0  0
        6   0  0  1  0  0  0  0  0
        5   0  1  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  1  0  0  0  0  0  0
        2   0  0  1  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x8040200020400,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  1  0  0  0
        6   0  0  0  1  0  0  0  0
        5   0  0  1  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  1  0  0  0  0  0
        2   0  0  0  1  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x10080400040800,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  1  0  0
        6   0  0  0  0  1  0  0  0
        5   0  1  0  1  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  1  0  1  0  0  0  0
        2   0  0  0  0  1  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x20100a000a1000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  1  0
        6   0  1  0  0  0  1  0  0
        5   0  0  1  0  1  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  1  0  1  0  0  0
        2   0  1  0  0  0  1  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x40221400142200,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  0  0  0  0  0  0
        6   0  0  1  0  0  0  1  0
        5   0  0  0  1  0  1  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  1  0  1  0  0
        2   0  0  1  0  0  0  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x2442800284400,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  1  0  0  0  0  0
        6   0  0  0  1  0  0  0  0
        5   0  0  0  0  1  0  1  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  1  0  1  0
        2   0  0  0  1  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x4085000500800,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  1  0  0  0  0
        6   0  0  0  0  1  0  0  0
        5   0  0  0  0  0  1  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  1  0  0
        2   0  0  0  0  1  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x8102000201000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  1  0  0  0
        6   0  0  0  0  0  1  0  0
        5   0  0  0  0  0  0  1  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  1  0
        2   0  0  0  0  0  1  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x10204000402000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  1  0  0  0  0  0
        6   0  1  0  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  1  0  0  0  0  0  0
        3   0  0  1  0  0  0  0  0
        2   0  0  0  1  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x4020002040800,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  1  0  0  0  0
        6   0  0  1  0  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  1  0  0  0  0  0
        3   0  0  0  1  0  0  0  0
        2   0  0  0  0  1  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x8040004081000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  1  0  0  0
        6   0  1  0  1  0  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  1  0  1  0  0  0  0
        3   0  0  0  0  1  0  0  0
        2   0  0  0  0  0  1  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x100a000a102000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  0  0  0  1  0  0
        6   0  0  1  0  1  0  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  1  0  1  0  0  0
        3   0  1  0  0  0  1  0  0
        2   0  0  0  0  0  0  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x22140014224000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  1  0  0  0  1  0
        6   0  0  0  1  0  1  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  1  0  1  0  0
        3   0  0  1  0  0  0  1  0
        2   0  1  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x44280028440200,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  1  0  0  0  0
        6   0  0  0  0  1  0  1  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  1  0  1  0
        3   0  0  0  1  0  0  0  0
        2   0  0  1  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x8500050080400,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  1  0  0  0
        6   0  0  0  0  0  1  0  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  1  0  0
        3   0  0  0  0  1  0  0  0
        2   0  0  0  1  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x10200020100800,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  1  0  0
        6   0  0  0  0  0  0  1  0
        5   0  0  0  0  0  0  0  0
        4   0  0  0  0  0  0  1  0
        3   0  0  0  0  0  1  0  0
        2   0  0  0  0  1  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x20400040201000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  0  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  1  0  0  0  0  0  0
        4   0  0  1  0  0  0  0  0
        3   0  0  0  1  0  0  0  0
        2   0  0  0  0  1  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x2000204081000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  1  0  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  1  0  0  0  0  0
        4   0  0  0  1  0  0  0  0
        3   0  0  0  0  1  0  0  0
        2   0  0  0  0  0  1  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x4000408102000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  0  1  0  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  1  0  1  0  0  0  0
        4   0  0  0  0  1  0  0  0
        3   0  0  0  0  0  1  0  0
        2   0  0  0  0  0  0  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0xa000a10204000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  1  0  1  0  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  1  0  1  0  0  0
        4   0  1  0  0  0  1  0  0
        3   0  0  0  0  0  0  1  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x14001422400000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  1  0  1  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  1  0  1  0  0
        4   0  0  1  0  0  0  1  0
        3   0  1  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x28002844020000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  1  0  1  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  1  0  1  0
        4   0  0  0  1  0  0  0  0
        3   0  0  1  0  0  0  0  0
        2   0  1  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x50005008040200,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  1  0  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  1  0  0
        4   0  0  0  0  1  0  0  0
        3   0  0  0  1  0  0  0  0
        2   0  0  1  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x20002010080400,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  1  0
        6   0  0  0  0  0  0  0  0
        5   0  0  0  0  0  0  1  0
        4   0  0  0  0  0  1  0  0
        3   0  0  0  0  1  0  0  0
        2   0  0  0  1  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x40004020100800,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  1  0  0  0  0  0  0
        5   0  0  1  0  0  0  0  0
        4   0  0  0  1  0  0  0  0
        3   0  0  0  0  1  0  0  0
        2   0  0  0  0  0  1  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x20408102000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  1  0  0  0  0  0
        5   0  0  0  1  0  0  0  0
        4   0  0  0  0  1  0  0  0
        3   0  0  0  0  0  1  0  0
        2   0  0  0  0  0  0  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x40810204000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  1  0  1  0  0  0  0
        5   0  0  0  0  1  0  0  0
        4   0  0  0  0  0  1  0  0
        3   0  0  0  0  0  0  1  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0xa1020400000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  1  0  1  0  0  0
        5   0  1  0  0  0  1  0  0
        4   0  0  0  0  0  0  1  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x142240000000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  1  0  1  0  0
        5   0  0  1  0  0  0  1  0
        4   0  1  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x284402000000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  1  0  1  0
        5   0  0  0  1  0  0  0  0
        4   0  0  1  0  0  0  0  0
        3   0  1  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x500804020000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  1  0  0
        5   0  0  0  0  1  0  0  0
        4   0  0  0  1  0  0  0  0
        3   0  0  1  0  0  0  0  0
        2   0  1  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x201008040200,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  0  0
        6   0  0  0  0  0  0  1  0
        5   0  0  0  0  0  1  0  0
        4   0  0  0  0  1  0  0  0
        3   0  0  0  1  0  0  0  0
        2   0  0  1  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x402010080400,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  0  0  0  0  0  0
        6   0  0  1  0  0  0  0  0
        5   0  0  0  1  0  0  0  0
        4   0  0  0  0  1  0  0  0
        3   0  0  0  0  0  1  0  0
        2   0  0  0  0  0  0  1  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x2040810204000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  1  0  0  0  0  0
        6   0  0  0  1  0  0  0  0
        5   0  0  0  0  1  0  0  0
        4   0  0  0  0  0  1  0  0
        3   0  0  0  0  0  0  1  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x4081020400000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  1  0  1  0  0  0  0
        6   0  0  0  0  1  0  0  0
        5   0  0  0  0  0  1  0  0
        4   0  0  0  0  0  0  1  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0xa102040000000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  1  0  1  0  0  0
        6   0  1  0  0  0  1  0  0
        5   0  0  0  0  0  0  1  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x14224000000000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  1  0  1  0  0
        6   0  0  1  0  0  0  1  0
        5   0  1  0  0  0  0  0  0
        4   0  0  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x28440200000000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  1  0  1  0
        6   0  0  0  1  0  0  0  0
        5   0  0  1  0  0  0  0  0
        4   0  1  0  0  0  0  0  0
        3   0  0  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x50080402000000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  1  0  0
        6   0  0  0  0  1  0  0  0
        5   0  0  0  1  0  0  0  0
        4   0  0  1  0  0  0  0  0
        3   0  1  0  0  0  0  0  0
        2   0  0  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x20100804020000,
        /*
        8   0  0  0  0  0  0  0  0
        7   0  0  0  0  0  0  1  0
        6   0  0  0  0  0  1  0  0
        5   0  0  0  0  1  0  0  0
        4   0  0  0  1  0  0  0  0
        3   0  0  1  0  0  0  0  0
        2   0  1  0  0  0  0  0  0
        1   0  0  0  0  0  0  0  0
        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x40201008040200
    };
}
#endif //BISHOP_ATTACK_MASKS_H
