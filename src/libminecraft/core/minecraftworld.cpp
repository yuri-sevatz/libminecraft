/*
 * minecraftworld.cpp
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

#include "minecraftworld.hpp"

namespace libminecraft
{
    MinecraftWorld::MinecraftWorld()
    {

    }

    bool MinecraftWorld::addPlayer(Player & player)
    {
        if (entities.find(player.id) != entities.end())
            return false;

        entities.insert(std::pair<uint8_t, Player>(player.id, player));
        return true;
    }

    bool MinecraftWorld::hasPlayer(uint8_t player_id) const
    {
        return (entities.find(player_id) != entities.end());
    }

    bool MinecraftWorld::removePlayer(uint8_t player_id)
    {
        std::map<uint8_t, Player>::iterator p_player = entities.find(player_id);

        if (p_player == entities.end())
            return false;

        entities.erase(p_player);
        return true;
    }

    Player * const MinecraftWorld::getPlayer(uint8_t player_id)
    {
        std::map<uint8_t, Player>::iterator p_player = entities.find(player_id);

        if (p_player != entities.end())
            return &p_player->second;

        return NULL;
    }

    const Player * const MinecraftWorld::getPlayer(uint8_t player_id) const
    {
        std::map<uint8_t, Player>::const_iterator p_player = entities.find(player_id);

        if (p_player != entities.end())
            return &p_player->second;

        return NULL;
    }

    const Player * const MinecraftWorld::getPlayer(const std::string &name) const
    {
        for (std::map<uint8_t, Player>::const_iterator p_player = entities.begin();
                p_player != entities.end(); p_player++)
        {
            if (name == p_player->second.name)
                return &p_player->second;
        }

        return NULL;
    }
}
