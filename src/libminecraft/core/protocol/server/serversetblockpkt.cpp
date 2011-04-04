/*
 * serversetblockpkt.cpp
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

#include "serversetblockpkt.hpp"

#include "../minecraftstream.hpp"

namespace libminecraft
{
    const MinecraftTypes::Byte ServerSetBlockPkt::id = ServerPkt::BLOCK;

    ServerSetBlockPkt::ServerSetBlockPkt() :
            ServerPkt(ServerPkt::BLOCK)
    {
    }

    void ServerSetBlockPkt::read(std::istream &stream)
    {
        MinecraftStream::getSignedShort(stream, x);
        MinecraftStream::getSignedShort(stream, y);
        MinecraftStream::getSignedShort(stream, z);
        MinecraftStream::getByte(stream, type);
    }

    void ServerSetBlockPkt::write(std::ostream &stream) const
    {
        MinecraftStream::putByte(stream, ServerSetBlockPkt::id);

        MinecraftStream::putSignedShort(stream, x);
        MinecraftStream::putSignedShort(stream, y);
        MinecraftStream::putSignedShort(stream, z);
        MinecraftStream::putByte(stream, type);
    }

    void ServerSetBlockPkt::toReadable(std::ostream &os) const
    {
        os << "X: " << x << "\n";
        os << "Y: " << y << "\n";
        os << "Z: " << z << "\n";
        os << "Type: " << type << std::endl;
    }
}


