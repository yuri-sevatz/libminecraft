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
#include "../../../../session/remotesession.hpp"
#include "../../../../interfaces/clienteventhandler.hpp"

#include "../../protocol/client/packet/ident.hpp"
#include "../../protocol/server/packet/ident.hpp"

namespace libminecraft
{
    namespace classic
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
            client::packet::Ident myident;
            myident.username = owner.session.username;
            myident.key = owner.session.key;
            myident.version = client::Protocol::version;
            owner.session.client.write(myident);

            std::cerr << "Awaiting Response..." << std::endl;

            if (owner.session.client.next() != server::Packet::IDENT)
                throw LoginException("Login Error - did not receive Ident from server");

            server::packet::Ident srvident;
            owner.session.client.read(srvident);

            const MCTypes::Byte ver_diff = srvident.cmpVersion();

            if (ver_diff < 0)
                throw ProtocolException("Unable to negotiate protocol version");
            else if (ver_diff > 0)
                owner.session.listener->onProtocolWarning("Invalid Server Version Detected - Attempting anyway.");

            // Read the facts of life...
            owner.session.server_name = srvident.srv_name;
            owner.session.server_motd = srvident.srv_motd;
            owner.session._world.playertype = srvident.user_type;

            // Await map data...
            std::cerr << "Awaiting Map Data..." << std::endl;

            if (owner.session.client.next() != server::Packet::LEVELBEGIN)
                throw ProtocolException("Unexpected data while waiting for world");

            // The packet type was a levelbegin... start loading the map.
            owner.ChangeState(owner.States.CLI_LOADINGMAP);
        }
        void CliNegotiating::Exit(t_owner &owner) const
        {

        }
    }
}

