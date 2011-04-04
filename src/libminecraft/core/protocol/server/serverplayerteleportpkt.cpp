/*
 * serverplayerteleportpkt.cpp
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

#include "serverplayerteleportpkt.hpp"

#include "../minecraftstream.hpp"

namespace libminecraft
{
    const MinecraftTypes::Byte ServerPlayerTeleportPkt::id = ServerPkt::TELEPORT;

    ServerPlayerTeleportPkt::ServerPlayerTeleportPkt() :
            ServerPkt(ServerPkt::TELEPORT)
    {
    }

    void ServerPlayerTeleportPkt::read(std::istream &stream)
    {
        MinecraftStream::getByte(stream, player_id);
        MinecraftStream::getSignedShort(stream, x);
        MinecraftStream::getSignedShort(stream, y);
        MinecraftStream::getSignedShort(stream, z);
        MinecraftStream::getByte(stream, yaw);
        MinecraftStream::getByte(stream, pitch);
    }

    void ServerPlayerTeleportPkt::write(std::ostream &stream) const
    {
        MinecraftStream::putByte(stream, ServerPlayerTeleportPkt::id);

        MinecraftStream::putByte(stream, player_id);
        MinecraftStream::putSignedShort(stream, x);
        MinecraftStream::putSignedShort(stream, y);
        MinecraftStream::putSignedShort(stream, z);
        MinecraftStream::putByte(stream, yaw);
        MinecraftStream::putByte(stream, pitch);
    }

    void ServerPlayerTeleportPkt::toReadable(std::ostream &os) const
    {
        os << "Player ID: " << (unsigned int) player_id << "\n";
        os << "Delta X: " << (int) x << "\n";
        os << "Delta Y: " << (int) y << "\n";
        os << "Delta Z: " << (int) z << "\n";
        os << "Yaw: " << (unsigned int) yaw << "\n";
        os << "Pitch: " << (unsigned int) pitch << "\n";
    }
}

