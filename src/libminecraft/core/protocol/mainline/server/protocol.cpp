#include "protocol.hpp"

#include <typeinfo>

#include <boost/assign/list_of.hpp>

#include "packet.hpp"
#include "packet/ping.hpp"

#include "../../stream.hpp"

namespace libminecraft
{
    namespace mainline
    {
        namespace server
        {
            const std::map<const std::type_info *, Protocol::TransType> Protocol::transmap =
                    boost::assign::map_list_of
                        (&typeid(packet::Ping), Protocol::PING);

            Protocol::Protocol(std::iostream & stream)
                : mainline::Protocol(stream)
            {
            }

            MCTypes::Byte Protocol::next()
            {
                return (MCTypes::Byte) stream.peek();
            }
        }
    }
}
