#include "connecting.hpp"
#include <iostream>

#include "../connection.hpp"

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
                    Connecting::Connecting()
                    {
                    }

                    void Connecting::Enter(t_owner &owner) const
                    {
                        std::cerr << "Connecting..." << std::endl;
                    }
                    void Connecting::Update(t_owner &owner) const
                    {
                        // Since boost asio iostream FAILS at error support...
                        // then we move into the next state and we handle connecting problems there :/
                        owner.ChangeState(owner.States.NEGOTIATING);
                    }
                    void Connecting::Exit(t_owner &owner) const
                    {

                    }
                }
            }
        }
    }
}
