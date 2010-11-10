/*
 * minecraftworld.hpp
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

#ifndef MINECRAFTWORLD_HPP
#define MINECRAFTWORLD_HPP

#include <map>

#include "player/player.hpp"

#include "map/map.hpp"

namespace libminecraft
{
    class MinecraftWorld
    {
    private:
        // Has a Map - modifiable is for internal use only.
        Map _map;

        // Has a list of entities...
        std::map<unsigned char, Player> _entities;
    public:
        // Reference to map, for external use.
        const Map & map;
        const std::map<unsigned char, Player> & entities;

        //const Player & player;

    public:



        MinecraftWorld();
    };
}

#endif // MINECRAFTWORLD_HPP
