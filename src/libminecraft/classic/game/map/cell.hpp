/*
 * cell.hpp
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

#ifndef LIBMINECRAFT_CLASSIC_GAME_MAP_CELL_HPP
#define LIBMINECRAFT_CLASSIC_GAME_MAP_CELL_HPP

#include <inttypes.h>

namespace libminecraft
{
    namespace classic
    {
        namespace game
        {
            namespace map
            {
                class Cell
                {
                public:
                    enum BlockType
                    {
                        BLANK = 0,
                        STONE = 1,
                        GRASS = 2,
                        DIRT = 3,
                        COBBLESTONE = 4,
                        WOOD = 5,
                        TREE = 6,
                        BEDROCK = 7,
                        WATER_MOVING = 8,
                        WATER = 9,
                        LAVA_MOVING = 10,
                        LAVA = 11,
                        SAND = 12,
                        GRAVEL = 13,
                        GOLD = 14,
                        IRON = 15,
                        COAL = 16,
                        LOG = 17,
                        LEAVES = 18,
                        SPONGE = 19,
                        GLASS = 20,
                        RED = 21,
                        ORANGE = 22,
                        YELLOW = 23,
                        LIGHTGREEN = 24,
                        GREEN = 25,
                        AQUA = 26,
                        CYAN = 27,
                        BLUE = 28,
                        PURPLE = 29,
                        INDIGO = 30,
                        VIOLET = 31,
                        MAGENTA = 32,
                        PINK = 33,
                        BLACK = 34,
                        GREY = 35,
                        WHITE = 36,
                        YELLOW_FLOWER = 37,
                        ROSE = 38,
                        RED_MUSHROOM = 39,
                        BROWN_MUSHROOM = 40,
                        GOLD_BLOCK = 41,
                        IRON_BLOCK = 42,
                        DOUBLE_STEP = 43,
                        STEP = 44,
                        BRICK = 45,
                        TNT = 46,
                        BOOKSHELF = 47,
                        MOSSY_COBBLESTONE = 48,
                        OBSIDIAN = 49,
                    /*
                     * Added in Alpha Version
                     *
                        //TORCH = 50,
                        //FIRE = 51,
                        //SPAWNER = 52,
                        //WOOD_STAIRS = 53,
                        //CHEST = 54,
                        //WIRE = 55,
                        //DIAMOND = 56
                        //DIAMOND_BLOCK = 57,
                        //WORKBENCH = 58,
                        //CROPS = 59,
                        //FIELD = 60,
                        //FURNACE_INACTIVE = 61,
                        //FURNACE_ACTIVE = 62,
                        //SIGN_POST = 63,
                        //WOOD_DOOR = 64,
                        //LADDER = 65,
                        //TRACKS = 66,
                        //STONE_STAIRS = 67,
                        //LEVER = 69,
                        //PLATE_WOODEN = 70,
                        //IRON_DOOR = 71,
                        //PLATE_STONE = 72,
                        //REDSTONE = 73,
                        //REDSTONE_GLOW = 74,
                        //TORCH_OFF = 75,
                        //TORCH_ON = 76,
                        //BUTTON = 77,
                        //SNOW = 78,
                        //ICE = 79,
                        //SNOW_BLOCK = 80,
                        //CACTUS = 81,
                        //CLAY = 82,
                        //REED = 83,
                        //JUKEBOX = 84,
                        //FENCE = 85,
                    */
                    } type;

                public:
                    Cell(BlockType t);
                    static BlockType GetCellType(int8_t num);
                };
            }
        }
    }
}

#endif // LIBMINECRAFT_CLASSIC_GAME_MAP_CELL_HPP
