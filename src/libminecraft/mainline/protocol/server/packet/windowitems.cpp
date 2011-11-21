/*
 * windowitems.cpp
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

#include "windowitems.hpp"

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
                    WindowItems::WindowItems()
                    {
                    }

                    void WindowItems::read(std::istream &stream)
                    {
                        Stream::getByte(stream, windowId);
                        Stream::getShort(stream, count);

                        // XXX: Add Slot Array
                    }

                    void WindowItems::write(std::ostream &stream) const
                    {
                        Stream::putByte(stream, windowId);
                        Stream::putShort(stream, count);

                        // XXX: Add Slot Array
                    }

                    void WindowItems::toReadable(std::ostream &os) const
                    {
                        os << "Window Id: " << (int) windowId << std::endl;
                        os << "Count: " << count << std::endl;

                        // XXX: Add Slot Array
                    }
                }
            }
        }
    }
}
