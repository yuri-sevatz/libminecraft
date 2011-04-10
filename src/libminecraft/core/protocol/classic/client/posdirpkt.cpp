/*
 * posdirpkt.cpp
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

#include "posdirpkt.hpp"

#include "../../stream.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace client
        {
            const NetworkTypes::Byte PosDirPkt::id = Packet::POSDIR;

            PosDirPkt::PosDirPkt() :
                    Packet(Packet::POSDIR)
            {

            }

            void PosDirPkt::read(std::istream &stream)
            {
                Stream::getByte(stream, player_id);
                Stream::getSignedShort(stream, x);
                Stream::getSignedShort(stream, y);
                Stream::getSignedShort(stream, z);
                Stream::getByte(stream, yaw);
                Stream::getByte(stream, pitch);
            }

            void PosDirPkt::write(std::ostream &stream) const
            {
                Stream::putByte(stream, PosDirPkt::id); // Byte (packet id)

                Stream::putByte(stream, player_id);
                Stream::putSignedShort(stream, x);
                Stream::putSignedShort(stream, y);
                Stream::putSignedShort(stream, z);
                Stream::putByte(stream, yaw);
                Stream::putByte(stream, pitch);
            }

            void PosDirPkt::toReadable(std::ostream &os) const
            {
                os << "Player ID: " << (unsigned int) player_id << "\n";
                os << "X: " << x << "\n";
                os << "Y: " << y << "\n";
                os << "Z: " << z << "\n";
                os << "Yaw: " << (unsigned int) yaw << "\n";
                os << "Pitch: " << (unsigned int) pitch << std::endl;
            }
        }
    }
}
