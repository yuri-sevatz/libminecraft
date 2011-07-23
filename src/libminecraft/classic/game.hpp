/*
 * game.hpp
 * This file is part of LibMinecraft.
 *
 * Created by Yuri Sevatz on 06/2011.
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
 
#ifndef LIBMINECRAFT_CLASSIC_GAME_HPP
#define LIBMINECRAFT_CLASSIC_GAME_HPP

#include "mctypes.hpp"
#include "game/world.hpp"
#include "game/map.hpp"
#include "game/map/cell.hpp"
 
namespace libminecraft
{
    namespace classic
    {
        class Game
        {
            using namespace game;
        public:
            Game();
        private:    
            World world;
        
            // When a new Player Connects
            virtual void onPlayerConnect() = 0;
            
            virtual void onPlayerLook() = 0;
            virtual void onPlayerMove() = 0;
            virtual void onPlayerMoveAndLook() = 0;
            
            virtual void onPlayerMessage() = 0;
            virtual void onPlayerClearBlock() = 0;
            virtual void onPlayerSetBlock() = 0;
            
            virtual void onPlayerDisconnect() = 0;
        protected:
            // Add a player to the game.
            void addPlayer(Player & player);
            
            // Set a world block
            void setBlock(Map::size_block x, Map::size_block y, Map::size_block z, map::Cell::BlockType type);
            
            // Set a world block as a client
            // Note: This hides the event from the client you're invoking it as.  You should only send this if you're
            // Forwarding a request from onPlayerSetBlock.
            void setBlock(Client & client, Map::size_block x, Map::size_block y, Map::size_block z, map::Cell::BlockType type);
            
            // Send a global message
            void sendMessage(MCTypes::String message);
            
            // Send a message from a player.
            void sendMessage(Player & player, MCTypes::String message);
            
            // Kick a player
            void kick(Player client, MCTypes::String reason);
        };
    }
}
 
#endif // LIBMINECRAFT_CLASSIC_GAME_HPP
