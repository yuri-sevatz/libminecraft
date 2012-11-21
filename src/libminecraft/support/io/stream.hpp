/*
 * stream.hpp
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

#ifndef SUPPORT_IO_STREAM_HPP
#define SUPPORT_IO_STREAM_HPP

#include <istream>
#include <ostream>

#include <stdint.h>

namespace io {
class stream {
public:
    static void getBool(std::istream & stream, bool & abool);
    static void putBool(std::ostream & stream, const bool & abool);

    static void getByte(std::istream & stream, int8_t & sbyte);
    static void putByte(std::ostream & stream, const int8_t & sbyte);

    static void getByte(std::istream & stream, uint8_t & ubyte);
    static void putByte(std::ostream & stream, const uint8_t & ubyte);
};

inline void stream::getBool(std::istream & stream, bool & abool) {
    abool = (bool) stream.get();
}

inline void stream::putBool(std::ostream & stream, const bool & abool) {
    stream.put(abool ? (char) 0x01 : (char) 0x00);
}

inline void stream::getByte(std::istream & stream, int8_t & sbyte) {
    getByte(stream, (uint8_t &) sbyte);
}

inline void stream::putByte(std::ostream & stream, const int8_t & sbyte) {
    putByte(stream, (const uint8_t &) sbyte);
}

inline void stream::getByte(std::istream & stream, uint8_t & ubyte) {
    stream.get((char &)ubyte);
}

inline void stream::putByte(std::ostream & stream, const uint8_t & ubyte) {
    stream.put((const char)ubyte);
}
}

#endif // SUPPORT_IO_STREAM_HPP
