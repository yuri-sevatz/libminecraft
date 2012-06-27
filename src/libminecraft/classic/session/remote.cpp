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

#include "remote/connection.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace session
        {
            Remote::Remote(const std::string &hostname,
                           const std::string &port,
                           const std::string &username,
                           const std::string &key) :
                Session(),
                // Connection object: This provides protocol, parsing, world, etc.
                connection(new remote::Connection(*this, hostname, port, username, key))
            {

            }

            Remote::~Remote()
            {
                delete connection;
            }

            const game::World & Remote::getWorld()
            {
                return connection->_world;
            }

            const game::player::Local & Remote::getSelf()
            {
                return connection->_self;
            }

            const session::Info & Remote::getInfo()
            {
                return connection->_server;
            }

            void Remote::connect()
            {
                run();
            }

            void Remote::run()
            {
                try
                {
                    while(true)
                        connection->Update();
                }
                catch (libminecraft::Exception ex)
                {
                    listener().onError(ex);
                }
            }

            void Remote::look(game::Player::t_pitch pitch, game::Player::t_yaw yaw)
            {
                moveAndLook(connection->_self.position, pitch, yaw);
            }

            void Remote::move(const game::map::Point & pos)
            {
                moveAndLook(pos, connection->_self.pitch, connection->_self.yaw);
            }

            void Remote::moveAndLook(const game::map::Point & pos, game::Player::t_pitch pitch, game::Player::t_yaw yaw)
            {
                protocol::client::packet::PosDir pkt;
                connection->_self.position.x = pkt.x = pos.x;
                connection->_self.position.y = pkt.y = pos.y;
                connection->_self.position.z = pkt.z = pos.z;
                connection->_self.pitch = pkt.pitch = pitch;
                connection->_self.yaw = pkt.yaw = yaw;
                // Bug: Have to write twice for some reason.
                connection->proto.write(pkt);
                connection->proto.write(pkt);
            }

            void Remote::sendMessage(const std::string & message)
            {
                for (size_t offset = 0; offset < message.length(); offset += MCTypes::String64_Max_Length)
                {
                    protocol::client::packet::Message msgpkt;
                    msgpkt.message = message.substr(offset, 64);
                    connection->proto.write(msgpkt);
                }
            }

            void Remote::setBlock(const game::map::Cell & cell, game::map::Block::Type type)
            {
                assert(connection->_world.map.isSetableBlock(cell));
                
                protocol::client::packet::SetBlock blkpkt;
                connection->_world.map.at(cell).type = type;
                blkpkt.type = type;
                blkpkt.x = cell.x;
                blkpkt.y = cell.y;
                blkpkt.z = cell.z;
                blkpkt.mode = 0x01;
                connection->proto.write(blkpkt);
            }

            void Remote::clearBlock(const game::map::Cell & cell)
            {
                assert(connection->_world.map.isClearableBlock(cell));

                protocol::client::packet::SetBlock blkpkt;
                blkpkt.x = cell.x;
                blkpkt.y = cell.y;
                blkpkt.z = cell.z;
                blkpkt.mode = 0x00;
                blkpkt.type = game::map::Block::DIRT;
                connection->_world.map.at(cell).type = game::map::Block::BLANK;
                connection->proto.write(blkpkt);
            }

            void Remote::enableTicks()
            {
                connection->worker = boost::thread(boost::bind(&Remote::tickNotifier, &listener()));
            }

            void Remote::disableTicks()
            {
                connection->worker.interrupt();
            }

            void Remote::tickNotifier(void *client)
            {
                // Todo: Limit the number of calls, space them evenly per second (as a suggestion)
                try
                {
                    for(;;)
                    {
                        // Create a tick event in the client
                        ((Client *) client)->onTick();

                        // Allow interruption at this point.
                        boost::this_thread::sleep(boost::posix_time::milliseconds(10));
                    }
                }
                catch (libminecraft::Exception ex)
                {
                    ((Client *)client)->onError(ex);
                    // XXX: Do pre-emptive termination of connection
                }
            }
        }
    }
}   
