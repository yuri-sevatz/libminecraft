#include "abilities.hpp"

#include "../../stream.hpp"

namespace libminecraft {
namespace mainline {
namespace protocol {
namespace server {
namespace packet {

Abilities::Abilities() {
}

void Abilities::read(std::istream & stream) {
    Stream::getBool(stream, isInvulnerable);
    Stream::getBool(stream, isFlying);
    Stream::getBool(stream, canFly);
    Stream::getBool(stream, canInstantDig);
}

void Abilities::write(std::ostream & stream) const {
    Stream::putBool(stream, isInvulnerable);
    Stream::putBool(stream, isFlying);
    Stream::putBool(stream, canFly);
    Stream::putBool(stream, canInstantDig);
}

void Abilities::toReadable(std::ostream & os) const {
    os << "isInvulnerable: " << isInvulnerable << "\n";
    os << "isFlying: " << isFlying << "\n";
    os << "canFly: " << canFly << "\n";
    os << "canInstantDig: " << canInstantDig << std::endl;
}

}
}
}
}
}
