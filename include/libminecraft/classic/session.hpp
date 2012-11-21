/*
 * session.hpp
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


#ifndef LIBMINECRAFT_CLASSIC_SESSION_HPP
#define LIBMINECRAFT_CLASSIC_SESSION_HPP

#include "session/info.hpp"

#include "game/world.hpp"
#include "game/player/local.hpp"
#include "game/map.hpp"

namespace libminecraft {
namespace classic {
// Forward-declare listener class (has circular dependency).
class Client;

// Abstract session class.
// Allows us to define actions without defining context, or really "what happens after".
// Note: This means we can make things like local/remote clients, client AND server-side NPC's, etc.
class Session {

public:
    // Only the Client can set this.
    // To get the client, just call client().
    // This is used for passing events.
    class {
        friend class Client;
    private:
        Client * address;
    public:
        Client & operator()() const {
            return *address;
        }
    } listener;

    // Session object returns the world
    virtual const game::World & getWorld() = 0;

    // Session object returns the self
    virtual const game::player::Local & getSelf() = 0;

    // Session object returns the server info
    virtual const session::Info & getInfo() = 0;

    // Set a block.
    virtual void setBlock(const game::map::Cell & cell, game::map::Block::Type type) = 0;

    // Clear a block.
    virtual void clearBlock(const game::map::Cell & cell) = 0;

    // Move.
    virtual void move(const game::map::Point & pos) = 0;

    // Look.
    virtual void look(game::Player::t_pitch pitch, game::Player::t_yaw yaw) = 0;

    // Move and look.
    virtual void moveAndLook(const game::map::Point & pos, game::Player::t_pitch pitch, game::Player::t_yaw yaw) = 0;

    // Send a message.
    virtual void sendMessage(const std::string & message) = 0;

    // Enable session ticks from the session's work handler.
    virtual void enableTicks() = 0;

    // Disable session ticks from the session's work handler.
    virtual void disableTicks() = 0;

    // End the session.
    // XXX: Not implemented.  Depends on having a proper threading model (use of connection object between functions and shielding thread objects from external linkage in remote.hpp <= external session class)
    //      What this actually does/means in the whole "gist" of things for various threaded/non-threaded uses needs to be reevaluated.
    // virtual void disconnect() = 0;

protected:
    Session();
};
}
}

#endif // LIBMINECRAFT_CLASSIC_SESSION_HPP
