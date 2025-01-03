// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//

#include "../tools/magic_numbers.h"
#include <../tools/attack_tables.h>
#include "chess_board.h"
#include "move_generator.h"
#include <print>


int main() {

    const auto board = std::make_unique<Kangaroo::Chess_Board>(fen_start_position);

    board->run_move_generation([]([[maybe_unused]] Chess_Pieces chess_piece, [[maybe_unused]] Move move) {
        print_bitboard(move);
    });


    return 0;
}
