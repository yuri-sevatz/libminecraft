#include "movingobjectspawn.hpp"

#include "../../stream.hpp"

namespace libminecraft {
namespace mainline {
namespace protocol {
namespace server {
namespace packet {
MovingObjectSpawn::MovingObjectSpawn() {
}

void MovingObjectSpawn::read(std::istream & stream) {
    Stream::getInt(stream, entity_id);
    Stream::getByte(stream, type);
    Stream::getInt(stream, x);
    Stream::getInt(stream, y);
    Stream::getInt(stream, z);
    Stream::getInt(stream, eid_tracking);

    if (includesMotion()) {
        Stream::getShort(stream, dx);
        Stream::getShort(stream, dy);
        Stream::getShort(stream, dz);
    }
}

void MovingObjectSpawn::write(std::ostream & stream) const {
    Stream::putInt(stream, entity_id);
    Stream::putByte(stream, type);
    Stream::putInt(stream, x);
    Stream::putInt(stream, y);
    Stream::putInt(stream, z);
    Stream::putInt(stream, eid_tracking);

    if (includesMotion()) {
        Stream::putShort(stream, dx);
        Stream::putShort(stream, dy);
        Stream::putShort(stream, dz);
    }
}

void MovingObjectSpawn::toReadable(std::ostream & os) const {
    os << "Entity ID: " << entity_id << "\n";
    os << "Type: " << (int) type << "\n";
    os << "X: " << x << "\n";
    os << "Y: " << y << "\n";
    os << "Z: " << z << "\n";
    os << "Tracking_Id: " << eid_tracking;

    if (includesMotion()) {
        os << "\n";
        os << "Delta X: " << dx << "\n";
        os << "Delta Y: " << dy << "\n";
        os << "Delta Z: " << dz;
    }

    os << std::endl;
}
}
}
}
}
}

