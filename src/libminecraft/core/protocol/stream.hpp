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

#include "mctypes.hpp"

namespace libminecraft
{
    class Stream
    {
    public:
        static const size_t M_STRING_LEN;

        static void getSignedByte(std::istream & stream, MCTypes::Byte & sbyte);
        static void putSignedByte(std::ostream & stream, const MCTypes::Byte & sbyte);
        static void getSignedShort(std::istream & stream, MCTypes::Short & sshort);
        static void putSignedShort(std::ostream & stream, const MCTypes::Short & sshort);
        static void getString(std::istream & stream, std::string & str);
        static void putString(std::ostream & stream, const std::string & str);
    };

    inline void Stream::getSignedByte(std::istream &stream, MCTypes::Byte &sbyte)
    {
        stream.get(*((char *)&sbyte));
    }

    inline void Stream::putSignedByte(std::ostream &stream, const MCTypes::Byte &sbyte)
    {
        stream.put(*((const char *)&sbyte));
    }
}

#endif // LIBMINECRAFT_STREAM_HPP
