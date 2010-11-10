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
#include "../../minecraftsession.hpp"

#include "../../protocol/server/serverlevelchunkpkt.hpp"

namespace libminecraft
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
        ServerPkt * const packet = owner.session.proto.Read();

        switch (packet->type)
        {
        case ServerPkt::LEVELCHUNK:
            {
                //owner.session.gz_data.append();
                ServerLevelChunkPkt * const lvlchunk = (ServerLevelChunkPkt * const) packet;
                //std::cerr << lvlchunk->data.size() << std::endl;
                //std::cerr << (unsigned int) lvlchunk->percent << std::endl;
                //throw MinecraftException("Unable to Parse Level Chunk (yet)");
            }
            break;
        case ServerPkt::LEVELDONE:
            //owner.ChangeState(owner.States.CLI_NEGOTIATING);
            throw MinecraftException("Level Loading Done - Next State Not Implemented");
            break;
        case ServerPkt::BLOCK:
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
