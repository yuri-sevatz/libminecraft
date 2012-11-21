/*
 * gamestate.cpp
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

#include "gamestate.hpp"

#include "../../stream.hpp"

namespace libminecraft {
namespace mainline {
namespace protocol {
namespace server {
namespace packet {
GameState::GameState() {
}

void GameState::read(std::istream & stream) {
    Stream::getByte(stream, reason);
    Stream::getByte(stream, mode);
}

void GameState::write(std::ostream & stream) const {
    Stream::putByte(stream, reason);
    Stream::putByte(stream, mode);
}

void GameState::toReadable(std::ostream & os) const {
    os << "Reason: " << (int) reason << std::endl;
    os << "Mode: " << (int) mode << std::endl;
}
}
}
}
}
}
