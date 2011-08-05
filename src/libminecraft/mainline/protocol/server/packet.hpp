/*
 * packet.hpp
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

#ifndef LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_HPP
#define LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_HPP

#include "../packet.hpp"

namespace libminecraft
{
    namespace mainline
    {
        namespace protocol
        {
            namespace server
            {
                class Packet : public virtual protocol::Packet
                {
                public:
                    enum PacketID
                    {
                        PING = 0x00,
                        LOGIN = 0x01,
                        IDENT = 0x02,
                        MESSAGE = 0x03,
                        TIME = 0x04,
                        EQUIPMENT = 0x05,
                        SPAWNPOINT = 0x06,
                        HEALTH = 0x08,
                        PLAYERPOSDIR = 0x0D,
                        MOVINGOBJECTSPAWN = 0x17,
                        MOBSPAWN = 0x18,
                        ENTITYVELOCITY = 0x1C,
                        PRECHUNK = 0x32,
                    };
                };
            }
        }
    }
}

#endif // LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_HPP
