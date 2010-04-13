/*
 * protocol.hpp
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

#ifndef LIBMINECRAFT_MAINLINE_SERVER_PROTOCOL_HPP
#define LIBMINECRAFT_MAINLINE_SERVER_PROTOCOL_HPP

#include "../protocol.hpp"
#include "packet.hpp"
#include "../../stream.hpp"

#include <assert.h>

#include <typeinfo>
#include <map>


namespace libminecraft
{
    namespace mainline
    {
        namespace server
        {
            class Protocol : public mainline::Protocol
            {
            public:
                // The transmission type.
                enum TransType
                {
                    PING = 0x00,
                };

                // The static map of classes to
                static const std::map<const std::type_info *, TransType> transmap;

                Protocol(std::iostream & stream);

                // Write a packet over the protocol.
                void write(const Packet & packet);

                // Read a packet over the protocol.
                // Ideally, you should be using a packet that was
                void read(Packet & packet);

                // Check the next type of packet on the wire
                MCTypes::Byte next();
            };

            // Since the RTTI type of the packet is likely known in the calling context,
            // then there's a good chance that the type of the packet can be resolved at compile time.
            inline void Protocol::write(const Packet & packet)
            {
                Stream::putSignedByte(stream, Protocol::transmap.at(&typeid(packet)));
                packet.write(stream);
            }

            // Since the RTTI type of the packet is likely known in the calling context,
            // then there's a good chance that the type of the packet will be resolved at compile time.
            inline void Protocol::read(Packet & packet)
            {
                // Skip the buffered id.
                MCTypes::Byte next;
                Stream::getSignedByte(stream, next);
                // Do a quick type check before write, for silly programmers (me? xD)
                assert(Protocol::transmap.at(&typeid(packet)) == next);
                packet.read(stream);
            }
        }
    }
}

#endif // PROTOCOL_HPP
