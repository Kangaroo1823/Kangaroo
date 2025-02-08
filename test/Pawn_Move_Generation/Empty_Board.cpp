// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by peter on 2/8/25.
//

#include "gtest/gtest.h"
#include "Move_Generator/Move_Generator.h"

namespace Kangaroo::Pawn_Move_Generation::Empty_Board
{
    Callback_Template_Inline(Dummy)
    {
    }

    Status_Callback_Template(Pawn_Movement_Generator_Test1, Chess_Board* board)
    {
        Move_Generator::Move_Generator<status, CallbackType> generator(board);
        return generator.generate_pawn_movements();
    }


    /**
     * Test if the empty board leads to no generated moves.
     */
    TEST(Pawn_Move_Generation, Empty_Board)
    {
        Chess_Board board{};
        const std::unique_ptr<Board_Status> status = board.reset_board("8/8/8/8/8/8/8/8 w - - 0 1");
        const auto number_of_moves = execute_status_callback_template<Pawn_Movement_Generator_Test1, Dummy,
                                                                      Chess_Board*>(*status, &board);
        ASSERT_EQ(number_of_moves, 0);
    }
}
