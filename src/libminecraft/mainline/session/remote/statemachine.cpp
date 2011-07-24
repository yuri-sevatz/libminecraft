#include "statemachine.hpp"

namespace libminecraft
{
    namespace mainline
    {
        namespace session
        {
            namespace remote
            {
                // Declare/Initialize the Default States
                const StateMachine::StatesDefs StateMachine::States;

                StateMachine::StateMachine(Remote & session) :
                        ActionStateMachine<StateMachine, const State>(*this, States.DISCONNECTED),
                        session(session)
                {

                }
            }
        }
    }
}
