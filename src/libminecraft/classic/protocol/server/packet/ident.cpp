/*
 * ident.cpp
 * This file is part of LibMinecraft.
 *
 * Created by Yuri Sevatz on 11/2010.
 * Copyright (c) 2010 Yuri Sevatz. All rights reserved
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

#include "ident.hpp"

#include "../../stream.hpp"
#include "../protocol.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace protocol
        {
            namespace server
            {
                namespace packet
                {
                    Ident::Ident()
                    {

                    }

                    void Ident::read(std::istream & stream)
                    {
                        Stream::getByte(stream, srv_version);
                        Stream::getString(stream, srv_name);
                        Stream::getString(stream, srv_motd);
                        Stream::getByte(stream, user_type);
                    }

                    void Ident::write(std::ostream &stream) const
                    {
                        Stream::putByte(stream, srv_version);
                        Stream::putString(stream, srv_name);
                        Stream::putString(stream, srv_motd);
                        Stream::putByte(stream, user_type);
                    }

                    void Ident::toReadable(std::ostream &os) const
                    {
                        os << "Version: " << (int) srv_version << "\n";
                        os << "Name: " << srv_name << "\n";
                        os << "Motd: " << srv_motd << "\n";
                        os << "User Type: " << (int) user_type << std::endl;
                    }

                    MCTypes::Byte Ident::cmpVersion() const
                    {
                        if (srv_version > Protocol::version)
                            return 1;
                        else if (srv_version < Protocol::version)
                            return -1;
                        else
                            return 0;
                    }
                }
            }
        }
    }
}
