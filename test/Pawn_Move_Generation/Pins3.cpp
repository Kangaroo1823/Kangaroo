// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by peter on 2/8/25.
//

#include "gtest/gtest.h"
#include "Move_Generator/Move_Generator.h"

namespace Kangaroo::Pawn_Move_Generation::Pins3 {




    Callback_Template_Inline(Pawn_Movement_Generator_Test6_Callback) {
        throw std::runtime_error("no moves should be generated here..");
    }

    Status_Callback_Template(Pawn_Movement_Generator_Test6, Chess_Board* board) {
        Move_Generator::Move_Generator<status, CallbackType> generator(board);
        return generator.generate_pawn_movements();
    }


    // test that horizontally pinned pawns cannot move.
    TEST(Pawn_Move_Generation, Pins3) {
        using namespace Kangaroo::Move_Generator;

        Chess_Board board{};
        const auto status = board.reset_board("8/8/8/8/2b5/r2P3K/8/8 w - - 0 1");


        const std::size_t n = execute_status_callback_template<Pawn_Movement_Generator_Test6,
            Pawn_Movement_Generator_Test6_Callback>(*status, &board);
        ASSERT_EQ(n, 0);
    }


}