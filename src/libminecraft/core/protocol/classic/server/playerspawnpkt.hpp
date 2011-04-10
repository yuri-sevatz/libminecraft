/*
 * playerspawnpkt.hpp
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

#ifndef LIBMINECRAFT_CLASSIC_SERVER_PLAYERSPAWNPKT_HPP
#define LIBMINECRAFT_CLASSIC_SERVER_PLAYERSPAWNPKT_HPP

#include "packet.hpp"

#include <string>

namespace libminecraft
{
    namespace classic
    {
        namespace server
        {
            class PlayerSpawnPkt : public Packet
            {
            public:
                static const NetworkTypes::Byte id;

                NetworkTypes::Byte player_id;
                std::string player_name;
                NetworkTypes::SShort x;
                NetworkTypes::SShort y;
                NetworkTypes::SShort z;
                NetworkTypes::Byte yaw;
                NetworkTypes::Byte pitch;

                PlayerSpawnPkt();
                virtual void read(std::istream &is);
                virtual void write(std::ostream &os) const;
                virtual void toReadable(std::ostream &os) const;
            };
        }
    }
}

#endif // LIBMINECRAFT_CLASSIC_SERVER_PLAYERSPAWNPKT_HPP
