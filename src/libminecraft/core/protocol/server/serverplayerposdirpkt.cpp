/*
 * serverplayerposdirpkt.cpp
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

#include "serverplayerposdirpkt.hpp"

#include "../minecraftstream.hpp"

namespace libminecraft
{
    const MinecraftTypes::Byte ServerPlayerPosDirPkt::id = ServerPkt::POSDIR;

    ServerPlayerPosDirPkt::ServerPlayerPosDirPkt() :
            ServerPkt(ServerPkt::POSDIR)
    {
    }

    void ServerPlayerPosDirPkt::read(std::istream &stream)
    {
        MinecraftStream::getByte(stream, player_id);
        MinecraftStream::getSignedByte(stream, delta_x);
        MinecraftStream::getSignedByte(stream, delta_y);
        MinecraftStream::getSignedByte(stream, delta_z);
        MinecraftStream::getByte(stream, yaw);
        MinecraftStream::getByte(stream, pitch);
    }

    void ServerPlayerPosDirPkt::write(std::ostream &stream) const
    {
        MinecraftStream::putByte(stream, ServerPlayerPosDirPkt::id);

        MinecraftStream::putByte(stream, player_id);
        MinecraftStream::putSignedByte(stream, delta_x);
        MinecraftStream::putSignedByte(stream, delta_y);
        MinecraftStream::putSignedByte(stream, delta_z);
        MinecraftStream::putByte(stream, yaw);
        MinecraftStream::putByte(stream, pitch);
    }

    void ServerPlayerPosDirPkt::toReadable(std::ostream &os) const
    {
        os << "Player ID: " << (unsigned int) player_id << "\n";
        os << "Delta X: " << (int) delta_x << "\n";
        os << "Delta Y: " << (int) delta_y << "\n";
        os << "Delta Z: " << (int) delta_z << "\n";
        os << "Yaw: " << (unsigned int) yaw << "\n";
        os << "Pitch: " << (unsigned int) pitch << std::endl;
    }
}

