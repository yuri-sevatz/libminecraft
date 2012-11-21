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

#ifndef LIBMINECRAFT_CLASSIC_GAME_PLAYER_HPP
#define LIBMINECRAFT_CLASSIC_GAME_PLAYER_HPP

#include "base.hpp"
#include "map.hpp"

#include <string>

namespace libminecraft {
namespace classic {
namespace game {
class Player {
public:
    typedef MCTypes::Byte t_id;
    typedef MCTypes::Byte t_pitch;
    typedef MCTypes::Byte t_yaw;

public:
    // Compass constants
    // North = -Z
    static const t_yaw YAW_NORTH = 0;
    static const t_yaw YAW_EAST = 64;
    static const t_yaw YAW_SOUTH = -128;
    static const t_yaw YAW_WEST = -64;

    // Pitch constants.
    static const t_pitch PITCH_UP = -64;
    static const t_pitch PITCH_DOWN = 64;
    static const t_pitch PITCH_NORMAL = 0;
    static const t_pitch PITCH_INVERT = -128;

    // Instance variables.
    t_id id;
    MCTypes::String64 name;
    t_pitch pitch;
    t_yaw yaw;

    Map::point position;

    Player();

    // Get the point that the player is standing on
    Map::point getBasePoint() const;
};

inline Map::point Player::getBasePoint() const {
    return Map::point(position.x, position.y - 51, position.z);
}
}
}
}

#endif // LIBMINECRAFT_CLASSIC_GAME_PLAYER_HPP
