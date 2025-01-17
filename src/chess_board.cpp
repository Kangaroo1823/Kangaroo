// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
//
// Created by peter on 01/12/2024.
//

#include "chess_board.h"
#include <print>             // for print
#include <cstddef>                // for size_t
#include <numeric>                // for accumulate
#include <ranges>
#include <vector>
#include "bitboard.h"  // for Position_t, set_bit, get_bit, rank_...
#include "types.h"
#include "Board_Status.h"


std::unique_ptr<Kangaroo::Board_Status> Kangaroo::Chess_Board::parce_fen_en_passant_notation(
    std::unique_ptr<Board_Status> &&status, const std::string_view str) {
    std::size_t rank = 8;
    std::size_t file = 8;

    status->en_passant_p = false;

    for (const auto &c: str) {
        switch (c) {
            case 'A':
            case 'a':
                file = 0;
                break;
            case 'B':
            case 'b':
                file = 1;
                break;
            case 'C':
            case 'c':
                file = 2;
                break;
            case 'D':
            case 'd':
                file = 3;
                break;
            case 'E':
            case 'e':
                file = 4; // -V112
                break;
            case 'F':
            case 'f':
                file = 5;
                break;
            case 'G':
            case 'g':
                file = 6;
                break;
            case 'H':
            case 'h':
                file = 7;
                break;
            case '1': rank = 0;
                break;
            case '2': rank = 1;
                break;
            case '3': rank = 2;
                break;
            case '4': rank = 3;
                break;
            case '5': rank = 4; // -V112
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
            en_passant_square = 1ULL << std::to_underlying(rank_file_to_position(rank, file));
            status->en_passant_p = true;
        }
    }

    return status;
}

void Kangaroo::Chess_Board::process_fen_board_setup(const std::string_view str) {
    std::size_t rank = 0;
    std::size_t file = 0;

    for (const auto &c: str) {
        Square position = rank_file_to_position(7 - rank, file);
        file = (file + 1) & 7;
        switch (c) {
            case 'p': black_pawns = set_bit(black_pawns, position);
                break;
            case 'P': white_pawns = set_bit(white_pawns, position);
                break;
            case 'n': black_knights = set_bit(black_knights, position);
                break;
            case 'N': white_knights = set_bit(white_knights, position);
                break;
            case 'b': black_bishops = set_bit(black_bishops, position);
                break;
            case 'B': white_bishops = set_bit(white_bishops, position);
                break;
            case 'r': black_rooks = set_bit(black_rooks, position);
                break;
            case 'R': white_rooks = set_bit(white_rooks, position);
                break;
            case 'q': black_queens = set_bit(black_queens, position);
                break;
            case 'Q': white_queens = set_bit(white_queens, position);
                break;
            case 'k': black_king = set_bit(black_king, position);
                break;
            case 'K': white_king = set_bit(white_king, position);
                break;
            case '/': if (++rank > 7) break;
                file = 0;
                break;
            case '1': break;
            case '2': file = (file + 1) & 7;
                break;
            case '3': file = (file + 2) & 7;
                break;
            case '4': file = (file + 3) & 7;
                break;
            case '5': file = (file + 4) & 7; // -V112
                break;
            case '6': file = (file + 5) & 7;
                break;
            case '7': file = (file + 6) & 7;
                break;
            case '8': file = (file + 7) & 7;
                break;
            default: break;
        }
    }
}

std::unique_ptr<Kangaroo::Board_Status> Kangaroo::Chess_Board::parse_fen_player_to_move(
    std::unique_ptr<Board_Status> &&status, const std::string_view str) {
    using enum Color;

    if (str == "-") {
        status->color_to_move = White;
        return status;
    }

    if (str == "w" || str == "W") {
        status->color_to_move = White;
        return status;
    }

    if (str == "b" || str == "B") {
        status->color_to_move = Black;
        return status;
    }

    throw ReadFENException();
}

std::unique_ptr<Kangaroo::Board_Status> Kangaroo::Chess_Board::parse_fen_castling_information(
    std::unique_ptr<Board_Status> &&status, const std::string_view fen) {
    status->white_king_castle = false;
    status->white_queen_castle = false;
    status->black_king_castle = false;
    status->black_queen_castle = false;

    for (const auto &c: fen) {
        switch (c) {
            case 'K': status->white_king_castle = true;
                break;
            case 'Q': status->white_queen_castle = true;
                break;
            case 'k': status->black_king_castle = true;
                break;
            case 'q': status->black_queen_castle = true;
                break;
            case '-': break;
            default: throw ReadFENException();
        }
    }

    return status;
}

void Kangaroo::Chess_Board::parse_fen_half_move_number(const std::string_view fen) {
    half_move_number = 0;
    for (const auto &c: fen) {
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
                half_move_number =
                        half_move_number * 10 + (static_cast<std::size_t>(c) - static_cast<std::size_t>('0'));
                break;
            default: break;
        }
    }
}

void Kangaroo::Chess_Board::parse_fen_full_move_number(const std::string_view fen) {
    full_move_number = 0;
    for (const auto &c: fen) {
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
                full_move_number =
                        10 * full_move_number + (static_cast<std::size_t>(c) - static_cast<std::size_t>('0'));
                break;
            default: break;
        }
    }
}


std::unique_ptr<Kangaroo::Board_Status> Kangaroo::Chess_Board::reset_board(const std::string_view fen) {
    auto status = std::make_unique<Board_Status>(0);

    white_pawns = 0ULL;
    white_knights = 0ULL;
    white_bishops = 0ULL;
    white_rooks = 0ULL;
    white_queens = 0ULL;
    white_king = 0ULL;
    black_pawns = 0ULL;
    black_knights = 0ULL;
    black_bishops = 0ULL;
    black_rooks = 0ULL;
    black_queens = 0ULL;
    black_king = 0ULL;
    en_passant_square = 0ULL;
    half_move_number = 0ULL;
    full_move_number = 0ULL;

    white_pieces = 0ULL;
    black_pieces = 0ULL;
    all_pieces = 0ULL;


    std::vector<std::string_view> tokens;
    for (auto &&part: std::views::split(fen, ' ')) {
        tokens.emplace_back(std::to_address(part.begin()), std::ranges::distance(part));
    }

    if (tokens.size() < 3) {
        throw ReadFENException();
    }
    process_fen_board_setup(tokens[0]);
    status = parse_fen_player_to_move(std::move(status), tokens[1]);
    status = parse_fen_castling_information(std::move(status), tokens[2]);


    if (tokens.size() >= 4) {
        // -V112
        status = parce_fen_en_passant_notation(std::move(status), tokens[3]);
    }

    if (tokens.size() >= 5) {
        parse_fen_half_move_number(tokens[4]);
    }

    if (tokens.size() >= 6) {
        parse_fen_full_move_number(tokens[5]);
    }

    update_collectors();

    return status;
}

Kangaroo::Chess_Board::Chess_Board(const std::string_view fen) {
    void(reset_board(fen)); // -V530
}

std::ostream &Kangaroo::operator<<(std::ostream &os, const Kangaroo::Chess_Board &board) {
    os << format_chess_board(board, false);
    return os;
}

[[nodiscard]] std::string Kangaroo::format_chess_board(const Chess_Board &board, bool output_data) {
    std::stringstream ss;

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

    if (output_data) {
        ss << std::format("/*\n");
    }

    std::print("\n       A  B  C  D  E  F  G  H\n\n");
    for (std::size_t rank = 8; rank > 0; --rank) {
        ss << std::format("  {}   ", rank);
        for (std::size_t file = 0; file < 8; ++file) {
            if (get_bit(board.black_king, rank_file_to_position(rank - 1, file)))
                ss << std::format("{}", black_king_c);
            else if (get_bit(board.black_queens, rank_file_to_position(rank - 1, file)))
                ss << std::format("{}", black_queen_c);
            else if (get_bit(board.black_rooks, rank_file_to_position(rank - 1, file)))
                ss << std::format("{}", black_rook_c);
            else if (get_bit(board.black_knights, rank_file_to_position(rank - 1, file)))
                ss << std::format("{}", black_knight_c);
            else if (get_bit(board.black_bishops, rank_file_to_position(rank - 1, file)))
                ss << std::format("{}", black_bishop_c);
            else if (get_bit(board.black_pawns, rank_file_to_position(rank - 1, file)))
                ss << std::format("{}", black_pawn_c);

            else if (get_bit(board.white_king, rank_file_to_position(rank - 1, file)))
                ss << std::format("{}", white_king_c);
            else if (get_bit(board.white_queens, rank_file_to_position(rank - 1, file)))
                ss << std::format("{}", white_queen_c);
            else if (get_bit(board.white_rooks, rank_file_to_position(rank - 1, file)))
                ss << std::format("{}", white_rook_c);
            else if (get_bit(board.white_knights, rank_file_to_position(rank - 1, file)))
                ss << std::format("{}", white_knight_c);
            else if (get_bit(board.white_bishops, rank_file_to_position(rank - 1, file)))
                ss << std::format("{}", white_bishop_c);
            else if (get_bit(board.white_pawns, rank_file_to_position(rank - 1, file)))
                ss << std::format("{}", white_pawn_c);
            else ss << std::format("{}", empty_c);
        }
        ss << std::format("\n");
    }
    ss << std::format("\n       A  B  C  D  E  F  G  H\n\n");

    if (output_data) {
        ss << std::format("*/\n  Kangaroo::Chess_Board( std::array<Bitboard, 15>{{\n");
        ss << std::format("    /* white pawns    */ 0x{0:016x}, ", board.white_pawns);
        ss << std::format("/* white knights */ 0x{0:016x}, ", board.white_knights);
        ss << std::format("/* white bishops */ 0x{0:016x}, \n", board.white_bishops);
        ss << std::format("    /* white rooks    */ 0x{0:016x}, ", board.white_rooks);
        ss << std::format("/* white queens  */ 0x{0:016x}, ", board.white_queens);
        ss << std::format("/* white king    */ 0x{0:016x}, \n", board.white_king);
        ss << std::format("    /* black pawns    */ 0x{0:016x}, ", board.black_pawns);
        ss << std::format("/* black knights */ 0x{0:016x}, ", board.black_knights);
        ss << std::format("/* black bishops */ 0x{0:016x}, \n", board.black_bishops);
        ss << std::format("    /* black rooks    */ 0x{0:016x}, ", board.black_rooks);
        ss << std::format("/* black queens  */ 0x{0:016x}, ", board.black_queens);
        ss << std::format("/* black king    */ 0x{0:016x}, \n", board.black_king);
        ss << std::format("    /* en passant sq. */ 0x{0:016x}, ", board.en_passant_square);
        ss << std::format("/* half move num */ 0x{0:016x}, ", board.half_move_number);
        ss << std::format("/* full move num */ 0x{0:016x} }}),\n", board.full_move_number);
    }

    return ss.str();
}

void Kangaroo::print_chess_board(const Chess_Board &board, const bool output_data) {
    std::print("{}", format_chess_board(board, output_data));
}
