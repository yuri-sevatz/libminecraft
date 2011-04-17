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

#ifndef SUPPORT_IO_BIGENDIAN_STREAM_HPP
#define SUPPORT_IO_BIGENDIAN_STREAM_HPP

#include "../stream.hpp"

// Big Endian stream functions for dealing with c++ equivalents of the java types.

namespace io
{
    namespace bigendian
    {
        class stream : public io::stream
        {
        public:
            static void getShort(std::istream & stream, int16_t & sshort);
            static void putShort(std::ostream & stream, const int16_t & sshort);

            static void getShort(std::istream & stream, uint16_t & ushort);
            static void putShort(std::ostream & stream, const uint16_t & ushort);

            static void getInt(std::istream & stream, int32_t & sint);
            static void putInt(std::ostream & stream, const int32_t & sint);

            static void getInt(std::istream & stream, uint32_t & uint);
            static void putInt(std::ostream & stream, const uint32_t & uint);

            static void getLong(std::istream & stream, int64_t & slong);
            static void putLong(std::ostream & stream, const int64_t & slong);

            static void getLong(std::istream & stream, uint64_t & ulong);
            static void putLong(std::ostream & stream, const uint64_t & ulong);

            static void getFloat(std::istream & stream, float & sfloat);
            static void putFloat(std::ostream & stream, const float & sfloat);

            static void getDouble(std::istream & stream, double & sdouble);
            static void putDouble(std::ostream & stream, const double & sdouble);

        private:
            template<typename T>
            class generic
            {
            public:
                static void getT(std::istream & stream, T & t_val);
                static void putT(std::ostream & stream, const T & t_val);
            };
        };

        inline void stream::getShort(std::istream &stream, int16_t & sshort)
        {
            stream::getShort(stream, (uint16_t &) sshort);
        }

        inline void stream::putShort(std::ostream & stream, const int16_t & sshort)
        {
            stream::putShort(stream, (const uint16_t &) sshort);
        }

        inline void stream::getInt(std::istream & stream, int32_t & sint)
        {
            stream::getInt(stream, (uint32_t &) sint);
        }

        inline void stream::putInt(std::ostream & stream, const int32_t & sint)
        {
            stream::putInt(stream, (const uint32_t &) sint);
        }

        inline void stream::getLong(std::istream & stream, int64_t & slong)
        {
            stream::getLong(stream, (uint64_t &) slong);
        }

        inline void stream::putLong(std::ostream & stream, const int64_t & slong)
        {
            stream::putLong(stream, (const uint64_t &) slong);
        }

        /*
         * Because float and double are of undefined sizes, we use a generic template.
         */
        inline void stream::getFloat(std::istream &stream, float &sfloat)
        {
            stream::generic<float>::getT(stream, sfloat);
        }

        inline void stream::putFloat(std::ostream &stream, const float &sfloat)
        {
            stream::generic<float>::putT(stream, sfloat);
        }

        inline void stream::getDouble(std::istream &stream, double &sdouble)
        {
            stream::generic<double>::getT(stream, sdouble);
        }

        inline void stream::putDouble(std::ostream &stream, const double &sdouble)
        {
            stream::generic<double>::putT(stream, sdouble);
        }
    }
}

#endif // SUPPORT_IO_BIGENDIAN_STREAM_HPP
