/*
 * map.hpp
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

#ifndef MAP_HPP
#define MAP_HPP

#include "mapcell.hpp"
#include "../../exceptions/mapexception.hpp"

#include <vector>
#include <inttypes.h>

namespace libminecraft
{
    // Describes an instance of a map.
    class Map
    {
    public:
        // The 3D grid breakdown.
        typedef std::vector<MapCell> Map1D;
        typedef std::vector<Map1D> Map2D;
        typedef std::vector<Map2D> Map3D;

        // The types used in the grid
        typedef uint16_t size_block;
        typedef float size_plot;

        // The size in world blocks.
        const size_block x_blocks;
        const size_block y_blocks;
        const size_block z_blocks;
/*
        // The size of the world, on the cartesian plane
        const size_plot x_plot;
        const size_plot y_plot;
        const size_plot z_plot;
*/

    private:
        Map3D grid;

    public:
        // XXX: Add support for zlib streams.
        Map(size_block x, size_block y, size_block z, const std::vector<uint16_t> & data);
    };
}

#endif // MAP_HPP
