#ifndef LIBMINECRAFT_MAINLINE_SESSION_REMOTE_STATE_DISCONECTED_HPP
#define LIBMINECRAFT_MAINLINE_SESSION_REMOTE_STATE_DISCONECTED_HPP

#include "../state.hpp"

namespace libminecraft
{
    namespace mainline
    {
        namespace session
        {
            namespace remote
            {
                namespace state
                {
                    class Disconnected : public State
                    {
                    public:
                        Disconnected();
                        virtual void Enter(t_owner &owner) const;
                        virtual void Update(t_owner &owner) const;
                        virtual void Exit(t_owner &owner) const;
                    };
                }
            }
        }
    }
}

#endif // LIBMINECRAFT_MAINLINE_SESSION_REMOTE_STATE_DISCONECTED_HPP
