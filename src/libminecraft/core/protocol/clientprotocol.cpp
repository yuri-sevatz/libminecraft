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

#include "minecraftstream.hpp"
#include "minecrafttypes.hpp"

// Each packet type knows how to parse itself from a stream.
#include "server/serveridentpkt.hpp"
#include "server/serverpingpkt.hpp"
#include "server/serverlevelbeginpkt.hpp"
#include "server/serverlevelchunkpkt.hpp"
#include "server/serverleveldonepkt.hpp"
#include "server/servermessagepkt.hpp"
#include "server/serverplayerdespawnpkt.hpp"
#include "server/serverplayerdisconnectpkt.hpp"
#include "server/serverplayerdirpkt.hpp"
#include "server/serverplayeroppkt.hpp"
#include "server/serverplayerposdirpkt.hpp"
#include "server/serverplayerspawnpkt.hpp"
#include "server/serverplayerteleportpkt.hpp"
#include "server/serversetblockpkt.hpp"
#include "server/serverplayerpospkt.hpp"

namespace libminecraft
{
    ClientProtocol::ClientProtocol(std::iostream &stream) :
            BaseProtocol(stream)
    {

    }

    ServerPkt * const ClientProtocol::Read()
    {
        MinecraftTypes::Byte packet_id;
        MinecraftStream::getByte(stream, packet_id);

        if (!stream.good())
            throw NetworkException("Connection closed while awaiting next packet");

        ServerPkt * packet;

        switch (packet_id)
        {
        case ServerPkt::IDENT:
            packet = new ServerIdentPkt();
            break;
        case ServerPkt::PING:
            packet = new ServerPingPkt();
            break;
        case ServerPkt::LEVELBEGIN:
            packet = new ServerLevelBeginPkt();
            break;
        case ServerPkt::LEVELCHUNK:
            packet = new ServerLevelChunkPkt();
            break;
        case ServerPkt::LEVELDONE:
            packet = new ServerLevelDonePkt();
            break;
        case ServerPkt::SPAWN:
            packet = new ServerPlayerSpawnPkt();
            break;
        case ServerPkt::MESSAGE:
            packet = new ServerMessagePkt();
            break;
        case ServerPkt::POS:
            packet = new ServerPlayerPosPkt();
            break;
        case ServerPkt::DIR:
            packet = new ServerPlayerDirPkt();
            break;
        case ServerPkt::POSDIR:
            packet = new ServerPlayerPosDirPkt();
            break;
        case ServerPkt::TELEPORT:
            packet = new ServerPlayerTeleportPkt();
            break;
        case ServerPkt::BLOCK:
            packet = new ServerSetBlockPkt();
            break;
        case ServerPkt::DESPAWN:
            packet = new ServerPlayerDespawnPkt();
            break;
        case ServerPkt::USEROP:
            packet = new ServerPlayerOpPkt();
            break;
        case ServerPkt::DISCONNECT:
            packet = new ServerPlayerDisconnectPkt();
            break;
        default:
            // Debugging Only
            //std::cerr << "UNKNOWN: " << (unsigned int) packet_id << std::endl;
            throw ProtocolException("Unknown minecraft packet received from server");
        }

        try
        {
            packet->read(stream);

            // Make sure that the data was read properly...
            if (!stream.good())
                throw NetworkException("Connection to server closed unexpectedly");
        }
        catch (MinecraftException ex)
        {
            delete packet;
            throw ex;
        }

        // Debugging?
        //packet->toReadable(std::cerr);

        return (ServerPkt * const) packet;
    }

    void ClientProtocol::Write(ClientPkt &packet)
    {
        packet.write(stream);
        stream.flush();

        if (!stream.good())
            throw NetworkException("Connection closed while writing outbound minecraft data");
    }
}
