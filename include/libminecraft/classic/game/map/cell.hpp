/*
 * cell.hpp
 * This file is part of LibMinecraft.
 *
 * Created by Yuri Sevatz on 11/2011.
 * Copyright (c) 2010 Yuri Sevatz. All rights reserved
 *
 * LibMinecraft is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LibMinecraft is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LibMinecraft.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef LIBMINECRAFT_CLASSIC_GAME_MAP_CELL_HPP
#define LIBMINECRAFT_CLASSIC_GAME_MAP_CELL_HPP

#include <libminecraft/minecraft_export.h>

#include "../base.hpp"

#include <ostream>

namespace libminecraft {
namespace classic {
namespace game {
namespace map {

class Point;

class MINECRAFT_EXPORT Cell {
public:
    typedef MCTypes::Short size_block;

    size_block x;
    size_block y;
    size_block z;

    Cell() : x(0), y(0), z(0) {}
    Cell(const Point & p);
    Cell(size_block x, size_block y, size_block z) : x(x), y(y), z(z) {}
};

inline std::ostream & operator<<(std::ostream & os, const Cell & c) {
    return (os << "(" << c.x << ", " << c.y << ", " << c.z << ")");
}

}
}
}
}

#endif // LIBMINECRAFT_CLASSIC_GAME_MAP_CELL_HPP
