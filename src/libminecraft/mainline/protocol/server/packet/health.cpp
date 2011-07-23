/*
 * health.cpp
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

#include "health.hpp"

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
                    Health::Health()
                    {
                    }

                    void Health::read(std::istream &stream)
                    {
                        Stream::getShort(stream, hp);
                    }

                    void Health::write(std::ostream &stream) const
                    {
                        Stream::putShort(stream, hp);
                    }

                    void Health::toReadable(std::ostream &os) const
                    {
                        os << "Hp: " << os << std::endl;
                    }
                }
            }
        }
    }
}
