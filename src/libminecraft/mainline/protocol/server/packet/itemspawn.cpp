/*
 * itemspawn.cpp
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

#include "itemspawn.hpp"

#include "../../stream.hpp"

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
                    ItemSpawn::ItemSpawn()
                    {
                    }

                    void ItemSpawn::read(std::istream &stream)
                    {
                        Stream::getInt(stream, entityId);
                        Stream::getShort(stream, itemId);
                        Stream::getByte(stream, count);
                        Stream::getShort(stream, data);
                        Stream::getInt(stream, x);
                        Stream::getInt(stream, y);
                        Stream::getInt(stream, z);
                        Stream::getByte(stream, rotation);
                        Stream::getByte(stream, pitch);
                        Stream::getByte(stream, roll);
                    }

                    void ItemSpawn::write(std::ostream &stream) const
                    {
                        Stream::putInt(stream, entityId);
                        Stream::putShort(stream, itemId);
                        Stream::putByte(stream, count);
                        Stream::putShort(stream, data);
                        Stream::putInt(stream, x);
                        Stream::putInt(stream, y);
                        Stream::putInt(stream, z);
                        Stream::putByte(stream, rotation);
                        Stream::putByte(stream, pitch);
                        Stream::putByte(stream, roll);
                    }

                    void ItemSpawn::toReadable(std::ostream &os) const
                    {
                        os << "Entity Id: " << entityId << std::endl;
                        os << "Item Id: " << itemId << std::endl;
                        os << "Count: " << (int) count << std::endl;
                        os << "Data: " << data << std::endl;
                        os << "X: " << x << std::endl;
                        os << "Y: " << y << std::endl;
                        os << "Z: " << z << std::endl;
                        os << "Rotation: " << (int) rotation << std::endl;
                        os << "Pitch: " << (int) pitch << std::endl;
                        os << "Roll: " << (int) roll << std::endl;
                    }
                }
            }
        }
    }
}
