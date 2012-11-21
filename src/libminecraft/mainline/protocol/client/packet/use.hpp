/*
 * use.hpp
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

#ifndef LIBMINECRAFT_MAINLINE_PROTOCOL_CLIENT_PACKET_USE_HPP
#define LIBMINECRAFT_MAINLINE_PROTOCOL_CLIENT_PACKET_USE_HPP

#include "../packet.hpp"

namespace libminecraft {
namespace mainline {
namespace protocol {
namespace client {
namespace packet {
class Use : public Packet {
public:
    MCTypes::Int user_entity_id;
    MCTypes::Int target_entity_id;
    MCTypes::Bool click;

    Use();
    void read(std::istream & is);
    void write(std::ostream & os) const;
    void toReadable(std::ostream & os) const;
};
}
}
}
}
}

#endif // LIBMINECRAFT_MAINLINE_PROTOCOL_CLIENT_PACKET_USE_HPP
