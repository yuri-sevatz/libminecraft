/*
 * clientidentpkt.hpp
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

#ifndef CLIENTIDENTPKT_HPP
#define CLIENTIDENTPKT_HPP

#include "clientpkt.hpp"

#include <string>

namespace libminecraft
{
    class ClientIdentPkt : public ClientPkt
    {
    public:
        std::string username;
        std::string key;
    public:
        ClientIdentPkt();
        static MinecraftPacket * const Read(std::istream &stream);
        virtual void Write(std::ostream & stream) const;
    };
}

#endif // CLIENTIDENTPKT_HPP
