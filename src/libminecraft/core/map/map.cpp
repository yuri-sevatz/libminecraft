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

#include "map.hpp"

namespace libminecraft
{
    Map::Map(size_block x, size_block y, size_block z, const std::vector<uint16_t> &data) :
            x_blocks(x), y_blocks(y), z_blocks(z),
            grid(x, Map2D(y, Map1D(z,MapCell(MapCell::BLANK))))
    {
        if(data.size() != (((size_t) x) * y) * z)
            throw MapException("Map Resolution Incampatible with Map Data");

        std::vector<uint16_t>::const_iterator d_ptr = data.begin();

        for (uint16_t x_i = 0; x_i != x; x_i++)
        {
            for (uint16_t y_i = 0; y_i != y; y_i++)
            {
                for (uint16_t z_i = 0; z_i != z; z_i++)
                {
                    grid[x_i][y_i][z_i].type = MapCell::GetCellType(*d_ptr++);
                }
            }
        }
    }
}
