/*
 * negotiating.cpp
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

#include "negotiating.hpp"
#include <iostream>

#include "../connection.hpp"
#include <libminecraft/classic/session/remote.hpp>
#include <libminecraft/classic/client.hpp>

#include "../../../protocol/client/packet/ident.hpp"
#include "../../../protocol/server/packet/ident.hpp"

#include <libminecraft/shared/exception/login.hpp>

namespace libminecraft {
namespace classic {
namespace session {
namespace remote {
namespace state {
Negotiating::Negotiating() {
}

void Negotiating::Enter(t_owner & owner) const {
    std::cerr << "Negotiating..." << std::endl;
}
void Negotiating::Update(t_owner & owner) const {
    protocol::client::packet::Ident myident;
    myident.username = owner.username;
    myident.key = owner.key;
    myident.version = protocol::client::Protocol::version;
    owner.proto.write(myident);

    std::cerr << "Awaiting Response..." << std::endl;

    if (owner.proto.next() != protocol::server::Packet::IDENT)
        throw exception::Login("Login Error - did not receive Ident from server");

    protocol::server::packet::Ident srvident;
    owner.proto.read(srvident);

    const MCTypes::Byte ver_diff = srvident.cmpVersion();

    if (ver_diff < 0)
        throw exception::Protocol("Unable to negotiate protocol version");
    else if (ver_diff > 0)
        owner.session.listener().onWarning("Invalid Server Version Detected - Attempting anyway.");

    // Read the facts of life...
    owner._server.name = srvident.srv_name;
    owner._server.motd = srvident.srv_motd;
    owner._self.optype = srvident.user_type;

    // Await map data...
    std::cerr << "Awaiting Map Data..." << std::endl;

    if (owner.proto.next() != protocol::server::Packet::LEVELBEGIN)
        throw exception::Protocol("Unexpected data while waiting for world");

    // The packet type was a levelbegin... start loading the map.
    owner.ChangeState(owner.States.LOADINGMAP);
}
void Negotiating::Exit(t_owner & owner) const {

}
}
}
}
}
}

