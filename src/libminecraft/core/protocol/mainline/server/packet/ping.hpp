#ifndef LIBMINECRAFT_MAINLINE_SERVER_PACKET_PING_HPP
#define LIBMINECRAFT_MAINLINE_SERVER_PACKET_PING_HPP

#include "../packet.hpp"

namespace libminecraft
{
    namespace mainline
    {
        namespace server
        {
            namespace packet
            {
                class Ping : public Packet
                {
                    Ping();
                    virtual void read(std::istream &is);
                    virtual void write(std::ostream &os) const;
                    virtual void toReadable(std::ostream &os) const;
                };
            }
        }
    }
}

#endif // LIBMINECRAFT_MAINLINE_SERVER_PACKET_PING_HPP
