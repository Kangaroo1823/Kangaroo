// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by peter on 2/8/25.
//

#include "Logger.h"
#include "gtest/gtest.h"
#include "Move_Generator/Move_Generator.h"
#include "spdlog/spdlog.h"

namespace Kangaroo::Pawn_Move_Generation::Promotion1
{


    Callback_Template_Inline(Pawn_Movement_Generator_Test3_Callback, const std::array<Chess_Board, 8> &new_boards,
                             const std::array<Bitboard, 8> &moves) {
        using enum Chess_Pieces;
        using enum Color;

        spdlog::info(format_chess_board(*pac_gen->get_board(), true, status));
        spdlog::info(format_bitboard(move));

        const auto it = std::ranges::find(moves, move);
        if (it == moves.end()) {
            std::stringstream ss;
            ss << "move: 0x" << std::hex << move << " not found in moves";
            throw std::runtime_error(ss.str());
        };


        if (const auto board_it = std::ranges::find(new_boards, *pac_gen->get_board()); board_it == new_boards.end()) {
            std::stringstream ss;
            ss << "board: " << *pac_gen->get_board() << " not found in boards";
            throw std::runtime_error(ss.str());
        }

        if (!pac_gen->get_board()->is_state_consistent()) {
            std::stringstream ss;
            ss << "board: " << *pac_gen->get_board() << " is not consistent";

            throw std::runtime_error(ss.str());
        }
    }

    Status_Callback_Template(Pawn_Movement_Generator_Test3, Chess_Board* board,
                             const std::array<Chess_Board, 8> &chess_boards, const std::array<Bitboard, 8> &moves) {
        Move_Generator::Move_Generator<status, CallbackType> generator(board);
        return generator.generate_pawn_movements(chess_boards, moves);
    }



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


    /**
     * Test that the board below, it is tested that the pawn will promote if it is moved.
     */
    TEST(Pawn_Move_Generation, Promotion1) {
        using namespace Kangaroo::Move_Generator;

        init_logger();
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


        const std::size_t n = execute_status_callback_template<Pawn_Movement_Generator_Test3,
            Pawn_Movement_Generator_Test3_Callback>(*status, &board, new_boards, moves);
        ASSERT_EQ(n, moves.size());
    }
}
