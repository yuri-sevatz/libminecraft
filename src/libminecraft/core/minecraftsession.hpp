/*
 * minecraftsession.hpp
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

#ifndef MINECRAFTSESSION_HPP
#define MINECRAFTSESSION_HPP

// World
#include "minecraftworld.hpp"

// FSM
#include "client/clientstatemachine.hpp"

// Protocol
#include "protocol/clientprotocol.hpp"

#include <boost/asio.hpp>
#include <string>
#include <iostream>

#include <inttypes.h>

namespace libminecraft
{
    // Creates a new session with a minecraft classic server.
    class MinecraftSession
    {
        // Allow private access to the states...
        friend class CliNegotiating;
        friend class CliConnecting;
        friend class CliLoadingMap;

    private:
        // The connection, and stream objects.
        boost::asio::ip::tcp::iostream stream;

        // The protocol used for reading/writing messages
        ClientProtocol proto;

        // The FSM
        ClientStateMachine fsm;

        // The credentials used for the session.
        std::string username;
        std::string key;

        // Once connected...
        std::string server_name;
        std::string server_motd;

        // Client information...
        bool is_op;

        // Map tmp data...
        std::vector<uint8_t> gz_data;

    public:
        // The game world
        MinecraftWorld world;

    public:
        // Create a new minecraft session with a target server
        MinecraftSession(const std::string &hostname,
                         const std::string &service);

        // Connects to the target server with username and validation key.
        // Throws NetworkException if the connection cannot be established.
        void Connect(const std::string &username,
                     const std::string &key);



        bool IsOp();

    private:
        void MasterLoop();
    };
}

#endif // MINECRAFTSESSION_HPP
