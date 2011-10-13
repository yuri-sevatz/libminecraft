/*
 * connection.hpp
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

#ifndef LIBMINECRAFT_CLASSIC_SESSION_REMOTE_CONNECTION_HPP
#define LIBMINECRAFT_CLASSIC_SESSION_REMOTE_CONNECTION_HPP

// Protocol
#include "../../protocol/client.hpp"

// State management
#include "../../../support/fsm/actionstatemachine.hpp"
#include "state.hpp"

// Include game necessities
#include "../../game/world.hpp"
#include "../../game/player/local.hpp"

// Include server properties
#include "../info.hpp"

// Include all the states...
#include "state/connecting.hpp"
#include "state/ingame.hpp"
#include "state/loadingmap.hpp"
#include "state/negotiating.hpp"

#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <sstream>

namespace libminecraft
{
    namespace classic
    {
        namespace session
        {
            // Forward-declare remote session.
            class Remote;

            namespace remote
            {
                class Connection : public ActionStateMachine<Connection, const State>
                {
                    friend class state::Connecting;
                    friend class state::Negotiating;
                    friend class state::LoadingMap;
                    friend class state::InGame;

                public:
                    // Create a container for all states statically for const references.
                    // This way, all the states have access to protected/private content.
                    static const struct StatesDefs
                    {
                        state::Connecting CONNECTING;
                        state::Negotiating NEGOTIATING;
                        state::LoadingMap LOADINGMAP;
                        state::InGame INGAME;
                    } States;

                    // The remote session's connection uses the client protocol.
                    protocol::Client proto;

                    // The "self" in the game, private, writable.
                    game::player::Local _self;

                    // The game world, private, writable.
                    game::World _world;

                    // Server information.
                    session::Info _server;

                    // The worker thread, if requested.
                    boost::thread worker;

                private:
                    // Map tmp data...
                    std::stringstream gz_data;

                    // The session object
                    Remote & session;

                    // Server properties
                    std::string username;
                    std::string key;

                    // The connection itself.
                    boost::asio::ip::tcp::iostream stream;

                public:
                    Connection(Remote & session,
                               const std::string & hostname,
                               const std::string & service,
                               const std::string & username,
                               const std::string & key);
                };
            }
        }
    }
}

#endif // LIBMINECRAFT_CLASSIC_SESSION_REMOTE_CONNECTION_HPP
