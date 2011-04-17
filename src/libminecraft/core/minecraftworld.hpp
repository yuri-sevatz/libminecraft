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

#ifndef LIBMINECRAFT_CLASSIC_MINECRAFTWORLD_HPP
#define LIBMINECRAFT_CLASSIC_MINECRAFTWORLD_HPP

#include "protocol/classic/mctypes.hpp"
#include "player/player.hpp"
#include "map/map.hpp"

#include <map>

namespace libminecraft
{
    namespace classic
    {
        class MinecraftWorld
        {
            // Allow private access to the states...
            friend class CliNegotiating;
            friend class CliConnecting;
            friend class CliLoadingMap;
            friend class CliGame;

        public:
            // Definitions.
            typedef MCTypes::Byte t_playertype;

            // Has a Map
            Map map;

            // Has a list of entities...
            std::map<Player::t_id, Player> entities;

            // You
            Player player;

            // Your op status
            t_playertype playertype;

        public:
            MinecraftWorld();

            bool addPlayer(Player & player);
            bool hasPlayer(Player::t_id player_id) const;
            bool removePlayer(Player::t_id player_id);
            bool removePlayer(Player & player);

            Player * const getPlayer(Player::t_id player_id);
            const Player * const getPlayer(Player::t_id player_id) const;
            const Player * const getPlayer(const std::string & name) const;
        };

        inline bool MinecraftWorld::removePlayer(Player & player)
        {
            return removePlayer(player.id);
        }
    }
}

#endif // LIBMINECRAFT_CLASSIC_MINECRAFTWORLD_HPP
