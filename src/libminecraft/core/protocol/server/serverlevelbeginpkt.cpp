/*
 * serverlevelbeginpkt.cpp
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

#include "serverlevelbeginpkt.hpp"

#include "../minecraftstream.hpp"

namespace libminecraft
{
    const MinecraftTypes::Byte ServerLevelBeginPkt::id = ServerPkt::LEVELBEGIN;

    ServerLevelBeginPkt::ServerLevelBeginPkt()
        : ServerPkt(ServerPkt::LEVELBEGIN)
    {
    }

    void ServerLevelBeginPkt::read(std::istream &stream)
    {

    }

    void ServerLevelBeginPkt::write(std::ostream &stream) const
    {
        MinecraftStream::putByte(stream, ServerLevelBeginPkt::id);
    }

    void ServerLevelBeginPkt::toReadable(std::ostream &os) const
    {

    }
}
