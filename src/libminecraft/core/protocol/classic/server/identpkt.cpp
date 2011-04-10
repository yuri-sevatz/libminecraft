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
#include "../protocol.hpp"
#include "../../stream.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace server
        {
            const NetworkTypes::Byte IdentPkt::id = Packet::IDENT;

            IdentPkt::IdentPkt()
                : Packet(Packet::IDENT), srv_version(classic::Protocol::proto_version)
            {

            }

            void IdentPkt::read(std::istream & stream)
            {
                Stream::getByte(stream, srv_version);
                Stream::getString(stream, srv_name);
                Stream::getString(stream, srv_motd);
                Stream::getByte(stream, user_type);
            }

            void IdentPkt::write(std::ostream &stream) const
            {
                Stream::putByte(stream, IdentPkt::id);

                Stream::putByte(stream, srv_version);
                Stream::putString(stream, srv_name);
                Stream::putString(stream, srv_motd);
                Stream::putByte(stream, user_type);
            }

            void IdentPkt::toReadable(std::ostream &os) const
            {
                os << "Version: " << (unsigned int) srv_version << "\n";
                os << "Name: " << srv_name << "\n";
                os << "Motd: " << srv_motd << "\n";
                os << "User Type: " << (unsigned int) user_type << std::endl;
            }
        }
    }
}
