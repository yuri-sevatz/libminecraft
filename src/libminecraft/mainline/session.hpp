#ifndef LIBMINECRAFT_MAINLINE_SESSION_HPP
#define LIBMINECRAFT_MAINLINE_SESSION_HPP

#include "game/player.hpp"

namespace libminecraft
{
    namespace mainline
    {
        class Client;

        class Session
        {
            /*
            // Read-only access to the world.
            const game::World & world;
            */

            // The client's gamepiece.
            const game::Player & self;

            // Only the Client can set this.
            // To get the client, just call client().
            class
            {
                friend class Client;
            private:
                Client * address;
            public:
                Client & operator()() const{
                    return *address;
                }
            } listener;

        protected:
            // A session can only be created with the needed information for playable game.
            // This requires:
            //  A World.
            //  A Self.
            Session(/*const game::World & world,*/ const game::Player & self);

            // End the session.
            virtual void disconnect() = 0;
        };
    }
}

#endif // LIBMINECRAFT_MAINLINE_SESSION_HPP
