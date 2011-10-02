#ifndef LIBMINECRAFT_MAINLINE_SESSION_REMOTE_STATE_HPP
#define LIBMINECRAFT_MAINLINE_SESSION_REMOTE_STATE_HPP

#include "../../../support/fsm/actionstate.hpp"

namespace libminecraft
{
    namespace mainline
    {
        namespace session
        {
            namespace remote
            {
                // Forward-declare the owner.  We only need pointers to this.
                class Connection;

                class State : public ActionState<Connection>
                {

                };
            }
        }
    }
}

#endif // LIBMINECRAFT_MAINLINE_SESSION_REMOTE_STATE_HPP
