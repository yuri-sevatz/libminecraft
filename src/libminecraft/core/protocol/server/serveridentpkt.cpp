/*
 * serveridentpkt.cpp
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

#include "serveridentpkt.hpp"

#include "../baseprotocol.hpp"
#include "../minecraftstring.hpp"

namespace libminecraft
{
    ServerIdentPkt::ServerIdentPkt()
        : ServerPkt(ServerPkt::IDENT)
    {

    }

    MinecraftPacket * const ServerIdentPkt::Read(std::istream & stream)
    {
        ServerIdentPkt * const pkt = new ServerIdentPkt();

        stream >> pkt->srv_version;

        MinecraftString::Read(stream, pkt->srv_name);
        MinecraftString::Read(stream, pkt->srv_motd);

        unsigned char op_byte = 0x00;
        stream >> op_byte;
        if (op_byte == 0x64)
            pkt->is_op = true;

        if (!stream.good())
        {
            delete pkt;
            throw NetworkException("Connection closed while parsing server ident header");
        }

        if (pkt->srv_version != BaseProtocol::proto_version)
        {
            delete pkt;
            throw ProtocolException("Unable to negotiate protocol version");
        }

        return pkt;
    }

    void ServerIdentPkt::Write(std::ostream &stream) const
    {
        throw ProtocolException("XXX: Not Implemented");
    }
}
