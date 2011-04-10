/*
 * cliloadingmap.cpp
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

#include "cliloadingmap.hpp"
#include <iostream>

#include "../clientstatemachine.hpp"
#include "../../../session/remotesession.hpp"

#include "../../protocol/classic/server/levelchunkpkt.hpp"
#include "../../protocol/classic/server/leveldonepkt.hpp"

#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filter/gzip.hpp>


#include "../../protocol/classic/client/messagepkt.hpp"

namespace libminecraft
{
    namespace classic
    {
        CliLoadingMap::CliLoadingMap()
        {

        }

        void CliLoadingMap::Enter(t_owner &owner) const
        {
            std::cerr << "Loading Map..." << std::endl;
        }
        void CliLoadingMap::Update(t_owner &owner) const
        {
            // Read some map data...
            server::Packet * const packet = owner.session.proto.read();

            switch (packet->type)
            {
            case server::Packet::LEVELCHUNK:
                {
                    server::LevelChunkPkt * const lvlchunk = (server::LevelChunkPkt * const) packet;

                    std::copy(
                            lvlchunk->data.begin(),
                            lvlchunk->data.end(),
                            std::ostream_iterator<unsigned char>(owner.session.gz_data)
                    );
                }
                break;
            case server::Packet::LEVELDONE:
                {
                    server::LevelDonePkt * const lvldone = (server::LevelDonePkt * const) packet;

                    // Create a decompression input streambuf and stream from the compressed map stream.
                    boost::iostreams::filtering_istream in;
                    in.push(boost::iostreams::gzip_decompressor());
                    in.push(owner.session.gz_data);

                    // Stream the decompressed map data into the map.
                    owner.session._world.map = Map(lvldone->size_x, lvldone->size_y, lvldone->size_z, in);

                    // Welcome to the server!
                    owner.ChangeState(owner.States.CLI_GAME);
                }
                break;
            case server::Packet::PING:
                break;
            default:
                delete packet;
                std::cerr << packet->type << std::endl;
                throw ProtocolException("Unexpected packet received during map data");
            }

            delete packet;
        }
        void CliLoadingMap::Exit(t_owner &owner) const
        {
            owner.session.gz_data.clear();
        }
    }
}
