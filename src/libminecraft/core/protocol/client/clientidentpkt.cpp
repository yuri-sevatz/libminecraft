/*
 * clientidentpkt.cpp
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

#include "clientidentpkt.hpp"
#include "../baseprotocol.hpp"

#include "../minecraftstring.hpp"

namespace libminecraft
{
    ClientIdentPkt::ClientIdentPkt() :
            ClientPkt(ClientPkt::IDENT)
    {

    }

    MinecraftPacket * const ClientIdentPkt::Read(std::istream &stream)
    {
        throw ProtocolException("XXX: Reading Client Ident Packet Not Implemented.");
    }

    void ClientIdentPkt::Write(std::ostream &stream) const
    {
        // Try sending our auth string...
        const unsigned char id = 0x00;
        stream << id; // Byte (packet id)
        stream << BaseProtocol::proto_version; // Byte
        MinecraftString::Write(stream, username); // String
        MinecraftString::Write(stream, key); // String
        const unsigned char byte = 0x00;
        stream << byte; // Byte (unused byte).
        stream.flush();
    }
}
