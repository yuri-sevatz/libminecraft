/*
 * ident.cpp
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

#include "ident.hpp"

#include "../../stream.hpp"

#include <iostream>

namespace libminecraft {
namespace mainline {
namespace protocol {
namespace client {
namespace packet {
Ident::Ident() {
}

void Ident::read(std::istream & stream) {
    Stream::getUCS2String(stream, username);
}

void Ident::write(std::ostream & stream) const {
    Stream::putUCS2String(stream, username);
}

void Ident::toReadable(std::ostream & os) const {
    // TODO : Removed Hardcoded Streams
    std::wcout << "Username: " << username << std::endl;
}
}
}
}
}
}
