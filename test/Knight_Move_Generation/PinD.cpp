// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by peter on 2/8/25.
//

#include "gtest/gtest.h"
#include "Move_Generator/Move_Generator.h"

namespace Kangaroo::Knight_Move_Generation::PinD {

    Callback_Template_Inline(Pawn_Movement_Generator_Test2_Callback) {
        throw std::runtime_error("No moves should be generated here.");
    }

    Status_Callback_Template(Pawn_Movement_Generator_Test2, Chess_Board* board) {
        Move_Generator::Move_Generator<status, CallbackType> generator(board);
        return generator.generate_knight_movements();
    }



    /**
     * Test that the board below leads to two generated moves.
     */
    TEST(Knight_Move_Generation, PinD) {
        using namespace Kangaroo::Move_Generator;
        using enum Chess_Pieces;
        using enum Color;

        /*
                    A  B  C  D  E  F  G  H

              8    ♚  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  ♞  .  .  .  .  .          half move number:  0
              5    .  .  .  .  .  .  .  .          full move number:  1
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  ♗

                   A  B  C  D  E  F  G  H
        */


        Chess_Board board{};
        const auto status = board.reset_board("K7/8/2N5/8/8/8/8/7b w kqKQ - 0 1");


        const std::size_t n = execute_status_callback_template<Pawn_Movement_Generator_Test2,
            Pawn_Movement_Generator_Test2_Callback>(*status, &board);

        ASSERT_EQ(n, 0);
    }
}
