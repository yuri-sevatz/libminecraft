#include "negotiating.hpp"

#include <libminecraft/mainline/session/remote.hpp>
#include "../connection.hpp"

#include "../../../protocol/client/packet/ident.hpp"
#include "../../../protocol/client/packet/login.hpp"

#include "../../../protocol/server/packet/ident.hpp"
#include "../../../protocol/server/packet/login.hpp"

#include <libminecraft/shared/exception/login.hpp>
#include <libminecraft/shared/exception/protocol.hpp>

#include <iostream>

namespace libminecraft {
namespace mainline {
namespace session {
namespace remote {
namespace state {
Negotiating::Negotiating() {
}

void Negotiating::Enter(t_owner & owner) const {
    std::cerr << "Negotiating..." << std::endl;
}

void Negotiating::Update(t_owner & owner) const {
    protocol::client::packet::Ident myident;
    myident.username.assign(owner.username.begin(), owner.username.end());
    owner.proto.write(myident);

    std::cerr << "Awaiting Response..." << std::endl;

    if (owner.proto.next() != protocol::server::Packet::IDENT) {
        std::cerr << (int) owner.proto.next() << std::endl;
        throw exception::Protocol("Invalid packet id received while awaiting IDENT");
    }

    protocol::server::packet::Ident srvident;
    owner.proto.read(srvident);

    protocol::client::packet::Login mylogin;

    mylogin.id = protocol::client::Protocol::version;

    static const MCTypes::UCS2Char AUTH_NONE [] = {'-', '\0'};
    static const MCTypes::UCS2Char AUTH_PASSOWRD [] = {'+', '\0'};

    if (srvident.hash == AUTH_NONE)
        mylogin.username.assign(owner.username.begin(), owner.username.end());
    else if (srvident.hash == AUTH_PASSOWRD)
        throw exception::Login("Password-Based Login is Unsupported");
    else {
        // TODO:
        // Copy the hash to a get request to minecraft.net

        throw exception::Login("Hash-Based Login is Unsupported");
    }

    // Write the login packet
    owner.proto.write(mylogin);

    if (owner.proto.next() != protocol::server::Packet::LOGIN)
        throw exception::Login("Login Failed");

    protocol::server::packet::Login srvlogin;
    owner.proto.read(srvlogin);

    // TODO: Get the player's entity id from the login success packet.

    // Ignore Map Seed
    // Ignore Dimension

    // Change the state to the loading map state...
    owner.ChangeState(owner.States.LOADING);
}

void Negotiating::Exit(t_owner & owner) const {

}
}
}
}
}
}
