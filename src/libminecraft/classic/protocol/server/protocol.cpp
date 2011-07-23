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

#include "packet/disconnect.hpp"
#include "packet/ident.hpp"
#include "packet/levelbegin.hpp"
#include "packet/levelchunk.hpp"
#include "packet/leveldone.hpp"
#include "packet/message.hpp"
#include "packet/ping.hpp"
#include "packet/playerdespawn.hpp"
#include "packet/playerdir.hpp"
#include "packet/playerop.hpp"
#include "packet/playerpos.hpp"
#include "packet/playerposdir.hpp"
#include "packet/playerspawn.hpp"
#include "packet/playerteleport.hpp"
#include "packet/setblock.hpp"

#include <boost/assign/list_of.hpp>

namespace libminecraft
{
    template<> const std::map<const std::type_info *, classic::protocol::server::Packet::PacketID>
            Protocol<classic::protocol::server::Protocol, classic::protocol::server::Packet, classic::protocol::server::Packet::PacketID>::msgmap =
                boost::assign::map_list_of                    
                    (&typeid(classic::protocol::server::packet::Disconnect), classic::protocol::server::Packet::DISCONNECT)
                    (&typeid(classic::protocol::server::packet::Ident), classic::protocol::server::Packet::IDENT)
                    (&typeid(classic::protocol::server::packet::Ping), classic::protocol::server::Packet::PING)
                    (&typeid(classic::protocol::server::packet::LevelBegin), classic::protocol::server::Packet::LEVELBEGIN)
                    (&typeid(classic::protocol::server::packet::LevelChunk), classic::protocol::server::Packet::LEVELCHUNK)
                    (&typeid(classic::protocol::server::packet::LevelDone), classic::protocol::server::Packet::LEVELDONE)
                    (&typeid(classic::protocol::server::packet::Message), classic::protocol::server::Packet::MESSAGE)
                    (&typeid(classic::protocol::server::packet::PlayerDespawn), classic::protocol::server::Packet::DESPAWN)
                    (&typeid(classic::protocol::server::packet::PlayerDir), classic::protocol::server::Packet::DIR)
                    (&typeid(classic::protocol::server::packet::PlayerOp), classic::protocol::server::Packet::USEROP)
                    (&typeid(classic::protocol::server::packet::PlayerPosDir), classic::protocol::server::Packet::POSDIR)
                    (&typeid(classic::protocol::server::packet::PlayerPos), classic::protocol::server::Packet::POS)
                    (&typeid(classic::protocol::server::packet::PlayerSpawn), classic::protocol::server::Packet::SPAWN)
                    (&typeid(classic::protocol::server::packet::PlayerTeleport), classic::protocol::server::Packet::TELEPORT)
                    (&typeid(classic::protocol::server::packet::SetBlock), classic::protocol::server::Packet::BLOCK);
}

