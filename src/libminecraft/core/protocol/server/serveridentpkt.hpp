/*
 * serveridentpkt.hpp
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

#ifndef LIBMINECRAFT_SERVERIDENTPKT_HPP
#define LIBMINECRAFT_SERVERIDENTPKT_HPP

#include "serverpkt.hpp"

#include "../minecrafttypes.hpp"

#include <string>

namespace libminecraft
{
    class ServerIdentPkt : public ServerPkt
    {
    public:
        static const MinecraftTypes::Byte id;

        MinecraftTypes::Byte srv_version;
        std::string srv_name;
        std::string srv_motd;
        MinecraftTypes::Byte user_type;
    public:
        ServerIdentPkt();
        virtual void read(std::istream &stream);
        virtual void write(std::ostream &stream) const;
        virtual void toReadable(std::ostream &os) const;
    };
}

#endif // LIBMINECRAFT_SERVERIDENTPKT_HPP
