//
// Created by peter on 01/12/2024.
//

#include "../include/chess_board.h"
#include <fmt/base.h>
#include <array>
#include <numeric>
#include <string>
#include <memory>
#include "../include/bitboard.h"

std::unique_ptr<Chess_Board> create_chess_board() {
    // Helper function to generate bitboard for a set of positions
    auto generate_bitboard = [](const std::array<Position, 8> &positions) -> Bitboard {
        return std::accumulate(positions.begin(), positions.end(), 0ULL, set_bit);
    };

    auto board = std::make_unique<Chess_Board>();

    // Initialize black pieces
    board->black_king = set_bit(0ULL, Position_t::E8);
    board->black_queens = set_bit(0ULL, Position_t::D8);
    board->black_rooks = set_bit(0ULL, Position_t::A8) | set_bit(0ULL, Position_t::H8);
    board->black_knights = set_bit(0ULL, Position_t::B8) | set_bit(0ULL, Position_t::G8);
    board->black_bishops = set_bit(0ULL, Position_t::C8) | set_bit(0ULL, Position_t::F8);

    // Define black pawn positions
    std::array<Position, 8> black_pawn_positions = {
        Position_t::A7, Position_t::B7, Position_t::C7, Position_t::D7,
        Position_t::E7, Position_t::F7, Position_t::G7, Position_t::H7
    };
    board->black_pawns = generate_bitboard(black_pawn_positions);

    // Initialize white pieces
    board->white_king = set_bit(0ULL, Position_t::E1);
    board->white_queens = set_bit(0ULL, Position_t::D1);
    board->white_rooks = set_bit(0ULL, Position_t::A1) | set_bit(0ULL, Position_t::H1);
    board->white_knights = set_bit(0ULL, Position_t::B1) | set_bit(0ULL, Position_t::G1);
    board->white_bishops = set_bit(0ULL, Position_t::C1) | set_bit(0ULL, Position_t::F1);

    // Define white pawn positions
    std::array<Position, 8> white_pawn_positions = {
        Position_t::A2, Position_t::B2, Position_t::C2, Position_t::D2,
        Position_t::E2, Position_t::F2, Position_t::G2, Position_t::H2
    };
    board->white_pawns = generate_bitboard(white_pawn_positions);

    return board;
}

void print_chess_board(const std::unique_ptr<Chess_Board> board) {
    std::string white_king_c = "K"; //"\u2654";
    std::string white_queen_c = "Q"; // "\u2655";
    std::string white_rook_c = "R"; // "\u2656";
    std::string white_knight_c = "K"; // "\u2658";
    std::string white_bishop_c = "B"; // "\u2657";
    std::string white_pawn_c = "P"; // "\u2659";

    std::string black_king_c = "k"; // "\u265A";
    std::string black_queen_c = "q"; // "\u265B";
    std::string black_rook_c = "r"; // "\u265C";
    std::string black_knight_c = "k"; // \u265E";
    std::string black_bishop_c = "b"; // "\u265D";
    std::string black_pawn_c = "p"; // "\u265F";

    std::string empty_c = " ";

    if (board == nullptr) return;

    for (std::size_t rank = 0; rank < 8; ++rank) {
        for (std::size_t file = 0; file < 8; ++file) {
            if (get_bit(board->black_king, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", black_king_c);
            else if (get_bit(board->black_queens, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", black_queen_c);
            else if (get_bit(board->black_rooks, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", black_rook_c);
            else if (get_bit(board->black_knights, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", black_knight_c);
            else if (get_bit(board->black_bishops, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", black_bishop_c);
            else if (get_bit(board->black_pawns, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", black_pawn_c);

            else if (get_bit(board->white_king, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", white_king_c);
            else if (get_bit(board->white_queens, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", white_queen_c);
            else if (get_bit(board->white_rooks, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", white_rook_c);
            else if (get_bit(board->white_knights, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", white_knight_c);
            else if (get_bit(board->white_bishops, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", white_bishop_c);
            else if (get_bit(board->white_pawns, rank_file_to_position(rank, file)))
                fmt::print("{: ^3}", white_pawn_c);
            else fmt::print("{}{}{}", empty_c, ".", empty_c);
        }
        fmt::print("\n");
    }
}
