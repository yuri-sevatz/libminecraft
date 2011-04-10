/*
 * minecraftstream.hpp
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

#ifndef LIBMINECRAFT_STREAM_HPP
#define LIBMINECRAFT_STREAM_HPP

#include <istream>
#include <ostream>

#include "networktypes.hpp"

namespace libminecraft
{
    class Stream
    {
    public:
        static const size_t M_STRING_LEN;

        static void getByte(std::istream & stream, NetworkTypes::Byte & byte);
        static void putByte(std::ostream & stream, const NetworkTypes::Byte & byte);
        static void getSignedByte(std::istream & stream, NetworkTypes::SByte & sbyte);
        static void putSignedByte(std::ostream & stream, const NetworkTypes::SByte & sbyte);
        static void getSignedShort(std::istream & stream, NetworkTypes::SShort & sshort);
        static void putSignedShort(std::ostream & stream, const NetworkTypes::SShort & sshort);
        static void getString(std::istream & stream, std::string & str);
        static void putString(std::ostream & stream, const std::string & str);
    };

    inline void Stream::getByte(std::istream &stream, NetworkTypes::Byte &byte)
    {
        stream.get(*((char *)&byte));
    }

    inline void Stream::putByte(std::ostream &stream, const NetworkTypes::Byte &byte)
    {
        stream.put(*((const char *)&byte));
    }

    inline void Stream::getSignedByte(std::istream &stream, NetworkTypes::SByte &sbyte)
    {
        stream.get(*((char *)&sbyte));
    }

    inline void Stream::putSignedByte(std::ostream &stream, const NetworkTypes::SByte &sbyte)
    {
        stream.put(*((const char *)&sbyte));
    }
}

#endif // LIBMINECRAFT_STREAM_HPP
