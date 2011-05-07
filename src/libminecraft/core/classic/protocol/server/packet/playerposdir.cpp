/*
 * playerposdir.cpp
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

#include "playerposdir.hpp"

#include "../../stream.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace server
        {
            namespace packet
            {
                PlayerPosDir::PlayerPosDir()
                {
                }

                void PlayerPosDir::read(std::istream &stream)
                {
                    Stream::getByte(stream, player_id);
                    Stream::getByte(stream, delta_x);
                    Stream::getByte(stream, delta_y);
                    Stream::getByte(stream, delta_z);
                    Stream::getByte(stream, yaw);
                    Stream::getByte(stream, pitch);
                }

                void PlayerPosDir::write(std::ostream &stream) const
                {
                    Stream::putByte(stream, player_id);
                    Stream::putByte(stream, delta_x);
                    Stream::putByte(stream, delta_y);
                    Stream::putByte(stream, delta_z);
                    Stream::putByte(stream, yaw);
                    Stream::putByte(stream, pitch);
                }

                void PlayerPosDir::toReadable(std::ostream &os) const
                {
                    os << "Player ID: " << (int) player_id << "\n";
                    os << "Delta X: " << (int) delta_x << "\n";
                    os << "Delta Y: " << (int) delta_y << "\n";
                    os << "Delta Z: " << (int) delta_z << "\n";
                    os << "Yaw: " << (int) yaw << "\n";
                    os << "Pitch: " << (int) pitch << std::endl;
                }
            }
        }
    }
}

