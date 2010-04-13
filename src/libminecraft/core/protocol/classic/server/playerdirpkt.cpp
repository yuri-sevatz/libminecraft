/*
 * playerdirpkt.cpp
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

#include "playerdirpkt.hpp"

#include "../../stream.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace server
        {
            const MCTypes::Byte PlayerDirPkt::id = Packet::DIR;

            PlayerDirPkt::PlayerDirPkt() :
                    Packet(Packet::DIR)
            {
            }

            void PlayerDirPkt::read(std::istream &stream)
            {
                Stream::getSignedByte(stream, player_id);
                Stream::getSignedByte(stream, yaw);
                Stream::getSignedByte(stream, pitch);
            }

            void PlayerDirPkt::write(std::ostream &stream) const
            {
                Stream::putSignedByte(stream, PlayerDirPkt::id);

                Stream::putSignedByte(stream, player_id);
                Stream::putSignedByte(stream, yaw);
                Stream::putSignedByte(stream, pitch);
            }

            void PlayerDirPkt::toReadable(std::ostream &os) const
            {
                os << "Player ID: " << (unsigned int) player_id << "\n";
                os << "Yaw: " << (unsigned int) yaw << "\n";
                os << "Pitch: " << (unsigned int) pitch << "\n";
            }
        }
    }
}

