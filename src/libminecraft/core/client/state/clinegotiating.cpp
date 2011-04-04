/*
 * clinegotiating.cpp
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

#include "clinegotiating.hpp"
#include <iostream>

#include "../clientstatemachine.hpp"
#include "../../../session/remotesession.hpp"
#include "../../../interfaces/clienteventhandler.hpp"

#include "../../protocol/client/clientidentpkt.hpp"
#include "../../protocol/server/serveridentpkt.hpp"

#include "../../protocol/server/serverlevelbeginpkt.hpp"

namespace libminecraft
{
    CliNegotiating::CliNegotiating()
    {
    }

    void CliNegotiating::Enter(t_owner &owner) const
    {
        std::cerr << "Negotiating..." << std::endl;
    }
    void CliNegotiating::Update(t_owner &owner) const
    {
        // Send an ident string.
        {
            ClientIdentPkt myident;
            myident.username = owner.session.username;
            myident.key = owner.session.key;
            owner.session.proto.Write(myident);
        }

        std::cerr << "Awaiting server ident..." << std::endl;

        // Read the server's ident string...
        {
            ServerIdentPkt * const srvident = (ServerIdentPkt *) owner.session.proto.Read();
            if (srvident->type != ServerPkt::IDENT)
            {
                delete srvident;
                throw LoginException("Login Error - did not receive OK from server");
            }

            if (srvident->srv_version != BaseProtocol::proto_version)
            {
                // Some opensource servers report a silly protocol version that doesn't exist o_o
                // Continue anyways.
                owner.session.listener->onProtocolWarning("Invalid Server Version Detected - Attempting anyway.");
                //throw ProtocolException("Unable to negotiate protocol version");
            }

            // Read the facts of life...
            owner.session.server_name = srvident->srv_name;
            owner.session.server_motd = srvident->srv_motd;
            owner.session._world.playertype = srvident->user_type;

            // Free our packet.
            delete srvident;
        }

        std::cerr << "Successfully Negotiated Connection..." << std::endl;
        std::cerr << "Awaiting Map Data..." << std::endl;

        // Await map data...
        {
            ServerLevelBeginPkt * const mapdata = (ServerLevelBeginPkt *) owner.session.proto.Read();

            if (mapdata->type != ServerPkt::LEVELBEGIN)
            {
                delete mapdata;
                throw ProtocolException("Unexpected data while waiting for world");
            }

            // Free our packet.
            delete mapdata;

            // The packet type was a levelbegin... start loading the map.
            owner.ChangeState(owner.States.CLI_LOADINGMAP);
        }


    }
    void CliNegotiating::Exit(t_owner &owner) const
    {

    }
}
