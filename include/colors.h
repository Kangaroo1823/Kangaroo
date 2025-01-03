//
// Created by peter on 01/12/2024.
//

#ifndef COLORS_H
#define COLORS_H

#include <array>
#include <cstdlib>


using Color = enum class Color_t : std::size_t {
    white = 0,
    black = 16,
};

constexpr std::array<Color_t, 2> All_Colors = {Color_t::white, Color_t::black};


#endif //COLORS_H
