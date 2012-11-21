/*
 * map.cpp
 * This file is part of LibMinecraft.
 *
 * Created by Yuri Sevatz on 11/2010.
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

#include <libminecraft/classic/game/map.hpp>

#include <iterator>
#include <iostream>

#include <cassert>

#include <boost/detail/endian.hpp>
#include <libminecraft/shared/exception/map.hpp>

namespace libminecraft {
namespace classic {
namespace game {
const Map::size_plot Map::CELL_SIZE = Map::toSizePlot(1);
const Map::size_plot Map::CELL_CENTER = CELL_SIZE >> 1; // Half a cell.
const Map::size_plot Map::EYE_HEIGHT = CELL_SIZE + 19; // 51 units above the feet.

Map::Map() : x_blocks(0), y_blocks(0), z_blocks(0), grid(0, Map2D(0, Map1D(0, map::Block(map::Block::BLANK)))) {

}

Map::Map(size_block x, size_block y, size_block z, std::istream & stream) :
    x_blocks(x), y_blocks(y), z_blocks(z),
    grid(x, Map2D(y, Map1D(z,map::Block(map::Block::BLANK)))) {
    // Parse an integer... (raw size of map)
    int raw_size;

#ifdef BOOST_LITTLE_ENDIAN // Go backwards - java encoded this in BE.
    for (char * int_ptr = (char *) &raw_size + 3;
            int_ptr !=((char *) &raw_size) - 1; int_ptr--)
#else // Go forwards - java encoded this in BE.
    for (char * int_ptr = (uint_8 *) &raw_size;
            int_ptr !=((char *) &raw_size) + 4; int_ptr++)
#endif
    {
        // Make sure we still have number...
        if (!stream.good())
            throw exception::Map("Map Data terminated unexpectedly while reading raw map size");

        stream.get(*int_ptr);
    }

    int computed_size = (int) x * (int) y * (int) z;

    std::cerr << "Raw Size: " << raw_size << std::endl;
    std::cerr << "Computed Size: " << computed_size << std::endl;

    if (raw_size != computed_size)
        throw exception::Map("Map Data raw size does not match computed size");


    for (uint16_t y_i = 0; y_i != y; y_i++) {
        for (uint16_t z_i = 0; z_i != z; z_i++) {
            for (uint16_t x_i = 0; x_i != x; x_i++) {
                if (!stream.good()) {
                    std::cerr << "Expected X: " << x << std::endl;
                    std::cerr << "Expected Y: " << y << std::endl;
                    std::cerr << "Expected Z: " << z << std::endl;

                    std::cerr << "Parsed X: " << x_i << std::endl;
                    std::cerr << "Parsed Y: " << y_i << std::endl;
                    std::cerr << "Parsed Z: " << z_i << std::endl;

                    throw exception::Map("Map Data terminated unexpectedly while reading grid");

                    return;
                }

                char type;
                stream.get(type);
                grid[x_i][y_i][z_i].type = map::Block::getBlockType(type);
            }
        }
    }
}

bool Map::isValidBlock(const map::Cell & c) const {
    return isValidBlockX(c.x) & isValidBlockY(c.y) & isValidBlockZ(c.z);
}

bool Map::isValidPoint(const map::Point & p) const {
    return isValidPointX(p.x) & isValidPointY(p.y) & isValidPointZ(p.z);
}

bool Map::isSetableBlock(const map::Cell & c) const {
    return  map::Block::isSetableBlockType(at(c).type);
}

bool Map::isClearableBlock(const map::Cell & c) const {
    return map::Block::isClearableBlockType(at(c).type);
}

map::Block & Map::at(const map::Cell & c) {
    assert(isValidBlock(c));
    return grid[c.x][c.y][c.z];
}

const map::Block & Map::at(const map::Cell & c) const {
    assert(isValidBlock(c));
    return grid[c.x][c.y][c.z];
}
}
}
}
