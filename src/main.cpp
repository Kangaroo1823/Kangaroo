// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//

#include "Chess_Board.h"

#include "Logger.h"


int main() {

    Kangaroo::Chess_Board board{};
    [[maybe_unused]] auto s = board.reset_board(fen_tricky_position_w);
    print_chess_board(board);


    logger->info("Hello World!");

    return 0;
}
