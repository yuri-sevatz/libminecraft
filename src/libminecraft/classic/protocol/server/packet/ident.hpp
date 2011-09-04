/*
 * ident.hpp
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

#ifndef LIBMINECRAFT_CLASSIC_PROTOCOL_SERVER_PACKET_IDENT_HPP
#define LIBMINECRAFT_CLASSIC_PROTOCOL_SERVER_PACKET_IDENT_HPP

#include "../packet.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace protocol
        {
            namespace server
            {
                namespace packet
                {
                    class Ident : public Packet
                    {
                    public:
                        MCTypes::Byte srv_version;
                        MCTypes::String64 srv_name;
                        MCTypes::String64 srv_motd;
                        MCTypes::Byte user_type;
                    public:
                        Ident();
                        virtual void read(std::istream &stream);
                        virtual void write(std::ostream &stream) const;
                        virtual void toReadable(std::ostream &os) const;
                        MCTypes::Byte cmpVersion() const;
                    };
                }
            }
        }
    }
}

#endif // LIBMINECRAFT_CLASSIC_PROTOCOL_SERVER_PACKET_IDENT_HPP
