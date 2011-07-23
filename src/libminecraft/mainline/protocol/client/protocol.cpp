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

#include "packet/ident.hpp"
#include "packet/login.hpp"
#include "packet/message.hpp"
#include "packet/player.hpp"
#include "packet/use.hpp"

#include <boost/assign/list_of.hpp>

namespace libminecraft
{
    template<> const std::map<const std::type_info *, mainline::protocol::client::Packet::PacketID>
            Protocol<mainline::protocol::client::Protocol, mainline::protocol::client::Packet, mainline::protocol::client::Packet::PacketID>::msgmap =
                boost::assign::map_list_of
                    (&typeid(mainline::protocol::client::packet::Ident), mainline::protocol::client::Packet::IDENT)
                    (&typeid(mainline::protocol::client::packet::Login), mainline::protocol::client::Packet::LOGIN)
                    (&typeid(mainline::protocol::client::packet::Message), mainline::protocol::client::Packet::MESSAGE)
                    (&typeid(mainline::protocol::client::packet::Player), mainline::protocol::client::Packet::PLAYER)
                    (&typeid(mainline::protocol::client::packet::Use), mainline::protocol::client::Packet::USE);
}
