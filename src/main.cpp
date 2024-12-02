

#include "../include/bitboard.h"
#include "../include/create_occupantion_of_mask.h"




int main() {

    Position position = E4;
    Bitboard mask = 0ULL;

    mask = set_bit(mask, A2);
    mask = set_bit(mask, A3);
    mask = set_bit(mask, A4);
    mask = set_bit(mask, B1);
    mask = set_bit(mask, C1);
    mask = set_bit(mask, D1);

    for (int occupancy = 0; occupancy < 64; occupancy++) {
        const Bitboard board = create_occupation_of_mask(occupancy, mask);
        print_bitboard(board);
    }

    return 0;
}

