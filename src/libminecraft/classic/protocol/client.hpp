/*
 * client.hpp
 * This file is part of LibMinecraft.
 *
 * Created by Yuri Sevatz on 04/2011.
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

#ifndef LIBMINECRAFT_CLASSIC_PROTOCOL_CLIENT_HPP
#define LIBMINECRAFT_CLASSIC_PROTOCOL_CLIENT_HPP

#include <iostream>
#include <boost/asio.hpp>
#include "client/protocol.hpp"
#include "server/protocol.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace protocol
        {
            class Client
            {
            private:
                boost::asio::ip::tcp::socket & socket;

            public:
                Client(boost::asio::ip::tcp::socket & socket);
                void read(server::Packet & dest);
                void write(const client::Packet & src);
                MCTypes::Byte next();
            };

            inline void Client::read(server::Packet &dest)
            {
                /*
                server::Protocol::read(stream, dest);

                if (!stream.good())
                    throw exception::Network("Client connection closed while reading inbound minecraft packet");
                */
            }

            inline void Client::write(const client::Packet &src)
            {
                /*
                client::Protocol::write(stream, src);
                stream.flush();

                if (!stream.good())
                    throw exception::Network("Client connection closed while writing outbound minecraft packet");
                */
            }

            inline MCTypes::Byte Client::next()
            {
                /*
                MCTypes::Byte id = client::Protocol::next(stream);
                if (!stream.good())
                    throw exception::Network("Client connection closed while awaiting next packet");
                return id;
                */
                return 0;
            }
        }
    }
}

#endif // LIBMINECRAFT_CLASSIC_PROTOCOL_CLIENT_HPP
