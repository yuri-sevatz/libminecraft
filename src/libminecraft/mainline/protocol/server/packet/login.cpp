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

#include "../../stream.hpp"

#include <iostream>

namespace libminecraft
{
    namespace mainline
    {
        namespace protocol
        {
            namespace server
            {
                namespace packet
                {
                    Login::Login()
                    {
                    }

                    void Login::read(std::istream &stream)
                    {
                        Stream::getInt(stream, player_id);
                        Stream::getUCS2String(stream, unknown_a);
                        Stream::getLong(stream, seed);
                        Stream::getByte(stream, dimension);
                    }

                    void Login::write(std::ostream &stream) const
                    {
                        Stream::putInt(stream, player_id);
                        Stream::putUCS2String(stream, unknown_a);
                        Stream::putLong(stream, seed);
                        Stream::putByte(stream, dimension);
                    }

                    void Login::toReadable(std::ostream &os) const
                    {
                        os << "Player ID: " << player_id << "\n";
                        // TODO : Remove Hardcoded Streams
                        std::wcout << "Unknown A: " << unknown_a << "\n";
                        os << "Seed: " << seed << "\n";
                        os << "Dimension: " << (int) dimension << std::endl;
                    }
                }
            }
        }
    }
}
