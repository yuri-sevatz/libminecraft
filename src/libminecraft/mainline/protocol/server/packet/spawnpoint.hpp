/*
 * spawnpoint.hpp
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

#ifndef LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_SPAWNPOINT_HPP
#define LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_SPAWNPOINT_HPP

#include "../packet.hpp"

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
                    class SpawnPoint : public Packet
                    {
                    public:
                        MCTypes::Int block_x;
                        MCTypes::Int block_y;
                        MCTypes::Int block_z;

                        SpawnPoint();
                        virtual void read(std::istream &is);
                        virtual void write(std::ostream &os) const;
                        virtual void toReadable(std::ostream &os) const;
                    };
                }
            }
        }
    }
}

#endif // LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_SPAWNPOINT_HPP
