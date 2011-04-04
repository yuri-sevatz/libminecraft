/*
 * player.hpp
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

#ifndef LIBMINECRAFT_PLAYER_HPP
#define LIBMINECRAFT_PLAYER_HPP

#include "../map/map.hpp"

#include <string>
#include <inttypes.h>

namespace libminecraft
{
    class Player
    {
    public:
        typedef uint8_t t_id;
        typedef uint8_t t_pitch;
        typedef uint8_t t_yaw;

    public:
        // Compass constants
        // North = -Z
        static const t_yaw YAW_NORTH = 0;
        static const t_yaw YAW_EAST = 64;
        static const t_yaw YAW_SOUTH = 128;
        static const t_yaw YAW_WEST = 192;

        // Pitch constants.
        static const t_pitch PITCH_UP = 192;
        static const t_pitch PITCH_DOWN = 64;
        static const t_pitch PITCH_NORMAL = 0;
        static const t_pitch PITCH_INVERT = 128;

        // Instance variables.
        t_id id;
        std::string name;
        t_pitch pitch;
        t_yaw yaw;

        Map::size_plot x;
        Map::size_plot y;
        Map::size_plot z;

        Player();
    };

}

#endif // LIBMINECRAFT_PLAYER_HPP
