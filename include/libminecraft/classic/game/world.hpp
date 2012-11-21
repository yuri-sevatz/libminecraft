/*
 * world.hpp
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

#ifndef LIBMINECRAFT_CLASSIC_GAME_WORLD_HPP
#define LIBMINECRAFT_CLASSIC_GAME_WORLD_HPP

#include "base.hpp"
#include "player.hpp"
#include "map.hpp"

#include <map>

namespace libminecraft {
namespace classic {
namespace game {
/*
 * A minecraft gamestate.
 * For all intents and purposes, this describes everything a client can possibly be aware of about a game in progress.
 */
class World {
public:
    // Has a Map
    Map map;

private:
    // Has a list of entities...
    typedef std::map<Player::t_id, Player> t_entity_index;
    t_entity_index entities;

public:
    World();

    Player * const addPlayer(Player & player);
    bool hasPlayer(const Player::t_id player_id) const;
    bool hasPlayer(const Player & player) const;
    bool removePlayer(const Player::t_id player_id);
    bool removePlayer(Player & player);

    Player * const getPlayer(const Player::t_id player_id);
    const Player * const getPlayer(const Player::t_id player_id) const;
    const Player * const getPlayer(const std::string & name) const;
};

inline bool World::removePlayer(Player & player) {
    return removePlayer(player.id);
}

inline bool World::hasPlayer(const Player & player) const {
    return hasPlayer(player.id);
}
}
}
}

#endif // LIBMINECRAFT_CLASSIC_GAME_WORLD_HPP
