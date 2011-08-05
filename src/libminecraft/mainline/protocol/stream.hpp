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

#ifndef LIBMINECRAFT_MAINLINE_PROTOCOL_STREAM_HPP
#define LIBMINECRAFT_MAINLINE_PROTOCOL_STREAM_HPP

#include "../../shared/protocol/stream.hpp"

#include "../../shared/exception/protocol.hpp"

#include "../mctypes.hpp"

namespace libminecraft
{
    namespace mainline
    {
        namespace protocol
        {
            class Stream : public libminecraft::protocol::Stream
            {
            public:
                static void getBool(std::istream & stream, MCTypes::Bool & tval);
                static MCTypes::Bool getBool(std::istream &stream);
                static void putBool(std::ostream & stream, const MCTypes::Bool & tval);

                static void getInt(std::istream & stream, MCTypes::Int & tval);
                static MCTypes::Int getInt(std::istream &stream);
                static void putInt(std::ostream & stream, const MCTypes::Int & tval);

                static void getLong(std::istream & stream, MCTypes::Long & tval);
                static MCTypes::Long getLong(std::istream &stream);
                static void putLong(std::ostream & stream, const MCTypes::Long & tval);

                static void getFloat(std::istream & stream, MCTypes::Float & tval);
                static MCTypes::Float getFloat(std::istream &stream);
                static void putFloat(std::ostream & stream, const MCTypes::Float & tval);

                static void getDouble(std::istream & stream, MCTypes::Double & tval);
                static MCTypes::Double getDouble(std::istream &stream);
                static void putDouble(std::ostream & stream, const MCTypes::Double & tval);

                /*
                static void getString(std::istream & stream, MCTypes::String & str);
                static void putString(std::ostream & stream, const MCTypes::String & str);
                */

                static void getUCS2Char(std::istream & stream, MCTypes::UCS2Char & ch);
                static MCTypes::UCS2Char getUCS2Char(std::istream & stream);
                static void putUCS2Char(std::ostream & stream, const MCTypes::UCS2Char & ch);

                static void getUCS2String(std::istream & stream, MCTypes::UCS2String & str);
                static MCTypes::UCS2String getUCS2String(std::istream &stream);
                static void putUCS2String(std::ostream & stream, const MCTypes::UCS2String & str);
            };

            inline void Stream::getBool(std::istream &stream, MCTypes::Bool &tval)
            {
                io::bigendian::stream::getBool(stream, tval);
            }

            inline MCTypes::Bool Stream::getBool(std::istream &stream)
            {
                MCTypes::Bool ret;
                getBool(stream, ret);
                return ret;
            }

            inline void Stream::putBool(std::ostream &stream, const MCTypes::Bool &tval)
            {
                io::bigendian::stream::putBool(stream, tval);
            }

            inline void Stream::getInt(std::istream &stream, MCTypes::Int &tval)
            {
                io::bigendian::stream::getInt(stream, tval);
            }

            inline MCTypes::Int Stream::getInt(std::istream &stream)
            {
                MCTypes::Int ret;
                getInt(stream, ret);
                return ret;
            }

            inline void Stream::putInt(std::ostream &stream, const MCTypes::Int &tval)
            {
                io::bigendian::stream::putInt(stream, tval);
            }

            inline void Stream::getLong(std::istream &stream, MCTypes::Long &tval)
            {
                io::bigendian::stream::getLong(stream, tval);
            }

            inline MCTypes::Long Stream::getLong(std::istream &stream)
            {
                MCTypes::Long ret;
                getLong(stream, ret);
                return ret;
            }

            inline void Stream::putLong(std::ostream &stream, const MCTypes::Long &tval)
            {
                io::bigendian::stream::putLong(stream, tval);
            }

            inline void Stream::getFloat(std::istream &stream, MCTypes::Float &tval)
            {
                io::bigendian::stream::getFloat(stream, tval);
            }

            inline MCTypes::Float Stream::getFloat(std::istream &stream)
            {
                MCTypes::Float ret;
                getFloat(stream, ret);
                return ret;
            }

            inline void Stream::putFloat(std::ostream &stream, const MCTypes::Float &tval)
            {
                io::bigendian::stream::putFloat(stream, tval);
            }

            inline void Stream::getDouble(std::istream &stream, MCTypes::Double &tval)
            {
                io::bigendian::stream::getDouble(stream, tval);
            }

            inline MCTypes::Double Stream::getDouble(std::istream &stream)
            {
                MCTypes::Double ret;
                getDouble(stream, ret);
                return ret;
            }

            inline void Stream::putDouble(std::ostream &stream, const MCTypes::Double &tval)
            {
                io::bigendian::stream::putDouble(stream, tval);
            }

            inline MCTypes::UCS2Char Stream::getUCS2Char(std::istream &stream)
            {
                MCTypes::UCS2Char ret;
                getUCS2Char(stream, ret);
                return ret;
            }

            inline MCTypes::UCS2String Stream::getUCS2String(std::istream &stream)
            {
                MCTypes::UCS2String ret;
                getUCS2String(stream, ret);
                return ret;
            }
        }
    }
}

#endif // LIBMINECRAFT_MAINLINE_PROTOCOL_STREAM_HPP
