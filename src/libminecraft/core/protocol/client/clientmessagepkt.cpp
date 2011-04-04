/*
 * clientmessagepkt.cpp
 * This file is part of LibMinecraft.
 *
 * Created by Yuri Sevatz on 03/2011.
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

#include "clientmessagepkt.hpp"
#include "../baseprotocol.hpp"

#include "../minecraftstream.hpp"

#include "../minecrafttypes.hpp"

namespace libminecraft
{
    const MinecraftTypes::Byte ClientMessagePkt::id = ClientPkt::MESSAGE;

    ClientMessagePkt::ClientMessagePkt() :
            ClientPkt(ClientPkt::MESSAGE), unused(0xFF)
    {

    }

    void ClientMessagePkt::read(std::istream &stream)
    {
        MinecraftStream::getByte(stream, unused);
        MinecraftStream::getString(stream, message);
    }

    void ClientMessagePkt::write(std::ostream &stream) const
    {
        // Try sending our auth string...
        MinecraftStream::putByte(stream, ClientMessagePkt::id); // Byte (packet id)

        MinecraftStream::putByte(stream, unused);
        MinecraftStream::putString(stream, message);
    }

    void ClientMessagePkt::toReadable(std::ostream &os) const
    {
        os << "Unused: " << (unsigned int) unused << "\n";
        os << "Message: " << message << "\n";
    }
}
