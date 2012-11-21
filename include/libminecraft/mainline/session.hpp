#ifndef LIBMINECRAFT_MAINLINE_SESSION_HPP
#define LIBMINECRAFT_MAINLINE_SESSION_HPP

#include "game/player.hpp"

namespace libminecraft {
namespace mainline {
class Client;

class Session {
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
