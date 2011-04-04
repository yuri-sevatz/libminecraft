/*
 * serverplayerpospkt.cpp
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

#include "serverplayerpospkt.hpp"

#include "../minecraftstream.hpp"

namespace libminecraft
{
    const MinecraftTypes::Byte ServerPlayerPosPkt::id = ServerPkt::POS;

    ServerPlayerPosPkt::ServerPlayerPosPkt() :
            ServerPkt(ServerPkt::POS)
    {
    }

    void ServerPlayerPosPkt::read(std::istream &stream)
    {
        MinecraftStream::getByte(stream, player_id);
        MinecraftStream::getSignedByte(stream, delta_x);
        MinecraftStream::getSignedByte(stream, delta_y);
        MinecraftStream::getSignedByte(stream, delta_z);
    }

    void ServerPlayerPosPkt::write(std::ostream &stream) const
    {
        MinecraftStream::putByte(stream, ServerPlayerPosPkt::id);

        MinecraftStream::putByte(stream, player_id);
        MinecraftStream::putSignedByte(stream, delta_x);
        MinecraftStream::putSignedByte(stream, delta_y);
        MinecraftStream::putSignedByte(stream, delta_z);
    }

    void ServerPlayerPosPkt::toReadable(std::ostream &os) const
    {
        os << "Player ID: " << (unsigned int) player_id << "\n";
        os << "Delta X: " << (int) delta_x << "\n";
        os << "Delta Y: " << (int) delta_y << "\n";
        os << "Delta Z: " << (int) delta_z << std::endl;
    }
}

