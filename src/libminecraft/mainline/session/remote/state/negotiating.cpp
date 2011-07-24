#include "negotiating.hpp"

#include "../../../../shared/exception/login.hpp"

#include <iostream>

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
                    Negotiating::Negotiating()
                    {
                    }

                    void Negotiating::Enter(t_owner &owner) const
                    {
                        std::cerr << "Negotiating..." << std::endl;
                    }

                    void Negotiating::Update(t_owner &owner) const
                    {
                        throw exception::Login("Not Implemented...");
                    }

                    void Negotiating::Exit(t_owner &owner) const
                    {

                    }
                }
            }
        }
    }
}
