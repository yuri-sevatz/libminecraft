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

#ifndef LIBMINECRAFT_CLASSIC_GAME_MAP_HPP
#define LIBMINECRAFT_CLASSIC_GAME_MAP_HPP

#include "base.hpp"
#include "map/block.hpp"
#include "map/cell.hpp"
#include "map/point.hpp"

#include <vector>
#include <istream>

namespace libminecraft
{
    namespace classic
    {
        namespace game
        {
            // Describes an instance of a map.
            class Map
            {
            public:
                // The 3D grid breakdown.
                typedef std::vector<map::Block> Map1D;
                typedef std::vector<Map1D> Map2D;
                typedef std::vector<Map2D> Map3D;

                // The types used in the grid
                typedef map::Cell::size_block size_block;
                typedef map::Point::size_plot size_plot;

                typedef map::Point point;
                typedef map::Cell cell;

                static const size_plot CELL_SIZE;
                static const size_plot CELL_CENTER;
                static const size_plot EYE_HEIGHT;

                // The size in world blocks.
                size_block x_blocks;
                size_block y_blocks;
                size_block z_blocks;

                // The size of the world, on the cartesian plane
                size_plot x_plot;
                size_plot y_plot;
                size_plot z_plot;

                Map3D grid;

            public:
                // Build an empty map...
                Map();
                // Build a Map...
                Map(size_block x, size_block y, size_block z, std::istream &stream);

                static size_block toSizeBlock(size_plot distance);
                static size_plot toSizePlot(size_block count);

                map::Block & at(const map::Cell & c);
                const map::Block & at(const map::Cell & c) const;

                map::Block & at(const map::Point & p);
                const map::Block & at(const map::Point & p) const;

                bool isValidBlockX(size_block x) const;
                bool isValidBlockY(size_block y) const;
                bool isValidBlockZ(size_block z) const;

                bool isValidPointX(size_plot x) const;
                bool isValidPointY(size_plot y) const;
                bool isValidPointZ(size_plot z) const;

                bool isValidBlock(const map::Cell & c) const;
                bool isValidPoint(const map::Point & p) const;

                bool isSetableBlock(const map::Cell & c) const;
                bool isClearableBlock(const map::Cell & c) const;
            };

            inline Map::size_block Map::toSizeBlock(size_plot pos)
            {
                 // 5 bits.
                return pos >> 5;
            }

            inline Map::size_plot Map::toSizePlot(size_block pos)
            {
                // 5 bits.
                return pos << 5;
            }

            inline bool Map::isValidBlockX(Map::size_block x) const
            {
                return (x >= 0 && x <= x_blocks);
            }

            inline bool Map::isValidBlockY(Map::size_block y) const
            {
                return (y >= 0 && y <= y_blocks);
            }

            inline bool Map::isValidBlockZ(Map::size_block z) const
            {
                return (z >= 0 && z <= z_blocks);
            }

            inline bool Map::isValidPointX(size_plot x) const
            {
                return isValidBlockX(toSizeBlock(x));
            }

            inline bool Map::isValidPointY(size_plot y) const
            {
                return isValidBlockY(toSizeBlock(y));
            }

            inline bool Map::isValidPointZ(size_plot z) const
            {
                return isValidBlockZ(toSizeBlock(z));
            }

            inline map::Block & Map::at(const map::Point & p)
            {
                return at(map::Cell(p));
            }

            inline const map::Block & Map::at(const map::Point & p) const
            {
                return at(map::Cell(p));
            }
        }
    }
}

#endif // LIBMINECRAFT_CLASSIC_GAME_MAP_HPP
