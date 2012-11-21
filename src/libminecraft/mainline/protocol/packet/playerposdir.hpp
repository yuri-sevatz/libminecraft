#ifndef LIBMINECRAFT_MAINLINE_PROTOCOL_PACKET_PLAYERPOSDIR_HPP
#define LIBMINECRAFT_MAINLINE_PROTOCOL_PACKET_PLAYERPOSDIR_HPP

#include "../packet.hpp"

namespace libminecraft {
namespace mainline {
namespace protocol {
namespace packet {
class PlayerPosDir : public virtual Packet {
public:
    MCTypes::Double x;
    MCTypes::Double y;
    MCTypes::Double z;
    MCTypes::Double stance;
    MCTypes::Float yaw;
    MCTypes::Float pitch;
    MCTypes::Bool on_ground;

    void read(std::istream & is);
    void write(std::ostream & os) const;
    void toReadable(std::ostream & os) const;
};
}
}
}
}

#endif // LIBMINECRAFT_MAINLINE_PROTOCOL_PACKET_PLAYERPOSDIR_HPP
