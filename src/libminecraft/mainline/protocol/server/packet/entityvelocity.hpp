#ifndef LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_ENTITYVELOCITY_HPP
#define LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_ENTITYVELOCITY_HPP

#include "../packet.hpp"

namespace libminecraft {
namespace mainline {
namespace protocol {
namespace server {
namespace packet {
class EntityVelocity : public Packet {
public:
    MCTypes::Int entity_id;
    MCTypes::Short dx;
    MCTypes::Short dy;
    MCTypes::Short dz;

    EntityVelocity();
    void read(std::istream & is);
    void write(std::ostream & os) const;
    void toReadable(std::ostream & os) const;
};
}
}
}
}
}

#endif // LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_ENTITYVELOCITY_HPP
