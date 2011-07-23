/*
 * setblock.cpp
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

#include "setblock.hpp"

#include "../../stream.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace protocol
        {
            namespace client
            {
                namespace packet
                {
                    SetBlock::SetBlock()
                    {

                    }

                    void SetBlock::read(std::istream &stream)
                    {
                        Stream::getShort(stream, x);
                        Stream::getShort(stream, y);
                        Stream::getShort(stream, z);
                        Stream::getByte(stream, mode);
                        Stream::getByte(stream, type);
                    }

                    void SetBlock::write(std::ostream &stream) const
                    {
                        Stream::putShort(stream, x);
                        Stream::putShort(stream, y);
                        Stream::putShort(stream, z);
                        Stream::putByte(stream, mode);
                        Stream::putByte(stream, type);
                    }

                    void SetBlock::toReadable(std::ostream &os) const
                    {
                        os << "X: " << x << "\n";
                        os << "Y: " << y << "\n";
                        os << "Z: " << z << "\n";
                        os << "Mode: " << (int) mode << "\n";
                        os << "Type: " << (int) type << std::endl;
                    }
                }
            }
        }
    }
}
