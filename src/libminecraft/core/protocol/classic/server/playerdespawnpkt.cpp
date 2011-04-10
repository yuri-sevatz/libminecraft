/*
 * playerdespawnpkt.cpp
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

#include "playerdespawnpkt.hpp"

#include "../../stream.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace server
        {
            const NetworkTypes::Byte PlayerDespawnPkt::id = Packet::DESPAWN;

            PlayerDespawnPkt::PlayerDespawnPkt() :
                    Packet(Packet::DESPAWN)
            {
            }

            void PlayerDespawnPkt::read(std::istream &stream)
            {
                Stream::getByte(stream, player_id);
            }

            void PlayerDespawnPkt::write(std::ostream &stream) const
            {
                Stream::putByte(stream, PlayerDespawnPkt::id);

                Stream::putByte(stream, player_id);
            }

            void PlayerDespawnPkt::toReadable(std::ostream &os) const
            {
                os << "Player ID: " << (unsigned int) player_id << std::endl;
            }
        }
    }
}

