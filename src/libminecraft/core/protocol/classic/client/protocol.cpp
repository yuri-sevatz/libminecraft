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

#include "protocol.hpp"

#include "../../stream.hpp"

// Each packet type knows how to parse itself from a stream.
#include "../server/disconnectpkt.hpp"
#include "../server/identpkt.hpp"
#include "../server/pingpkt.hpp"
#include "../server/levelbeginpkt.hpp"
#include "../server/levelchunkpkt.hpp"
#include "../server/leveldonepkt.hpp"
#include "../server/messagepkt.hpp"
#include "../server/playerdespawnpkt.hpp"
#include "../server/playerdirpkt.hpp"
#include "../server/playeroppkt.hpp"
#include "../server/playerposdirpkt.hpp"
#include "../server/playerspawnpkt.hpp"
#include "../server/playerteleportpkt.hpp"
#include "../server/setblockpkt.hpp"
#include "../server/playerpospkt.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace client
        {
            Protocol::Protocol(std::iostream &stream) :
                    classic::Protocol(stream)
            {
                
            }

            server::Packet * const Protocol::read()
            {
                NetworkTypes::Byte packet_id;
                Stream::getByte(stream, packet_id);

                if (!stream.good())
                    throw NetworkException("Connection closed while awaiting next packet");

                server::Packet * packet;

                switch (packet_id)
                {
                case server::Packet::IDENT:
                    packet = new server::IdentPkt();
                    break;
                case server::Packet::PING:
                    packet = new server::PingPkt();
                    break;
                case server::Packet::LEVELBEGIN:
                    packet = new server::LevelBeginPkt();
                    break;
                case server::Packet::LEVELCHUNK:
                    packet = new server::LevelChunkPkt();
                    break;
                case server::Packet::LEVELDONE:
                    packet = new server::LevelDonePkt();
                    break;
                case server::Packet::SPAWN:
                    packet = new server::PlayerSpawnPkt();
                    break;
                case server::Packet::MESSAGE:
                    packet = new server::MessagePkt();
                    break;
                case server::Packet::POS:
                    packet = new server::PlayerPosPkt();
                    break;
                case server::Packet::DIR:
                    packet = new server::PlayerDirPkt();
                    break;
                case server::Packet::POSDIR:
                    packet = new server::PlayerPosDirPkt();
                    break;
                case server::Packet::TELEPORT:
                    packet = new server::PlayerTeleportPkt();
                    break;
                case server::Packet::BLOCK:
                    packet = new server::SetBlockPkt();
                    break;
                case server::Packet::DESPAWN:
                    packet = new server::PlayerDespawnPkt();
                    break;
                case server::Packet::USEROP:
                    packet = new server::PlayerOpPkt();
                    break;
                case server::Packet::DISCONNECT:
                    packet = new server::DisconnectPkt();
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

                return packet;
            }

            void Protocol::write(client::Packet &packet)
            {
                packet.write(stream);
                stream.flush();

                if (!stream.good())
                    throw NetworkException("Connection closed while writing outbound minecraft data");
            }
        }
    }
}
