/*
 * protocol.hpp
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

#ifndef LIBMINECRAFT_CLASSIC_CLIENT_PROTOCOL_HPP
#define LIBMINECRAFT_CLASSIC_CLIENT_PROTOCOL_HPP

#include "../protocol.hpp"

#include "packet.hpp"
#include "../server/packet.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace client
        {
            // This class is responsible for the embodiment of all Client I/O parsing/writing.
            // Meant to separate the "reacting" code from the logic of a minecraft client.
            class Protocol : public classic::Protocol
            {
            public:
                Protocol(std::iostream &stream);

                // Returns a reference to the next client packet read from a server.
                // This memory is not freed.
                server::Packet * const read();

                // Write data from the client
                void write(client::Packet & packet);
            };
        }
    }
}

#endif // LIBMINECRAFT_CLASSIC_CLIENT_PROTOCOL_HPP
