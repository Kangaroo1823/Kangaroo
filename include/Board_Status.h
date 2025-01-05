//
// Created by peter on 01/01/2025.
//

#ifndef BOARD_STATUS_H
#define BOARD_STATUS_H
#include <string_view>

#include "colors.h"

namespace Kangaroo {
    class Board_Status {
    public:
        Board_Status() = delete;

        /**
         * Constructor to initialize the board status with specific game state parameters.
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
            : color_p(color), check_p(check), en_passant_p(en_passant),
              white_left_castle_p(white_left_castle), white_right_castle_p(white_right_castle),
              black_left_castle_p(black_left_castle), black_right_castle_p(black_right_castle) {
        }


        /**
         * Constructor to initialize the board status using a single 64-bit flags variable.
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
        explicit constexpr Board_Status(const uint64_t flags) : color_p((flags & 0x1) ? Color::white : Color::black),
                                                                check_p((flags & 0x40) != 0),
                                                                en_passant_p((flags & 0x2) != 0),
                                                                white_left_castle_p((flags & 0x04) != 0),
                                                                white_right_castle_p((flags & 0x08) != 0),
                                                                black_left_castle_p((flags & 0x10) != 0),
                                                                black_right_castle_p((flags & 0x20) != 0) {
        }

        /**
         * Who's turn is it?
         */
        Color color_p = Color::white;

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
         * Indicates whether white is allowed to castle on the left (queen's side).
         * True if castling is still possible, false otherwise.
         */
        bool white_left_castle_p = true;

        /**
         * Indicates whether white is allowed to castle on the right (king's side).
         * True if castling is still possible, false otherwise.
         */
        bool white_right_castle_p = true;

        /**
         * Indicates whether black is allowed to castle on the left (queen's side).
         * True if castling is still possible, false otherwise.
         */
        bool black_left_castle_p = true;

        /**
         * Indicates whether black is allowed to castle on the right (king's side).
         * True if castling is still possible, false otherwise.
         */
        bool black_right_castle_p = true;
    };
} // Kangaroo

#endif //BOARD_STATUS_H
