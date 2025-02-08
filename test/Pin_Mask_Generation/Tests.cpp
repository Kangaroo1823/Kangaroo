// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by U439644 on 1/8/2025.
//


#include "gtest/gtest.h"
#include "Move_Generator/Move_Generator.h"

namespace Kangaroo::Pin_Mask_Generation::Test
{
    Callback_Template_Inline(Dummy) {
    }

    Status_Callback_Template(Compare_Pin_Mask_HV, Chess_Board * board, const Bitboard value, const std::string& str) {
        Move_Generator::Move_Generator<status, CallbackType> gen(board);
        ASSERT_EQ(gen.get_pin_mask_HV(), value) << str;
    }

    Status_Callback_Template(Compare_Pin_Mask_D, Chess_Board * board, const Bitboard value, const std::string& str) {
        Move_Generator::Move_Generator<status, CallbackType> gen(board);
        ASSERT_EQ(gen.get_pin_mask_D(), value) << str;
    }

    Status_Callback_Template(Compare_Pin_Mask_D2, Chess_Board * board, const Bitboard value, const std::string& str) {
        Move_Generator::Move_Generator<status, CallbackType> gen(board);
        print_bitboard(gen.get_pin_mask_D());
        ASSERT_EQ(gen.get_pin_mask_D(), value) << str;
    }

    TEST(Pin_Mask_Generattion, Test) {
        using enum Color;
        using enum Pin_Masks_Suitable_For;

        using namespace Kangaroo::Move_Generator;

        Chess_Board board{};

        auto s = board.reset_board("K7/8/8/P7/P7/8/r7/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>( // -V530
            *s, &board, 0x0, "1st test not true");

        s = board.reset_board("K7/8/8/8/P7/8/r7/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x1010101010100, "2nd test not true");

        s = board.reset_board("k7/8/8/8/P7/8/R7/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x00, "3rd test not true");

        s = board.reset_board("k7/8/8/8/p7/8/R7/8 b - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x1010101010100, "4th test not true");

        s = board.reset_board("K7/8/8/8/P7/8/q7/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x1010101010100, "5th test not true");

        s = board.reset_board("k7/8/8/8/p7/8/Q7/8 b - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x1010101010100, "6th test not true");

        s = board.reset_board("8/q7/8/P7/8/8/8/K7 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x1010101010100, "7th test not true");

        s = board.reset_board("8/Q7/8/p7/8/8/8/k7 b - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x1010101010100, "8th test not true");

        s = board.reset_board("8/r7/8/P7/8/8/8/K7 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x1010101010100, "9th test not true");

        s = board.reset_board("8/R7/8/p7/8/8/8/k7 b - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x1010101010100, "10th test not true");

        s = board.reset_board("8/r7/8/P7/P7/8/8/K7 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x00, "11th test not true");

        s = board.reset_board("8/R7/8/p7/p7/8/8/k7 b - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x00, "12th test not true");

        s = board.reset_board("8/8/R1pp2k1/8/8/8/8/8 b - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x00, "13th test not true");

        s = board.reset_board("8/8/R2p2k1/8/8/8/8/8 b - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x3f0000000000, "14th test not true");

        s = board.reset_board("8/8/r1PP2K1/8/8/8/8/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x0, "15th test not true");

        s = board.reset_board("8/8/r2P2K1/8/8/8/8/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x3f0000000000, "16th test not true");

        s = board.reset_board("8/8/K2P2r1/8/8/8/8/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x7e0000000000, "17th test not true");

        s = board.reset_board("8/8/K1PP2r1/8/8/8/8/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x0, "18th test not true");

        s = board.reset_board("8/8/k2p2R1/8/8/8/8/8 b - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x7e0000000000, "19th test not true");

        s = board.reset_board("8/8/k1pp2R1/8/8/8/8/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x0, "20th test not true");

        s = board.reset_board("8/8/K2P2q1/8/8/8/8/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x7e0000000000, "21th test not true");

        s = board.reset_board("8/8/K1PP2q1/8/8/8/8/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x0, "22th test not true");

        s = board.reset_board("8/8/k2p2Q1/8/8/8/8/8 b - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x7e0000000000, "23th test not true");

        s = board.reset_board("8/8/k1pp2Q1/8/8/8/8/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_HV, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x0, "24th test not true");


        // Bishop tests
        s = board.reset_board("8/1k6/8/3p4/4p3/8/6B/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_D, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x0, "25th test not true");

        s = board.reset_board("8/1k6/8/3p4/8/8/6B/8 b - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_D, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x40810204000, "26th test not true");

        s = board.reset_board("8/1K6/8/3P4/4P3/8/6b/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_D, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x0, "27th test not true");

        s = board.reset_board("8/1K6/8/3P4/8/8/6b/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_D, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x40810204000, "28th test not true");

        s = board.reset_board("8/1k6/8/3p4/4p3/8/6Q/8 b - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_D, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x0, "29th test not true");

        s = board.reset_board("8/1k6/8/3p4/8/8/6Q/8 b - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_D, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x40810204000, "30th test not true");

        s = board.reset_board("8/1K6/8/3P4/4P3/8/6q/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_D, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x0, "31th test not true");

        s = board.reset_board("8/1K6/8/3P4/8/8/6q/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_D, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x40810204000, "32th test not true");

        s = board.reset_board("8/6k1/8/4p3/3p4/8/1B6/8 b - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_D, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x0, "33th test not true");

        s = board.reset_board("8/6k1/8/8/3p4/8/1B6/8 b - - 0 1 ");
        print_chess_board(board);
        execute_status_callback_template<Compare_Pin_Mask_D, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x201008040200, "34th test not true");

        s = board.reset_board("8/6K1/8/4P3/3P4/8/1b6/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_D, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x0, "35th test not true");

        s = board.reset_board("8/6K1/8/8/3P4/8/1b6/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_D, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x201008040200, "36th test not true");

        s = board.reset_board("8/6k1/8/4p3/3p4/8/1Q6/8 b - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_D, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x0, "37th test not true");

        s = board.reset_board("8/6k1/8/8/3p4/8/1Q6/8 b - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_D, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x201008040200, "38th test not true");

        s = board.reset_board("8/6K1/8/4P3/3P4/8/1q6/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_D, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x0, "39th test not true");

        s = board.reset_board("8/6K1/8/8/3P4/8/1q6/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_D, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x201008040200, "40th test not true");

        // should be zero
        s = board.reset_board("8/6K1/8/4p3/3P4/8/1q6/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_D, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x0, "41th test not true");

        s = board.reset_board("8/6K1/8/8/3P4/8/q7/8 w - - 0 1 ");
        execute_status_callback_template<Compare_Pin_Mask_D, Dummy, Chess_Board *, const Bitboard>(// -V530
            *s, &board, 0x0, "42th test not true");
    }
}









