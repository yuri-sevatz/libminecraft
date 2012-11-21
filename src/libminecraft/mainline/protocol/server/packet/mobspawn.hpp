#ifndef LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_MOBSPAWN_HPP
#define LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_MOBSPAWN_HPP

#include "../packet.hpp"

namespace libminecraft {
namespace mainline {
namespace protocol {
namespace server {
namespace packet {
class MobSpawn : public Packet {
public:
    MCTypes::Int entity_id;
    MCTypes::Byte type;
    MCTypes::Int x;
    MCTypes::Int y;
    MCTypes::Int z;
    MCTypes::Byte yaw;
    MCTypes::Byte pitch;
    MCTypes::Byte head;

    // Metadata type

    MobSpawn();
    void read(std::istream & is);
    void write(std::ostream & os) const;
    void toReadable(std::ostream & os) const;
};
}
}
}
}
}

#endif // LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_MOBSPAWN_HPP
