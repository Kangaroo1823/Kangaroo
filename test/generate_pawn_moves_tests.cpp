// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by peter on 03/01/2025.
//

#include "chess_board.h"
#include "Movement_Generator.h"
#include "gtest/gtest.h"
#include "move_generator.h"

namespace Kangaroo {
    TEST(Pawn_Move_Generator, pawn_move_generator_white_pawns_base) {
        auto board = std::make_unique<
            Kangaroo::Chess_Board>("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
        Kangaroo::Movement_Generator gen(board.get());

        [[maybe_unused]] std::array<Move, 16> moves = {
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

        const auto s = gen.generate_pawn_moves<Kangaroo::Board_Status(0x3d)>(
            [&moves]([[maybe_unused]] const Chess_Board *board, const Move &move, const Color color,
                     const Chess_Pieces chess_piece) {
                ASSERT_EQ(color, Color::white);
                ASSERT_EQ(chess_piece, Chess_Pieces::pawn);
                ASSERT_TRUE(std::ranges::contains(moves, move));
            });

        ASSERT_EQ(moves.size(), s);
    }


    TEST(Pawn_Move_Generator, pawn_move_generator_black_pawns_base) {
        auto board = std::make_unique<
            Kangaroo::Chess_Board>("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR b KQkq - 0 1");
        Movement_Generator gen(board.get());

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

        const auto s = gen.generate_pawn_moves<Kangaroo::Board_Status(0x3c)>(
            [&moves]([[maybe_unused]] const Chess_Board *board, const Move move, const Color color,
                     const Chess_Pieces chess_piece) {
                ASSERT_EQ(color, Color::black);
                ASSERT_EQ(chess_piece, Chess_Pieces::pawn);
                ASSERT_TRUE(std::ranges::contains(moves, move));
                print_bitboard(move);
            });

        ASSERT_EQ(s, moves.size());
    }


    TEST(Pawn_Move_Generator, pawn_move_generator_white_pawn_capture) {
        const auto board = std::make_unique<Kangaroo::Chess_Board>(fen_tricky_position_w);
        Movement_Generator gen(board.get());

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

        print_chess_board(board.get());

        const auto s = gen.generate_pawn_moves<Kangaroo::Board_Status(0x3d)>(
            [&moves]([[maybe_unused]] const Chess_Board *board, const Move move, const Color color,
                     const Chess_Pieces chess_piece) {
                ASSERT_EQ(color, Color::white);
                ASSERT_EQ(chess_piece, Chess_Pieces::pawn);
                ASSERT_TRUE(std::ranges::contains(moves, move));
                print_bitboard(move);
            });

        ASSERT_EQ(s, moves.size());
    }


    TEST(Pawn_Move_Generator, pawn_move_generator_black_pawn_capture) {
        const auto board = std::make_unique<Kangaroo::Chess_Board>(fen_tricky_position_b);
        Movement_Generator gen(board.get());

        [[maybe_unused]] std::array<Move, 8> moves = {
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

        print_chess_board(board.get());

        const auto s = gen.generate_pawn_moves<Kangaroo::Board_Status(0x3c)>(
            [&moves]([[maybe_unused]] const Chess_Board *board, const Move move, const Color color, const Chess_Pieces chess_piece) {
                ASSERT_EQ(color, Color::black);
                ASSERT_EQ(chess_piece, Chess_Pieces::pawn);
                ASSERT_TRUE(std::ranges::contains(moves, move));
                print_bitboard(move);
            });

        ASSERT_EQ(s, moves.size());
    }
}
