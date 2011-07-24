#ifndef LIBMINECRAFT_MAINLINE_SESSION_REMOTE_STATEMACHINE_HPP
#define LIBMINECRAFT_MAINLINE_SESSION_REMOTE_STATEMACHINE_HPP

#include "../../../support/fsm/actionstatemachine.hpp"

#include "state.hpp"

// Include all the states...
#include "state/connecting.hpp"
#include "state/disconnected.hpp"
#include "state/negotiating.hpp"

namespace libminecraft
{
    namespace mainline
    {
        namespace session
        {
            // Forward-declare remote session.
            class Remote;

            namespace remote
            {
                class StateMachine : public ActionStateMachine<StateMachine, const State>
                {
                public:
                    // Create a container for all states statically for const references.
                    // This way, all the states have access to protected/private content.
                    static const struct StatesDefs
                    {
                        state::Disconnected DISCONNECTED;
                        state::Connecting CONNECTING;
                        state::Negotiating NEGOTIATING;
                    } States;

                    StateMachine(Remote & session);

                    Remote & session;
                };
            }
        }
    }
}

#endif // LIBMINECRAFT_MAINLINE_SESSION_REMOTE_STATEMACHINE_HPP
