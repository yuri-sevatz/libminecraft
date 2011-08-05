#ifndef LIBMINECRAFT_MAINLINE_SESSION_REMOTE_HPP
#define LIBMINECRAFT_MAINLINE_SESSION_REMOTE_HPP

#include "../session.hpp"

#include "remote/statemachine.hpp"
#include "../protocol/client.hpp"

#include <boost/asio.hpp>

namespace libminecraft
{
    namespace mainline
    {
        namespace session
        {
        class Remote : public Session
            {
                friend class remote::state::Negotiating;
        private:
            // The credentials used for the session.
            std::string username;
            /*
            std::string key;
            */

            /*
            // Once connected...
            std::string server_name;
            std::string server_motd;
            */

            /*
            // Map tmp data...
            std::stringstream gz_data;
            */

            // The "self" in the game, private, writable.
            game::Player _self;

            /*
            // The actual world, private, writable.
            game::World _world;
            */

            remote::StateMachine fsm;

            // The connection
            boost::asio::ip::tcp::iostream stream;

            public:
                // The remote session uses the client protocol.
                protocol::Client proto;

                Remote(const std::string &hostname,
                       const std::string &service);

                // Connect to the target server
                void connect(const std::string &username,
                             const std::string &key);

                virtual void disconnect();

            private:
                // The master loop, used for FSM update() calls.
                void loop();
            };
        }
    }
}

#endif // LIBMINECRAFT_MAINLINE_SESSION_REMOTE_HPP
