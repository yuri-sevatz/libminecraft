/*
 * spawnpoint.cpp
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

#include "spawnpoint.hpp"

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
                    SpawnPoint::SpawnPoint()
                    {
                    }

                    void SpawnPoint::read(std::istream &stream)
                    {
                        Stream::getInt(stream, block_x);
                        Stream::getInt(stream, block_y);
                        Stream::getInt(stream, block_z);
                    }

                    void SpawnPoint::write(std::ostream &stream) const
                    {
                        Stream::putInt(stream, block_x);
                        Stream::putInt(stream, block_y);
                        Stream::putInt(stream, block_z);
                    }

                    void SpawnPoint::toReadable(std::ostream &os) const
                    {
                        os << "Block X: " << block_x << "\n";
                        os << "Block Y: " << block_y << "\n";
                        os << "Block Z: " << block_z << std::endl;
                    }
                }
            }
        }
    }
}
