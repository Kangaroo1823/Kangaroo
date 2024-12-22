
#include "magic_numbers.h"

#include <attack_tables.h>
#include <iostream>

#include "chess_board.h"



int main() {

    const auto board = create_chess_board_from_fen(fen_tricky_position);
    print_chess_board(board.get());

    const auto restult = is_position_attacked_by<Color::black>(Position::D4, board.get());
    std::cout << restult << std::endl;

    return 0;
}
