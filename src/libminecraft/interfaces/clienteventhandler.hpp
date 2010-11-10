/*
 * clienteventhandler.hpp
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

#ifndef CLIENTEVENTHANDLER_HPP
#define CLIENTEVENTHANDLER_HPP

#include <string>

#include "core/player/player.hpp"
#include "core/map/map.hpp"
#include "core/map/mapcell.hpp"
#include "core/minecraftworld.hpp"

namespace libminecraft
{
    // The main client interface.  Implement this to respond to events in the minecraft world.
    class ClientEventHandler
    {
        // Access to the world
        const MinecraftWorld & world;

    public:
        // When a message is received from a player.
        // Note: Messages from yourself appear here too.
        virtual void OnMessage(const Player & player, std::string message) = 0;

        // When an entity, other than yourself, has a position and orientation update
        virtual void OnEntitySync(const Player & player) = 0;

        // When an entity, other than yourself, moves.
        virtual void OnEntityMove(const Player & player) = 0;

        // When an entity, other than yourself, turns.
        virtual void OnEntityTurn(const Player & player) = 0;

        // When an entity, other than yourself, spawns.
        virtual void OnEntitySpawn(const Player & player) = 0;

        // When an entity, other than yourself, despawns.
        virtual void OnEntityDespawn(const Player & player) = 0;

        // When an entity, other than yourself, teleports.
        virtual void OnEntityTeleport(const Player & player) = 0;

        // When you are kicked and disconnected from the server.
        virtual void OnKick(std::string reason) = 0;

        // When the network connection is terminated for unknown reasons.
        // This can occur at any time.
        // Furthermore, any allocated world(s) will be deallocated,
        // after execution of this function.
        virtual void OnNetworkError(std::string reason) = 0;

        // When an error in the protocol communicated by the server occurs
        // This can occur at any time - usually due to updates or improper client/server protocol.
        // Furthermore, any allocated world(s) will be deallocated,
        // after this function is executed.
        virtual void OnProtocolError(std::string reason) = 0;

        // When a login error occues.
        // This will only occur when first connecting to a server,
        // usually due to invalid login credentials.
        virtual void OnLoginError(std::string reason) = 0;

        // Occurs when your op status is updated.
        // This may or may not be different than the value previously saved.
        virtual void OnOpUpdate() = 0;

        // Occurs when a block is updated on the map.
        // This may or may not be different than the value previously saved.
        virtual void OnBlockUpdate(MapCell::BlockType type, Map::size_block x, Map::size_block y, Map::size_block z) = 0;

        // Occurs when you are teleported to a new location in the same world.
        virtual void OnTeleport() = 0;

        // Occurs when you enter a new world.
        virtual void OnWorldEnter() = 0;

        // Occurs when you are about to part from a world.
        // Note: The world will be deallocated after execution of this function.
        virtual void OnWorldExit() = 0;
    };
}

#endif // CLIENTEVENTHANDLER_HPP
