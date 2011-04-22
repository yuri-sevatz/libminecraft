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
                throw ProtocolException("Invalid string length detected");
            
            str.resize(length);
            // TODO: Ugly looking call - is there a better way to do this?
            stream.read(&*str.begin(), length);
        }
    
        // static
        void Stream::putString(std::ostream & stream, const MCTypes::String & str)
        {
            size_t length = std::min(str.length(), (size_t) MCTypes::MAX_STRING_LENGTH);
            putShort(stream, length);
            stream.write(str.c_str(), length);
        }

        void Stream::getUCS2String(std::istream &stream, MCTypes::UCS2String &str)
        {
            MCTypes::Short length;
            getShort(stream, length);

            if (length < 0)
                throw ProtocolException("Invalid UCS2 string length detected");

            str.resize(length);

            for(MCTypes::UCS2String::iterator iter = str.begin(); iter != str.end(); iter++)
                getUCS2Char(stream, *iter);
        }

        void Stream::putUCS2String(std::ostream &stream, const MCTypes::UCS2String &str)
        {
            const size_t length = std::min(str.length(), (size_t) MCTypes::MAX_UCS2_LENGTH);
            putShort(stream, length);
            for(MCTypes::UCS2String::const_iterator iter = str.begin(); iter != str.begin() + length; iter++)
                putUCS2Char(stream, *iter);
        }
    }
}
