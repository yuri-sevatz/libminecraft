/*
 * main.cpp
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

#include <libminecraft/classic/session/remote.hpp>

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "myclassicclient.hpp"

void print_usage(char * my_name)
{
    std::cerr << "Minecraft Classic Test\n";
    std::cerr << "\tUsage:\t";
    std::cerr << my_name << " [hostname|ip] [port] [username] [key]" << std::endl;
}

int main(int argc, char * argv[])
{
    if (argc < 5)
    {   
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    srand(time(NULL));

    std::string hostname(argv[1]);
    std::string port(argv[2]);

    // get the username and key.
    std::string username(argv[3]);
    std::string key(argv[4]);

    // Create the session.
    libminecraft::classic::session::Remote session(hostname, port, username, key);

    // Instantiate our client, give it the session.
    MyClassicClient client(session);

    // Connect... (blocks)
    session.connect();

    return EXIT_SUCCESS;
}
