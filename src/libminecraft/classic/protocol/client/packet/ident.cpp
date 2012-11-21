/*
 * ident.cpp
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

#include "ident.hpp"

#include "../../stream.hpp"
#include "../protocol.hpp"

namespace libminecraft {
namespace classic {
namespace protocol {
namespace client {
namespace packet {
Ident::Ident() {

}

void Ident::read(std::istream & stream) {
    Stream::getByte(stream, version);
    Stream::getString64(stream, username);
    Stream::getString64(stream, key);
    Stream::getByte(stream, unused);
}

void Ident::write(std::ostream & stream) const {
    Stream::putByte(stream, version);
    Stream::putString64(stream, username);
    Stream::putString64(stream, key);
    Stream::putByte(stream, unused);
}

void Ident::toReadable(std::ostream & os) const {
    os << "Version: " << (int) version << "\n";
    os << "Username: " << username << "\n";
    os << "Key: " << key << "\n";
    os << "Unused: " << (int) unused << std::endl;
}

MCTypes::Byte Ident::cmpVersion() const {
    if (version > Protocol::version)
        return 1;
    else if (version < Protocol::version)
        return -1;
    else
        return 0;
}
}
}
}
}
}
