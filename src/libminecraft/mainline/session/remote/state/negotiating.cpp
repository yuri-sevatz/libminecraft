#include "negotiating.hpp"

#include "../../remote.hpp"

#include "../../../protocol/client/packet/ident.hpp"
#include "../../../protocol/client/packet/login.hpp"

#include "../../../protocol/server/packet/ident.hpp"
#include "../../../protocol/server/packet/login.hpp"

#include "../../../../shared/exception/login.hpp"
#include "../../../../shared/exception/protocol.hpp"

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
                        protocol::client::packet::Ident myident;
                        myident.username.assign(owner.session.username.begin(), owner.session.username.end());
                        owner.session.proto.write(myident);

                        std::cerr << "Awaiting Response..." << std::endl;

                        if (owner.session.proto.next() != protocol::server::Packet::IDENT)
                        {
                            std::cerr << (int) owner.session.proto.next() << std::endl;
                            throw exception::Protocol("Invalid packet id received while awaiting IDENT");
                        }

                        protocol::server::packet::Ident srvident;
                        owner.session.proto.read(srvident);

                        protocol::client::packet::Login mylogin;

                        mylogin.version = protocol::client::Protocol::version;

                        static const MCTypes::UCS2Char AUTH_NONE [] = {'-', NULL};
                        static const MCTypes::UCS2Char AUTH_PASSOWRD [] = {'+', NULL};

                        if (srvident.hash == AUTH_NONE)
                            mylogin.username.assign(owner.session.username.begin(), owner.session.username.end());
                        else if (srvident.hash == AUTH_PASSOWRD)
                            throw exception::Login("Password-Based Login is Unsupported");
                        else
                        {
                            // TODO:
                            // Copy the hash to a get request to minecraft.net

                            throw exception::Login("Hash-Based Login is Unsupported");
                        }

                        // Write the login packet
                        owner.session.proto.write(mylogin);

                        if (owner.session.proto.next() != protocol::server::Packet::LOGIN)
                            throw exception::Login("Login Failed");

                        protocol::server::packet::Login srvlogin;
                        owner.session.proto.read(srvlogin);

                        // TODO: Get the player's entity id from the login success packet.

                        // Ignore Map Seed
                        // Ignore Dimension

                        // Change the state to the loading map state...
                        owner.ChangeState(owner.States.LOADING);
                    }

                    void Negotiating::Exit(t_owner &owner) const
                    {

                    }
                }
            }
        }
    }
}
