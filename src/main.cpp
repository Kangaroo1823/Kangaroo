#include <bitset>
#include <iostream>
#include <iso646.h>

#include "bitboard.h"
#include "chess_board.h"
#include "colors.h"


Bitboard create_queen_attack_mask(Position position) {
    Bitboard attacks = 0ULL;

    const int rank = position >> 3;
    const int file = position & 7;

    int r, f;
    for (r = rank + 1, f = file + 1; r < 7 && f < 7; ++r, ++f) attacks |= 1ULL << r * 8 + f;
    for (r = rank + 1, f = file - 1; r < 7 && f > 0; ++r, --f) attacks |= 1ULL << r * 8 + f;
    for (r = rank - 1, f = file - 1; r > 0 && f > 0; --r, --f) attacks |= 1ULL << r * 8 + f;
    for (r = rank - 1, f = file + 1; r > 0 && f < 7; --r, ++f) attacks |= 1ULL << r * 8 + f;

    for (r = rank + 1; r < 7; ++r) attacks |= 1ULL << r * 8 + file;
    for (f = file + 1; f < 7; ++f) attacks |= 1ULL << rank * 8 + f;
    for (r = rank - 1; r > 0; --r) attacks |= 1ULL << r * 8 + file;
    for (f = file - 1; f > 0; --f) attacks |= 1ULL << rank * 8 + f;

    return attacks;
}


Bitboard create_pawn_attacks(unsigned int color, const Position position) {

    Bitboard attacks = 0ULL;

    Bitboard bitboard = set_bit(0ULL, position);

    if (color == black) {
        // color = black
        attacks = attacks | bitboard >> 7 & not_a_file;
        attacks = attacks | bitboard >> 9 & not_h_file;
    } else {
        // color = white
        attacks = attacks | bitboard << 7 & not_h_file;
        attacks = attacks | bitboard << 9 & not_a_file;
    }

    return attacks;
}



int main() {

    for (Position position : All_Positions) {
        const Bitboard board = create_pawn_attacks(black, position);
        print_bitboard(board);
    }

    /*
    for (Position position : All_Positions) {
    // constexpr Position position = E4;
        const Bitboard bitboard = create_queen_attack_mask(position);
        print_bitboard(bitboard);
    }
    */
    return 0;
}

