/*
 * stream.hpp
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

#include "../../../support/io/bigendian/stream.hpp"
#include "mctypes.hpp"

namespace libminecraft
{
    class Stream
    {
    public:
        static void getByte(std::istream & stream, MCTypes::Byte & sbyte);
        static void putByte(std::ostream & stream, const MCTypes::Byte & sbyte);
        static void getShort(std::istream & stream, MCTypes::Short & sshort);
        static void putShort(std::ostream & stream, const MCTypes::Short & sshort);
    };

    inline void Stream::getByte(std::istream &stream, MCTypes::Byte &sbyte)
    {
        io::bigendian::stream::getByte(stream, sbyte);
    }

    inline void Stream::putByte(std::ostream &stream, const MCTypes::Byte &sbyte)
    {
        io::bigendian::stream::putByte(stream, sbyte);
    }

    inline void Stream::getShort(std::istream &stream, MCTypes::Short &sshort)
    {
        io::bigendian::stream::getShort(stream, sshort);
    }

    inline void Stream::putShort(std::ostream &stream, const MCTypes::Short &sshort)
    {
        io::bigendian::stream::putShort(stream, sshort);
    }
}

#endif // LIBMINECRAFT_STREAM_HPP
