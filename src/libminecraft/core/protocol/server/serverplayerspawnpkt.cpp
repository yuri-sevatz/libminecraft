/*
 * serverplayerspawnpkt.cpp
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

#include "serverplayerspawnpkt.hpp"

#include "../minecraftstream.hpp"

namespace libminecraft
{
    const MinecraftTypes::Byte ServerPlayerSpawnPkt::id = ServerPkt::SPAWN;

    ServerPlayerSpawnPkt::ServerPlayerSpawnPkt() :
            ServerPkt(ServerPkt::SPAWN)
    {
    }

    void ServerPlayerSpawnPkt::read(std::istream &stream)
    {
        MinecraftStream::getByte(stream, player_id);
        MinecraftStream::getString(stream, player_name);
        MinecraftStream::getSignedShort(stream, x);
        MinecraftStream::getSignedShort(stream, y);
        MinecraftStream::getSignedShort(stream, z);
        MinecraftStream::getByte(stream, yaw);
        MinecraftStream::getByte(stream, pitch);
    }

    void ServerPlayerSpawnPkt::write(std::ostream &stream) const
    {
        MinecraftStream::putByte(stream, ServerPlayerSpawnPkt::id);

        MinecraftStream::putByte(stream, player_id);
        MinecraftStream::putString(stream, player_name);
        MinecraftStream::putSignedShort(stream, x);
        MinecraftStream::putSignedShort(stream, y);
        MinecraftStream::putSignedShort(stream, z);
        MinecraftStream::putByte(stream, yaw);
        MinecraftStream::putByte(stream, pitch);

    }

    void ServerPlayerSpawnPkt::toReadable(std::ostream &os) const
    {
        os << "Player ID: " << (unsigned int) player_id << "\n";
        os << "Player Name: " << player_name << "\n";
        os << "Spawn X: " << (int) x << "\n";
        os << "Spawn Y: " << (int) y << "\n";
        os << "Spawn Z: " << (int) z << "\n";
        os << "Yaw: " << (unsigned int) yaw << "\n";
        os << "Pitch: " << (unsigned int) pitch << std::endl;
    }
}

