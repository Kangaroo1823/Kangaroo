// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by peter on 2/8/25.
//

#include "gtest/gtest.h"
#include "Move_Generator/Move_Generator.h"

namespace Kangaroo::Pawn_Move_Generation::Check1
{


    Callback_Template_Inline(Pawn_Movement_Generator_Test11_Callback, const std::array<Chess_Board, 1> &new_boards) {

        print_chess_board(*board, true);


        if (status.color_to_move != Color::White) {
            throw std::runtime_error("color should be black");
        }

        if (chess_piece != Chess_Pieces::Pawn) {
            throw std::runtime_error("chess piece should be pawn");
        }
        
        if (std::ranges::find(new_boards, *board) == new_boards.end()) {
            throw std::runtime_error("board not found in new_boards");
        }
    }

    Status_Callback_Template(Pawn_Movement_Generator_Test11, Chess_Board* board,
                             const std::array<Chess_Board, 1> &chess_boards) {
        Move_Generator::Move_Generator<status, CallbackType> generator(board);
        return generator.generate_pawn_movements(chess_boards);
    }



    std::array<Chess_Board, 1> new_boards{
        /*

               A  B  C  D  E  F  G  H

          8    .  .  .  .  .  .  .  .
          7    .  .  .  .  .  .  .  .
          6    .  .  .  .  .  .  .  .          half move number:  0
          5    .  .  .  .  .  .  .  .          full move number:  1
          4    ♚  .  .  ♟  .  .  .  ♖
          3    .  .  .  .  .  .  .  .
          2    .  .  .  .  .  .  .  .
          1    .  .  .  .  .  .  .  .

               A  B  C  D  E  F  G  H

        */
        Kangaroo::Chess_Board( std::array<Bitboard, 15>{
          /* white pawns    */ 0x0000000008000000, /* white knights */ 0x0000000000000000, /* white bishops */ 0x0000000000000000,
          /* white rooks    */ 0x0000000000000000, /* white queens  */ 0x0000000000000000, /* white king    */ 0x0000000001000000,
          /* black pawns    */ 0x0000000000000000, /* black knights */ 0x0000000000000000, /* black bishops */ 0x0000000000000000,
          /* black rooks    */ 0x0000000080000000, /* black queens  */ 0x0000000000000000, /* black king    */ 0x0000000000000000,
          /* en passant sq. */ 0x0000000000000000, /* half move num */ 0x0000000000000000, /* full move num */ 0x0000000000000001 }),
    };

    TEST(Pawn_Move_Generation, Check1)
    {
        using namespace Kangaroo::Move_Generator;

        /*
                    A  B  C  D  E  F  G  H

              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .          half move number:  0
              5    .  .  .  .  .  .  .  .          full move number:  1
              4    ♚  .  .  .  .  .  .  ♖
              3    .  .  .  .  .  .  .  .
              2    .  .  .  ♟  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

         */

        Chess_Board board{};
        const auto status = board.reset_board("8/8/8/8/K6r/8/3P4/8 w kqKQ - 0 1");

        print_chess_board(board);

        const std::size_t n = execute_status_callback_template<Pawn_Movement_Generator_Test11,
        Pawn_Movement_Generator_Test11_Callback>(*status, &board, new_boards);
        ASSERT_EQ(n, new_boards.size());
    }
}
