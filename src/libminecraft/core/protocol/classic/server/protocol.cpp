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
    template<> const std::map<const std::type_info *, classic::server::Packet::PacketID>
            Protocol<classic::server::Protocol, classic::server::Packet, classic::server::Packet::PacketID>::msgmap =
                boost::assign::map_list_of                    
                    (&typeid(classic::server::packet::Disconnect), classic::server::Packet::DISCONNECT)
                    (&typeid(classic::server::packet::Ident), classic::server::Packet::IDENT)
                    (&typeid(classic::server::packet::Ping), classic::server::Packet::PING)
                    (&typeid(classic::server::packet::LevelBegin), classic::server::Packet::LEVELBEGIN)
                    (&typeid(classic::server::packet::LevelChunk), classic::server::Packet::LEVELCHUNK)
                    (&typeid(classic::server::packet::LevelDone), classic::server::Packet::LEVELDONE)
                    (&typeid(classic::server::packet::Message), classic::server::Packet::MESSAGE)
                    (&typeid(classic::server::packet::PlayerDespawn), classic::server::Packet::DESPAWN)
                    (&typeid(classic::server::packet::PlayerDir), classic::server::Packet::DIR)
                    (&typeid(classic::server::packet::PlayerOp), classic::server::Packet::USEROP)
                    (&typeid(classic::server::packet::PlayerPosDir), classic::server::Packet::POSDIR)
                    (&typeid(classic::server::packet::PlayerPos), classic::server::Packet::POS)
                    (&typeid(classic::server::packet::PlayerSpawn), classic::server::Packet::SPAWN)
                    (&typeid(classic::server::packet::PlayerTeleport), classic::server::Packet::TELEPORT)
                    (&typeid(classic::server::packet::SetBlock), classic::server::Packet::BLOCK);

    namespace classic
    {
        namespace server
        {

        }
    }
}

