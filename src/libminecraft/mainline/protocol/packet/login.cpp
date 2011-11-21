/*
 * login.cpp
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

#include "login.hpp"

#include "../stream.hpp"

#include <iostream>

namespace libminecraft
{
    namespace mainline
    {
        namespace protocol
        {
            namespace packet
            {
                void Login::read(std::istream &stream)
                {
                    Stream::getInt(stream, id);
                    Stream::getUCS2String(stream, username);
                    Stream::getLong(stream, seed);
                    Stream::getInt(stream, mode);
                    Stream::getByte(stream, dimension);
                    Stream::getByte(stream, difficulty);
                    Stream::getByte(stream, maxPlayers);
                    Stream::getByte(stream, worldHeight);
                }

                void Login::write(std::ostream &stream) const
                {
                    Stream::putInt(stream, id);
                    Stream::putUCS2String(stream, username);
                    Stream::putLong(stream, seed);
                    Stream::putInt(stream, mode);
                    Stream::putByte(stream, dimension);
                    Stream::putByte(stream, difficulty);
                    Stream::putByte(stream, maxPlayers);
                    Stream::putByte(stream, worldHeight);
                }

                void Login::toReadable(std::ostream &os) const
                {
                    os << "Version/Player ID: " << id << "\n";
                    // TODO : Remove Hardcoded Streams
                    std::wcout << "Username: " << username << "\n";
                    os << "Seed: " << seed << "\n";
                    os << "Mode: " << mode << "\n";
                    os << "Dimension: " << (int) dimension << std::endl;
                    os << "Difficulty: " << (int) difficulty << std::endl;
                    os << "Max Players: " << (int) maxPlayers << std::endl;
                    os << "World Height: " << (int) worldHeight << std::endl;
                }
            }
        }
    }
}
