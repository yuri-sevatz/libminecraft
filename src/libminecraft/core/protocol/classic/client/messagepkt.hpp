/*
 * messagepkt.hpp
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

#ifndef LIBMINECRAFT_CLASSIC_CLIENT_MESSAGEPKT_HPP
#define LIBMINECRAFT_CLASSIC_CLIENT_MESSAGEPKT_HPP

#include "packet.hpp"

#include <string>

namespace libminecraft
{
    namespace classic
    {
        namespace client
        {
            class MessagePkt : public Packet
            {
            public:
                static const MCTypes::Byte id = Packet::MESSAGE;

                MCTypes::Byte unused;
                std::string message;

            public:
                MessagePkt();
                virtual void read(std::istream &stream);
                virtual void write(std::ostream &os) const;
                virtual void toReadable(std::ostream &os) const;
            };
        }
    }
}

#endif // LIBMINECRAFT_CLIENTMESSAGEPKT_HPP
