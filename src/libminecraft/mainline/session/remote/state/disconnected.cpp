#include "disconnected.hpp"

#include "../../../../shared/exception/network.hpp"

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
                    Disconnected::Disconnected()
                    {
                    }

                    void Disconnected::Enter(t_owner &owner) const
                    {

                    }
                    void Disconnected::Update(t_owner &owner) const
                    {
                        throw exception::Network("No connection to network - nothing to do.");
                    }
                    void Disconnected::Exit(t_owner &owner) const
                    {

                    }
                }
            }
        }
    }
}
