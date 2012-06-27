/*
 * connecting.cpp
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

#include "connecting.hpp"
#include <iostream>

#include "../connection.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace session
        {
            namespace remote
            {
                namespace state
                {
                    Connecting::Connecting()
                    {
                    }

                    void Connecting::Enter(t_owner &owner) const
                    {
                        std::cerr << "Connecting..." << std::endl;
                    }
                    void Connecting::Update(t_owner &owner) const
                    {
                        boost::asio::ip::tcp::resolver resolver(owner.service);
                        boost::asio::ip::tcp::resolver::query query(owner.hostname, owner.port);

                        boost::asio::ip::tcp::resolver::iterator endpoint = resolver.resolve(query);
                        const boost::asio::ip::tcp::resolver::iterator end;

                        // Check if any endpoints were resolved at all...
                        if (endpoint == end) {
                            throw exception::Network("Unable to resolve target hostname");
                        }

                        do
                        {
                            boost::system::error_code error;

                            owner.socket.connect(*endpoint++, error);

                            if(error)
                            {
                                owner.socket.close();
                            }
                            else {
                                owner.ChangeState(owner.States.NEGOTIATING);
                                return;
                            }
                        } while (endpoint != end);

                        // Throw an exception, all connections failed...
                        throw exception::Network("Unable to connect to target hostname");

                    }
                    void Connecting::Exit(t_owner &owner) const
                    {
                        std::cerr << "Successfully Connected!" << std::endl;
                    }
                }
            }
        }
    }
}
