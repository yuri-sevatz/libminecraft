#ifndef LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_PLAYERPOSDIR_HPP
#define LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_PLAYERPOSDIR_HPP

#include "../packet.hpp"
#include "../../packet/playerposdir.hpp"

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
                    class PlayerPosDir : public server::Packet, public protocol::packet::PlayerPosDir
                    {
                    public:
                        PlayerPosDir();
                    };
                }
            }
        }
    }
}

#endif // LIBMINECRAFT_MAINLINE_PROTOCOL_SERVER_PACKET_PLAYERPOSDIR_HPP
