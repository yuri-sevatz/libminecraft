#ifndef LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_MOVINGOBJECTSPAWN_HPP
#define LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_MOVINGOBJECTSPAWN_HPP

#include "../packet.hpp"

namespace libminecraft {
namespace mainline {
namespace protocol {
namespace server {
namespace packet {
class MovingObjectSpawn : public Packet {
public:
    MCTypes::Int entity_id;
    MCTypes::Byte type;
    MCTypes::Int x;
    MCTypes::Int y;
    MCTypes::Int z;
    MCTypes::Int eid_tracking;
    MCTypes::Short dx;
    MCTypes::Short dy;
    MCTypes::Short dz;

    MovingObjectSpawn();
    void read(std::istream & is);
    void write(std::ostream & os) const;
    void toReadable(std::ostream & os) const;
private:
    bool includesMotion() const;
};

inline bool MovingObjectSpawn::includesMotion() const {
    return eid_tracking > 0;
}
}
}
}
}
}

#endif // LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_MOVINGOBJECTSPAWN_HPP
