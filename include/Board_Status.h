//
// Created by peter on 01/01/2025.
//

#ifndef BOARD_STATUS_H
#define BOARD_STATUS_H
#include <stdexcept>

#include "Base.h"
#include "Types.h"



namespace Kangaroo {
    class Chess_Board;


    class Invalid_Board_Status final : public std::runtime_error {
    public:
        Invalid_Board_Status() : std::runtime_error("Invalid m_board status") {
        }

        ~Invalid_Board_Status() override = default;
    };


    class Board_Status {
    public:
        Board_Status() = delete;

        /**
         * Constructor to initialize the m_board status with specific game state parameters.
         *
         * @param color Specifies the current turn color (white or black).
         * @param check Indicates if the current player is in check.
         * @param en_passant Specifies whether an en passant move is possible.
         * @param white_left_castle Indicates if white is allowed to castle on the left (queen's side).
         * @param white_right_castle Indicates if white is allowed to castle on the right (king's side).
         * @param black_left_castle Indicates if black is allowed to castle on the left (queen's side).
         * @param black_right_castle Indicates if black is allowed to castle on the right (king's side).
         */
        constexpr Board_Status(const Color color, const bool en_passant, const bool white_left_castle,
                               const bool white_right_castle,
                               const bool black_left_castle, const bool black_right_castle, const bool check)
            : color_to_move(color), check_p(check), en_passant_p(en_passant),
              white_king_castle(white_left_castle), white_queen_castle(white_right_castle),
              black_king_castle(black_left_castle), black_queen_castle(black_right_castle) {
        }


        /**
         * Constructor to initialize the m_board status using a single 64-bit flags variable.
         *
         * @param flags A 64-bit integer containing encoded information about the game state.
         *              The bits represent:
         *              - Bit 0: Specifies the current turn color (0 for black, 1 for white).
         *              - Bit 1: Specifies whether an en passant move is possible.
         *              - Bit 2: Indicates if white is allowed to castle on the left (queen's side).
         *              - Bit 3: Indicates if white is allowed to castle on the right (king's side).
         *              - Bit 4: Indicates if black is allowed to castle on the left (queen's side).
         *              - Bit 5: Indicates if black is allowed to castle on the right (king's side).
         *              - Bit 6: Indicates if the current player is in check.
         *
         * @return An instance of the `Board_Status` class initialized with the game state parameters
         *         derived from the encoded flags.
         */
        explicit constexpr Board_Status(const uint64_t flags) : color_to_move(
                                                                    (flags & 0x1) ? Color::White : Color::Black),
                                                                check_p((flags & 0x40) != 0),
                                                                en_passant_p((flags & 0x2) != 0),
                                                                white_king_castle((flags & 0x04) != 0),
                                                                white_queen_castle((flags & 0x08) != 0),
                                                                black_king_castle((flags & 0x10) != 0),
                                                                black_queen_castle((flags & 0x20) != 0) {
        }

        [[nodiscard]] _ForceInline constexpr uint64_t to_flags() const {
            uint64_t flags = 0;
            flags |= color_to_move == Color::White ? 0x1 : 0x0;
            flags |= en_passant_p ? 0x2 : 0x0;
            flags |= white_king_castle ? 0x04 : 0x0; // -V112
            flags |= white_queen_castle ? 0x08 : 0x0;
            flags |= black_king_castle ? 0x10 : 0x0;
            flags |= black_queen_castle ? 0x20 : 0x0; // -V112
            flags |= check_p ? 0x40 : 0x0;
            return flags;
        }

        /**
         * Who's turn is it?
         */
        Color color_to_move = Color::White;

        /**
         * Is it a check_p?
         */
        bool check_p = false;

        /**
         * Indicates whether an en passant move is possible.
         * True if en passant is allowed, false otherwise.
         */
        bool en_passant_p = false;

        /**
         * Indicates whether White is allowed to castle on the left (Queen's side).
         * True if castling is still possible, false otherwise.
         */
        bool white_king_castle = true;

        /**
         * Indicates whether White is allowed to castle on the right (King's side).
         * True if castling is still possible, false otherwise.
         */
        bool white_queen_castle = true;

        /**
         * Indicates whether Black is allowed to castle on the left (Queen's side).
         * True if castling is still possible, false otherwise.
         */
        bool black_king_castle = true;

        /**
         * Indicates whether Black is allowed to castle on the right (King's side).
         * True if castling is still possible, false otherwise.
         */
        bool black_queen_castle = true;


        [[nodiscard]] _ForceInline constexpr Board_Status copy_and_set_en_passant(const bool en_passant) const {
            Board_Status copy = *this;
            copy.en_passant_p = en_passant;
            return copy;
        }

        [[nodiscard]] _ForceInline constexpr Board_Status copy_and_prep_for_next_player() const {
            Board_Status copy = *this;

            if (copy.color_to_move == Color::White) {
                copy.color_to_move = Color::Black;
            } else {
                copy.color_to_move = Color::White;
            }
            copy.en_passant_p = false;

            return copy;
        }
    };

    template<template<Board_Status, template<Board_Status, Move_Type, Chess_Pieces, typename ...Args_> class> class T,
        template<Board_Status, Move_Type, Chess_Pieces> class CallbackType, typename... Args>
    [[nodiscard]] _ForceInline constexpr auto execute_status_callback_template(const Board_Status &status, Args... args) {
        switch (status.to_flags()) {
            case 0x00: return T<Board_Status(0x00), CallbackType>::execute(args...);
            case 0x01: return T<Board_Status(0x01), CallbackType>::execute(args...);
            case 0x02: return T<Board_Status(0x02), CallbackType>::execute(args...);
            case 0x03: return T<Board_Status(0x03), CallbackType>::execute(args...);
            case 0x04: return T<Board_Status(0x04), CallbackType>::execute(args...);
            case 0x05: return T<Board_Status(0x05), CallbackType>::execute(args...);
            case 0x06: return T<Board_Status(0x06), CallbackType>::execute(args...);
            case 0x07: return T<Board_Status(0x07), CallbackType>::execute(args...);
            case 0x08: return T<Board_Status(0x08), CallbackType>::execute(args...);
            case 0x09: return T<Board_Status(0x09), CallbackType>::execute(args...);
            case 0x0A: return T<Board_Status(0x0A), CallbackType>::execute(args...);
            case 0x0B: return T<Board_Status(0x0B), CallbackType>::execute(args...);
            case 0x0C: return T<Board_Status(0x0C), CallbackType>::execute(args...);
            case 0x0D: return T<Board_Status(0x0D), CallbackType>::execute(args...);
            case 0x0E: return T<Board_Status(0x0E), CallbackType>::execute(args...);
            case 0x0F: return T<Board_Status(0x0F), CallbackType>::execute(args...);
            case 0x10: return T<Board_Status(0x10), CallbackType>::execute(args...);
            case 0x11: return T<Board_Status(0x11), CallbackType>::execute(args...);
            case 0x12: return T<Board_Status(0x12), CallbackType>::execute(args...);
            case 0x13: return T<Board_Status(0x13), CallbackType>::execute(args...);
            case 0x14: return T<Board_Status(0x14), CallbackType>::execute(args...);
            case 0x15: return T<Board_Status(0x15), CallbackType>::execute(args...);
            case 0x16: return T<Board_Status(0x16), CallbackType>::execute(args...);
            case 0x17: return T<Board_Status(0x17), CallbackType>::execute(args...);
            case 0x18: return T<Board_Status(0x18), CallbackType>::execute(args...);
            case 0x19: return T<Board_Status(0x19), CallbackType>::execute(args...);
            case 0x1A: return T<Board_Status(0x1A), CallbackType>::execute(args...);
            case 0x1B: return T<Board_Status(0x1B), CallbackType>::execute(args...);
            case 0x1C: return T<Board_Status(0x1C), CallbackType>::execute(args...);
            case 0x1D: return T<Board_Status(0x1D), CallbackType>::execute(args...);
            case 0x1E: return T<Board_Status(0x1E), CallbackType>::execute(args...);
            case 0x1F: return T<Board_Status(0x1F), CallbackType>::execute(args...);
            case 0x20: return T<Board_Status(0x20), CallbackType>::execute(args...);
            case 0x21: return T<Board_Status(0x21), CallbackType>::execute(args...);
            case 0x22: return T<Board_Status(0x22), CallbackType>::execute(args...);
            case 0x23: return T<Board_Status(0x23), CallbackType>::execute(args...);
            case 0x24: return T<Board_Status(0x24), CallbackType>::execute(args...);
            case 0x25: return T<Board_Status(0x25), CallbackType>::execute(args...);
            case 0x26: return T<Board_Status(0x26), CallbackType>::execute(args...);
            case 0x27: return T<Board_Status(0x27), CallbackType>::execute(args...);
            case 0x28: return T<Board_Status(0x28), CallbackType>::execute(args...);
            case 0x29: return T<Board_Status(0x29), CallbackType>::execute(args...);
            case 0x2A: return T<Board_Status(0x2A), CallbackType>::execute(args...);
            case 0x2B: return T<Board_Status(0x2B), CallbackType>::execute(args...);
            case 0x2C: return T<Board_Status(0x2C), CallbackType>::execute(args...);
            case 0x2D: return T<Board_Status(0x2D), CallbackType>::execute(args...);
            case 0x2E: return T<Board_Status(0x2E), CallbackType>::execute(args...);
            case 0x2F: return T<Board_Status(0x2F), CallbackType>::execute(args...);
            case 0x30: return T<Board_Status(0x30), CallbackType>::execute(args...);
            case 0x31: return T<Board_Status(0x31), CallbackType>::execute(args...);
            case 0x32: return T<Board_Status(0x32), CallbackType>::execute(args...);
            case 0x33: return T<Board_Status(0x33), CallbackType>::execute(args...);
            case 0x34: return T<Board_Status(0x34), CallbackType>::execute(args...);
            case 0x35: return T<Board_Status(0x35), CallbackType>::execute(args...);
            case 0x36: return T<Board_Status(0x36), CallbackType>::execute(args...);
            case 0x37: return T<Board_Status(0x37), CallbackType>::execute(args...);
            case 0x38: return T<Board_Status(0x38), CallbackType>::execute(args...);
            case 0x39: return T<Board_Status(0x39), CallbackType>::execute(args...);
            case 0x3A: return T<Board_Status(0x3A), CallbackType>::execute(args...);
            case 0x3B: return T<Board_Status(0x3B), CallbackType>::execute(args...);
            case 0x3C: return T<Board_Status(0x3C), CallbackType>::execute(args...);
            case 0x3D: return T<Board_Status(0x3D), CallbackType>::execute(args...);
            case 0x3E: return T<Board_Status(0x3E), CallbackType>::execute(args...);
            case 0x3F: return T<Board_Status(0x3F), CallbackType>::execute(args...);
            case 0x40: return T<Board_Status(0x40), CallbackType>::execute(args...);
            default: { throw Invalid_Board_Status(); }
        }
    }

#define Status_Callback_Template(tn, ...) template<Board_Status status, template<Board_Status, Move_Type, Chess_Pieces> class CallbackType> class tn { public: _ForceInline static constexpr auto execute(__VA_ARGS__); }; template<Board_Status status, template<Board_Status, Move_Type, Chess_Pieces> class CallbackType> _ForceInline constexpr auto tn<status, CallbackType>::execute(__VA_ARGS__)


    template<template<Board_Status status> class T, typename... Args>
    [[nodiscard]] _ForceInline constexpr auto execute_status_template(const Board_Status &status, Args... args) {
        switch (status.to_flags()) {
            case 0x00: return T<Board_Status(0x00)>::execute(args...);
            case 0x01: return T<Board_Status(0x01)>::execute(args...);
            case 0x02: return T<Board_Status(0x02)>::execute(args...);
            case 0x03: return T<Board_Status(0x03)>::execute(args...);
            case 0x04: return T<Board_Status(0x04)>::execute(args...);
            case 0x05: return T<Board_Status(0x05)>::execute(args...);
            case 0x06: return T<Board_Status(0x06)>::execute(args...);
            case 0x07: return T<Board_Status(0x07)>::execute(args...);
            case 0x08: return T<Board_Status(0x08)>::execute(args...);
            case 0x09: return T<Board_Status(0x09)>::execute(args...);
            case 0x0A: return T<Board_Status(0x0A)>::execute(args...);
            case 0x0B: return T<Board_Status(0x0B)>::execute(args...);
            case 0x0C: return T<Board_Status(0x0C)>::execute(args...);
            case 0x0D: return T<Board_Status(0x0D)>::execute(args...);
            case 0x0E: return T<Board_Status(0x0E)>::execute(args...);
            case 0x0F: return T<Board_Status(0x0F)>::execute(args...);
            case 0x10: return T<Board_Status(0x10)>::execute(args...);
            case 0x11: return T<Board_Status(0x11)>::execute(args...);
            case 0x12: return T<Board_Status(0x12)>::execute(args...);
            case 0x13: return T<Board_Status(0x13)>::execute(args...);
            case 0x14: return T<Board_Status(0x14)>::execute(args...);
            case 0x15: return T<Board_Status(0x15)>::execute(args...);
            case 0x16: return T<Board_Status(0x16)>::execute(args...);
            case 0x17: return T<Board_Status(0x17)>::execute(args...);
            case 0x18: return T<Board_Status(0x18)>::execute(args...);
            case 0x19: return T<Board_Status(0x19)>::execute(args...);
            case 0x1A: return T<Board_Status(0x1A)>::execute(args...);
            case 0x1B: return T<Board_Status(0x1B)>::execute(args...);
            case 0x1C: return T<Board_Status(0x1C)>::execute(args...);
            case 0x1D: return T<Board_Status(0x1D)>::execute(args...);
            case 0x1E: return T<Board_Status(0x1E)>::execute(args...);
            case 0x1F: return T<Board_Status(0x1F)>::execute(args...);
            case 0x20: return T<Board_Status(0x20)>::execute(args...);
            case 0x21: return T<Board_Status(0x21)>::execute(args...);
            case 0x22: return T<Board_Status(0x22)>::execute(args...);
            case 0x23: return T<Board_Status(0x23)>::execute(args...);
            case 0x24: return T<Board_Status(0x24)>::execute(args...);
            case 0x25: return T<Board_Status(0x25)>::execute(args...);
            case 0x26: return T<Board_Status(0x26)>::execute(args...);
            case 0x27: return T<Board_Status(0x27)>::execute(args...);
            case 0x28: return T<Board_Status(0x28)>::execute(args...);
            case 0x29: return T<Board_Status(0x29)>::execute(args...);
            case 0x2A: return T<Board_Status(0x2A)>::execute(args...);
            case 0x2B: return T<Board_Status(0x2B)>::execute(args...);
            case 0x2C: return T<Board_Status(0x2C)>::execute(args...);
            case 0x2D: return T<Board_Status(0x2D)>::execute(args...);
            case 0x2E: return T<Board_Status(0x2E)>::execute(args...);
            case 0x2F: return T<Board_Status(0x2F)>::execute(args...);
            case 0x30: return T<Board_Status(0x30)>::execute(args...);
            case 0x31: return T<Board_Status(0x31)>::execute(args...);
            case 0x32: return T<Board_Status(0x32)>::execute(args...);
            case 0x33: return T<Board_Status(0x33)>::execute(args...);
            case 0x34: return T<Board_Status(0x34)>::execute(args...);
            case 0x35: return T<Board_Status(0x35)>::execute(args...);
            case 0x36: return T<Board_Status(0x36)>::execute(args...);
            case 0x37: return T<Board_Status(0x37)>::execute(args...);
            case 0x38: return T<Board_Status(0x38)>::execute(args...);
            case 0x39: return T<Board_Status(0x39)>::execute(args...);
            case 0x3A: return T<Board_Status(0x3A)>::execute(args...);
            case 0x3B: return T<Board_Status(0x3B)>::execute(args...);
            case 0x3C: return T<Board_Status(0x3C)>::execute(args...);
            case 0x3D: return T<Board_Status(0x3D)>::execute(args...);
            case 0x3E: return T<Board_Status(0x3E)>::execute(args...);
            case 0x3F: return T<Board_Status(0x3F)>::execute(args...);
            case 0x40: return T<Board_Status(0x40)>::execute(args...);
            default: throw Invalid_Board_Status();
        }
    }

#define Status_Template(template_name, ...) template<Board_Status status> class template_name { public: _ForceInline constexpr static void execute(__VA_ARGS__); }; template<Board_Status status> _ForceInline constexpr void template_name<status>::execute(__VA_ARGS__)


#define Callback_Template(tn, ...) template<Board_Status status, Move_Type move_type, Chess_Pieces chess_piece> class tn { public: _ForceInline constexpr static auto callback(const Chess_Board *board, Bitboard move, Bitboard from, Bitboard to __VA_OPT__(,) __VA_ARGS__); }; template<Board_Status status, Move_Type move_type, Chess_Pieces chess_piece> constexpr auto tn<status, move_type, chess_piece>::callback([[maybe_unused]] const Chess_Board *board, [[maybe_unused]] Bitboard move, [[maybe_unused]] Bitboard from, [[maybe_unused]] Bitboard to __VA_OPT__(,) __VA_ARGS__)
#define Callback_Template_MT_Specialization(tn, move_type, ...) template<Board_Status status, Chess_Pieces chess_piece> class tn<status, move_type, chess_piece> { public: _ForceInline constexpr static auto callback(const Chess_Board *board, Bitboard move, Bitboard from, Bitboard to __VA_OPT__(,) __VA_ARGS__); }; template<Board_Status status, Chess_Pieces chess_piece> constexpr auto tn<status, move_type, chess_piece>::callback([[maybe_unused]] const Chess_Board *board, [[maybe_unused]] Bitboard move, [[maybe_unused]] Bitboard from, [[maybe_unused]] Bitboard to __VA_OPT__(,) __VA_ARGS__)
#define Callback_Template_CP_Specialization(tn, chess_piece, ...) template<Board_Status status, Move_Type move_type> class tn<status, move_type, chess_piece> { public: _ForceInline constexpr static auto callback(const Chess_Board *board, Bitboard move, Bitboard from, Bitboard to __VA_OPT(,) __VA_ARGS__); }; template<Board_Status status, Move_Type move_type> constexpr auto tn<status, move_type, chess_piece>::callback([[maybe_unused]] const Chess_Board *board, [[maybe_unused]] Bitboard move, [[maybe_unused]] Bitboard from, [[maybe_unused]] Bitboard to __VA_OPT__(,) __VA_ARGS__)
#define Callback_Template_MT_CP_Specialization(tn, move_type, chess_piece, ...) template<Board_Status status> class tn<status, move_type, chess_piece> { public: _ForceInline constexpr static auto callback(const Chess_Board *board, Bitboard move, Bitboard from, Bitboard to __VA_OPT__(,) __VA_ARGS__); }; template<Board_Status status> constexpr auto tn<status, move_type, chess_piece>::callback([[maybe_unused]] const Chess_Board *board, [[maybe_unused]] Bitboard move, [[maybe_unused]] Bitboard from, [[maybe_unused]] Bitboard to __VA_OPT__(,) __VA_ARGS__)

} // Kangaroo

#endif //BOARD_STATUS_H
