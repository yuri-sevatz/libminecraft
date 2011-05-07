/*
 * mapcell.cpp
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

#include <map>

#include "mapcell.hpp"
#include "../../../shared/exception/mapexception.hpp"

//#define CREATE_PAIR(MSG) std::make_pair(MapCell::MSG, MapCell::MSG),

namespace libminecraft
{
    /* We shouldn't need this since Notch is adding cells as int16_t -> fits with enum nicely!
    const std::pair<MapCell::BlockType, uint16_t> pairs [] = {
        CREATE_PAIR(ADG)
        CREATE_PAIR(BLANK)
        CREATE_PAIR(STONE)
        CREATE_PAIR(GRASS)
        CREATE_PAIR(DIRT)
        CREATE_PAIR(COBBLESTONE)
        CREATE_PAIR(WOOD)
        CREATE_PAIR(TREE)
        CREATE_PAIR(BEDROCK)
        CREATE_PAIR(WATER_MOVING)
        CREATE_PAIR(WATER)
        CREATE_PAIR(LAVA_MOVING)
        CREATE_PAIR(LAVA)
        CREATE_PAIR(SAND)
        CREATE_PAIR(GRAVEL)
        CREATE_PAIR(GOLD)
        CREATE_PAIR(IRON)
        CREATE_PAIR(COAL)
        CREATE_PAIR(LOG)
        CREATE_PAIR(LEAVES)
        CREATE_PAIR(SPONGE)
        CREATE_PAIR(GLASS)
        CREATE_PAIR(RED)
        CREATE_PAIR(ORANGE)
        CREATE_PAIR(YELLOW)
        CREATE_PAIR(LIGHTGREEN)
        CREATE_PAIR(GREEN)
        CREATE_PAIR(AQUA)
        CREATE_PAIR(CYAN)
        CREATE_PAIR(BLUE)
        CREATE_PAIR(PURPLE)
        CREATE_PAIR(INDIGO)
        CREATE_PAIR(VIOLET)
        CREATE_PAIR(MAGENTA)
        CREATE_PAIR(PINK)
        CREATE_PAIR(BLACK)
        CREATE_PAIR(GREY)
        CREATE_PAIR(WHITE)
        CREATE_PAIR(YELLOW_FLOWER)
        CREATE_PAIR(ROSE)
        CREATE_PAIR(RED_MUSHROOM)
        CREATE_PAIR(BROWN_MUSHROOM)
        CREATE_PAIR(GOLD_BLOCK)
        CREATE_PAIR(IRON_BLOCK)
        CREATE_PAIR(DOUBLE_STEP)
        CREATE_PAIR(STEP)
        CREATE_PAIR(BRICK)
        CREATE_PAIR(TNT)
        CREATE_PAIR(BOOKSHELF)
        CREATE_PAIR(MOSSY_COBBLESTONE)
        CREATE_PAIR(OBSIDIAN)
    };

    typedef std::map<MapCell::BlockType, uint16_t> lookup_type;

    const lookup_type lookups(pairs, pairs + ARRAY_COUNT(pairs));

    */

    MapCell::MapCell(MapCell::BlockType t) : type(t)
    {

    }

    MapCell::BlockType MapCell::GetCellType(int8_t num)
    {
        // If the val is allowed in the classic version...
        if (num >= 0 && num < 50)
            return (MapCell::BlockType) num;
        else
            throw MapException("Invalid Block Type Detected");
    }
}
