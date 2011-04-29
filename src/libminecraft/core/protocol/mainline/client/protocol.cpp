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
    template<> const std::map<const std::type_info *, mainline::client::Packet::PacketID>
            Protocol<mainline::client::Protocol, mainline::client::Packet, mainline::client::Packet::PacketID>::msgmap =
                boost::assign::map_list_of
                    (&typeid(mainline::client::packet::Ident), mainline::client::Packet::IDENT)
                    (&typeid(mainline::client::packet::Login), mainline::client::Packet::LOGIN)
                    (&typeid(mainline::client::packet::Message), mainline::client::Packet::MESSAGE)
                    (&typeid(mainline::client::packet::Player), mainline::client::Packet::PLAYER)
                    (&typeid(mainline::client::packet::Use), mainline::client::Packet::USE);

    namespace mainline
    {
        namespace client
        {

        }
    }
}
