#ifndef LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_ABILITIES_HPP
#define LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_ABILITIES_HPP

#include "../packet.hpp"

namespace libminecraft {
namespace mainline {
namespace protocol {
namespace server {
namespace packet {

class Abilities  : public Packet {
public:
    MCTypes::Bool isInvulnerable;
    MCTypes::Bool isFlying;
    MCTypes::Bool canFly;
    MCTypes::Bool canInstantDig;

    Abilities();
    void read(std::istream & is);
    void write(std::ostream & os) const;
    void toReadable(std::ostream & os) const;
};

}
}
}
}
}

#endif // LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_ABILITIES_HPP
