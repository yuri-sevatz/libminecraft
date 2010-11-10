/*
 * clientprotocol.cpp
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

#include "clientprotocol.hpp"

// Each packet type knows how to parse itself from a stream.
#include "server/serveridentpkt.hpp"
#include "server/serverpingpkt.hpp"
#include "server/serverlevelbeginpkt.hpp"
#include "server/serverlevelchunkpkt.hpp"
#include "server/serverleveldonepkt.hpp"

namespace libminecraft
{
    ClientProtocol::ClientProtocol(std::iostream &stream) :
            BaseProtocol(stream)
    {

    }

    ServerPkt * const ClientProtocol::Read()
    {
        unsigned char packet_id;
        stream >> packet_id;

        if (!stream.good())
            throw NetworkException("Connection closed while awaiting next packet");

        MinecraftPacket * packet;

        std::cerr << "ID: " << (unsigned int) packet_id << std::endl;

        switch (packet_id)
        {
        case ServerPkt::IDENT:
            std::cerr << "IDENT" << std::endl;
            packet = ServerIdentPkt::Read(stream);
            break;
        case ServerPkt::PING:
            std::cerr << "PING" << std::endl;
            packet = ServerPingPkt::Read(stream);
            break;
        case ServerPkt::LEVELBEGIN:
            std::cerr << "LEVELBEGIN" << std::endl;
            packet = ServerLevelBeginPkt::Read(stream);
            break;
        case ServerPkt::LEVELCHUNK:
            std::cerr << "LEVELCHUNK" << std::endl;
            packet = ServerLevelChunkPkt::Read(stream);
            break;
        case ServerPkt::LEVELDONE:
            std::cerr << "LEVELDONE" << std::endl;
            packet = ServerLevelDonePkt::Read(stream);
            break;
        default:
            delete packet;
            throw ProtocolException("Unknown minecraft packet received from server");
        }

        // Make sure that the data was read properly...
        if (!stream.good())
        {
            delete packet;
            throw NetworkException("Connection to server closed unexpectedly");
        }

        return (ServerPkt * const) packet;
    }

    void ClientProtocol::Write(ClientPkt &packet)
    {
        packet.Write(stream);

        if (!stream.good())
            throw NetworkException("Connection closed while writing outbound minecraft data");
    }
}
