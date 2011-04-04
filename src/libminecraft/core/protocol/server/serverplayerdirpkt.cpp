/*
 * serverplayerdirpkt.cpp
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

#include "serverplayerdirpkt.hpp"

#include "../minecraftstream.hpp"

namespace libminecraft
{
    const MinecraftTypes::Byte ServerPlayerDirPkt::id = ServerPkt::DIR;

    ServerPlayerDirPkt::ServerPlayerDirPkt() :
            ServerPkt(ServerPkt::DIR)
    {
    }

    void ServerPlayerDirPkt::read(std::istream &stream)
    {
        MinecraftStream::getByte(stream, player_id);
        MinecraftStream::getByte(stream, yaw);
        MinecraftStream::getByte(stream, pitch);
    }

    void ServerPlayerDirPkt::write(std::ostream &stream) const
    {
        MinecraftStream::putByte(stream, ServerPlayerDirPkt::id);

        MinecraftStream::putByte(stream, player_id);
        MinecraftStream::putByte(stream, yaw);
        MinecraftStream::putByte(stream, pitch);
    }

    void ServerPlayerDirPkt::toReadable(std::ostream &os) const
    {
        os << "Player ID: " << (unsigned int) player_id << "\n";
        os << "Yaw: " << (unsigned int) yaw << "\n";
        os << "Pitch: " << (unsigned int) pitch << "\n";
    }
}

