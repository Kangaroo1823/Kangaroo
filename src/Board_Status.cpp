// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by U439644 on 1/17/2025.
//


#include "Board_Status.h"
#include "Move_Generator/Move_Generator.h"

namespace Kangaroo {


    [[nodiscard]] std::size_t Board_Status::run_pawn_move_generation(Chess_Board *board) const {
        switch (to_flags()) {
            case 0x00: { Move_Generator::Move_Generator<Board_Status(0x00)> gen(board); return gen.generate_moves(); }
            case 0x01: { Move_Generator::Move_Generator<Board_Status(0x01)> gen(board); return gen.generate_moves(); }
            case 0x02: { Move_Generator::Move_Generator<Board_Status(0x02)> gen(board); return gen.generate_moves(); }
            case 0x03: { Move_Generator::Move_Generator<Board_Status(0x03)> gen(board); return gen.generate_moves(); }
            case 0x04: { Move_Generator::Move_Generator<Board_Status(0x04)> gen(board); return gen.generate_moves(); }
            case 0x05: { Move_Generator::Move_Generator<Board_Status(0x05)> gen(board); return gen.generate_moves(); }
            case 0x06: { Move_Generator::Move_Generator<Board_Status(0x06)> gen(board); return gen.generate_moves(); }
            case 0x07: { Move_Generator::Move_Generator<Board_Status(0x07)> gen(board); return gen.generate_moves(); }
            case 0x08: { Move_Generator::Move_Generator<Board_Status(0x08)> gen(board); return gen.generate_moves(); }
            case 0x09: { Move_Generator::Move_Generator<Board_Status(0x09)> gen(board); return gen.generate_moves(); }
            case 0x0a: { Move_Generator::Move_Generator<Board_Status(0x0a)> gen(board); return gen.generate_moves(); }
            case 0x0b: { Move_Generator::Move_Generator<Board_Status(0x0b)> gen(board); return gen.generate_moves(); }
            case 0x0c: { Move_Generator::Move_Generator<Board_Status(0x0c)> gen(board); return gen.generate_moves(); }
            case 0x0d: { Move_Generator::Move_Generator<Board_Status(0x0d)> gen(board); return gen.generate_moves(); }
            case 0x0e: { Move_Generator::Move_Generator<Board_Status(0x0e)> gen(board); return gen.generate_moves(); }
            case 0x0f: { Move_Generator::Move_Generator<Board_Status(0x0f)> gen(board); return gen.generate_moves(); }
            case 0x10: { Move_Generator::Move_Generator<Board_Status(0x10)> gen(board); return gen.generate_moves(); }
            case 0x11: { Move_Generator::Move_Generator<Board_Status(0x11)> gen(board); return gen.generate_moves(); }
            case 0x12: { Move_Generator::Move_Generator<Board_Status(0x12)> gen(board); return gen.generate_moves(); }
            case 0x13: { Move_Generator::Move_Generator<Board_Status(0x13)> gen(board); return gen.generate_moves(); }
            case 0x14: { Move_Generator::Move_Generator<Board_Status(0x14)> gen(board); return gen.generate_moves(); }
            case 0x15: { Move_Generator::Move_Generator<Board_Status(0x15)> gen(board); return gen.generate_moves(); }
            case 0x16: { Move_Generator::Move_Generator<Board_Status(0x16)> gen(board); return gen.generate_moves(); }
            case 0x17: { Move_Generator::Move_Generator<Board_Status(0x17)> gen(board); return gen.generate_moves(); }
            case 0x18: { Move_Generator::Move_Generator<Board_Status(0x18)> gen(board); return gen.generate_moves(); }
            case 0x19: { Move_Generator::Move_Generator<Board_Status(0x19)> gen(board); return gen.generate_moves(); }
            case 0x1a: { Move_Generator::Move_Generator<Board_Status(0x1a)> gen(board); return gen.generate_moves(); }
            case 0x1b: { Move_Generator::Move_Generator<Board_Status(0x1b)> gen(board); return gen.generate_moves(); }
            case 0x1c: { Move_Generator::Move_Generator<Board_Status(0x1c)> gen(board); return gen.generate_moves(); }
            case 0x1d: { Move_Generator::Move_Generator<Board_Status(0x1d)> gen(board); return gen.generate_moves(); }
            case 0x1e: { Move_Generator::Move_Generator<Board_Status(0x1e)> gen(board); return gen.generate_moves(); }
            case 0x1f: { Move_Generator::Move_Generator<Board_Status(0x1f)> gen(board); return gen.generate_moves(); }
            case 0x20: { Move_Generator::Move_Generator<Board_Status(0x20)> gen(board); return gen.generate_moves(); }
            case 0x21: { Move_Generator::Move_Generator<Board_Status(0x21)> gen(board); return gen.generate_moves(); }
            case 0x22: { Move_Generator::Move_Generator<Board_Status(0x22)> gen(board); return gen.generate_moves(); }
            case 0x23: { Move_Generator::Move_Generator<Board_Status(0x23)> gen(board); return gen.generate_moves(); }
            case 0x24: { Move_Generator::Move_Generator<Board_Status(0x24)> gen(board); return gen.generate_moves(); }
            case 0x25: { Move_Generator::Move_Generator<Board_Status(0x25)> gen(board); return gen.generate_moves(); }
            case 0x26: { Move_Generator::Move_Generator<Board_Status(0x26)> gen(board); return gen.generate_moves(); }
            case 0x27: { Move_Generator::Move_Generator<Board_Status(0x27)> gen(board); return gen.generate_moves(); }
            case 0x28: { Move_Generator::Move_Generator<Board_Status(0x28)> gen(board); return gen.generate_moves(); }
            case 0x29: { Move_Generator::Move_Generator<Board_Status(0x29)> gen(board); return gen.generate_moves(); }
            case 0x2a: { Move_Generator::Move_Generator<Board_Status(0x2a)> gen(board); return gen.generate_moves(); }
            case 0x2b: { Move_Generator::Move_Generator<Board_Status(0x2b)> gen(board); return gen.generate_moves(); }
            case 0x2c: { Move_Generator::Move_Generator<Board_Status(0x2c)> gen(board); return gen.generate_moves(); }
            case 0x2d: { Move_Generator::Move_Generator<Board_Status(0x2d)> gen(board); return gen.generate_moves(); }
            case 0x2e: { Move_Generator::Move_Generator<Board_Status(0x2e)> gen(board); return gen.generate_moves(); }
            case 0x2f: { Move_Generator::Move_Generator<Board_Status(0x2f)> gen(board); return gen.generate_moves(); }
            case 0x30: { Move_Generator::Move_Generator<Board_Status(0x30)> gen(board); return gen.generate_moves(); }
            case 0x31: { Move_Generator::Move_Generator<Board_Status(0x31)> gen(board); return gen.generate_moves(); }
            case 0x32: { Move_Generator::Move_Generator<Board_Status(0x32)> gen(board); return gen.generate_moves(); }
            case 0x33: { Move_Generator::Move_Generator<Board_Status(0x33)> gen(board); return gen.generate_moves(); }
            case 0x34: { Move_Generator::Move_Generator<Board_Status(0x34)> gen(board); return gen.generate_moves(); }
            case 0x35: { Move_Generator::Move_Generator<Board_Status(0x35)> gen(board); return gen.generate_moves(); }
            case 0x36: { Move_Generator::Move_Generator<Board_Status(0x36)> gen(board); return gen.generate_moves(); }
            case 0x37: { Move_Generator::Move_Generator<Board_Status(0x37)> gen(board); return gen.generate_moves(); }
            case 0x38: { Move_Generator::Move_Generator<Board_Status(0x38)> gen(board); return gen.generate_moves(); }
            case 0x39: { Move_Generator::Move_Generator<Board_Status(0x39)> gen(board); return gen.generate_moves(); }
            case 0x3a: { Move_Generator::Move_Generator<Board_Status(0x3a)> gen(board); return gen.generate_moves(); }
            case 0x3b: { Move_Generator::Move_Generator<Board_Status(0x3b)> gen(board); return gen.generate_moves(); }
            case 0x3c: { Move_Generator::Move_Generator<Board_Status(0x3c)> gen(board); return gen.generate_moves(); }
            case 0x3d: { Move_Generator::Move_Generator<Board_Status(0x3d)> gen(board); return gen.generate_moves(); }
            case 0x3e: { Move_Generator::Move_Generator<Board_Status(0x3e)> gen(board); return gen.generate_moves(); }
            case 0x3f: { Move_Generator::Move_Generator<Board_Status(0x3f)> gen(board); return gen.generate_moves(); }
            case 0x40: { Move_Generator::Move_Generator<Board_Status(0x40)> gen(board); return gen.generate_moves(); }
            default: throw Kangaroo::Invalid_Board_Status();
        }
    }
}
