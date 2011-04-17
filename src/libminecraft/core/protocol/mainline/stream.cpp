#include "stream.hpp"

#include "../../../exceptions/protocolexception.hpp"

namespace libminecraft
{
    namespace mainline
    {
        // static
        void Stream::getString(std::istream & stream, MCTypes::String & str)
        {
            MCTypes::Short length;
            getShort(stream, length);
            
            if (length < 0)
                throw ProtocolException("Invalid chunk size detected while receiving map");
            
            str.resize(length);
            // TODO: Improper call - is there a better way to do this?
            stream.read(&*str.begin(), length);
        }
    
        // static
        void Stream::putString(std::ostream & stream, const MCTypes::String & str)
        {
            size_t length = std::min(str.length(), (size_t) MCTypes::MAX_STRING_LENGTH);
            putShort(stream, length);
            // TODO: Improper call - is there a better way to do this?
            stream.write(str.c_str(), length);
        }
    }
}
