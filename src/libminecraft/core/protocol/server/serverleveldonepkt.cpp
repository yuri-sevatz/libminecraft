/*
 * serverleveldonepkt.cpp
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

#include "serverleveldonepkt.hpp"
#include "../minecraftstream.hpp"

#include <iostream>

namespace libminecraft
{
    const MinecraftTypes::Byte ServerLevelDonePkt::id = ServerPkt::LEVELDONE;

    ServerLevelDonePkt::ServerLevelDonePkt() :
            ServerPkt(ServerPkt::LEVELDONE)
    {
    }

    void ServerLevelDonePkt::read(std::istream &stream)
    {
        // Read final size
        MinecraftStream::getSignedShort(stream, size_x);
        MinecraftStream::getSignedShort(stream, size_y);
        MinecraftStream::getSignedShort(stream, size_z);
    }

    void ServerLevelDonePkt::write(std::ostream &stream) const
    {
        MinecraftStream::putByte(stream, ServerLevelDonePkt::id);
        MinecraftStream::putSignedShort(stream, size_x);
        MinecraftStream::putSignedShort(stream, size_y);
        MinecraftStream::putSignedShort(stream, size_z);
    }

    void ServerLevelDonePkt::toReadable(std::ostream &os) const
    {
        os << "Size X: " << size_x << "\n";
        os << "Size Y: " << size_y << "\n";
        os << "Size Z: " << size_z << std::endl;
    }


}
