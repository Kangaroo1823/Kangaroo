// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//

#include "chess_board.h"



int main() {

    const auto board = std::make_unique<Kangaroo::Chess_Board>(fen_tricky_position_w);
    print_chess_board(board.get());



    return 0;
}
