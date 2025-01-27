//
// Created by peter on 01/01/2025.
//

#ifndef BOARD_STATUS_H
#define BOARD_STATUS_H
#include <functional>
#include <memory>
#include <stdexcept>

#include "Base.h"
#include "Types.h"


namespace Kangaroo {
    class Chess_Board;

    typedef std::function<void(const Chess_Board *, Move, Color, Chess_Pieces)> CallbackType;


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

        [[nodiscard]] std::size_t run_pawn_move_generation(Chess_Board *board, const CallbackType &callback) const;
    };

    template<template<Board_Status status> class T, typename... Args>
    void execute_status_template(const Board_Status &status, Args... args) {
        switch (status.to_flags()) {
            case 0x00: {
                T<Board_Status(0x00)>::execute(args...);
                break;
            }
            case 0x01: {
                T<Board_Status(0x01)>::execute(args...);
                break;
            }
            case 0x02: {
                T<Board_Status(0x02)>::execute(args...);
                break;
            }
            case 0x03: {
                T<Board_Status(0x03)>::execute(args...);
                break;
            }
            case 0x04: {
                T<Board_Status(0x04)>::execute(args...);
                break;
            }
            case 0x05: {
                T<Board_Status(0x05)>::execute(args...);
                break;
            }
            case 0x06: {
                T<Board_Status(0x06)>::execute(args...);
                break;
            }
            case 0x07: {
                T<Board_Status(0x07)>::execute(args...);
                break;
            }
            case 0x08: {
                T<Board_Status(0x08)>::execute(args...);
                break;
            }
            case 0x09: {
                T<Board_Status(0x09)>::execute(args...);
                break;
            }
            case 0x0A: {
                T<Board_Status(0x0A)>::execute(args...);
                break;
            }
            case 0x0B: {
                T<Board_Status(0x0B)>::execute(args...);
                break;
            }
            case 0x0C: {
                T<Board_Status(0x0C)>::execute(args...);
                break;
            }
            case 0x0D: {
                T<Board_Status(0x0D)>::execute(args...);
                break;
            }
            case 0x0E: {
                T<Board_Status(0x0E)>::execute(args...);
                break;
            }
            case 0x0F: {
                T<Board_Status(0x0F)>::execute(args...);
                break;
            }
            case 0x10: {
                T<Board_Status(0x10)>::execute(args...);
                break;
            }
            case 0x11: {
                T<Board_Status(0x11)>::execute(args...);
                break;
            }
            case 0x12: {
                T<Board_Status(0x12)>::execute(args...);
                break;
            }
            case 0x13: {
                T<Board_Status(0x13)>::execute(args...);
                break;
            }
            case 0x14: {
                T<Board_Status(0x14)>::execute(args...);
                break;
            }
            case 0x15: {
                T<Board_Status(0x15)>::execute(args...);
                break;
            }
            case 0x16: {
                T<Board_Status(0x16)>::execute(args...);
                break;
            }
            case 0x17: {
                T<Board_Status(0x17)>::execute(args...);
                break;
            }
            case 0x18: {
                T<Board_Status(0x18)>::execute(args...);
                break;
            }
            case 0x19: {
                T<Board_Status(0x19)>::execute(args...);
                break;
            }
            case 0x1A: {
                T<Board_Status(0x1A)>::execute(args...);
                break;
            }
            case 0x1B: {
                T<Board_Status(0x1B)>::execute(args...);
                break;
            }
            case 0x1C: {
                T<Board_Status(0x1C)>::execute(args...);
                break;
            }
            case 0x1D: {
                T<Board_Status(0x1D)>::execute(args...);
                break;
            }
            case 0x1E: {
                T<Board_Status(0x1E)>::execute(args...);
                break;
            }
            case 0x1F: {
                T<Board_Status(0x1F)>::execute(args...);
                break;
            }
            case 0x20: {
                T<Board_Status(0x20)>::execute(args...);
                break;
            }
            case 0x21: {
                T<Board_Status(0x21)>::execute(args...);
                break;
            }
            case 0x22: {
                T<Board_Status(0x22)>::execute(args...);
                break;
            }
            case 0x23: {
                T<Board_Status(0x23)>::execute(args...);
                break;
            }
            case 0x24: {
                T<Board_Status(0x24)>::execute(args...);
                break;
            }
            case 0x25: {
                T<Board_Status(0x25)>::execute(args...);
                break;
            }
            case 0x26: {
                T<Board_Status(0x26)>::execute(args...);
                break;
            }
            case 0x27: {
                T<Board_Status(0x27)>::execute(args...);
                break;
            }
            case 0x28: {
                T<Board_Status(0x28)>::execute(args...);
                break;
            }
            case 0x29: {
                T<Board_Status(0x29)>::execute(args...);
                break;
            }
            case 0x2A: {
                T<Board_Status(0x2A)>::execute(args...);
                break;
            }
            case 0x2B: {
                T<Board_Status(0x2B)>::execute(args...);
                break;
            }
            case 0x2C: {
                T<Board_Status(0x2C)>::execute(args...);
                break;
            }
            case 0x2D: {
                T<Board_Status(0x2D)>::execute(args...);
                break;
            }
            case 0x2E: {
                T<Board_Status(0x2E)>::execute(args...);
                break;
            }
            case 0x2F: {
                T<Board_Status(0x2F)>::execute(args...);
                break;
            }
            case 0x30: {
                T<Board_Status(0x30)>::execute(args...);
                break;
            }
            case 0x31: {
                T<Board_Status(0x31)>::execute(args...);
                break;
            }
            case 0x32: {
                T<Board_Status(0x32)>::execute(args...);
                break;
            }
            case 0x33: {
                T<Board_Status(0x33)>::execute(args...);
                break;
            }
            case 0x34: {
                T<Board_Status(0x34)>::execute(args...);
                break;
            }
            case 0x35: {
                T<Board_Status(0x35)>::execute(args...);
                break;
            }
            case 0x36: {
                T<Board_Status(0x36)>::execute(args...);
                break;
            }
            case 0x37: {
                T<Board_Status(0x37)>::execute(args...);
                break;
            }
            case 0x38: {
                T<Board_Status(0x38)>::execute(args...);
                break;
            }
            case 0x39: {
                T<Board_Status(0x39)>::execute(args...);
                break;
            }
            case 0x3A: {
                T<Board_Status(0x3A)>::execute(args...);
                break;
            }
            case 0x3B: {
                T<Board_Status(0x3B)>::execute(args...);
                break;
            }
            case 0x3C: {
                T<Board_Status(0x3C)>::execute(args...);
                break;
            }
            case 0x3D: {
                T<Board_Status(0x3D)>::execute(args...);
                break;
            }
            case 0x3E: {
                T<Board_Status(0x3E)>::execute(args...);
                break;
            }
            case 0x3F: {
                T<Board_Status(0x3F)>::execute(args...);
                break;
            }
            case 0x40: {
                T<Board_Status(0x40)>::execute(args...);
                break;
            }
            default: {
                throw Invalid_Board_Status();
            }
        }
    }

#define Status_Template(template_name, ...) template<Board_Status status> class template_name { public: _ForceInline constexpr static void execute(__VA_ARGS__); }; template<Board_Status status> _ForceInline constexpr void template_name<status>::execute
} // Kangaroo

#endif //BOARD_STATUS_H
