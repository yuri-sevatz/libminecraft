/*
 * mymainlineclient.hpp
 * This file is part of LibMinecraft.
 *
 * Created by Yuri Sevatz on 11/2011.
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

#ifndef MYMAINLINECLIENT_HPP
#define MYMAINLINECLIENT_HPP

#include <libminecraft/mainline/client.hpp>

using namespace libminecraft;
using namespace libminecraft::mainline;

class MyMainlineClient : private Client
{
public:
    MyMainlineClient(Session & session);

    // When the network connection is terminated for unknown reasons.
    // This can occur at any time.
    // Note: The world will be destroyed after execution of this function.
    void onNetworkError(const char * reason);

    // When an error in the protocol communicated by the server occurs
    // This can occur at any time - usually due to updates or improper client/server protocol.
    // Note: The world will be destroyed after execution of this function.
    void onProtocolError(const char * reason);

    // When a login error occues.
    // This will only occur when first connecting to a server,
    // possibly due to invalid login credentials.
    void onLoginError(const char * reason);

    // When a warning is provided.
    // This can occur at any time.  The explanation for the warning is provided.
    // Usually this is due to opensource server software incorrect implementation.
    void onProtocolWarning(const char * reason);
};

#endif // MYMAINLINECLIENT_HPP
