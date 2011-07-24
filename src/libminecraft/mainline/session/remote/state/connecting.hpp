#ifndef LIBMINECRAFT_MAINLINE_SESSION_REMOTE_STATE_CONNECTING_HPP
#define LIBMINECRAFT_MAINLINE_SESSION_REMOTE_STATE_CONNECTING_HPP

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
                    class Connecting : public State
                    {
                    public:
                        Connecting();
                        virtual void Enter(t_owner &owner) const;
                        virtual void Update(t_owner &owner) const;
                        virtual void Exit(t_owner &owner) const;
                    };
                }
            }
        }
    }
}

#endif // LIBMINECRAFT_MAINLINE_SESSION_REMOTE_STATE_CONNECTING_HPP
