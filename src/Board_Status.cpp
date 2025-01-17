// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
//
// Created by U439644 on 1/17/2025.
//

#include <functional>
#include "base.h"
#include "types.h"
#include "Board_Status.h"
#include "Movement_Generator.h"

namespace Kangaroo {
    [[nodiscard]] std::size_t Board_Status::run_move_generation(Movement_Generator &gen,
        const CallbackType& callback) const { // -V2008
        switch (to_flags()) {
            case 0x00: return gen.generate_moves<Board_Status(0x00)>(callback);
            case 0x01: return gen.generate_moves<Board_Status(0x01)>(callback);
            case 0x02: return gen.generate_moves<Board_Status(0x02)>(callback);
            case 0x03: return gen.generate_moves<Board_Status(0x03)>(callback);
            case 0x04: return gen.generate_moves<Board_Status(0x04)>(callback);
            case 0x05: return gen.generate_moves<Board_Status(0x05)>(callback);
            case 0x06: return gen.generate_moves<Board_Status(0x06)>(callback);
            case 0x07: return gen.generate_moves<Board_Status(0x07)>(callback);
            case 0x08: return gen.generate_moves<Board_Status(0x08)>(callback);
            case 0x09: return gen.generate_moves<Board_Status(0x09)>(callback);
            case 0x0a: return gen.generate_moves<Board_Status(0x0a)>(callback);
            case 0x0b: return gen.generate_moves<Board_Status(0x0b)>(callback);
            case 0x0c: return gen.generate_moves<Board_Status(0x0c)>(callback);
            case 0x0d: return gen.generate_moves<Board_Status(0x0d)>(callback);
            case 0x0e: return gen.generate_moves<Board_Status(0x0e)>(callback);
            case 0x0f: return gen.generate_moves<Board_Status(0x0f)>(callback);
            case 0x10: return gen.generate_moves<Board_Status(0x10)>(callback);
            case 0x11: return gen.generate_moves<Board_Status(0x11)>(callback);
            case 0x12: return gen.generate_moves<Board_Status(0x12)>(callback);
            case 0x13: return gen.generate_moves<Board_Status(0x13)>(callback);
            case 0x14: return gen.generate_moves<Board_Status(0x14)>(callback);
            case 0x15: return gen.generate_moves<Board_Status(0x15)>(callback);
            case 0x16: return gen.generate_moves<Board_Status(0x16)>(callback);
            case 0x17: return gen.generate_moves<Board_Status(0x17)>(callback);
            case 0x18: return gen.generate_moves<Board_Status(0x18)>(callback);
            case 0x19: return gen.generate_moves<Board_Status(0x19)>(callback);
            case 0x1a: return gen.generate_moves<Board_Status(0x1a)>(callback);
            case 0x1b: return gen.generate_moves<Board_Status(0x1b)>(callback);
            case 0x1c: return gen.generate_moves<Board_Status(0x1c)>(callback);
            case 0x1d: return gen.generate_moves<Board_Status(0x1d)>(callback);
            case 0x1e: return gen.generate_moves<Board_Status(0x1e)>(callback);
            case 0x1f: return gen.generate_moves<Board_Status(0x1f)>(callback);
            case 0x20: return gen.generate_moves<Board_Status(0x20)>(callback);
            case 0x21: return gen.generate_moves<Board_Status(0x21)>(callback);
            case 0x22: return gen.generate_moves<Board_Status(0x22)>(callback);
            case 0x23: return gen.generate_moves<Board_Status(0x23)>(callback);
            case 0x24: return gen.generate_moves<Board_Status(0x24)>(callback);
            case 0x25: return gen.generate_moves<Board_Status(0x25)>(callback);
            case 0x26: return gen.generate_moves<Board_Status(0x26)>(callback);
            case 0x27: return gen.generate_moves<Board_Status(0x27)>(callback);
            case 0x28: return gen.generate_moves<Board_Status(0x28)>(callback);
            case 0x29: return gen.generate_moves<Board_Status(0x29)>(callback);
            case 0x2a: return gen.generate_moves<Board_Status(0x2a)>(callback);
            case 0x2b: return gen.generate_moves<Board_Status(0x2b)>(callback);
            case 0x2c: return gen.generate_moves<Board_Status(0x2c)>(callback);
            case 0x2d: return gen.generate_moves<Board_Status(0x2d)>(callback);
            case 0x2e: return gen.generate_moves<Board_Status(0x2e)>(callback);
            case 0x2f: return gen.generate_moves<Board_Status(0x2f)>(callback);
            case 0x30: return gen.generate_moves<Board_Status(0x30)>(callback);
            case 0x31: return gen.generate_moves<Board_Status(0x31)>(callback);
            case 0x32: return gen.generate_moves<Board_Status(0x32)>(callback);
            case 0x33: return gen.generate_moves<Board_Status(0x33)>(callback);
            case 0x34: return gen.generate_moves<Board_Status(0x34)>(callback);
            case 0x35: return gen.generate_moves<Board_Status(0x35)>(callback);
            case 0x36: return gen.generate_moves<Board_Status(0x36)>(callback);
            case 0x37: return gen.generate_moves<Board_Status(0x37)>(callback);
            case 0x38: return gen.generate_moves<Board_Status(0x38)>(callback);
            case 0x39: return gen.generate_moves<Board_Status(0x39)>(callback);
            case 0x3a: return gen.generate_moves<Board_Status(0x3a)>(callback);
            case 0x3b: return gen.generate_moves<Board_Status(0x3b)>(callback);
            case 0x3c: return gen.generate_moves<Board_Status(0x3c)>(callback);
            case 0x3d: return gen.generate_moves<Board_Status(0x3d)>(callback);
            case 0x3e: return gen.generate_moves<Board_Status(0x3e)>(callback);
            case 0x3f: return gen.generate_moves<Board_Status(0x3f)>(callback);
            case 0x40: return gen.generate_moves<Board_Status(0x40)>(callback);
            default: throw Kangaroo::Invalid_Board_Status();
        }
    }
}