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

#ifndef LIBMINECRAFT_CLASSIC_PROTOCOL_STREAM_HPP
#define LIBMINECRAFT_CLASSIC_PROTOCOL_STREAM_HPP

#include "../../shared/protocol/stream.hpp"
#include "../mctypes.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace protocol
        {
            class Stream : public libminecraft::protocol::Stream
            {
            public:
                static void getString64(std::istream & stream, MCTypes::String64 & str);
                static void putString64(std::ostream & stream, const MCTypes::String64 & str);
            };
        }
    }
}

#endif // LIBMINECRAFT_CLASSIC_PROTOCOL_STREAM_HPP
