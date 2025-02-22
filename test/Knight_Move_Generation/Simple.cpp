// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by peter on 2/8/25.
//

#include "gtest/gtest.h"
#include "Move_Generator/Move_Generator.h"

namespace Kangaroo::Knight_Move_Generation::Simple {
    Callback_Template_Inline(Pawn_Movement_Generator_Test2_Callback,const std::array<Chess_Board,
                             4> &new_boards, const std::array<Bitboard, 4> &moves) {
        using enum Chess_Pieces;
        using enum Color;


        const auto it = std::ranges::find(moves, move);
        if (it == moves.end())
        {
            std::stringstream ss;
            ss << "move: 0x" << std::hex << move << " not found in moves";
            throw std::runtime_error(ss.str());
        };


        const auto board_it = std::ranges::find(new_boards, *pac_gen->get_board());
        if (board_it == new_boards.end())
        {
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

    Status_Callback_Template(Pawn_Movement_Generator_Test2, Chess_Board* board,
                             const std::array<Chess_Board, 4> &chess_boards, const std::array<Bitboard, 4> &moves) {
        Move_Generator::Move_Generator<status, CallbackType> generator(board);
        return generator.generate_knight_movements(chess_boards, moves);
    }


    [[maybe_unused]] std::array<Chess_Board, 4> new_boards = {
        /*

       A  B  C  D  E  F  G  H

  8    ♖  ♘  ♗  ♕  ♔  ♗  ♘  ♖
  7    ♙  ♙  ♙  ♙  ♙  ♙  ♙  ♙
  6    .  .  .  .  .  .  .  .          half move number:  0
  5    .  .  .  .  .  .  .  .          full move number:  1
  4    .  .  .  .  .  .  .  .
  3    ♞  .  .  .  .  .  .  .
  2    ♟  ♟  ♟  ♟  ♟  ♟  ♟  ♟
  1    ♜  .  ♝  ♛  ♚  ♝  ♞  ♜

       A  B  C  D  E  F  G  H

*/
        Kangaroo::Chess_Board(std::array<Bitboard, 15>{
            /* white pawns    */ 0x000000000000ff00, /* white knights */ 0x0000000000010040, /* white bishops */
            0x0000000000000024,
            /* white rooks    */ 0x0000000000000081, /* white queens  */ 0x0000000000000008, /* white king    */
            0x0000000000000010,
            /* black pawns    */ 0x00ff000000000000, /* black knights */ 0x4200000000000000, /* black bishops */
            0x2400000000000000,
            /* black rooks    */ 0x8100000000000000, /* black queens  */ 0x0800000000000000, /* black king    */
            0x1000000000000000,
            /* en passant sq. */ 0x0000000000000000, /* half move num */ 0x0000000000000000, /* full move num */
            0x0000000000000001
        }),
        /*

               A  B  C  D  E  F  G  H

          8    ♖  ♘  ♗  ♕  ♔  ♗  ♘  ♖
          7    ♙  ♙  ♙  ♙  ♙  ♙  ♙  ♙
          6    .  .  .  .  .  .  .  .          half move number:  0
          5    .  .  .  .  .  .  .  .          full move number:  1
          4    .  .  .  .  .  .  .  .
          3    .  .  ♞  .  .  .  .  .
          2    ♟  ♟  ♟  ♟  ♟  ♟  ♟  ♟
          1    ♜  .  ♝  ♛  ♚  ♝  ♞  ♜

               A  B  C  D  E  F  G  H

        */
        Kangaroo::Chess_Board(std::array<Bitboard, 15>{
            /* white pawns    */ 0x000000000000ff00, /* white knights */ 0x0000000000040040, /* white bishops */
            0x0000000000000024,
            /* white rooks    */ 0x0000000000000081, /* white queens  */ 0x0000000000000008, /* white king    */
            0x0000000000000010,
            /* black pawns    */ 0x00ff000000000000, /* black knights */ 0x4200000000000000, /* black bishops */
            0x2400000000000000,
            /* black rooks    */ 0x8100000000000000, /* black queens  */ 0x0800000000000000, /* black king    */
            0x1000000000000000,
            /* en passant sq. */ 0x0000000000000000, /* half move num */ 0x0000000000000000, /* full move num */
            0x0000000000000001
        }),
        /*

               A  B  C  D  E  F  G  H

          8    ♖  ♘  ♗  ♕  ♔  ♗  ♘  ♖
          7    ♙  ♙  ♙  ♙  ♙  ♙  ♙  ♙
          6    .  .  .  .  .  .  .  .          half move number:  0
          5    .  .  .  .  .  .  .  .          full move number:  1
          4    .  .  .  .  .  .  .  .
          3    .  .  .  .  .  ♞  .  .
          2    ♟  ♟  ♟  ♟  ♟  ♟  ♟  ♟
          1    ♜  ♞  ♝  ♛  ♚  ♝  .  ♜

               A  B  C  D  E  F  G  H

        */
        Kangaroo::Chess_Board(std::array<Bitboard, 15>{
            /* white pawns    */ 0x000000000000ff00, /* white knights */ 0x0000000000200002, /* white bishops */
            0x0000000000000024,
            /* white rooks    */ 0x0000000000000081, /* white queens  */ 0x0000000000000008, /* white king    */
            0x0000000000000010,
            /* black pawns    */ 0x00ff000000000000, /* black knights */ 0x4200000000000000, /* black bishops */
            0x2400000000000000,
            /* black rooks    */ 0x8100000000000000, /* black queens  */ 0x0800000000000000, /* black king    */
            0x1000000000000000,
            /* en passant sq. */ 0x0000000000000000, /* half move num */ 0x0000000000000000, /* full move num */
            0x0000000000000001
        }),
        /*

               A  B  C  D  E  F  G  H

          8    ♖  ♘  ♗  ♕  ♔  ♗  ♘  ♖
          7    ♙  ♙  ♙  ♙  ♙  ♙  ♙  ♙
          6    .  .  .  .  .  .  .  .          half move number:  0
          5    .  .  .  .  .  .  .  .          full move number:  1
          4    .  .  .  .  .  .  .  .
          3    .  .  .  .  .  .  .  ♞
          2    ♟  ♟  ♟  ♟  ♟  ♟  ♟  ♟
          1    ♜  ♞  ♝  ♛  ♚  ♝  .  ♜

               A  B  C  D  E  F  G  H

        */
        Kangaroo::Chess_Board(std::array<Bitboard, 15>{
            /* white pawns    */ 0x000000000000ff00, /* white knights */ 0x0000000000800002, /* white bishops */
            0x0000000000000024,
            /* white rooks    */ 0x0000000000000081, /* white queens  */ 0x0000000000000008, /* white king    */
            0x0000000000000010,
            /* black pawns    */ 0x00ff000000000000, /* black knights */ 0x4200000000000000, /* black bishops */
            0x2400000000000000,
            /* black rooks    */ 0x8100000000000000, /* black queens  */ 0x0800000000000000, /* black king    */
            0x1000000000000000,
            /* en passant sq. */ 0x0000000000000000, /* half move num */ 0x0000000000000000, /* full move num */
            0x0000000000000001
        }),

    };

    [[maybe_unused]] std::array<Bitboard, 4> moves = {
        /*
          8    .  .  .  .  .  .  .  .
          7    .  .  .  .  .  .  .  .
          6    .  .  .  .  .  .  .  .
          5    .  .  .  .  .  .  .  .
          4    .  .  .  .  .  .  .  .
          3    1  .  .  .  .  .  .  .
          2    .  .  .  .  .  .  .  .
          1    .  1  .  .  .  .  .  .

               A  B  C  D  E  F  G  H

               bitboard as 64 bit integer: */
        0x10002,

        /*
          8    .  .  .  .  .  .  .  .
          7    .  .  .  .  .  .  .  .
          6    .  .  .  .  .  .  .  .
          5    .  .  .  .  .  .  .  .
          4    .  .  .  .  .  .  .  .
          3    .  .  1  .  .  .  .  .
          2    .  .  .  .  .  .  .  .
          1    .  1  .  .  .  .  .  .

               A  B  C  D  E  F  G  H

               bitboard as 64 bit integer: */
        0x40002,

        /*
          8    .  .  .  .  .  .  .  .
          7    .  .  .  .  .  .  .  .
          6    .  .  .  .  .  .  .  .
          5    .  .  .  .  .  .  .  .
          4    .  .  .  .  .  .  .  .
          3    .  .  .  .  .  1  .  .
          2    .  .  .  .  .  .  .  .
          1    .  .  .  .  .  .  1  .

               A  B  C  D  E  F  G  H

               bitboard as 64 bit integer: */
        0x200040,

        /*
          8    .  .  .  .  .  .  .  .
          7    .  .  .  .  .  .  .  .
          6    .  .  .  .  .  .  .  .
          5    .  .  .  .  .  .  .  .
          4    .  .  .  .  .  .  .  .
          3    .  .  .  .  .  .  .  1
          2    .  .  .  .  .  .  .  .
          1    .  .  .  .  .  .  1  .

               A  B  C  D  E  F  G  H

               bitboard as 64 bit integer: */
        0x800040,
    };

    /**
     * Test that the board below leads to two generated moves.
     */
    TEST(Knight_Move_Generation, Simple) {
        using namespace Kangaroo::Move_Generator;
        using enum Chess_Pieces;
        using enum Color;



        Chess_Board board{};
        const auto status = board.reset_board(fen_start_position);

        const std::size_t n = execute_status_callback_template<Pawn_Movement_Generator_Test2,
            Pawn_Movement_Generator_Test2_Callback, Chess_Board *,
            const std::array<Chess_Board, 4> &, const std::array<
                Move, 4> &>(*status, &board, new_boards, moves);

        ASSERT_EQ(n, moves.size());
    }
}
