/*
 * baseprotocol.hpp
 * This file is part of LibMinecraft.
 *
 * Created by Yuri Sevatz on 11/2010.
 * Copyright (c) 2010 Yuri Sevatz. All rights reserved
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

#ifndef BASEPROTOCOL_HPP
#define BASEPROTOCOL_HPP

#include <iostream>

namespace libminecraft
{
    class BaseProtocol
    {
    protected:
        // The stream object tied to this protocol.
        // Don't deallocate this during use.
        std::iostream &stream;

    public:
        // Constants...
        static const char proto_version = 0x07;

    public:
        BaseProtocol(std::iostream & stream);
    };
}

#endif // BASEPROTOCOL_HPP
