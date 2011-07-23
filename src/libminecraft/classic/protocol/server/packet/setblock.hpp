/*
 * setblock.hpp
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

#ifndef LIBMINECRAFT_CLASSIC_PROTOCOL_SERVER_PACKET_SETBLOCK_HPP
#define LIBMINECRAFT_CLASSIC_PROTOCOL_SERVER_PACKET_SETBLOCK_HPP

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
                    class SetBlock : public Packet
                    {
                    public:
                        MCTypes::Short x;
                        MCTypes::Short y;
                        MCTypes::Short z;
                        MCTypes::Byte type;

                        SetBlock();
                        virtual void read(std::istream &is);
                        virtual void write(std::ostream &os) const;
                        virtual void toReadable(std::ostream &os) const;
                    };
                }
            }
        }
    }
}

#endif // LIBMINECRAFT_CLASSIC_PROTOCOL_SERVER_PACKET_SETBLOCK_HPP
