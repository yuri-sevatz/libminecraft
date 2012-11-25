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

#ifndef LIBMINECRAFT_MAINLINE_SESSION_HPP
#define LIBMINECRAFT_MAINLINE_SESSION_HPP

#include <libminecraft/minecraft_export.h>

#include "game/player.hpp"

namespace libminecraft {
namespace mainline {
class Client;

class MINECRAFT_EXPORT Session {
public:
    // Only the Client can set this.
    // To get the client, just call client().
    class {
        friend class Client;
    private:
        Client * address;
    public:
        Client & operator()() const {
            return *address;
        }
    } listener;

    // Session object returns the self
    virtual const game::Player & getSelf() = 0;

    // End the session.
    // XXX: Not implemented.  Depends on having a proper threading model (use of connection object between functions and shielding thread objects from external linkage in remote.hpp <= external session class)
    //      What this actually does/means in the whole "gist" of things for various threaded/non-threaded uses needs to be reevaluated.
    // virtual void disconnect() = 0;

protected:
    Session();
};
}
}

#endif // LIBMINECRAFT_MAINLINE_SESSION_HPP
