/*
 * session.hpp
 * This file is part of LibMinecraft.
 *
 * Created by Yuri Sevatz on 03/2011.
 * Copyright (c) 2011 Yuri Sevatz. All rights reserved
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


#ifndef LIBMINECRAFT_CLASSIC_SESSION_HPP
#define LIBMINECRAFT_CLASSIC_SESSION_HPP

#include "game/world.hpp"
#include "game/player/local.hpp"
#include "game/map.hpp"
#include "game/map/cell.hpp"

namespace libminecraft
{
    namespace classic
    {
        // Forward-declare listener class (has circular dependency).
        class Client;

        // Abstract session class.
        // Allows us to define actions without defining context, or really "what happens after".
        // Note: This means we can make things like local/remote clients, client AND server-side NPC's, etc.
        class Session
        {
        public:
            // Read-only access to the world.
            const game::World & world;
            
            // The client's gamepiece.
            const game::player::Local & self;

            // Only the Client can set this.
            // To get the client, just call client().
            class
            {
                friend class Client;
            private:
                Client * address;
            public:
                Client & operator()() const{
                    return *address;
                }
            } listener;

        protected:
            // A session can only be created with the needed information for playabel game.
            // This requires:
            //  A World.
            //  A Self.
            Session(const game::World & world, const game::player::Local & self);

        public:
            // Set a block.
            virtual void setBlock(game::Map::size_block x, game::Map::size_block y, game::Map::size_block z, game::map::Cell::BlockType type) = 0;

            // Clear a block.
            virtual void clearBlock(game::Map::size_block x, game::Map::size_block y, game::Map::size_block z) = 0;

            // Move.
            virtual void move(game::Map::size_plot x, game::Map::size_plot y, game::Map::size_plot z) = 0;

            // Look.
            virtual void look(game::Player::t_pitch pitch, game::Player::t_yaw yaw) = 0;

            // Move and look.
            virtual void moveAndLook(game::Map::size_plot x, game::Map::size_plot y, game::Map::size_plot z, game::Player::t_pitch pitch, game::Player::t_yaw yaw) = 0;

            // Send a message.
            virtual void sendMessage(const std::string & message) = 0;

            // End the session.
            virtual void disconnect() = 0;
        };
    }
}

#endif // LIBMINECRAFT_CLASSIC_SESSION_HPP
