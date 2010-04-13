/*
 * identpkt.cpp
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

#include "identpkt.hpp"

#include "protocol.hpp"

#include "../../stream.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace client
        {
            const MCTypes::Byte IdentPkt::id = Packet::IDENT;

            IdentPkt::IdentPkt() :
                    Packet(Packet::IDENT), version(classic::Protocol::proto_version), unused(0x00)
            {

            }

            void IdentPkt::read(std::istream &stream)
            {
                Stream::getSignedByte(stream, version);
                Stream::getString(stream, username);
                Stream::getString(stream, key);
                Stream::getSignedByte(stream, unused);
            }

            void IdentPkt::write(std::ostream &stream) const
            {
                Stream::putSignedByte(stream, IdentPkt::id); // Byte (packet id)

                Stream::putSignedByte(stream, version);
                Stream::putString(stream, username);
                Stream::putString(stream, key);
                Stream::putSignedByte(stream, unused);
            }

            void IdentPkt::toReadable(std::ostream &os) const
            {
                os << "Version: " << (unsigned int) version << "\n";
                os << "Username: " << username << "\n";
                os << "Key: " << key << "\n";
                os << "Unused: " << (unsigned int) unused << std::endl;
            }
        }
    }
}
