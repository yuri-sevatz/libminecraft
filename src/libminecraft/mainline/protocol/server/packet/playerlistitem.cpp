/*
 * playerlistitem.cpp
 * This file is part of LibMinecraft.
 *
 * Created by Yuri Sevatz on 11/2011.
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

#include "playerlistitem.hpp"

#include "../../stream.hpp"

#include <iostream>

namespace libminecraft {
namespace mainline {
namespace protocol {
namespace server {
namespace packet {
PlayerListItem::PlayerListItem() {
}

void PlayerListItem::read(std::istream & stream) {
    Stream::getUCS2String(stream, name);
    Stream::getBool(stream, online);
    Stream::getShort(stream, ping);
}

void PlayerListItem::write(std::ostream & stream) const {
    Stream::putUCS2String(stream, name);
    Stream::putBool(stream, online);
    Stream::putShort(stream, ping);
}

void PlayerListItem::toReadable(std::ostream & os) const {
    // TODO : Remove Hardcoded Streams
    std::wcout << "Name: " << name << std::endl;
    os << "Online: " << online << std::endl;
    os << "Ping: " << ping << std::endl;
}
}
}
}
}
}
