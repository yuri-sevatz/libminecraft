/*
 * playerteleport.cpp
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

#include "playerteleport.hpp"

#include "../../stream.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace protocol
        {
            namespace server
            {
                namespace packet
                {
                    PlayerTeleport::PlayerTeleport()
                    {
                    }

                    void PlayerTeleport::read(std::istream &stream)
                    {
                        Stream::getByte(stream, player_id);
                        Stream::getShort(stream, x);
                        Stream::getShort(stream, y);
                        Stream::getShort(stream, z);
                        Stream::getByte(stream, yaw);
                        Stream::getByte(stream, pitch);
                    }

                    void PlayerTeleport::write(std::ostream &stream) const
                    {
                        Stream::putByte(stream, player_id);
                        Stream::putShort(stream, x);
                        Stream::putShort(stream, y);
                        Stream::putShort(stream, z);
                        Stream::putByte(stream, yaw);
                        Stream::putByte(stream, pitch);
                    }

                    void PlayerTeleport::toReadable(std::ostream &os) const
                    {
                        os << "Player ID: " << (int) player_id << "\n";
                        os << "Delta X: " << x << "\n";
                        os << "Delta Y: " << y << "\n";
                        os << "Delta Z: " << z << "\n";
                        os << "Yaw: " << (int) yaw << "\n";
                        os << "Pitch: " << (int) pitch << "\n";
                    }
                }
            }
        }
    }
}

