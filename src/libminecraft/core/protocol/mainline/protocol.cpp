#include "protocol.hpp"

namespace libminecraft
{
    namespace mainline
    {
        Protocol::Protocol(std::iostream & stream)
            : stream(stream)
        {
        }
    }
}
