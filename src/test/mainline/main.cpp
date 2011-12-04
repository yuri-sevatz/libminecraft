/*
 * main.cpp
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

#include <iostream>
#include <cstdlib>
#include <string>

#include <libminecraft/mainline/session/remote.hpp>

#include "mymainlineclient.hpp"

void print_usage(char * my_name)
{
    std::cerr << "Minecraft Mainline Test\n";
    std::cerr << "\tUsage:\t";
    std::cerr << my_name << " [hostname|ip] [port] [username] <[wip:key]>" << std::endl;
}

int main(int argc, char * argv[])
{
    if (argc < 4)
    {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    std::string hostname(argv[1]);
    std::string port(argv[2]);
    std::string username(argv[3]);

    // Create the session
    libminecraft::mainline::session::Remote session(hostname, port, username);

    MyMainlineClient client(session);

    session.connect();

    return EXIT_SUCCESS;
}
