/*
 * clientidentpkt.cpp
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

#include "clientidentpkt.hpp"
#include "../baseprotocol.hpp"

#include "../minecraftstream.hpp"

#include "../minecrafttypes.hpp"

namespace libminecraft
{
    const MinecraftTypes::Byte ClientIdentPkt::id = ClientPkt::IDENT;

    ClientIdentPkt::ClientIdentPkt() :
            ClientPkt(ClientPkt::IDENT), version(BaseProtocol::proto_version), unused(0x00)
    {

    }

    void ClientIdentPkt::read(std::istream &stream)
    {
        MinecraftStream::getByte(stream, version);
        MinecraftStream::getString(stream, username);
        MinecraftStream::getString(stream, key);
        MinecraftStream::getByte(stream, unused);
    }

    void ClientIdentPkt::write(std::ostream &stream) const
    {
        MinecraftStream::putByte(stream, ClientIdentPkt::id); // Byte (packet id)

        MinecraftStream::putByte(stream, version);
        MinecraftStream::putString(stream, username);
        MinecraftStream::putString(stream, key);
        MinecraftStream::putByte(stream, unused);
    }

    void ClientIdentPkt::toReadable(std::ostream &os) const
    {
        os << "Version: " << (unsigned int) version << "\n";
        os << "Username: " << username << "\n";
        os << "Key: " << key << "\n";
        os << "Unused: " << (unsigned int) unused << std::endl;
    }
}
