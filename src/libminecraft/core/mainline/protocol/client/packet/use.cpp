/*
 * use.cpp
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

#include "use.hpp"

#include "../../stream.hpp"

namespace libminecraft
{
    namespace mainline
    {
        namespace client
        {
            namespace packet
            {
                Use::Use()
                {

                }

                void Use::read(std::istream &stream)
                {
                    Stream::getInt(stream, user_entity_id);
                    Stream::getInt(stream, target_entity_id);
                    Stream::getBool(stream, click);
                }

                void Use::write(std::ostream &stream) const
                {
                    Stream::putInt(stream, user_entity_id);
                    Stream::putInt(stream, target_entity_id);
                    Stream::putBool(stream, click);
                }

                void Use::toReadable(std::ostream &os) const
                {
                    os << "User Id: " << user_entity_id << "\n";
                    os << "Target Id " << target_entity_id << "\n";
                    os << "Left Click?: " << click << std::endl;
                }
            }
        }
    }
}
