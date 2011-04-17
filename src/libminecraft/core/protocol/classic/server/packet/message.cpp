/*
 * message.cpp
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

#include "message.hpp"

#include "../../stream.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace server
        {
            namespace packet
            {
                Message::Message()
                {
                }

                void Message::read(std::istream &stream)
                {
                    Stream::getByte(stream, player_id);
                    Stream::getString(stream, message);
                }

                void Message::write(std::ostream &stream) const
                {
                    Stream::putByte(stream, player_id);
                    Stream::putString(stream, message);
                }

                void Message::toReadable(std::ostream &os) const
                {
                    os << "Player ID: " << (int) player_id << "\n";
                    os << "Message: " << message << std::endl;
                }
            }
        }
    }
}

