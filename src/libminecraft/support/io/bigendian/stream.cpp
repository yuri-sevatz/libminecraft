/*
 * stream.cpp
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

#include "stream.hpp"

#include <boost/detail/endian.hpp>

namespace io
{
    namespace bigendian
    {
        void stream::getShort(std::istream &stream, uint16_t &ushort)
        {
        #ifdef BOOST_LITTLE_ENDIAN
            stream.get(*(((char *) &ushort) + 1));
            stream.get(*((char *) &ushort));
        #else
            stream.read((char *) &ushort, sizeof(ushort));
        #endif
        }

        void stream::putShort(std::ostream &stream, const uint16_t &ushort)
        {
        #ifdef BOOST_LITTLE_ENDIAN
            stream.put(*(((const char *) &ushort) + 1));
            stream.put(*((const char *) &ushort));
        #else
            stream.write((const char *) &ushort, sizeof(ushort));
        #endif
        }

        void stream::getInt(std::istream &stream, uint32_t &uint)
        {
        #ifdef BOOST_LITTLE_ENDIAN
            stream.get(*(((char *) &uint) + 3));
            stream.get(*(((char *) &uint) + 2));
            stream.get(*(((char *) &uint) + 1));
            stream.get(*((char *) &uint));
        #else
            stream.read((char *) &uint, sizeof(uint));
        #endif
        }

        void stream::putInt(std::ostream &stream, const uint32_t &uint)
        {
        #ifdef BOOST_LITTLE_ENDIAN
            stream.put(*(((const char *) &uint) + 3));
            stream.put(*(((const char *) &uint) + 2));
            stream.put(*(((const char *) &uint) + 1));
            stream.put(*((const char *) &uint));
        #else
            stream.write((const char *) &uint, sizeof(uint));
        #endif
        }

        void stream::getLong(std::istream &stream, uint64_t &ulong)
        {
        #ifdef BOOST_LITTLE_ENDIAN
            stream.get(*(((char *) &ulong) + 7));
            stream.get(*(((char *) &ulong) + 6));
            stream.get(*(((char *) &ulong) + 5));
            stream.get(*(((char *) &ulong) + 4));
            stream.get(*(((char *) &ulong) + 3));
            stream.get(*(((char *) &ulong) + 2));
            stream.get(*(((char *) &ulong) + 1));
            stream.get(*((char *) &ulong));
        #else
            stream.read((char *) &ulong, sizeof(ulong));
        #endif
        }

        void stream::putLong(std::ostream &stream, const uint64_t &ulong)
        {
        #ifdef BOOST_LITTLE_ENDIAN
            stream.put(*(((char *) &ulong) + 7));
            stream.put(*(((char *) &ulong) + 6));
            stream.put(*(((char *) &ulong) + 5));
            stream.put(*(((char *) &ulong) + 4));
            stream.put(*(((char *) &ulong) + 3));
            stream.put(*(((char *) &ulong) + 2));
            stream.put(*(((char *) &ulong) + 1));
            stream.put(*((char *) &ulong));
        #else
            stream.write((char *) &ulong, sizeof(ulong));
        #endif
        }

        template<typename T>
        void stream::generic<T>::getT(std::istream & stream, T & t_val)
        {
        #ifdef BOOST_LITTLE_ENDIAN
            for (unsigned i = sizeof(t_val) - 1; i != 0; i--)
                stream.get(*(((char *) &t_val) + i));;
            stream.get(*((char *) &t_val));
        #else
            stream.read((char *) &t_val, sizeof(t_val));
        #endif
        }

        template<typename T>
        void stream::generic<T>::putT(std::ostream & stream, const T & t_val)
        {
        #ifdef BOOST_LITTLE_ENDIAN
            for (unsigned i = sizeof(t_val) - 1; i != 0; i--)
                stream.put(*(((char *) &t_val) + i));
            stream.put(*((char *) &t_val));
        #else
            stream.write((char *) &t_val, sizeof(t_val));
        #endif
        }

        // Explicit instantiation of our private generically supported types.
        template class stream::generic<float>;
        template class stream::generic<double>;
        template class stream::generic<wchar_t>;
    }
}
