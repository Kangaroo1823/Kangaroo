// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by U439644 on 1/8/2025.
//

#include <bitset>

#include "Movement_Generator.h"
#include "gtest/gtest.h"
#include "move_generator.h"

namespace Kangaroo {
    TEST(Movement_Generator_Test, test_pin_masks_generator) {
        using enum Color;
        using enum Pin_Masks_Suitable_For;

        Chess_Board board("K7/8/8/P7/P7/8/r7/8 w - - 0 1 ");
        Movement_Generator gen(&board);
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0) << "1st test not true";

        void(board.reset_board("K7/8/8/8/P7/8/r7/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x1010101010100) << "2nd test not true";

        void(board.reset_board("k7/8/8/8/P7/8/R7/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0) << "3rd test not true";

        void(board.reset_board("k7/8/8/8/p7/8/R7/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x1010101010100) << "4th test not true";


        void(board.reset_board("K7/8/8/8/P7/8/q7/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x1010101010100) << "5th test not true";

        void(board.reset_board("k7/8/8/8/p7/8/Q7/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x1010101010100) << "6th test not true";


        void(board.reset_board("8/q7/8/P7/8/8/8/K7 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x1010101010100) << "7th test not true";

        void(board.reset_board("8/Q7/8/p7/8/8/8/k7 w - - 0 1 ")); // -V530
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x1010101010100) << "8th test not true";

        void(board.reset_board("8/r7/8/P7/8/8/8/K7 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x1010101010100) << "9th test not true";

        void(board.reset_board("8/R7/8/p7/8/8/8/k7 w - - 0 1 ")); // -V530
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x1010101010100) << "10th test not true";

        void(board.reset_board("8/r7/8/P7/P7/8/8/K7 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x0) << "11th test not true";

        void(board.reset_board("8/R7/8/p7/p7/8/8/k7 w - - 0 1 ")); // -V530
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x0) << "12th test not true";

        void(board.reset_board("8/8/R1pp2k1/8/8/8/8/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x0) << "13th test not true";

        void(board.reset_board("8/8/R2p2k1/8/8/8/8/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x3f0000000000) << "14th test not true";

        void(board.reset_board("8/8/r1PP2K1/8/8/8/8/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x0) << "15th test not true";

        void(board.reset_board("8/8/r2P2K1/8/8/8/8/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x3f0000000000) << "16th test not true";


        void(board.reset_board("8/8/K2P2r1/8/8/8/8/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x7e0000000000) << "17th test not true";

        void(board.reset_board("8/8/K1PP2r1/8/8/8/8/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x0) << "18th test not true";

        void(board.reset_board("8/8/k2p2R1/8/8/8/8/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x7e0000000000) << "19th test not true";

        void(board.reset_board("8/8/k1pp2R1/8/8/8/8/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x0) << "20th test not true";

        void(board.reset_board("8/8/K2P2q1/8/8/8/8/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x7e0000000000) << "21th test not true";

        void(board.reset_board("8/8/K1PP2q1/8/8/8/8/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x0) << "22th test not true";

        void(board.reset_board("8/8/k2p2Q1/8/8/8/8/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x7e0000000000) << "23th test not true";

        void(board.reset_board("8/8/k1pp2Q1/8/8/8/8/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_HV, 0x0) << "24th test not true";

        // Bishop tests

        void(board.reset_board("8/1k6/8/3p4/4p3/8/6B/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x00) << "25th test not true";

        void(board.reset_board("8/1k6/8/3p4/8/8/6B/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x40810204000) << "26th test not true";

        void(board.reset_board("8/1K6/8/3P4/4P3/8/6b/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x00) << "27th test not true";

        void(board.reset_board("8/1K6/8/3P4/8/8/6b/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x40810204000) << "28th test not true";

        void(board.reset_board("8/1k6/8/3p4/4p3/8/6Q/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x00) << "29th test not true";

        void(board.reset_board("8/1k6/8/3p4/8/8/6Q/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x40810204000) << "30th test not true";

        void(board.reset_board("8/1K6/8/3P4/4P3/8/6q/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x00) << "31th test not true";

        void(board.reset_board("8/1K6/8/3P4/8/8/6q/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x40810204000) << "32th test not true";


        void(board.reset_board("8/6k1/8/4p3/3p4/8/1B6/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x00) << "25th test not true";

        void(board.reset_board("8/6k1/8/8/3p4/8/1B6/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x201008040200) << "25th test not true";

        void(board.reset_board("8/6K1/8/4P3/3P4/8/1b6/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x00) << "25th test not true";

        void(board.reset_board("8/6K1/8/8/3P4/8/1b6/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x201008040200) << "25th test not true";

        void(board.reset_board("8/6k1/8/4p3/3p4/8/1Q6/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x00) << "25th test not true";

        void(board.reset_board("8/6k1/8/8/3p4/8/1Q6/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<Black, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x201008040200) << "25th test not true";

        void(board.reset_board("8/6K1/8/4P3/3P4/8/1q6/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x00) << "25th test not true";

        void(board.reset_board("8/6K1/8/8/3P4/8/1q6/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x201008040200) << "25th test not true";

        // should be zero
        void(board.reset_board("8/6K1/8/4p3/3P4/8/1q6/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x0) << "25th test not true";

        void(board.reset_board("8/6K1/8/8/3P4/8/q7/8 w - - 0 1 ")); // -V530
        gen.build_pin_masks<White, Detecting_Pins>();
        ASSERT_EQ(gen.pin_mask_D, 0x0) << "25th test not true";
    }


    /**
     * Test if the empty board leads to no generated moves.
     */
    void pawn_movement_generator_test1() {
        Chess_Board board{};
        std::unique_ptr<Board_Status> status = board.reset_board("8/8/8/8/8/8/8/8 w - - 0 1");
        Movement_Generator gen(&board);

        // empty board results in no moves generated
        auto number_of_moves = status->run_move_generation(gen,
                                                           []([[maybe_unused]] const Chess_Board &new_board,
                                                              [[maybe_unused]] const Move move,
                                                              [[maybe_unused]] const Color color,
                                                              [[maybe_unused]] const Chess_Pieces chess_piece) -> bool {
                                                               return true;
                                                           });
        ASSERT_EQ(number_of_moves, 0);
    }


    /**
     * Test that the board below leads to two generated moves.
     */
    void pawn_movement_generator_test2() {
        /*
                    A  B  C  D  E  F  G  H

               8    .  .  .  .  .  .  .  .
               7    .  .  ♖  .  .  .  .  .
               6    .  .  .  ♟  .  .  .  .
               5    .  .  .  .  .  .  .  .
               4    .  .  .  .  .  .  .  .
               3    .  .  .  .  .  .  .  .
               2    .  .  .  .  .  .  .  .
               1    .  .  .  .  .  .  .  .

                    A  B  C  D  E  F  G  H
      */

        Chess_Board board{};
        const auto status = board.reset_board("8/2r5/3P4/8/8/8/8/8 w - - 0 1");
        Movement_Generator gen(&board);


        std::array<Chess_Board, 2> new_boards = {
            /*

                       A  B  C  D  E  F  G  H

                  8    .  .  .  .  .  .  .  .
                  7    .  .  ♖  ♟  .  .  .  .
                  6    .  .  .  .  .  .  .  .
                  5    .  .  .  .  .  .  .  .
                  4    .  .  .  .  .  .  .  .
                  3    .  .  .  .  .  .  .  .
                  2    .  .  .  .  .  .  .  .
                  1    .  .  .  .  .  .  .  .

                       A  B  C  D  E  F  G  H

                */
            Chess_Board(std::array<Bitboard, 15>{
                /* white pawns    */ 0x0008000000000000, /* white knights */ 0x0000000000000000, /* white bishops */
                0x0000000000000000,
                /* white rooks    */ 0x0000000000000000, /* white queens  */ 0x0000000000000000, /* white king    */
                0x0000000000000000,
                /* black pawns    */ 0x0000000000000000, /* black knights */ 0x0000000000000000, /* black bishops */
                0x0000000000000000,
                /* black rooks    */ 0x0004000000000000, /* black queens  */ 0x0000000000000000, /* black king    */
                0x0000000000000000,
                /* en passant sq. */ 0x0000000000000000, /* half move num */ 0x0000000000000000, /* full move num */
                0x0000000000000001
            }),
            /*

                   A  B  C  D  E  F  G  H

              8    .  .  .  .  .  .  .  .
              7    .  .  ♟  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

            */
            Kangaroo::Chess_Board(std::array<Bitboard, 15>{
                /* white pawns    */ 0x0004000000000000, /* white knights */ 0x0000000000000000, /* white bishops */
                0x0000000000000000,
                /* white rooks    */ 0x0000000000000000, /* white queens  */ 0x0000000000000000, /* white king    */
                0x0000000000000000,
                /* black pawns    */ 0x0000000000000000, /* black knights */ 0x0000000000000000, /* black bishops */
                0x0000000000000000,
                /* black rooks    */ 0x0000000000000000, /* black queens  */ 0x0000000000000000, /* black king    */
                0x0000000000000000,
                /* en passant sq. */ 0x0000000000000000, /* half move num */ 0x0000000000000000, /* full move num */
                0x0000000000000001
            }),
        };

        std::array<Bitboard, 2> moves = {
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  1  .  .  .  .
              6    .  .  .  1  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x8080000000000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  1  .  .  .  .  .
              6    .  .  .  1  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x4080000000000,
        };


        auto f = [&moves, &new_boards]([[maybe_unused]] const Chess_Board &new_board, [[maybe_unused]] const Move
                                       move, [[maybe_unused]] const Color color,
                                       [[maybe_unused]] const Chess_Pieces chess_piece)-> bool {
            const auto it = std::ranges::find(moves, move);
            if (it == moves.end()) {
                std::stringstream ss;
                ss << "move: 0x" << std::hex << move << " not found in moves";
                throw std::runtime_error(ss.str());
            };

            const auto board_it = std::ranges::find(new_boards, new_board);
            if (board_it == new_boards.end()) {
                std::stringstream ss;
                ss << "board: " << new_board << " not found in boards";
                throw std::runtime_error(ss.str());
            }

            if (!new_board.is_state_consistent()) {
                std::stringstream ss;
                ss << "board: " << std::endl << new_board << " is not consistent." << std::endl;
                ss << "--- details of board: ---------------------------------------------------" << std::endl;
                ss << "   white pawns:    " << format_bitboard(new_board.white_pawns) << std::endl;
                ss << "   black pawns:    " << format_bitboard(new_board.black_pawns) << std::endl;
                ss << "   white knights:  " << format_bitboard(new_board.white_knights) << std::endl;
                ss << "   black knights:  " << format_bitboard(new_board.black_knights) << std::endl;
                ss << "   white bishops:  " << format_bitboard(new_board.white_bishops) << std::endl;
                ss << "   black bishops:  " << format_bitboard(new_board.black_bishops) << std::endl;
                ss << "   white rooks:    " << format_bitboard(new_board.white_rooks) << std::endl;
                ss << "   black rooks:    " << format_bitboard(new_board.black_rooks) << std::endl;
                ss << "   white queens:   " << format_bitboard(new_board.white_queens) << std::endl;
                ss << "   black queens:   " << format_bitboard(new_board.black_queens) << std::endl;
                ss << "   white king:     " << format_bitboard(new_board.white_king) << std::endl;
                ss << "   black king:     " << format_bitboard(new_board.black_king) << std::endl;
                ss << "   white pieces:   " << format_bitboard(new_board.white_pieces) << std::endl;
                ss << "   black pieces:   " << format_bitboard(new_board.black_pieces) << std::endl;
                ss << "   all pieces:     " << format_bitboard(new_board.all_pieces) << std::endl;
                ss << "   en passant sq.: " << format_bitboard(new_board.en_passant_square) << std::endl;
                ss << "-------------------------------------------------------------------------" << std::endl;
                throw std::runtime_error(ss.str());
            }

            return false;
        };

        const auto n = status->run_move_generation(gen, f);
        ASSERT_EQ(n, moves.size());
    }

    /**
     * Test that the board below, it is tested that the pawn will promote if it is moved.
     */
    void pawn_movement_generator_test3() {
        /*
            A  B  C  D  E  F  G  H

       8    .  .  ♖  .  .  .  .  .
       7    .  .  .  ♟  .  .  .  .
       6    .  .  .  .  .  .  .  .
       5    .  .  .  .  .  .  .  .
       4    .  .  .  .  .  .  .  .
       3    .  .  .  .  .  .  .  .
       2    .  .  .  .  .  .  .  .
       1    .  .  .  .  .  .  .  .

            A  B  C  D  E  F  G  H
*/

        Chess_Board board{};
        const auto status = board.reset_board("2r5/3P4/8/8/8/8/8/8 w - - 0 1");
        Movement_Generator gen(&board);


        [[maybe_unused]] constexpr std::array<Chess_Board, 8> new_boards = {
            /*

                   A  B  C  D  E  F  G  H

              8    .  .  ♖  ♛  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

            */
            Kangaroo::Chess_Board(std::array<Bitboard, 15>{
                /* white pawns    */ 0x0000000000000000, /* white knights */ 0x0000000000000000, /* white bishops */
                0x0000000000000000,
                /* white rooks    */ 0x0000000000000000, /* white queens  */ 0x0800000000000000, /* white king    */
                0x0000000000000000,
                /* black pawns    */ 0x0000000000000000, /* black knights */ 0x0000000000000000, /* black bishops */
                0x0000000000000000,
                /* black rooks    */ 0x0400000000000000, /* black queens  */ 0x0000000000000000, /* black king    */
                0x0000000000000000,
                /* en passant sq. */ 0x0000000000000000, /* half move num */ 0x0000000000000000, /* full move num */
                0x0000000000000001
            }),
            /*

                   A  B  C  D  E  F  G  H

              8    .  .  ♖  ♝  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

            */
            Kangaroo::Chess_Board(std::array<Bitboard, 15>{
                /* white pawns    */ 0x0000000000000000, /* white knights */ 0x0000000000000000, /* white bishops */
                0x0800000000000000,
                /* white rooks    */ 0x0000000000000000, /* white queens  */ 0x0000000000000000, /* white king    */
                0x0000000000000000,
                /* black pawns    */ 0x0000000000000000, /* black knights */ 0x0000000000000000, /* black bishops */
                0x0000000000000000,
                /* black rooks    */ 0x0400000000000000, /* black queens  */ 0x0000000000000000, /* black king    */
                0x0000000000000000,
                /* en passant sq. */ 0x0000000000000000, /* half move num */ 0x0000000000000000, /* full move num */
                0x0000000000000001
            }),
            /*

                   A  B  C  D  E  F  G  H

              8    .  .  ♖  ♞  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

            */
            Kangaroo::Chess_Board(std::array<Bitboard, 15>{
                /* white pawns    */ 0x0000000000000000, /* white knights */ 0x0800000000000000, /* white bishops */
                0x0000000000000000,
                /* white rooks    */ 0x0000000000000000, /* white queens  */ 0x0000000000000000, /* white king    */
                0x0000000000000000,
                /* black pawns    */ 0x0000000000000000, /* black knights */ 0x0000000000000000, /* black bishops */
                0x0000000000000000,
                /* black rooks    */ 0x0400000000000000, /* black queens  */ 0x0000000000000000, /* black king    */
                0x0000000000000000,
                /* en passant sq. */ 0x0000000000000000, /* half move num */ 0x0000000000000000, /* full move num */
                0x0000000000000001
            }),
            /*

                   A  B  C  D  E  F  G  H

              8    .  .  ♖  ♜  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

            */
            Kangaroo::Chess_Board(std::array<Bitboard, 15>{
                /* white pawns    */ 0x0000000000000000, /* white knights */ 0x0000000000000000, /* white bishops */
                0x0000000000000000,
                /* white rooks    */ 0x0800000000000000, /* white queens  */ 0x0000000000000000, /* white king    */
                0x0000000000000000,
                /* black pawns    */ 0x0000000000000000, /* black knights */ 0x0000000000000000, /* black bishops */
                0x0000000000000000,
                /* black rooks    */ 0x0400000000000000, /* black queens  */ 0x0000000000000000, /* black king    */
                0x0000000000000000,
                /* en passant sq. */ 0x0000000000000000, /* half move num */ 0x0000000000000000, /* full move num */
                0x0000000000000001
            }),
            /*

                   A  B  C  D  E  F  G  H

              8    .  .  ♛  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

            */
            Kangaroo::Chess_Board(std::array<Bitboard, 15>{
                /* white pawns    */ 0x0000000000000000, /* white knights */ 0x0000000000000000, /* white bishops */
                0x0000000000000000,
                /* white rooks    */ 0x0000000000000000, /* white queens  */ 0x0400000000000000, /* white king    */
                0x0000000000000000,
                /* black pawns    */ 0x0000000000000000, /* black knights */ 0x0000000000000000, /* black bishops */
                0x0000000000000000,
                /* black rooks    */ 0x0000000000000000, /* black queens  */ 0x0000000000000000, /* black king    */
                0x0000000000000000,
                /* en passant sq. */ 0x0000000000000000, /* half move num */ 0x0000000000000000, /* full move num */
                0x0000000000000001
            }),
            /*

                   A  B  C  D  E  F  G  H

              8    .  .  ♝  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

            */
            Kangaroo::Chess_Board(std::array<Bitboard, 15>{
                /* white pawns    */ 0x0000000000000000, /* white knights */ 0x0000000000000000, /* white bishops */
                0x0400000000000000,
                /* white rooks    */ 0x0000000000000000, /* white queens  */ 0x0000000000000000, /* white king    */
                0x0000000000000000,
                /* black pawns    */ 0x0000000000000000, /* black knights */ 0x0000000000000000, /* black bishops */
                0x0000000000000000,
                /* black rooks    */ 0x0000000000000000, /* black queens  */ 0x0000000000000000, /* black king    */
                0x0000000000000000,
                /* en passant sq. */ 0x0000000000000000, /* half move num */ 0x0000000000000000, /* full move num */
                0x0000000000000001
            }),
            /*

                   A  B  C  D  E  F  G  H

              8    .  .  ♞  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

            */
            Kangaroo::Chess_Board(std::array<Bitboard, 15>{
                /* white pawns    */ 0x0000000000000000, /* white knights */ 0x0400000000000000, /* white bishops */
                0x0000000000000000,
                /* white rooks    */ 0x0000000000000000, /* white queens  */ 0x0000000000000000, /* white king    */
                0x0000000000000000,
                /* black pawns    */ 0x0000000000000000, /* black knights */ 0x0000000000000000, /* black bishops */
                0x0000000000000000,
                /* black rooks    */ 0x0000000000000000, /* black queens  */ 0x0000000000000000, /* black king    */
                0x0000000000000000,
                /* en passant sq. */ 0x0000000000000000, /* half move num */ 0x0000000000000000, /* full move num */
                0x0000000000000001
            }),
            /*

                   A  B  C  D  E  F  G  H

              8    .  .  ♜  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

            */
            Kangaroo::Chess_Board(std::array<Bitboard, 15>{
                /* white pawns    */ 0x0000000000000000, /* white knights */ 0x0000000000000000, /* white bishops */
                0x0000000000000000,
                /* white rooks    */ 0x0400000000000000, /* white queens  */ 0x0000000000000000, /* white king    */
                0x0000000000000000,
                /* black pawns    */ 0x0000000000000000, /* black knights */ 0x0000000000000000, /* black bishops */
                0x0000000000000000,
                /* black rooks    */ 0x0000000000000000, /* black queens  */ 0x0000000000000000, /* black king    */
                0x0000000000000000,
                /* en passant sq. */ 0x0000000000000000, /* half move num */ 0x0000000000000000, /* full move num */
                0x0000000000000001
            }),
        };

        [[maybe_unused]] constexpr std::array<Bitboard, 8> moves = {
            /*
  8    .  .  .  1  .  .  .  .
  7    .  .  .  1  .  .  .  .
  6    .  .  .  .  .  .  .  .
  5    .  .  .  .  .  .  .  .
  4    .  .  .  .  .  .  .  .
  3    .  .  .  .  .  .  .  .
  2    .  .  .  .  .  .  .  .
  1    .  .  .  .  .  .  .  .

       A  B  C  D  E  F  G  H

       bitboard as 64 bit integer: */
            0x808000000000000,
            /*
              8    .  .  .  1  .  .  .  .
              7    .  .  .  1  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x808000000000000,
            /*
              8    .  .  .  1  .  .  .  .
              7    .  .  .  1  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x808000000000000,
            /*
              8    .  .  .  1  .  .  .  .
              7    .  .  .  1  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x808000000000000,
            /*
              8    .  .  1  .  .  .  .  .
              7    .  .  .  1  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x408000000000000,
            /*
              8    .  .  1  .  .  .  .  .
              7    .  .  .  1  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x408000000000000,
            /*
              8    .  .  1  .  .  .  .  .
              7    .  .  .  1  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x408000000000000,
            /*
              8    .  .  1  .  .  .  .  .
              7    .  .  .  1  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x408000000000000,

        };


        auto f = [&new_boards, &moves]([[maybe_unused]] const Chess_Board &new_board, [[maybe_unused]] const Move
                               move, [[maybe_unused]] const Color color,
                               [[maybe_unused]] const Chess_Pieces chess_piece)-> bool {

            const auto it = std::ranges::find(moves, move);
            if (it == moves.end()) {
                std::stringstream ss;
                ss << "move: 0x" << std::hex << move << " not found in moves";
                throw std::runtime_error(ss.str());
            };


            if (const auto board_it = std::ranges::find(new_boards, new_board); board_it == new_boards.end()) {
                std::stringstream ss;
                ss << "board: " << new_board << " not found in boards";
                throw std::runtime_error(ss.str());
            }

            if (!new_board.is_state_consistent()) {
                std::stringstream ss;
                ss << "board: " << new_board << " is not consistent";

                throw std::runtime_error(ss.str());
            }
            return false;
        };

        const auto n = status->run_move_generation(gen, f);
        ASSERT_EQ(n, moves.size());
    }

    TEST(Movement_Generator_Test, test_pawn_movement_generator) {
        // empty board leads to no generated moves
        pawn_movement_generator_test1();

        // simple board leads to two generated moves.
        pawn_movement_generator_test2();

        // test that promotion generation works.
        pawn_movement_generator_test3();
    }
}
