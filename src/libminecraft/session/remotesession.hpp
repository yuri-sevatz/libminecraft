/*
 * remotesession.hpp
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


#ifndef LIBMINECRAFT_REMOTESESSION_HPP
#define LIBMINECRAFT_REMOTESESSION_HPP

#include "minecraftsession.hpp"

// FSM
#include "../core/client/clientstatemachine.hpp"
#include "../core/protocol/clientprotocol.hpp"

#include <sstream>
#include <boost/asio.hpp>

namespace libminecraft
{
    // Defines a local session.
    class RemoteSession : public MinecraftSession
    {
        friend class CliConnecting;
        friend class CliDisconnected;
        friend class CliGame;
        friend class CliLoadingMap;
        friend class CliNegotiating;

    private:
        // The credentials used for the session.
        std::string username;
        std::string key;

        // Once connected...
        std::string server_name;
        std::string server_motd;

        // Map tmp data...
        std::stringstream gz_data;

        // The actual world, private, writable.
        MinecraftWorld _world;

        ClientStateMachine fsm;


    public:
        // The connection, and stream objects.
        boost::asio::ip::tcp::iostream stream;
        ClientProtocol proto;

    public:
        RemoteSession(const std::string &hostname,
                      const std::string &service);

        void connect(const std::string &username,
                     const std::string &key);

        // Set a block.
        virtual void setBlock(Map::size_block x, Map::size_block y, Map::size_block z, MapCell::BlockType type);

        // Clear a block
        virtual void clearBlock(Map::size_block x, Map::size_block y, Map::size_block z);

        // Move.
        virtual void move(Map::size_plot x, Map::size_plot y, Map::size_plot z);

        // Look.
        virtual void look(Player::t_pitch pitch, Player::t_yaw yaw);

        // Move and look.
        virtual void moveAndLook(Map::size_plot x, Map::size_plot y, Map::size_plot z, Player::t_pitch pitch, Player::t_yaw yaw);

        // Send a message.
        virtual void sendMessage(const std::string & message);

        // End the session.
        virtual void disconnect();

    private:
        // The master loop, used for FSM update() calls.
        void loop();
    };
}

#endif // LIBMINECRAFT_REMOTESESSION_HPP
