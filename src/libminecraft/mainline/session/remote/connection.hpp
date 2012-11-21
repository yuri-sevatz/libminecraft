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

#ifndef LIBMINECRAFT_MAINLINE_SESSION_REMOTE_CONNECTION_HPP
#define LIBMINECRAFT_MAINLINE_SESSION_REMOTE_CONNECTION_HPP

// Protocol
#include "../../protocol/client.hpp"

// State management
#include "../../../support/fsm/actionstatemachine.hpp"
#include "state.hpp"

// Include game necessities
#include <libminecraft/mainline/game/player.hpp>

// Include all the states...
#include "state/connecting.hpp"
#include "state/negotiating.hpp"
#include "state/loading.hpp"

#include <boost/asio.hpp>

namespace libminecraft {
namespace mainline {
namespace session {
// Forward-declare remote session.
class Remote;

namespace remote {

class Connection : public ActionStateMachine<Connection, const State> {
    friend class state::Connecting;
    friend class state::Negotiating;
    friend class state::Loading;

public:
    // Create a container for all states statically for const references.
    // This way, all the states have access to protected/private content.
    static const struct StatesDefs {
        state::Connecting CONNECTING;
        state::Negotiating NEGOTIATING;
        state::Loading LOADING;
    } States;

    // This connection uses the client protocol.
    protocol::Client proto;

    // The "self" in the game, private, writable.
    game::Player _self;

    /*
    // The actual world, private, writable.
    game::World _world;
    */

private:
    // The connection
    boost::asio::ip::tcp::iostream stream;

    // The session
    Remote & session;

    // The credentials used for the session.
    std::string username;
    // std::string key;

public:
    Connection(Remote & session, const std::string & hostname, const std::string & service, const std::string & username);
};

}
}
}
}

#endif // LIBMINECRAFT_MAINLINE_SESSION_REMOTE_CONNECTION_HPP
