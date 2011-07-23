/*
 * remote.cpp
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

#include "remote.hpp"
#include "../client.hpp"

#include "../protocol/stream.hpp"
#include "../protocol/client/packet/message.hpp"
#include "../protocol/client/packet/posdir.hpp"
#include "../protocol/client/packet/setblock.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace session
        {         
            Remote::Remote(const std::string &hostname,
                                         const std::string &service) : Session(_world, _self),
            // Connection attributes.
            stream(hostname, service),
            proto(stream),
            fsm(*this),
            gz_data(std::ios_base::out | std::ios_base::in | std::ios_base::binary)
            {

            }

            void Remote::connect(const std::string &username, const std::string &key)
            {
                this->username = username;
                this->key = key;

                fsm.ChangeState(fsm.States.CONNECTING);

                // Enter the master loop...
                loop();
            }

            void Remote::loop()
            {
                try
                {
                    while(true)
                        fsm.Update();
                }
                catch (libminecraft::Exception ex)
                {
                    listener().onNetworkError(ex.message);
                    disconnect(); // Kill the game.
                }
            }

            void Remote::disconnect()
            {
                fsm.ChangeState(fsm.States.DISCONNECTED);
            }

            void Remote::look(game::Player::t_pitch pitch, game::Player::t_yaw yaw)
            {
                moveAndLook(_self.x, _self.y, _self.z, pitch, yaw);
            }

            void Remote::move(game::Map::size_plot x, game::Map::size_plot y, game::Map::size_plot z)
            {
                moveAndLook(x, y, z, _self.pitch, _self.yaw);
            }

            void Remote::moveAndLook(game::Map::size_plot x, game::Map::size_plot y, game::Map::size_plot z, game::Player::t_pitch pitch, game::Player::t_yaw yaw)
            {
                protocol::client::packet::PosDir pkt;
                _self.x = pkt.x = x;
                _self.y = pkt.y = y;
                _self.z = pkt.z = z;
                _self.pitch = pkt.pitch = pitch;
                _self.yaw = pkt.yaw = yaw;
                // Bug: Have to write twice for some reason.
                proto.write(pkt);
                proto.write(pkt);
            }

            void Remote::sendMessage(const std::string & message)
            {
                for (size_t offset = 0; offset < message.length(); offset += MCTypes::MAX_STRING_LENGTH)
                {
                    protocol::client::packet::Message msgpkt;
                    msgpkt.message = message.substr(offset, 64);
                    proto.write(msgpkt);
                }
            }

            void Remote::setBlock(game::Map::size_block x, game::Map::size_block y, game::Map::size_block z, game::map::Cell::BlockType type)
            {
                assert(world.map.isValidBlock(x, y, z));
                assert(type >= game::map::Cell::BLANK && type <= game::map::Cell::OBSIDIAN);
                
                protocol::client::packet::SetBlock blkpkt;
                _world.map.grid[x][y][z].type = type;
                blkpkt.type = type;
                blkpkt.x = x;
                blkpkt.y = y;
                blkpkt.z = z;
                blkpkt.mode = 0x01;
                proto.write(blkpkt);
            }

            void Remote::clearBlock(game::Map::size_block x, game::Map::size_block y, game::Map::size_block z)
            {
                assert(world.map.isValidBlock(x, y, z));

                protocol::client::packet::SetBlock blkpkt;
                blkpkt.x = x;
                blkpkt.y = y;
                blkpkt.z = z;
                blkpkt.mode = 0x00;
                blkpkt.type = game::map::Cell::DIRT;
                _world.map.grid[x][y][z].type = game::map::Cell::BLANK;
                proto.write(blkpkt);
            }
        }
    }
}   
