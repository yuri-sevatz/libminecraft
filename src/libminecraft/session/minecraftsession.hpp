/*
 * minecraftsession.hpp
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


#ifndef LIBMINECRAFT_CLASSIC_MINECRAFTSESSION_HPP
#define LIBMINECRAFT_CLASSIC_MINECRAFTSESSION_HPP

#include "../core/classic/world/map.hpp"
#include "../core/classic/world/map/mapcell.hpp"
#include "../core/classic/minecraftworld.hpp"

namespace libminecraft
{
    namespace classic
    {
        // Forward-declare listener class (has circular dependency).
        class ClientEventHandler;

        // Abstract minecraftsession class.
        // Allows us to define actions without defining context, or really "what happens after".
        // Note: This means we can make things like local/remote clients, client AND server-side NPC's, etc.
        class MinecraftSession
        {
            friend class ClientEventHandler;

        protected:
            ClientEventHandler * listener;

        public:
            // Read access to the world...
            const MinecraftWorld & world;

        protected:
            // A session can only be created with a constant reference to a world.
            // To be thought of as "The client world".
            // It is a read-only entity.
            MinecraftSession(const MinecraftWorld & cli_world);

        private:
            void registerHandler(ClientEventHandler & listener);

        public:
            // Set a block.
            virtual void setBlock(Map::size_block x, Map::size_block y, Map::size_block z, MapCell::BlockType type) = 0;

            // Clear a block.
            virtual void clearBlock(Map::size_block x, Map::size_block y, Map::size_block z) = 0;

            // Move.
            virtual void move(Map::size_plot x, Map::size_plot y, Map::size_plot z) = 0;

            // Look.
            virtual void look(Player::t_pitch pitch, Player::t_yaw yaw) = 0;

            // Move and look.
            virtual void moveAndLook(Map::size_plot x, Map::size_plot y, Map::size_plot z, Player::t_pitch pitch, Player::t_yaw yaw) = 0;

            // Send a message.
            virtual void sendMessage(const std::string & message) = 0;

            // End the session.
            virtual void disconnect() = 0;
        };
    }
}

#endif // LIBMINECRAFT_CLASSIC_MINECRAFTSESSION_HPP
