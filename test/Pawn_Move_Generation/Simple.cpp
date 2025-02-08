// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by peter on 2/8/25.
//

#include "gtest/gtest.h"
#include "Move_Generator/Move_Generator.h"

namespace Kangaroo::Pawn_Move_Generation::Simple
{
    Callback_Template_Inline(Pawn_Movement_Generator_Test2_Callback, [[maybe_unused]] const std::array<Chess_Board,
                             2> &new_boards,
                             [[maybe_unused]] const std::array<Bitboard, 2> &moves)
    {
        using enum Chess_Pieces;
        using enum Color;

        const auto it = std::ranges::find(moves, move);
        if (it == moves.end())
        {
            std::stringstream ss;
            ss << "move: 0x" << std::hex << move << " not found in moves";
            throw std::runtime_error(ss.str());
        };


        const auto board_it = std::ranges::find(new_boards, *board);
        if (board_it == new_boards.end())
        {
            std::stringstream ss;
            ss << "board: " << *board << " not found in boards";
            throw std::runtime_error(ss.str());
        }
        if (!board->is_state_consistent())
        {
            std::stringstream ss;
            ss << "board: " << std::endl << *board << " is not consistent." << std::endl;
            ss << "--- details of board: ---------------------------------------------------" << std::endl;
            ss << "   white pawns:    " << format_bitboard(bitboard_for(*board, White, Pawn)) << std::endl;
            ss << "   black pawns:    " << format_bitboard(bitboard_for(*board, Black, Pawn)) << std::endl;
            ss << "   white knights:  " << format_bitboard(bitboard_for(*board, White, Knight)) << std::endl;
            ss << "   black knights:  " << format_bitboard(bitboard_for(*board, Black, Knight)) << std::endl;
            ss << "   white bishops:  " << format_bitboard(bitboard_for(*board, White, Bishop)) << std::endl;
            ss << "   black bishops:  " << format_bitboard(bitboard_for(*board, Black, Bishop)) << std::endl;
            ss << "   white rooks:    " << format_bitboard(bitboard_for(*board, White, Rook)) << std::endl;
            ss << "   black rooks:    " << format_bitboard(bitboard_for(*board, Black, Rook)) << std::endl;
            ss << "   white queens:   " << format_bitboard(bitboard_for(*board, White, Queen)) << std::endl;
            ss << "   black queens:   " << format_bitboard(bitboard_for(*board, Black, Queen)) << std::endl;
            ss << "   white king:     " << format_bitboard(bitboard_for(*board, White, King)) << std::endl;
            ss << "   black king:     " << format_bitboard(bitboard_for(*board, Black, King)) << std::endl;
            ss << "   white pieces:   " << format_bitboard(all_pieces_for(*board, White)) << std::endl;
            ss << "   black pieces:   " << format_bitboard(all_pieces_for(*board, Black)) << std::endl;
            ss << "   all pieces:     " << format_bitboard(total_pieces_for(*board)) << std::endl;
            ss << "   en passant sq.: " << format_bitboard(en_passant_square_for(*board)) << std::endl;
            ss << "-------------------------------------------------------------------------" << std::endl;
            throw std::runtime_error(ss.str());
        }
    }

    Status_Callback_Template(Pawn_Movement_Generator_Test2, Chess_Board* board,
                             const std::array<Chess_Board, 2> &chess_boards, const std::array<Bitboard, 2> &moves)
    {
        Move_Generator::Move_Generator<status, CallbackType> generator(board);
        return generator.generate_pawn_movements(chess_boards, moves);
    }


    [[maybe_unused]] std::array<Chess_Board, 2> new_boards = {
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

    [[maybe_unused]] std::array<Bitboard, 2> moves = {
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

    /**
     * Test that the board below leads to two generated moves.
     */
    TEST(Pawn_Move_Generation, Simple)
    {
        using namespace Kangaroo::Move_Generator;
        using enum Chess_Pieces;
        using enum Color;

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


        const std::size_t n = execute_status_callback_template<Pawn_Movement_Generator_Test2,
                                                               Pawn_Movement_Generator_Test2_Callback, Chess_Board*,
                                                               const std::array<Chess_Board, 2>&, const std::array<
                                                                   Move, 2>&>(*status, &board, new_boards, moves);

        ASSERT_EQ(n, moves.size());

    }
}
