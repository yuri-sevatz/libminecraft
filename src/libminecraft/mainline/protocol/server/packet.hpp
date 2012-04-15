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
                        PING = (MCTypes::Byte)0x00,
                        LOGIN = (MCTypes::Byte) 0x01,
                        IDENT = (MCTypes::Byte) 0x02,
                        MESSAGE = (MCTypes::Byte) 0x03,
                        TIME = (MCTypes::Byte) 0x04,
                        EQUIPMENT = (MCTypes::Byte) 0x05,
                        SPAWNPOINT = (MCTypes::Byte) 0x06,
                        HEALTH = (MCTypes::Byte) 0x08,
                        PLAYERPOSDIR = (MCTypes::Byte) 0x0D,
                        ITEMSPAWN = (MCTypes::Byte) 0x15,
                        MOVINGOBJECTSPAWN = (MCTypes::Byte) 0x17,
                        MOBSPAWN = (MCTypes::Byte) 0x18,
                        ENTITYVELOCITY = (MCTypes::Byte) 0x1C,
                        PRECHUNK = (MCTypes::Byte) 0x32,
                        GAMESTATE = (MCTypes::Byte) 0x46,
                        WINDOWITEMS = (MCTypes::Byte) 0x68,
                        PLAYERLISTITEM = (MCTypes::Byte) 0xC9,
                        ABILITIES = (MCTypes::Byte) 0xCA
                    };
                };
            }
        }
    }
}

#endif // LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_HPP
