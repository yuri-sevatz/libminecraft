/*
 * block.hpp
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

#ifndef LIBMINECRAFT_CLASSIC_GAME_MAP_BLOCK_HPP
#define LIBMINECRAFT_CLASSIC_GAME_MAP_BLOCK_HPP

#include "../base.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace game
        {
            namespace map
            {
                class Block
                {
                public:
                    enum Type
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
                    } type;

                public:
                    Block(Type t);
                    static Type getBlockType(MCTypes::Int num);

                    static bool isSetableBlockType(Type type);
                    static bool isClearableBlockType(Type type);
                };
            }
        }
    }
}

#endif // LIBMINECRAFT_CLASSIC_GAME_MAP_BLOCK_HPP
