/*
 * protocol.cpp
 * This file is part of LibMinecraft.
 *
 * Created by Yuri Sevatz on 04/2011.
 * Copyright (c) 2011 Yuri Sevatz. All rights reserved
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

#include "packet/equipment.hpp"
#include "packet/health.hpp"
#include "packet/ident.hpp"
#include "packet/login.hpp"
#include "packet/ping.hpp"
#include "packet/spawnpoint.hpp"
#include "packet/time.hpp"

#include <boost/assign/list_of.hpp>

namespace libminecraft
{
    template<> const std::map<const std::type_info *, mainline::server::Packet::PacketID>
            Protocol<mainline::server::Protocol, mainline::server::Packet, mainline::server::Packet::PacketID>::msgmap =
                boost::assign::map_list_of
                    (&typeid(mainline::server::packet::Equipment), mainline::server::Packet::EQUIPMENT)
                    (&typeid(mainline::server::packet::Health), mainline::server::Packet::HEALTH)
                    (&typeid(mainline::server::packet::Ident), mainline::server::Packet::IDENT)
                    (&typeid(mainline::server::packet::Login), mainline::server::Packet::LOGIN)
                    (&typeid(mainline::server::packet::Ping), mainline::server::Packet::PING)
                    (&typeid(mainline::server::packet::SpawnPoint), mainline::server::Packet::SPAWNPOINT)
                    (&typeid(mainline::server::packet::Time), mainline::server::Packet::TIME);

    namespace mainline
    {
        namespace server
        {

        }
    }
}
