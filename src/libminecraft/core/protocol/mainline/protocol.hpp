#ifndef LIBMINECRAFT_MAINLINE_PROTOCOL_HPP
#define LIBMINECRAFT_MAINLINE_PROTOCOL_HPP

#include <iostream>

#include "../protocol.hpp"

namespace libminecraft
{
    namespace mainline
    {
        class Protocol : public libminecraft::Protocol
        {
        protected:
            // A single stream exists in the classic protocol for a session.
            std::iostream & stream;
        public:
            Protocol(std::iostream & stream);
        };
    }
}

#endif // LIBMINECRAFT_MAINLINE_PROTOCOL_HPP
