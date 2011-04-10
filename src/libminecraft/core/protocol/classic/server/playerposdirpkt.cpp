/*
 * playerposdirpkt.cpp
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

#include "playerposdirpkt.hpp"

#include "../../stream.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace server
        {
            const NetworkTypes::Byte PlayerPosDirPkt::id = Packet::POSDIR;

            PlayerPosDirPkt::PlayerPosDirPkt() :
                    Packet(Packet::POSDIR)
            {
            }

            void PlayerPosDirPkt::read(std::istream &stream)
            {
                Stream::getByte(stream, player_id);
                Stream::getSignedByte(stream, delta_x);
                Stream::getSignedByte(stream, delta_y);
                Stream::getSignedByte(stream, delta_z);
                Stream::getByte(stream, yaw);
                Stream::getByte(stream, pitch);
            }

            void PlayerPosDirPkt::write(std::ostream &stream) const
            {
                Stream::putByte(stream, PlayerPosDirPkt::id);

                Stream::putByte(stream, player_id);
                Stream::putSignedByte(stream, delta_x);
                Stream::putSignedByte(stream, delta_y);
                Stream::putSignedByte(stream, delta_z);
                Stream::putByte(stream, yaw);
                Stream::putByte(stream, pitch);
            }

            void PlayerPosDirPkt::toReadable(std::ostream &os) const
            {
                os << "Player ID: " << (unsigned int) player_id << "\n";
                os << "Delta X: " << (int) delta_x << "\n";
                os << "Delta Y: " << (int) delta_y << "\n";
                os << "Delta Z: " << (int) delta_z << "\n";
                os << "Yaw: " << (unsigned int) yaw << "\n";
                os << "Pitch: " << (unsigned int) pitch << std::endl;
            }
        }
    }
}

