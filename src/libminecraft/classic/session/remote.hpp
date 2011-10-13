/*
 * remote.hpp
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

#ifndef LIBMINECRAFT_CLASSIC_SESSION_REMOTE_HPP
#define LIBMINECRAFT_CLASSIC_SESSION_REMOTE_HPP

#include "../session.hpp"

// Include states that need private access
#include "remote/state/ingame.hpp"
#include "remote/state/loadingmap.hpp"
#include "remote/state/negotiating.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace session
        {
            namespace remote
            {
            // Forward-declare connection d-pointer.
            class Connection;
            }

            // Defines a local session.
            class Remote : public Session
            {
                remote::Connection * const connection;

            public:
                Remote(const std::string & hostname,
                       const std::string & service,
                       const std::string & username,
                       const std::string & key);
                ~Remote();

                // Connect to the target server
                void connect();

                // Set a block.
                virtual void setBlock(game::Map::size_block x, game::Map::size_block y, game::Map::size_block z, game::map::Cell::BlockType type);

                // Clear a block
                virtual void clearBlock(game::Map::size_block x, game::Map::size_block y, game::Map::size_block z);

                // Move.
                virtual void move(game::Map::size_plot x, game::Map::size_plot y, game::Map::size_plot z);

                // Look.
                virtual void look(game::Player::t_pitch pitch, game::Player::t_yaw yaw);

                // Move and look.
                virtual void moveAndLook(game::Map::size_plot x, game::Map::size_plot y, game::Map::size_plot z, game::Player::t_pitch pitch, game::Player::t_yaw yaw);

                // Send a message.
                virtual void sendMessage(const std::string & message);

                // Enable ticks.
                virtual void enableTicks();

                // Disable ticks.
                virtual void disableTicks();

                // End the session.
                // virtual void disconnect();

            protected:
                virtual const game::World & getWorld();

                virtual const game::player::Local & getSelf();

                virtual const session::Info & getInfo();

            private:
                // The master listener.  Blocks until complete.
                void run();

                static void tickNotifier(void * client);
            };
        }
    }
}

#endif // LIBMINECRAFT_CLASSIC_SESSION_REMOTE_HPP
