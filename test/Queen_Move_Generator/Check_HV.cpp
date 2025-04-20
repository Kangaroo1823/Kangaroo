// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by U439644 on 4/16/2025.
//

#include "Move_Generator/Move_Generator.h"
#include <gtest/gtest.h>

namespace Kangaroo::Queen_Move_Generation::Check_HV {
    Callback_Template_Inline(Queen_Movement_Generator_Test2_Callback, const std::array<Chess_Board,
                             3> &new_boards, const std::array<Bitboard, 3> &moves) {
        using enum Chess_Pieces;
        using enum Color;

        // print_chess_board(*pac_gen->get_board(), true);
        // print_bitboard(move);
        // return;

        if (const auto it = std::ranges::find(moves, move); it == moves.end()) {
            std::stringstream ss;
            ss << "move: 0x" << std::hex << move << " not found in moves";
            throw std::runtime_error(ss.str());
        };


        const auto board_it = std::ranges::find(new_boards, *pac_gen->get_board());
        if (board_it == new_boards.end()) {
            std::stringstream ss;
            ss << "board: " << *pac_gen->get_board() << " not found in boards";
            throw std::runtime_error(ss.str());
        }
        if (!pac_gen->get_board()->is_state_consistent()) {
            std::stringstream ss;
            ss << "board: " << std::endl << pac_gen->get_board() << " is not consistent." << std::endl;
            ss << "--- details of board: ---------------------------------------------------" << std::endl;
            ss << "   white pawns:    " << format_bitboard(bitboard_for(*pac_gen->get_board(), White, Pawn)) <<
                    std::endl;
            ss << "   black pawns:    " << format_bitboard(bitboard_for(*pac_gen->get_board(), Black, Pawn)) <<
                    std::endl;
            ss << "   white knights:  " << format_bitboard(bitboard_for(*pac_gen->get_board(), White, Knight)) <<
                    std::endl;
            ss << "   black knights:  " << format_bitboard(bitboard_for(*pac_gen->get_board(), Black, Knight)) <<
                    std::endl;
            ss << "   white bishops:  " << format_bitboard(bitboard_for(*pac_gen->get_board(), White, Bishop)) <<
                    std::endl;
            ss << "   black bishops:  " << format_bitboard(bitboard_for(*pac_gen->get_board(), Black, Bishop)) <<
                    std::endl;
            ss << "   white rooks:    " << format_bitboard(bitboard_for(*pac_gen->get_board(), White, Rook)) <<
                    std::endl;
            ss << "   black rooks:    " << format_bitboard(bitboard_for(*pac_gen->get_board(), Black, Rook)) <<
                    std::endl;
            ss << "   white queens:   " << format_bitboard(bitboard_for(*pac_gen->get_board(), White, Queen)) <<
                    std::endl;
            ss << "   black queens:   " << format_bitboard(bitboard_for(*pac_gen->get_board(), Black, Queen)) <<
                    std::endl;
            ss << "   white king:     " << format_bitboard(bitboard_for(*pac_gen->get_board(), White, King)) <<
                    std::endl;
            ss << "   black king:     " << format_bitboard(bitboard_for(*pac_gen->get_board(), Black, King)) <<
                    std::endl;
            ss << "   white pieces:   " << format_bitboard(all_pieces_for(*pac_gen->get_board(), White)) << std::endl;
            ss << "   black pieces:   " << format_bitboard(all_pieces_for(*pac_gen->get_board(), Black)) << std::endl;
            ss << "   all pieces:     " << format_bitboard(total_pieces_for(*pac_gen->get_board())) << std::endl;
            ss << "   en passant sq.: " << format_bitboard(en_passant_square_for(*pac_gen->get_board())) << std::endl;
            ss << "-------------------------------------------------------------------------" << std::endl;
            throw std::runtime_error(ss.str());
        }
    }

    Status_Callback_Template(Queen_Movement_Generator_Test2, Chess_Board* board,
                             const std::array<Chess_Board, 3> &chess_boards, const std::array<Bitboard, 3> &moves) {
        Move_Generator::Move_Generator<status, CallbackType> generator(board);
        return generator.generate_queen_movements(chess_boards, moves);
    }


    std::array<Chess_Board, 3> new_boards = {
/*

       A  B  C  D  E  F  G  H

  8    .  .  .  .  .  .  .  .
  7    .  ♙  .  ♕  .  ♙  .  .
  6    .  .  .  .  .  .  .  .          half move number:  0
  5    .  ♖  .  ♛  .  ♜  .  .          full move number:  1
  4    .  .  .  .  .  .  .  .
  3    .  ♟  .  ♚  .  ♟  .  .
  2    .  .  .  .  .  .  .  .
  1    .  .  .  .  .  .  .  .

       A  B  C  D  E  F  G  H

*/
  Kangaroo::Chess_Board( std::array<Bitboard, 15>{
    /* white pawns    */ 0x0000000000220000, /* white knights */ 0x0000000000000000, /* white bishops */ 0x0000000000000000,
    /* white rooks    */ 0x0000002000000000, /* white queens  */ 0x0000000800000000, /* white king    */ 0x0000000000080000,
    /* black pawns    */ 0x0022000000000000, /* black knights */ 0x0000000000000000, /* black bishops */ 0x0000000000000000,
    /* black rooks    */ 0x0000000200000000, /* black queens  */ 0x0008000000000000, /* black king    */ 0x0000000000000000,
    /* en passant sq. */ 0x0000000000000000, /* half move num */ 0x0000000000000000, /* full move num */ 0x0000000000000001 }),
/*

       A  B  C  D  E  F  G  H

  8    .  .  .  .  .  .  .  .
  7    .  ♙  .  ♕  .  ♙  .  .
  6    .  .  .  ♛  .  .  .  .          half move number:  0
  5    .  ♖  .  .  .  ♜  .  .          full move number:  1
  4    .  .  .  .  .  .  .  .
  3    .  ♟  .  ♚  .  ♟  .  .
  2    .  .  .  .  .  .  .  .
  1    .  .  .  .  .  .  .  .

       A  B  C  D  E  F  G  H

*/
  Kangaroo::Chess_Board( std::array<Bitboard, 15>{
    /* white pawns    */ 0x0000000000220000, /* white knights */ 0x0000000000000000, /* white bishops */ 0x0000000000000000,
    /* white rooks    */ 0x0000002000000000, /* white queens  */ 0x0000080000000000, /* white king    */ 0x0000000000080000,
    /* black pawns    */ 0x0022000000000000, /* black knights */ 0x0000000000000000, /* black bishops */ 0x0000000000000000,
    /* black rooks    */ 0x0000000200000000, /* black queens  */ 0x0008000000000000, /* black king    */ 0x0000000000000000,
    /* en passant sq. */ 0x0000000000000000, /* half move num */ 0x0000000000000000, /* full move num */ 0x0000000000000001 }),
/*

       A  B  C  D  E  F  G  H

  8    .  .  .  .  .  .  .  .
  7    .  ♙  .  ♛  .  ♙  .  .
  6    .  .  .  .  .  .  .  .          half move number:  0
  5    .  ♖  .  .  .  ♜  .  .          full move number:  1
  4    .  .  .  .  .  .  .  .
  3    .  ♟  .  ♚  .  ♟  .  .
  2    .  .  .  .  .  .  .  .
  1    .  .  .  .  .  .  .  .

       A  B  C  D  E  F  G  H

*/
  Kangaroo::Chess_Board( std::array<Bitboard, 15>{
    /* white pawns    */ 0x0000000000220000, /* white knights */ 0x0000000000000000, /* white bishops */ 0x0000000000000000,
    /* white rooks    */ 0x0000002000000000, /* white queens  */ 0x0008000000000000, /* white king    */ 0x0000000000080000,
    /* black pawns    */ 0x0022000000000000, /* black knights */ 0x0000000000000000, /* black bishops */ 0x0000000000000000,
    /* black rooks    */ 0x0000000200000000, /* black queens  */ 0x0000000000000000, /* black king    */ 0x0000000000000000,
    /* en passant sq. */ 0x0000000000000000, /* half move num */ 0x0000000000000000, /* full move num */ 0x0000000000000001 }),

    };

    std::array<Bitboard, 3> moves = {
        /*
          8    .  .  .  .  .  .  .  .
          7    .  .  .  .  .  .  .  .
          6    .  .  1  .  .  .  .  .
          5    .  .  .  1  .  .  .  .
          4    .  .  .  .  .  .  .  .
          3    .  .  .  .  .  .  .  .
          2    .  .  .  .  .  .  .  .
          1    .  .  .  .  .  .  .  .

               A  B  C  D  E  F  G  H

               bitboard as 64 bit integer: */
        0x40800000000,

 /*
   8    .  .  .  .  .  .  .  .
   7    .  .  .  .  .  .  .  .
   6    .  .  1  1  .  .  .  .
   5    .  .  .  .  .  .  .  .
   4    .  .  .  .  .  .  .  .
   3    .  .  .  .  .  .  .  .
   2    .  .  .  .  .  .  .  .
   1    .  .  .  .  .  .  .  .

        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0xc0000000000,

 /*
   8    .  .  .  .  .  .  .  .
   7    .  .  .  1  .  .  .  .
   6    .  .  1  .  .  .  .  .
   5    .  .  .  .  .  .  .  .
   4    .  .  .  .  .  .  .  .
   3    .  .  .  .  .  .  .  .
   2    .  .  .  .  .  .  .  .
   1    .  .  .  .  .  .  .  .

        A  B  C  D  E  F  G  H

        bitboard as 64 bit integer: */
        0x8040000000000,

    };

    /**
     * Test that the board below leads to two generated moves.
     */
    TEST(Queen_Move_Generation, Check_HV) {
        using namespace Kangaroo::Move_Generator;
        using enum Chess_Pieces;
        using enum Color;


        Chess_Board board{};
        const auto status = board.reset_board("8/1p1q1p2/2Q5/1r3R2/8/1P1K1P2/8/8 w KQkq - 0 1 ");

        const std::size_t n = execute_status_callback_template<Queen_Movement_Generator_Test2,
            Queen_Movement_Generator_Test2_Callback, Chess_Board *,
            const std::array<Chess_Board, 3> &, const std::array<
                Move, 3> &>(*status, &board, new_boards, moves);

        ASSERT_EQ(n, moves.size());
    }
}
