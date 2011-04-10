/*
 * minecraftstream.cpp
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

#include "stream.hpp"

#include <string>

#include <boost/detail/endian.hpp>

namespace libminecraft
{
    const size_t Stream::M_STRING_LEN = 64;

    // static
    void Stream::putString(std::ostream & stream, const std::string & str)
    {
        // Write Max M_STRING_LEN characters from the string
        stream.write(str.c_str(), std::min(str.length(), (size_t) M_STRING_LEN));

        // If the string is less than 64 characters long...
        for (unsigned  i = str.length(); i < M_STRING_LEN; i++)
        {
            // Pad with spaces
            stream.put(0x20);
        }
    }

    // static
    void Stream::getString(std::istream & stream, std::string & str)
    {
        // Tmp space.
        str.resize(M_STRING_LEN);
        stream.read(&*str.begin(), M_STRING_LEN);

        // Position of the end of the string
        std::string::reverse_iterator str_end;

        // Find the iterator position of the first non-space character from the right.
        for (str_end = str.rbegin(); str_end != str.rend(); str_end++)
        {
            // Break on the first space.
            if (*str_end != ' ')
                break;
        }

        // str_end points to the last character - convert to forward_iterator.
        // --> it's automatically incremented to one past this position.

        str.erase(str_end.base(), str.end());
    }

    // static
    void Stream::getSignedShort(std::istream &stream, NetworkTypes::SShort &sshort)
    {
#ifdef BOOST_LITTLE_ENDIAN
        // Shorts received in network order.
        stream.get(*(((char *) &sshort) + 1));
        stream.get(*((char *) &sshort));
#else
        stream.read((char *) &sshort, 2);
#endif
    }

    void Stream::putSignedShort(std::ostream &stream, const NetworkTypes::SShort &sshort)
    {
#ifdef BOOST_LITTLE_ENDIAN
        // Shorts sent in network order.
        stream.put(*(((char *) &sshort) + 1));
        stream.put(*((char *) &sshort));
#else
        stream.write((const char *) &sshort, 2);
#endif

    }
}
