//
// Created by peter on 01/12/2024.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <memory>
#include "types.h"
#include <string>

#include "colors.h"

inline constexpr std::string_view fen_empty_board      = "8/8/8/8/8/8/8/8 w - - 0 1 ";
inline constexpr std::string_view fen_start_position   = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1 ";
inline constexpr std::string_view fen_tricky_position  = "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1 ";
inline constexpr std::string_view fen_killer_position  = "rnbqkb1r/pp1p1pPp/8/2p1pP2/1P1P4/3P3P/P1P1P3/RNBQKBNR w KQkq e6 0 1";
inline constexpr std::string_view fen_cmk_position     = "r2q1rk1/ppp2ppp/2n1bn2/2b1p3/3pP3/3P1NPP/PPP1NPB1/R1BQ1RK1 b - - 0 9 ";


class Board_Status {
protected:
    /**
     * Who's turn is it?
     */
    Color color = Color::white;

    /**
     * Is it a check?
     */
    bool check = false;


};



using Chess_Board = struct Chess_Board_t {

    Bitboard white_king     = 0ULL;
    Bitboard white_queens   = 0ULL;
    Bitboard white_rooks    = 0ULL;
    Bitboard white_knights  = 0ULL;
    Bitboard white_bishops  = 0ULL;
    Bitboard white_pawns    = 0ULL;

    Bitboard black_king     = 0ULL;
    Bitboard black_queens   = 0ULL;
    Bitboard black_rooks    = 0ULL;
    Bitboard black_knights  = 0ULL;
    Bitboard black_bishops  = 0ULL;
    Bitboard black_pawns    = 0ULL;

    Bitboard black_pieces   = 0ULL;
    Bitboard white_pieces   = 0ULL;
    Bitboard all_pieces     = 0ULL;

    std::size_t en_passant_square   = 0;
    std::size_t half_move_number    = 0;
    std::size_t full_move_number    = 0;
};


std::unique_ptr<Chess_Board> create_chess_board_from_fen(const std::string_view &fen);


std::unique_ptr<Chess_Board> create_chess_board();
void print_chess_board(const Chess_Board *board);

#endif //CHESS_BOARD_H
