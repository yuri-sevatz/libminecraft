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

#ifndef LIBMINECRAFT_MINECRAFTSTREAM_HPP
#define LIBMINECRAFT_MINECRAFTSTREAM_HPP

#include <istream>
#include <ostream>

#include "minecrafttypes.hpp"

namespace libminecraft
{

    class MinecraftStream
    {
    public:
        static const size_t M_STRING_LEN;

        static void getByte(std::istream & stream, MinecraftTypes::Byte & byte);
        static void putByte(std::ostream & stream, const MinecraftTypes::Byte & byte);
        static void getSignedByte(std::istream & stream, MinecraftTypes::SByte & sbyte);
        static void putSignedByte(std::ostream & stream, const MinecraftTypes::SByte & sbyte);
        static void getSignedShort(std::istream & stream, MinecraftTypes::SShort & sshort);
        static void putSignedShort(std::ostream & stream, const MinecraftTypes::SShort & sshort);
        static void getString(std::istream & stream, std::string & str);
        static void putString(std::ostream & stream, const std::string & str);
    };

    inline void MinecraftStream::getByte(std::istream &stream, MinecraftTypes::Byte &byte)
    {
        stream.get(*((char *)&byte));
    }

    inline void MinecraftStream::putByte(std::ostream &stream, const MinecraftTypes::Byte &byte)
    {
        stream.put(*((const char *)&byte));
    }

    inline void MinecraftStream::getSignedByte(std::istream &stream, MinecraftTypes::SByte &sbyte)
    {
        stream.get(*((char *)&sbyte));
    }

    inline void MinecraftStream::putSignedByte(std::ostream &stream, const MinecraftTypes::SByte &sbyte)
    {
        stream.put(*((const char *)&sbyte));
    }

}

#endif // LIBMINECRAFT_MINECRAFTSTREAM_HPP
