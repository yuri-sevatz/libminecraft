/*
 * packet.hpp
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

#ifndef LIBMINECRAFT_CLASSIC_SERVER_PACKET_HPP
#define LIBMINECRAFT_CLASSIC_SERVER_PACKET_HPP

#include "../packet.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace server
        {
            class Packet : public classic::Packet
            {
            public:
                enum PacketID
                {
                    IDENT = 0x00,
                    PING = 0x01,
                    LEVELBEGIN = 0x02,
                    LEVELCHUNK = 0x03,
                    LEVELDONE = 0x04,
                    BLOCK = 0x06,
                    SPAWN = 0x07,
                    TELEPORT = 0x08,
                    POSDIR = 0x09,
                    POS = 0x0a,
                    DIR = 0x0b,
                    DESPAWN = 0x0c,
                    MESSAGE = 0x0d,
                    DISCONNECT = 0x0e,
                    USEROP = 0x0f,
                };
            };
        }
    }
}

#endif // LIBMINECRAFT_CLASSIC_SERVER_PACKET_HPP
