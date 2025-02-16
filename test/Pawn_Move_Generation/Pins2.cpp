// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by peter on 2/8/25.
//

#include "gtest/gtest.h"
#include "Move_Generator/Move_Generator.h"

namespace Kangaroo::Pawn_Move_Generation::Pins2
{
    Callback_Template_Inline(Pawn_Movement_Generator_Test5_Callback, const std::array<Chess_Board, 1> &new_boards,
                             const std::array<Move, 1> &moves)
    {
        if (const auto it = std::ranges::find(moves, move); it == moves.end())
        {
            std::stringstream ss;
            ss << "move: 0x" << std::hex << move << " not found in moves";
            throw std::runtime_error(ss.str());
        };


        if (const auto board_it = std::ranges::find(new_boards, *pac_gen->get_board()); board_it == new_boards.end())
        {
            std::stringstream ss;
            ss << "board: " << *pac_gen->get_board() << " not found in boards";
            throw std::runtime_error(ss.str());
        }

        if (!pac_gen->get_board()->is_state_consistent())
        {
            std::stringstream ss;
            ss << "board: " << *pac_gen->get_board() << " is not consistent";

            throw std::runtime_error(ss.str());
        }
    }

    Status_Callback_Template(Pawn_Movement_Generator_Test5, Chess_Board* board,
                             const std::array<Chess_Board, 1> &chess_boards, const std::array<Bitboard, 1> &moves)
    {
        Move_Generator::Move_Generator<status, CallbackType> generator(board);
        return generator.generate_pawn_movements(chess_boards, moves);
    }

    std::array<Chess_Board, 1> new_boards{
        /*

               A  B  C  D  E  F  G  H

          8    .  .  .  .  .  ♚  .  .
          7    .  .  .  .  .  .  .  .
          6    .  .  .  .  ♗  ♟  .  .
          5    .  .  .  .  .  .  .  .
          4    .  .  .  .  .  .  .  .
          3    .  .  .  .  .  .  .  .
          2    .  .  .  .  .  .  .  .
          1    .  .  .  .  .  ♖  .  .

               A  B  C  D  E  F  G  H

        */
        Kangaroo::Chess_Board(std::array<Bitboard, 15>{
            /* white pawns    */ 0x0000200000000000, /* white knights */ 0x0000000000000000, /* white bishops */
            0x0000000000000000,
            /* white rooks    */ 0x0000000000000000, /* white queens  */ 0x0000000000000000, /* white king    */
            0x2000000000000000,
            /* black pawns    */ 0x0000000000000000, /* black knights */ 0x0000000000000000, /* black bishops */
            0x0000100000000000,
            /* black rooks    */ 0x0000000000000020, /* black queens  */ 0x0000000000000000, /* black king    */
            0x0000000000000000,
            /* en passant sq. */ 0x0000000000000000, /* half move num */ 0x0000000000000000, /* full move num */
            0x0000000000000001
        }),
    };

    std::array<Bitboard, 1> moves{
        /*
            8    .  .  .  .  .  .  .  .
            7    .  .  .  .  .  .  .  .
            6    .  .  .  .  .  1  .  .
            5    .  .  .  .  .  1  .  .
            4    .  .  .  .  .  .  .  .
            3    .  .  .  .  .  .  .  .
            2    .  .  .  .  .  .  .  .
            1    .  .  .  .  .  .  .  .

               A  B  C  D  E  F  G  H

               bitboard as 64 bit integer: */
        0x202000000000,
    };

    // test if vertically pinned pawn moves are generated correctly
    TEST(Pawn_Move_Generation, Pins2)
    {
        using namespace Kangaroo::Move_Generator;

        Chess_Board board{};
        const auto status = board.reset_board("5K2/8/4b3/5P2/8/8/8/5r2 w - - 0 1");

        const std::size_t n = execute_status_callback_template<Pawn_Movement_Generator_Test5,
                                                               Pawn_Movement_Generator_Test5_Callback>(
            *status, &board, new_boards, moves);
        ASSERT_EQ(n, 1);
    }
}
