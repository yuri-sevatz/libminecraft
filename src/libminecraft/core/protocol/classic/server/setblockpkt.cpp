/*
 * setblockpkt.cpp
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

#include "setblockpkt.hpp"

#include "../../stream.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace server
        {
            const MCTypes::Byte SetBlockPkt::id = Packet::BLOCK;

            SetBlockPkt::SetBlockPkt() :
                    Packet(Packet::BLOCK)
            {
            }

            void SetBlockPkt::read(std::istream &stream)
            {
                Stream::getSignedShort(stream, x);
                Stream::getSignedShort(stream, y);
                Stream::getSignedShort(stream, z);
                Stream::getSignedByte(stream, type);
            }

            void SetBlockPkt::write(std::ostream &stream) const
            {
                Stream::putSignedByte(stream, SetBlockPkt::id);

                Stream::putSignedShort(stream, x);
                Stream::putSignedShort(stream, y);
                Stream::putSignedShort(stream, z);
                Stream::putSignedByte(stream, type);
            }

            void SetBlockPkt::toReadable(std::ostream &os) const
            {
                os << "X: " << x << "\n";
                os << "Y: " << y << "\n";
                os << "Z: " << z << "\n";
                os << "Type: " << type << std::endl;
            }
        }
    }
}


