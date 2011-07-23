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
#include "packet/message.hpp"
#include "packet/posdir.hpp"
#include "packet/setblock.hpp"

#include <boost/assign/list_of.hpp>

namespace libminecraft
{
    template<> const std::map<const std::type_info *, classic::protocol::client::Packet::PacketID>
            Protocol<classic::protocol::client::Protocol, classic::protocol::client::Packet, classic::protocol::client::Packet::PacketID>::msgmap =
                boost::assign::map_list_of
                    (&typeid(classic::protocol::client::packet::Ident), classic::protocol::client::Packet::IDENT)
                    (&typeid(classic::protocol::client::packet::Message), classic::protocol::client::Packet::MESSAGE)
                    (&typeid(classic::protocol::client::packet::PosDir), classic::protocol::client::Packet::POSDIR)
                    (&typeid(classic::protocol::client::packet::SetBlock), classic::protocol::client::Packet::BLOCK);
}
