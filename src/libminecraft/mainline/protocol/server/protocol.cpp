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

#include "packet/abilities.hpp"
#include "packet/entityvelocity.hpp"
#include "packet/equipment.hpp"
#include "packet/gamestate.hpp"
#include "packet/health.hpp"
#include "packet/ident.hpp"
#include "packet/itemspawn.hpp"
#include "packet/login.hpp"
#include "packet/message.hpp"
#include "packet/mobspawn.hpp"
#include "packet/movingobjectspawn.hpp"
#include "packet/ping.hpp"
#include "packet/playerlistitem.hpp"
#include "packet/playerposdir.hpp"
#include "packet/prechunk.hpp"
#include "packet/spawnpoint.hpp"
#include "packet/time.hpp"
#include "packet/windowitems.hpp"

#include <boost/assign/list_of.hpp>

namespace libminecraft
{
    template<> const std::map<const std::type_info *, mainline::protocol::server::Packet::PacketID>
            Protocol<mainline::protocol::server::Protocol, mainline::protocol::server::Packet, mainline::protocol::server::Packet::PacketID>::msgmap =
                boost::assign::map_list_of
                    (&typeid(mainline::protocol::server::packet::Abilities), mainline::protocol::server::Packet::ABILITIES)
                    (&typeid(mainline::protocol::server::packet::EntityVelocity), mainline::protocol::server::Packet::ENTITYVELOCITY)
                    (&typeid(mainline::protocol::server::packet::Equipment), mainline::protocol::server::Packet::EQUIPMENT)
                    (&typeid(mainline::protocol::server::packet::GameState), mainline::protocol::server::Packet::GAMESTATE)
                    (&typeid(mainline::protocol::server::packet::Health), mainline::protocol::server::Packet::HEALTH)
                    (&typeid(mainline::protocol::server::packet::Ident), mainline::protocol::server::Packet::IDENT)
                    (&typeid(mainline::protocol::server::packet::ItemSpawn), mainline::protocol::server::Packet::ITEMSPAWN)
                    (&typeid(mainline::protocol::server::packet::Login), mainline::protocol::server::Packet::LOGIN)
                    (&typeid(mainline::protocol::server::packet::Message), mainline::protocol::server::Packet::MESSAGE)
                    (&typeid(mainline::protocol::server::packet::MobSpawn), mainline::protocol::server::Packet::MOBSPAWN)
                    (&typeid(mainline::protocol::server::packet::MovingObjectSpawn), mainline::protocol::server::Packet::MOVINGOBJECTSPAWN)
                    (&typeid(mainline::protocol::server::packet::Ping), mainline::protocol::server::Packet::PING)
                    (&typeid(mainline::protocol::server::packet::PlayerListItem), mainline::protocol::server::Packet::PLAYERLISTITEM)
                    (&typeid(mainline::protocol::server::packet::PlayerPosDir), mainline::protocol::server::Packet::PLAYERPOSDIR)
                    (&typeid(mainline::protocol::server::packet::PreChunk), mainline::protocol::server::Packet::PRECHUNK)
                    (&typeid(mainline::protocol::server::packet::SpawnPoint), mainline::protocol::server::Packet::SPAWNPOINT)
                    (&typeid(mainline::protocol::server::packet::Time), mainline::protocol::server::Packet::TIME)
                    (&typeid(mainline::protocol::server::packet::WindowItems), mainline::protocol::server::Packet::WINDOWITEMS);
}
