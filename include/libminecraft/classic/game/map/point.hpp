/*
 * point.hpp
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

#ifndef LIBMINECRAFT_CLASSIC_GAME_MAP_POINT_HPP
#define LIBMINECRAFT_CLASSIC_GAME_MAP_POINT_HPP

#include <libminecraft/minecraft_export.h>

#include "../base.hpp"
#include <ostream>

namespace libminecraft {
namespace classic {
namespace game {
namespace map {

class Cell;

class MINECRAFT_EXPORT Point {
public:
    typedef MCTypes::Short size_plot;

    size_plot x;
    size_plot y;
    size_plot z;

    Point() : x(0), y(0), z(0) {}
    Point(const Cell & c);
    Point(size_plot x, size_plot y, size_plot z) : x(x), y(y), z(z) {}
};

inline std::ostream & operator<<(std::ostream & os, const Point & p) {
    return (os << "(" << p.x << ", " << p.y << ", " << p.z << ")");
}

}
}
}
}

#endif // LIBMINECRAFT_CLASSIC_GAME_MAP_POINT_HPP
