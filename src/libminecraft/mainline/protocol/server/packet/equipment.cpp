/*
 * equipment.cpp
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

#include "equipment.hpp"

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
                    Equipment::Equipment()
                    {
                    }

                    void Equipment::read(std::istream &stream)
                    {
                        Stream::getInt(stream, entity_id);
                        Stream::getShort(stream, slot);
                        Stream::getShort(stream, item_id);
                        Stream::getShort(stream, health);
                    }

                    void Equipment::write(std::ostream &stream) const
                    {
                        Stream::putInt(stream, entity_id);
                        Stream::putShort(stream, slot);
                        Stream::putShort(stream, item_id);
                        Stream::putShort(stream, health);
                    }

                    void Equipment::toReadable(std::ostream &os) const
                    {
                        os << "Entity_Id: " << entity_id << "\n";
                        os << "Slot: " << slot << "\n";
                        os << "Item_Id: " << item_id << "\n";
                        os << "Health?: " << health << std::endl;
                    }
                }
            }
        }
    }
}
