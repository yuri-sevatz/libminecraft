#ifndef LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_PRECHUNK_HPP
#define LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_PRECHUNK_HPP

#include "../packet.hpp"

namespace libminecraft
{
    namespace mainline
    {
        namespace protocol
        {
            namespace server
            {
                namespace packet
                {
                    class PreChunk : public Packet
                    {
                    public:
                        MCTypes::Int x;
                        MCTypes::Int z;
                        MCTypes::Bool load;

                        PreChunk();
                        void read(std::istream &is);
                        void write(std::ostream &os) const;
                        void toReadable(std::ostream &os) const;
                    };
                }
            }
        }
    }
}

#endif // LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_PRECHUNK_HPP
