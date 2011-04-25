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

#ifndef LIBMINECRAFT_MAINLINE_STREAM_HPP
#define LIBMINECRAFT_MAINLINE_STREAM_HPP

#include "../stream.hpp"

#include "mctypes.hpp"

namespace libminecraft
{
    namespace mainline
    {
        class Stream : public libminecraft::Stream
        {
        public:
            static void getBool(std::istream & stream, MCTypes::Bool & tval);
            static void putBool(std::ostream & stream, const MCTypes::Bool & tval);

            static void getInt(std::istream & stream, MCTypes::Int & tval);
            static void putInt(std::ostream & stream, const MCTypes::Int & tval);

            static void getLong(std::istream & stream, MCTypes::Long & tval);
            static void putLong(std::ostream & stream, const MCTypes::Long & tval);

            static void getFloat(std::istream & stream, MCTypes::Float & tval);
            static void putFloat(std::ostream & stream, const MCTypes::Float & tval);

            static void getDouble(std::istream & stream, MCTypes::Double & tval);
            static void putDouble(std::ostream & stream, const MCTypes::Double & tval);

            static void getString(std::istream & stream, MCTypes::String & str);
            static void putString(std::ostream & stream, const MCTypes::String & str);

            static void getUCS2Char(std::istream & stream, MCTypes::UCS2Char & ch);
            static void putUCS2Char(std::ostream & stream, const MCTypes::UCS2Char & ch);

            static void getUCS2String(std::istream & stream, MCTypes::UCS2String & str);
            static void putUCS2String(std::ostream & stream, const MCTypes::UCS2String & str);
        };

        inline void Stream::getBool(std::istream &stream, MCTypes::Bool &tval)
        {
            io::bigendian::stream::getBool(stream, tval);
        }

        inline void Stream::putBool(std::ostream &stream, const MCTypes::Bool &tval)
        {
            io::bigendian::stream::putBool(stream, tval);
        }

        inline void Stream::getInt(std::istream &stream, MCTypes::Int &tval)
        {
            io::bigendian::stream::getInt(stream, tval);
        }

        inline void Stream::putInt(std::ostream &stream, const MCTypes::Int &tval)
        {
            io::bigendian::stream::putInt(stream, tval);
        }

        inline void Stream::getLong(std::istream &stream, MCTypes::Long &tval)
        {
            io::bigendian::stream::getLong(stream, tval);
        }

        inline void Stream::putLong(std::ostream &stream, const MCTypes::Long &tval)
        {
            io::bigendian::stream::putLong(stream, tval);
        }

        inline void Stream::getFloat(std::istream &stream, MCTypes::Float &tval)
        {
            io::bigendian::stream::getFloat(stream, tval);
        }

        inline void Stream::putFloat(std::ostream &stream, const MCTypes::Float &tval)
        {
            io::bigendian::stream::putFloat(stream, tval);
        }

        inline void Stream::getDouble(std::istream &stream, MCTypes::Double &tval)
        {
            io::bigendian::stream::getDouble(stream, tval);
        }

        inline void Stream::putDouble(std::ostream &stream, const MCTypes::Double &tval)
        {
            io::bigendian::stream::putDouble(stream, tval);
        }
    }
}

#endif // LIBMINECRAFT_MAINLINE_STREAM_HPP
