/*
 * minecraftpacket.hpp
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

#ifndef LIBMINECRAFT_MINECRAFTPACKET_HPP
#define LIBMINECRAFT_MINECRAFTPACKET_HPP

#include <istream>
#include <ostream>

#include "../../exceptions/networkexception.hpp"
#include "../../exceptions/protocolexception.hpp"

namespace libminecraft
{
    class MinecraftPacket
    {
    public:
        // Write the packet to a stream.
        // Throws NetworkException if there is an issue.


        // Read the packet from a stream.
        // Network Exception, or ProtocolException can occur.
        // No data will be returned in the event of an exception,
        // and no leaked memory should occur.
        // Note: For derrived class to implement.
        // static MinecraftPacket * const Read(std::istream & stream);

        // Convert the packet to human readable output
        virtual void read(std::istream &is) = 0;
        virtual void write(std::ostream &os) const = 0;
        virtual void toReadable(std::ostream &os) const = 0;
    };
}

#endif // LIBMINECRAFT_MINECRAFTPACKET_HPP
