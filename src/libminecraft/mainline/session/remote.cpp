/*
 * remote.cpp
 * This file is part of LibMinecraft.
 *
 * Created by Yuri Sevatz on 10/2011.
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

#include "remote.hpp"

#include <boost/asio.hpp>

#include "remote/connection.hpp"

namespace libminecraft
{
    namespace mainline
    {
        namespace session
        {
            Remote::Remote(const std::string &hostname, const std::string &service, const std::string &username) :
                // Connection object: This provides protocol, parsing, world, etc.
                connection(new remote::Connection(*this, hostname, service, username)),
                Session()
            {

            }

            Remote::~Remote()
            {
                delete connection;
            }

            const game::Player & Remote::getSelf()
            {
                return connection->_self;
            }

            void Remote::connect()
            {
                run();
            }

            void Remote::run()
            {
                try
                {
                    while(true)
                        connection->Update();
                }
                catch (libminecraft::Exception ex)
                {
                    /* listener().onNetworkError(ex.message); */
                    std::cerr << ex.what() << std::endl;
                    //disconnect(); // Kill the game.
                }
            }
        }
    }
}
