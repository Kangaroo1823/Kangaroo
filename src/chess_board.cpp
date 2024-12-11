//
// Created by peter on 01/12/2024.
//

#include "../include/chess_board.h"
#include <iostream>
#include <numeric>
#include <fmt/xchar.h>

Chess_Board* create_chess_board() {
    auto* board = new Chess_Board();

    board->black_king = set_bit(0ULL, E8);
    board->black_queens = set_bit(0ULL, D8);
    board->black_rooks = set_bit(0ULL, A8) | set_bit(0ULL, H8);
    board->black_knights = set_bit(0ULL, B8) | set_bit(0ULL, G8);
    board->black_bishops = set_bit(0ULL, C8) | set_bit(0ULL, F8);

    Bitboard bitboard = 0ULL;
    std::array<Position, 8> positions = {A7, B7, C7, D7, E7, F7, G7, H7};
    bitboard = std::accumulate(positions.begin(), positions.end(), bitboard, set_bit);

 //   for (Position position : {A7, B7, C7, D7, E7, F7, G7, H7}) {
 //       bitboard = set_bit(bitboard, position);
  //  }
    board->black_pawns = bitboard;

    board->white_king = set_bit(0ULL, E1);
    board->white_queens = set_bit(0ULL, D1);
    board->white_rooks = set_bit(0ULL, A1) | set_bit(0ULL, H1);
    board->white_knights = set_bit(0ULL, B1) | set_bit(0ULL, G1);
    board->white_bishops = set_bit(0ULL, C1) | set_bit(0ULL, F1);

    bitboard = 0ULL;
    positions = {A2, B2, C2, D2, E2, F2, G2, H2};
    bitboard = std::accumulate(positions.begin(), positions.end(), bitboard, set_bit);
    // for (Position position : {A2, B2, C2, D2, E2, F2, G2, H2}) {
    //     bitboard = set_bit(bitboard, position);
    // }
    board->white_pawns = bitboard;

    return board;
}

void print_chess_board(const Chess_Board* board) {
    std::string white_king_c   = "K"; //"\u2654";
    std::string white_queen_c  = "Q"; // "\u2655";
    std::string white_rook_c   = "R"; // "\u2656";
    std::string white_knight_c = "K"; // "\u2658";
    std::string white_bishop_c = "B"; // "\u2657";
    std::string white_pawn_c   = "P"; // "\u2659";

    std::string black_king_c   = "k"; // "\u265A";
    std::string black_queen_c  = "q"; // "\u265B";
    std::string black_rook_c   = "r"; // "\u265C";
    std::string black_knight_c = "k"; // \u265E";
    std::string black_bishop_c = "b"; // "\u265D";
    std::string black_pawn_c   = "p"; // "\u265F";

    std::string empty_c  = " "; // "\u2003";
    // std::string empty2_c  = " "; // "\u2007\u200A\u200A";

    if (board == nullptr) return;

    for (int rank = 0; rank < 8; ++rank) {
        for (int file = 0; file < 8; ++file) {
            if ( get_bit(board->black_king, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", black_king_c);
            else if ( get_bit(board->black_queens, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", black_queen_c);
            else if ( get_bit(board->black_rooks, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", black_rook_c);
            else if ( get_bit(board->black_knights, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", black_knight_c);
            else if ( get_bit(board->black_bishops, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", black_bishop_c);
            else if ( get_bit(board->black_pawns, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", black_pawn_c);

            else if ( get_bit(board->white_king, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", white_king_c);
            else if ( get_bit(board->white_queens, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", white_queen_c);
            else if ( get_bit(board->white_rooks, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", white_rook_c);
            else if ( get_bit(board->white_knights, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", white_knight_c);
            else if ( get_bit(board->white_bishops, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", white_bishop_c);
            else if ( get_bit(board->white_pawns, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", white_pawn_c);
            else fmt::print("{}{}{}", empty_c, ".", empty_c);

        }
        fmt::print("\n");
    }

}