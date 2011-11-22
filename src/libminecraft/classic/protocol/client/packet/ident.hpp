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

#ifndef LIBMINECRAFT_CLASSIC_PROTOCOL_CLIENT_PACKET_IDENT_HPP
#define LIBMINECRAFT_CLASSIC_PROTOCOL_CLIENT_PACKET_IDENT_HPP

#include "../packet.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace protocol
        {
            namespace client
            {
                namespace packet
                {
                    class Ident : public Packet
                    {
                    public:
                        static const MCTypes::Byte id;

                        MCTypes::Byte version;
                        MCTypes::String64 username;
                        MCTypes::String64 key;
                        MCTypes::Byte unused;

                    public:
                        Ident();
                        void read(std::istream &stream);
                        void write(std::ostream &os) const;
                        void toReadable(std::ostream &os) const;
                        MCTypes::Byte cmpVersion() const;
                    };
                }
            }
        }
    }
}

#endif // LIBMINECRAFT_CLASSIC_CLIENT_PACKET_IDENT_HPP
