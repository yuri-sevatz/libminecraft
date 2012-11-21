/*
 * world.cpp
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

#include <libminecraft/classic/game/world.hpp>

namespace libminecraft {
namespace classic {
namespace game {
World::World() {

}

Player * const World::addPlayer(Player & player) {
    const std::pair<t_entity_index::iterator,bool> ret =
        entities.insert(std::make_pair(player.id, player));
    // Return the newly allocated player if it worked, null otherwise.
    return (ret.second ? &ret.first->second : NULL);
}

bool World::hasPlayer(const Player::t_id player_id) const {
    return (entities.find(player_id) != entities.end());
}

bool World::removePlayer(const Player::t_id player_id) {
    t_entity_index::iterator p_player = entities.find(player_id);

    if (p_player == entities.end())
        return false;

    entities.erase(p_player);
    return true;
}

Player * const World::getPlayer(const Player::t_id player_id) {
    t_entity_index::iterator p_player = entities.find(player_id);

    if (p_player != entities.end())
        return &p_player->second;

    return NULL;
}

const Player * const World::getPlayer(const Player::t_id player_id) const {
    t_entity_index::const_iterator p_player = entities.find(player_id);

    if (p_player != entities.end())
        return &p_player->second;

    return NULL;
}

const Player * const World::getPlayer(const std::string & name) const {
    for (t_entity_index::const_iterator p_player = entities.begin();
            p_player != entities.end(); p_player++) {
        if (name == p_player->second.name)
            return &p_player->second;
    }

    return NULL;
}
}
}
}
