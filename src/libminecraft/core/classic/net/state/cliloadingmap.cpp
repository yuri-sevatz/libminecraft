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
#include "../../../../session/remotesession.hpp"

#include "../../protocol/server/packet/levelbegin.hpp"
#include "../../protocol/server/packet/levelchunk.hpp"
#include "../../protocol/server/packet/leveldone.hpp"

#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filter/gzip.hpp>

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

            // Grab the packet out of the stream (it has no payload in classic)
            server::packet::LevelBegin beginpkt;
            owner.session.client.read(beginpkt);
        }
        void CliLoadingMap::Update(t_owner &owner) const
        {
            // Read some map data...
            switch (owner.session.client.next())
            {
            case server::Packet::LEVELCHUNK:
                {
                    server::packet::LevelChunk lvlchunk;
                    owner.session.client.read(lvlchunk);

                    std::copy(
                            lvlchunk.data.begin(),
                            lvlchunk.data.end(),
                            std::ostream_iterator<unsigned char>(owner.session.gz_data)
                            );
                }
                break;
            case server::Packet::LEVELDONE:
                {
                    server::packet::LevelDone lvldone;
                    owner.session.client.read(lvldone);

                    // Create a decompression input streambuf and stream from the compressed map stream.
                    boost::iostreams::filtering_istream in;
                    in.push(boost::iostreams::gzip_decompressor());
                    in.push(owner.session.gz_data);

                    // Stream the decompressed map data into the map.
                    owner.session._world.map = Map(lvldone.size_x, lvldone.size_y, lvldone.size_z, in);

                    // Welcome to the server!
                    owner.ChangeState(owner.States.CLI_GAME);
                }
                break;
            default:
                std::cerr << (int) owner.session.client.next() << std::endl;
                throw ProtocolException("Unexpected packet received during map data");
            }
        }
        void CliLoadingMap::Exit(t_owner &owner) const
        {
            owner.session.gz_data.clear();
        }
    }
}
