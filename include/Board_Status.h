//
// Created by peter on 01/01/2025.
//

#ifndef BOARD_STATUS_H
#define BOARD_STATUS_H
#include "base.h"
#include "colors.h"
#include "types.h"


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
            : color_to_move(color), check_p(check), en_passant_p(en_passant),
              white_king_castle(white_left_castle), white_queen_castle(white_right_castle),
              black_king_castle(black_left_castle), black_queen_castle(black_right_castle) {
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
            flags |= white_king_castle ? 0x04 : 0x0;
            flags |= white_queen_castle ? 0x08 : 0x0;
            flags |= black_king_castle ? 0x10 : 0x0;
            flags |= black_queen_castle ? 0x20 : 0x0;
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

        /**
         * Represents the mode in which move generation is conducted during gameplay.
         *
         * The possible modes include:
         * - normal_move_generation: Default mode for generating legal moves under standard rules.
         * - pin_move_generation: Mode for generating moves while considering pin constraints.
         * - check_move_generation: Mode for generating only those moves that resolve a check.
         */
        Move_Generation_Mode mode = Move_Generation_Mode::Normal_Move_Generation;

        [[nodiscard]] _ForceInline constexpr Board_Status copy_and_set_mode(const Move_Generation_Mode _mode) const {
            Board_Status copy = *this;
            copy.mode = _mode;
            return copy;
        }
    };
} // Kangaroo

#endif //BOARD_STATUS_H
