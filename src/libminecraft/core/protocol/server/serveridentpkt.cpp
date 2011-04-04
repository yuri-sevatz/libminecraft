/*
 * serveridentpkt.cpp
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

#include "serveridentpkt.hpp"

#include "../baseprotocol.hpp"
#include "../minecraftstream.hpp"

namespace libminecraft
{
    const MinecraftTypes::Byte ServerIdentPkt::id = ServerPkt::IDENT;

    ServerIdentPkt::ServerIdentPkt()
        : ServerPkt(ServerPkt::IDENT)
    {

    }

    void ServerIdentPkt::read(std::istream & stream)
    {
        MinecraftStream::getByte(stream, srv_version);
        MinecraftStream::getString(stream, srv_name);
        MinecraftStream::getString(stream, srv_motd);
        MinecraftStream::getByte(stream, user_type);
    }

    void ServerIdentPkt::write(std::ostream &stream) const
    {
        MinecraftStream::putByte(stream, ServerIdentPkt::id);

        MinecraftStream::putByte(stream, srv_version);
        MinecraftStream::putString(stream, srv_name);
        MinecraftStream::putString(stream, srv_motd);
        MinecraftStream::putByte(stream, user_type);
    }

    void ServerIdentPkt::toReadable(std::ostream &os) const
    {
        os << "Version: " << (unsigned int) srv_version << "\n";
        os << "Name: " << srv_name << "\n";
        os << "Motd: " << srv_motd << "\n";
        os << "User Type: " << (unsigned int) user_type << std::endl;
    }
}
