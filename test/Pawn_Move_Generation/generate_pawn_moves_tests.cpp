// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by peter on 03/01/2025.
//

#include <ranges>
#include <algorithm>

#include "Logger.h"
#include "../../include/Chess_Board.h"
#include "../../cpm_source_cache/googletest/c89ee04fa01138c2db034b2627b51a145ba09878/googletest/googletest/include/gtest/gtest.h"
#include "../../include/Move_Generator/Move_Generator.h"



namespace Kangaroo::Generate_Pawn_Moves_Tests {
    Callback_Template_Inline(Pawn_Move_Generator_White_Pawn_Base_Callback, const std::array<Move, 16> &moves) {
        if (status.color_to_move != Color::Black) {
            throw std::runtime_error("Color is not black");
        }
        if (chess_piece != Chess_Pieces::Pawn) {
            throw std::runtime_error("Chess piece is not pawn");
        }
        if (!std::ranges::contains(moves, move)) {
            throw std::runtime_error("Move is not in moves");
        }
    }

    Status_Callback_Template(Pawn_Move_Generator_Base, Chess_Board *board, const std::array<Move,
                             16> &moves) {
        Move_Generator::Move_Generator<status, CallbackType> generator(board);
        return generator.generate_pawn_movements(moves);
    }

    TEST(Pawn_Move_Generator, pawn_move_generator_white_pawns_base) {

        Chess_Board board{};
        auto status = board.reset_board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");


        const std::array<Move, 16> moves = {
            /*
          8    .  .  .  .  .  .  .  .
          7    .  .  .  .  .  .  .  .
          6    .  .  .  .  .  .  .  .
          5    .  .  .  .  .  .  .  .
          4    .  .  .  .  .  .  .  .
          3    1  .  .  .  .  .  .  .
          2    1  .  .  .  .  .  .  .
          1    .  .  .  .  .  .  .  .

               A  B  C  D  E  F  G  H

               bitboard as 64 bit integer: */
            0x10100,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    1  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    1  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x1000100,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  1  .  .  .  .  .  .
              2    .  1  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x20200,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  1  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  1  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x2000200,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  1  .  .  .  .  .
              2    .  .  1  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x40400,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  1  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  1  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x4000400,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  1  .  .  .  .
              2    .  .  .  1  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x80800,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  1  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  1  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x8000800,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  1  .  .  .
              2    .  .  .  .  1  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x101000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  1  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  1  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x10001000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  1  .  .
              2    .  .  .  .  .  1  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x202000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  1  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  1  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x20002000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  1  .
              2    .  .  .  .  .  .  1  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x404000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  1  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  1  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x40004000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  1
              2    .  .  .  .  .  .  .  1
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x808000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  1
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  1
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x80008000,
        };


        const std::size_t s = execute_status_callback_template<Pawn_Move_Generator_Base,
            Pawn_Move_Generator_White_Pawn_Base_Callback>(*status, &board, moves);

        ASSERT_EQ(moves.size(), s);
    }


    Callback_Template_Inline(Pawn_Move_Generator_Black_Pawn_Base_Callback, const std::array<Move, 16> &moves) {
        if (status.color_to_move != Color::White) {
            throw std::runtime_error("Color is not white");
        }
        if (chess_piece != Chess_Pieces::Pawn) {
            throw std::runtime_error("Chess piece is not pawn");
        }
        if (!std::ranges::contains(moves, move)) {
            throw std::runtime_error("Move is not in moves");
        }
    }

    TEST(Pawn_Move_Generator, pawn_move_generator_black_pawns_base) {
        Chess_Board board{};
        auto status = board.reset_board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1");

        [[maybe_unused]] std::array<Move, 16> moves = {
            /*
      8    .  .  .  .  .  .  .  .
      7    1  .  .  .  .  .  .  .
      6    1  .  .  .  .  .  .  .
      5    .  .  .  .  .  .  .  .
      4    .  .  .  .  .  .  .  .
      3    .  .  .  .  .  .  .  .
      2    .  .  .  .  .  .  .  .
      1    .  .  .  .  .  .  .  .

           A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
            0x1010000000000,
            /*
              8    .  .  .  .  .  .  .  .
              7    1  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    1  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x1000100000000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  1  .  .  .  .  .  .
              6    .  1  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x2020000000000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  1  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  1  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x2000200000000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  1  .  .  .  .  .
              6    .  .  1  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x4040000000000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  1  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  1  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x4000400000000,
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
              7    .  .  .  1  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  1  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x8000800000000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  1  .  .  .
              6    .  .  .  .  1  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x10100000000000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  1  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  1  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x10001000000000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  1  .  .
              6    .  .  .  .  .  1  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x20200000000000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  1  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  1  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x20002000000000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  1  .
              6    .  .  .  .  .  .  1  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x40400000000000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  1  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  1  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x40004000000000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  1
              6    .  .  .  .  .  .  .  1
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x80800000000000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  1
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  1
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x80008000000000,
        };

        const std::size_t s = execute_status_callback_template<Pawn_Move_Generator_Base,
            Pawn_Move_Generator_Black_Pawn_Base_Callback>(*status, &board, moves);
        ASSERT_EQ(s, moves.size());
    }

    Callback_Template_Inline(Pawn_Move_Generator_White_Pawn_Capture_Callback, const std::array<Move, 8> &moves) {
        if (status.color_to_move != Color::Black) {
            throw std::runtime_error("Color is not black");
        }
        if (chess_piece != Chess_Pieces::Pawn) {
            throw std::runtime_error("Chess piece is not pawn");
        }
        if (!std::ranges::contains(moves, move)) {
            throw std::runtime_error("Move is not in moves");
        }
    }

    Status_Callback_Template(Pawn_Move_Generator_white_pawn_capture, Chess_Board *board, const std::array<Move, 8> &moves) {
        Move_Generator::Move_Generator<status, CallbackType> generator(board);
        return generator.generate_pawn_movements(moves);
    }

    TEST(Pawn_Move_Generator, pawn_move_generator_white_pawn_capture) {

        init_logger();

        Chess_Board board{};
        auto status = board.reset_board(fen_tricky_position_w);

        [[maybe_unused]] std::array<Move, 8> moves = {
            /*
      8    .  .  .  .  .  .  .  .
      7    .  .  .  .  .  .  .  .
      6    .  .  .  .  .  .  .  .
      5    .  .  .  .  .  .  .  .
      4    .  .  .  .  .  .  .  .
      3    1  .  .  .  .  .  .  .
      2    1  .  .  .  .  .  .  .
      1    .  .  .  .  .  .  .  .

           A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
            0x10100,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    1  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    1  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x1000100,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  1  .  .  .  .  .  .
              2    .  1  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x20200,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  1  .
              2    .  .  .  .  .  .  1  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x404000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  1  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  1  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x40004000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  1
              2    .  .  .  .  .  .  1  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x804000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  1  .  .  .  .
              5    .  .  .  1  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x80800000000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  1  .  .  .
              5    .  .  .  1  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x100800000000,
        };


        const std::size_t s = execute_status_callback_template<Pawn_Move_Generator_white_pawn_capture, Pawn_Move_Generator_White_Pawn_Capture_Callback>(*status, &board, moves);
        ASSERT_EQ(s, moves.size());
    }

    Callback_Template_Inline(Pawn_Move_Generator_Black_Pawn_Capture_Callback, const std::array<Move, 8> &moves) {
        if (status.color_to_move != Color::White) {
            throw std::runtime_error("Color is not white");
        }
        if (chess_piece != Chess_Pieces::Pawn) {
            throw std::runtime_error("Chess piece is not pawn");
        }
        if (!std::ranges::contains(moves, move)) {
            throw std::runtime_error("Move is not in moves");
        }
    }

    Status_Callback_Template(Pawn_Move_Generator_black_pawn_capture, Chess_Board *board, const std::array<Move, 8> &moves) {
        Move_Generator::Move_Generator<status, CallbackType> generator(board);
        return generator.generate_pawn_movements(moves);
    }


    TEST(Pawn_Move_Generator, pawn_move_generator_black_pawn_capture) {
        Chess_Board board{};
        auto status = board.reset_board(fen_tricky_position_b);

        constexpr std::array<Move, 8> moves = {
            /*
      8    .  .  .  .  .  .  .  .
      7    .  .  .  .  .  .  .  .
      6    .  .  .  .  .  .  .  .
      5    .  .  .  .  .  .  .  .
      4    .  .  .  .  .  .  .  .
      3    .  .  .  .  .  .  .  1
      2    .  .  .  .  .  .  1  .
      1    .  .  .  .  .  .  .  .

           A  B  C  D  E  F  G  H

           bitboard as 64 bit integer: */
            0x804000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  1  .  .  .  .  .  .
              3    .  1  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x2020000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  1  .  .  .  .  .  .
              3    .  .  1  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x2040000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  1  .  .  .
              5    .  .  .  1  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x100800000000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  .  .  .  .  .  .
              6    .  .  .  .  .  .  1  .
              5    .  .  .  .  .  .  1  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x404000000000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  1  .  .  .  .  .
              6    .  .  1  .  .  .  .  .
              5    .  .  .  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x4040000000000,
            /*
              8    .  .  .  .  .  .  .  .
              7    .  .  1  .  .  .  .  .
              6    .  .  .  .  .  .  .  .
              5    .  .  1  .  .  .  .  .
              4    .  .  .  .  .  .  .  .
              3    .  .  .  .  .  .  .  .
              2    .  .  .  .  .  .  .  .
              1    .  .  .  .  .  .  .  .

                   A  B  C  D  E  F  G  H

                   bitboard as 64 bit integer: */
            0x4000400000000,
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
        };


        const std::size_t s = execute_status_callback_template<Pawn_Move_Generator_black_pawn_capture, Pawn_Move_Generator_Black_Pawn_Capture_Callback>(*status, &board, moves);
        ASSERT_EQ(s, moves.size());
    }
}
