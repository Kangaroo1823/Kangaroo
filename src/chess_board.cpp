//
// Created by peter on 01/12/2024.
//

#include "../include/chess_board.h"
#include <fmt/base.h>             // for print
#include <array>                  // for array
#include <cstddef>                // for size_t
#include <iostream>
#include <memory>                 // for unique_ptr, make_unique, operator==
#include <numeric>                // for accumulate
#include <ranges>
#include <vector>
#include <string>                 // for basic_string, string
#include "../include/bitboard.h"  // for Position_t, set_bit, get_bit, rank_...


std::unique_ptr<Chess_Board> create_chess_board() {
    // Helper function to generate bitboard for a set of positions
    auto generate_bitboard = [](const std::array<Position, 8> &positions) {
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


void parce_en_passant_notation(const std::string_view &str) {

    std::size_t rank = 8;
    std::size_t file = 8;

    for ( const auto &c: str) {
        switch (c) {
            case 'A': file = 0;
                break;
            case 'B': file = 1;
                break;
            case 'C': file = 2;
                break;
            case 'D': file = 3;
                break;
            case 'E': file = 4;
                break;
            case 'F': file = 5;
                break;
            case 'G': file = 6;
                break;
            case 'H': file = 7;
                break;
            case 'a': file = 0;
                break;
            case 'b': file = 1;
                break;
            case 'c': file = 2;
                break;
            case 'd': file = 3;
                break;
            case 'e': file = 4;
                break;
            case 'f': file = 5;
                break;
            case 'g': file = 6;
                break;
            case 'h': file = 7;
                break;
            case '1': rank = 0;
                break;
            case '2': rank = 1;
                break;
            case '3': rank = 2;
                break;
            case '4': rank = 3;
                break;
            case '5': rank = 4;
                break;
            case '6': rank = 5;
                break;
            case '7': rank = 6;
                break;
            case '8': rank = 7;
                break;
            default: break;
        }
        if (rank < 8 && file < 8) {
            std::cout << "En Passant @ " << print_position(rank_file_to_position(rank, file)) << "\n";
        }
    }
}

void process_fen_board_setup( Chess_Board *board, const std::string_view &str) {

    std::size_t rank = 0;
    std::size_t file = 0;

    for (const auto &c: str) {
        Position position = rank_file_to_position(rank, file);
        file = (file + 1) & 7;
        switch (c) {
            case 'p': board->black_pawns = set_bit(board->black_pawns, position);
                break;
            case 'P': board->white_pawns = set_bit(board->white_pawns, position);
                break;
            case 'n': board->black_knights = set_bit(board->black_knights, position);
                break;
            case 'N': board->white_knights = set_bit(board->white_knights, position);
                break;
            case 'b': board->black_bishops = set_bit(board->black_bishops, position);
                break;
            case 'B': board->white_bishops = set_bit(board->white_bishops, position);
                break;
            case 'r': board->black_rooks = set_bit(board->black_rooks, position);
                break;
            case 'R': board->white_rooks = set_bit(board->white_rooks, position);
                break;
            case 'q': board->black_queens = set_bit(board->black_queens, position);
                break;
            case 'Q': board->white_queens = set_bit(board->white_queens, position);
                break;
            case 'k': board->black_king = set_bit(board->black_king, position);
                break;
            case 'K': board->white_king = set_bit(board->white_king, position);
                break;
            case '/': if (++rank > 7) break;
                file = 0;
                break;
            case '1': break;
            case '2': file += 1;
                break;
            case '3': file += 2;
                break;
            case '4': file += 3;
                break;
            case '5': file += 4;
                break;
            case '6': file += 5;
                break;
            case '7': file += 6;
                break;
            case '8': file += 7;
                break;
            default: break;
        }
    }
}

bool parse_player_to_move(const std::string_view &str) {
    if (str == "w") {
        std::cout << "white to move\n";
    } else if (str == "b") {
        std::cout << "black to move\n";
    } else {
        std::cout << "Invalid FEN string\n";
        return false;
    }
    return true;
}

bool parse_castling_information(const std::string_view &str) {
    for (const auto &c: str) {
        switch (c) {
            case 'K': std::cout << "White king can castle to the king-side\n";
                break;
            case 'Q': std::cout << "White king can castle to the queen-side\n";
                break;
            case 'k': std::cout << "Black king can castle to the king-side\n";
                break;
            case 'q': std::cout << "Black king can castle to the queen-side\n";
                break;
            case '-': break;
            default: std::cout << "Invalid FEN string\n";
                return false;
        }
    }
    return true;
}

void parse_half_move_number( Chess_Board *board, const std::string_view &str) {
    for (const auto &c: str) {
        switch (c) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                board->half_move_number *= 10;
                board->half_move_number += static_cast<std::size_t>(c) - static_cast<std::size_t>('0');
                break;
            default: break;
        }
    }
    std::cout << "Half move number: " << board->half_move_number << "\n";
}

void parse_full_move_number( Chess_Board *board, const std::string_view &str) {
    for (const auto &c: str) {
        switch (c) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                board->full_move_number *= 10;
                board->full_move_number += static_cast<std::size_t>(c) - static_cast<std::size_t>('0');
                break;
            default: break;
        }
    }
    std::cout << "Full move number: " << board->full_move_number << "\n";
}

std::unique_ptr<Chess_Board> create_chess_board_from_fen(const std::string &fen) {
    auto board = std::make_unique<Chess_Board>();

    std::vector<std::string_view> tokens;
    for (auto &&part: std::views::split(fen, ' ')) {
        tokens.emplace_back(std::to_address(part.begin()), std::ranges::distance(part));
    }

    if (tokens.size() < 6) {
        std::cout << "Invalid FEN string\n";
        return nullptr;
    }

    process_fen_board_setup(board.get(), tokens[0]);

    if (!parse_player_to_move(tokens[1])) return nullptr;

    if (!parse_castling_information(tokens[2])) return nullptr;

    parce_en_passant_notation(tokens[3]);

    parse_half_move_number(board.get(), tokens[4]);

    parse_full_move_number(board.get(), tokens[5]);

    board->white_pieces = board->white_pawns | board->white_knights | board->white_bishops | board->white_rooks | board
                          ->white_queens | board->white_king;
    board->black_pieces = board->black_pawns | board->black_knights | board->black_bishops | board->black_rooks | board
                          ->black_queens | board->black_king;

    board->all_pieces = board->white_pieces | board->black_pieces;

    return board;
}

void print_chess_board(const Chess_Board *board) {
    constexpr std::string_view black_king_c = " \u{2654} ";
    constexpr std::string_view black_queen_c = " \u{2655} ";
    constexpr std::string_view black_rook_c = " \u{2656} ";
    constexpr std::string_view black_knight_c = " \u{2658} ";
    constexpr std::string_view black_bishop_c = " \u{2657} ";
    constexpr std::string_view black_pawn_c = " \u{2659} ";

    constexpr std::string_view white_king_c = " \u{265A} ";
    constexpr std::string_view white_queen_c = " \u{265B} ";
    constexpr std::string_view white_rook_c = " \u{265C} ";
    constexpr std::string_view white_knight_c = " \u{265E} ";
    constexpr std::string_view white_bishop_c = " \u{265D} ";
    constexpr std::string_view white_pawn_c = " \u{265F} ";

    constexpr std::string_view empty_c = " . ";
    //"\u2005\u2005\u2004\u2024\u2004\u2005"; // "1 x \u2003 == 1 x \u3000 == 4 x \u202f";

    if (board == nullptr) return;

    fmt::print("\n\n       A  B  C  D  E  F  G  H\n\n");
    for (std::size_t rank = 8; rank > 0; --rank) {
        fmt::print("  {}   ", rank);
        for (std::size_t file = 0; file < 8; ++file) {
            if (get_bit(board->black_king, rank_file_to_position(rank - 1, file)))
                fmt::print("{}", black_king_c);
            else if (get_bit(board->black_queens, rank_file_to_position(rank - 1, file)))
                fmt::print("{}", black_queen_c);
            else if (get_bit(board->black_rooks, rank_file_to_position(rank - 1, file)))
                fmt::print("{}", black_rook_c);
            else if (get_bit(board->black_knights, rank_file_to_position(rank - 1, file)))
                fmt::print("{}", black_knight_c);
            else if (get_bit(board->black_bishops, rank_file_to_position(rank - 1, file)))
                fmt::print("{}", black_bishop_c);
            else if (get_bit(board->black_pawns, rank_file_to_position(rank - 1, file)))
                fmt::print("{}", black_pawn_c);

            else if (get_bit(board->white_king, rank_file_to_position(rank - 1, file)))
                fmt::print("{}", white_king_c);
            else if (get_bit(board->white_queens, rank_file_to_position(rank - 1, file)))
                fmt::print("{}", white_queen_c);
            else if (get_bit(board->white_rooks, rank_file_to_position(rank - 1, file)))
                fmt::print("{}", white_rook_c);
            else if (get_bit(board->white_knights, rank_file_to_position(rank - 1, file)))
                fmt::print("{}", white_knight_c);
            else if (get_bit(board->white_bishops, rank_file_to_position(rank - 1, file)))
                fmt::print("{}", white_bishop_c);
            else if (get_bit(board->white_pawns, rank_file_to_position(rank - 1, file)))
                fmt::print("{}", white_pawn_c);
            else fmt::print("{}", empty_c);
        }
        fmt::print("\n");
    }
    fmt::print("\n       A  B  C  D  E  F  G  H\n\n");
}
