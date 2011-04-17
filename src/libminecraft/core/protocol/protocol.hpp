/*
 * protocol.hpp
 * This file is part of LibMinecraft.
 *
 * Created by Yuri Sevatz on 04/2011.
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

#ifndef LIBMINECRAFT_PROTOCOL_HPP
#define LIBMINECRAFT_PROTOCOL_HPP

#include "mctypes.hpp"
#include "stream.hpp"

// Used in protocol headers (implementations).
#include <istream>
#include <ostream>
#include <map>
#include <typeinfo>
#include <assert.h>

namespace libminecraft
{
    // Maintains a generic read/write protocol.
    // Uses std::map's red-black trees for a type to-id-lookup system.
    // The reacting code of each type is left to the implementation, so that packets
    // can optionally be placed on the stack for less memory fragmentation.
    //
    // Configuration: Enable assertions to create read-time PacketID checks on reaction code.
    //
    template<class TProtocol, class TPacket, typename TPacketID>
    class Protocol
    {
    public:
        // The static map of class to packet id's for writing
        // TPacketID - a valid enum/type containing the type of the desired packet.
        static const std::map<const std::type_info *, TPacketID> msgmap;

        // Write a packet over the protocol.
        static void write(std::ostream & stream, const TPacket & packet);

        // Read a packet over the protocol.
        // Ideally, you should be using a packet that was
        static void read(std::istream & stream, TPacket & packet);

        // Check the next type of packet on the wire
        static MCTypes::Byte next(std::istream & stream);
    };

    // Since the RTTI type of the packet is likely known in the calling context,
    // then there's a good chance that the type of the packet will be resolved at compile time.
    template<class TProtocol, class TPacket, typename TPacketID>
    inline void Protocol<TProtocol, TPacket, TPacketID>::read(std::istream & stream, TPacket & packet)
    {
        // Skip the buffered id.
        MCTypes::Byte next;
        Stream::getByte(stream, next);
        // Do a quick type check before write, for silly programmers (me? xD)
        assert(TProtocol::msgmap.at(&typeid(packet)) == next);
        packet.read(stream);
    }

    // Since the RTTI type of the packet is likely known in the calling context,
    // then there's a good chance that the type of the packet can be resolved at compile time.
    template<class TProtocol, class TPacket, typename TPacketID>
    inline void Protocol<TProtocol, TPacket, TPacketID>::write(std::ostream & stream, const TPacket & packet)
    {
        Stream::putByte(stream, TProtocol::msgmap.at(&typeid(packet)));
        packet.write(stream);
        stream.flush();
    }

    template<class TProtocol, class TPacket, typename TPacketID>
    inline MCTypes::Byte Protocol<TProtocol, TPacket, TPacketID>::next(std::istream & stream)
    {
        return (MCTypes::Byte) stream.peek();
    }
}

#endif // LIBMINECRAFT_PROTOCOL_HPP
