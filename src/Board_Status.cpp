// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by U439644 on 1/17/2025.
//

#include <functional>
#include "Base.h"
#include "Types.h"
#include "Board_Status.h"
#include "Movement_Generator.h"

namespace Kangaroo {
    [[nodiscard]] std::size_t Board_Status::run_pawn_move_generation(const CallbackType &callback) const { // -V2008
        switch (to_flags()) {
            case 0x00: return Movement_Generator::generate_pawn_moves<Board_Status(0x00)>(callback);
            case 0x01: return Movement_Generator::generate_pawn_moves<Board_Status(0x01)>(callback);
            case 0x02: return Movement_Generator::generate_pawn_moves<Board_Status(0x02)>(callback);
            case 0x03: return Movement_Generator::generate_pawn_moves<Board_Status(0x03)>(callback);
            case 0x04: return Movement_Generator::generate_pawn_moves<Board_Status(0x04)>(callback);
            case 0x05: return Movement_Generator::generate_pawn_moves<Board_Status(0x05)>(callback);
            case 0x06: return Movement_Generator::generate_pawn_moves<Board_Status(0x06)>(callback);
            case 0x07: return Movement_Generator::generate_pawn_moves<Board_Status(0x07)>(callback);
            case 0x08: return Movement_Generator::generate_pawn_moves<Board_Status(0x08)>(callback);
            case 0x09: return Movement_Generator::generate_pawn_moves<Board_Status(0x09)>(callback);
            case 0x0a: return Movement_Generator::generate_pawn_moves<Board_Status(0x0a)>(callback);
            case 0x0b: return Movement_Generator::generate_pawn_moves<Board_Status(0x0b)>(callback);
            case 0x0c: return Movement_Generator::generate_pawn_moves<Board_Status(0x0c)>(callback);
            case 0x0d: return Movement_Generator::generate_pawn_moves<Board_Status(0x0d)>(callback);
            case 0x0e: return Movement_Generator::generate_pawn_moves<Board_Status(0x0e)>(callback);
            case 0x0f: return Movement_Generator::generate_pawn_moves<Board_Status(0x0f)>(callback);
            case 0x10: return Movement_Generator::generate_pawn_moves<Board_Status(0x10)>(callback);
            case 0x11: return Movement_Generator::generate_pawn_moves<Board_Status(0x11)>(callback);
            case 0x12: return Movement_Generator::generate_pawn_moves<Board_Status(0x12)>(callback);
            case 0x13: return Movement_Generator::generate_pawn_moves<Board_Status(0x13)>(callback);
            case 0x14: return Movement_Generator::generate_pawn_moves<Board_Status(0x14)>(callback);
            case 0x15: return Movement_Generator::generate_pawn_moves<Board_Status(0x15)>(callback);
            case 0x16: return Movement_Generator::generate_pawn_moves<Board_Status(0x16)>(callback);
            case 0x17: return Movement_Generator::generate_pawn_moves<Board_Status(0x17)>(callback);
            case 0x18: return Movement_Generator::generate_pawn_moves<Board_Status(0x18)>(callback);
            case 0x19: return Movement_Generator::generate_pawn_moves<Board_Status(0x19)>(callback);
            case 0x1a: return Movement_Generator::generate_pawn_moves<Board_Status(0x1a)>(callback);
            case 0x1b: return Movement_Generator::generate_pawn_moves<Board_Status(0x1b)>(callback);
            case 0x1c: return Movement_Generator::generate_pawn_moves<Board_Status(0x1c)>(callback);
            case 0x1d: return Movement_Generator::generate_pawn_moves<Board_Status(0x1d)>(callback);
            case 0x1e: return Movement_Generator::generate_pawn_moves<Board_Status(0x1e)>(callback);
            case 0x1f: return Movement_Generator::generate_pawn_moves<Board_Status(0x1f)>(callback);
            case 0x20: return Movement_Generator::generate_pawn_moves<Board_Status(0x20)>(callback);
            case 0x21: return Movement_Generator::generate_pawn_moves<Board_Status(0x21)>(callback);
            case 0x22: return Movement_Generator::generate_pawn_moves<Board_Status(0x22)>(callback);
            case 0x23: return Movement_Generator::generate_pawn_moves<Board_Status(0x23)>(callback);
            case 0x24: return Movement_Generator::generate_pawn_moves<Board_Status(0x24)>(callback);
            case 0x25: return Movement_Generator::generate_pawn_moves<Board_Status(0x25)>(callback);
            case 0x26: return Movement_Generator::generate_pawn_moves<Board_Status(0x26)>(callback);
            case 0x27: return Movement_Generator::generate_pawn_moves<Board_Status(0x27)>(callback);
            case 0x28: return Movement_Generator::generate_pawn_moves<Board_Status(0x28)>(callback);
            case 0x29: return Movement_Generator::generate_pawn_moves<Board_Status(0x29)>(callback);
            case 0x2a: return Movement_Generator::generate_pawn_moves<Board_Status(0x2a)>(callback);
            case 0x2b: return Movement_Generator::generate_pawn_moves<Board_Status(0x2b)>(callback);
            case 0x2c: return Movement_Generator::generate_pawn_moves<Board_Status(0x2c)>(callback);
            case 0x2d: return Movement_Generator::generate_pawn_moves<Board_Status(0x2d)>(callback);
            case 0x2e: return Movement_Generator::generate_pawn_moves<Board_Status(0x2e)>(callback);
            case 0x2f: return Movement_Generator::generate_pawn_moves<Board_Status(0x2f)>(callback);
            case 0x30: return Movement_Generator::generate_pawn_moves<Board_Status(0x30)>(callback);
            case 0x31: return Movement_Generator::generate_pawn_moves<Board_Status(0x31)>(callback);
            case 0x32: return Movement_Generator::generate_pawn_moves<Board_Status(0x32)>(callback);
            case 0x33: return Movement_Generator::generate_pawn_moves<Board_Status(0x33)>(callback);
            case 0x34: return Movement_Generator::generate_pawn_moves<Board_Status(0x34)>(callback);
            case 0x35: return Movement_Generator::generate_pawn_moves<Board_Status(0x35)>(callback);
            case 0x36: return Movement_Generator::generate_pawn_moves<Board_Status(0x36)>(callback);
            case 0x37: return Movement_Generator::generate_pawn_moves<Board_Status(0x37)>(callback);
            case 0x38: return Movement_Generator::generate_pawn_moves<Board_Status(0x38)>(callback);
            case 0x39: return Movement_Generator::generate_pawn_moves<Board_Status(0x39)>(callback);
            case 0x3a: return Movement_Generator::generate_pawn_moves<Board_Status(0x3a)>(callback);
            case 0x3b: return Movement_Generator::generate_pawn_moves<Board_Status(0x3b)>(callback);
            case 0x3c: return Movement_Generator::generate_pawn_moves<Board_Status(0x3c)>(callback);
            case 0x3d: return Movement_Generator::generate_pawn_moves<Board_Status(0x3d)>(callback);
            case 0x3e: return Movement_Generator::generate_pawn_moves<Board_Status(0x3e)>(callback);
            case 0x3f: return Movement_Generator::generate_pawn_moves<Board_Status(0x3f)>(callback);
            case 0x40: return Movement_Generator::generate_pawn_moves<Board_Status(0x40)>(callback);
            default: throw Kangaroo::Invalid_Board_Status();
        }
    }
}
