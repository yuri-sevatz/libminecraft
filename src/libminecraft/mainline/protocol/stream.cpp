#include "stream.hpp"

#include "../../support/io/bigendian/stream.hpp"

#include <boost/static_assert.hpp>
#include <boost/detail/endian.hpp>

namespace libminecraft
{
    namespace mainline
    {
        namespace protocol
        {
            // We require that the MC Char is at least 16 bits.
            BOOST_STATIC_ASSERT(sizeof(MCTypes::UCS2Char) >= 2);

            // static
            /*
            void Stream::getString(std::istream & stream, MCTypes::String & str)
            {
                MCTypes::Short length;
                getShort(stream, length);

                if (length < 0)
                    throw exception::Protocol("Invalid string length detected");

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
            */

            void Stream::getUCS2String(std::istream &stream, MCTypes::UCS2String &str)
            {
                MCTypes::Short length;
                getShort(stream, length);

                if (length < 0)
                    throw exception::Protocol("Invalid UCS2 string length detected");

                str.resize(length);

                for(MCTypes::UCS2String::iterator iter = str.begin(); iter != str.end(); iter++)
                    getUCS2Char(stream, *iter);
            }

            void Stream::putUCS2String(std::ostream &stream, const MCTypes::UCS2String &str)
            {
                const size_t length = std::min(str.length(), (size_t) MCTypes::UCS2String_Max_Length);
                putShort(stream, length);
                for(MCTypes::UCS2String::const_iterator iter = str.begin(); iter != str.begin() + length; iter++)
                    putUCS2Char(stream, *iter);
            }

            void Stream::getUCS2Char(std::istream &stream, MCTypes::UCS2Char &ch)
            {
                // Zero out overflow bytes first, only if wchar is not 16 bits.
                if (sizeof (MCTypes::UCS2Char) != sizeof(MCTypes::Short))
                    ch = 0;

    #ifdef BOOST_LITTLE_ENDIAN
                // Byte positions:
                // ex. with 32-bit wchar_t
                // (1, 2), 3, 4
                // Since the bytes are already in the right order.
                // we can use the regular offset.
                io::bigendian::stream::getShort(stream, (MCTypes::Short &) ch);
    #else
                // Byte positions:
                // ex. with 32-bit wchar_t
                // 4, 3, (2, 1)
                // Since the short isn't addressible at the base address
                // the short needs to be stored at the address of '2'.
                io::bigendian::stream::getShort(stream, *(((MCTypes::Short *) &ch) + sizeof(MCTypes::UCS2Char) - sizeof(MCTypes::Short));
    #endif
            }

            void Stream::putUCS2Char(std::ostream &stream, const MCTypes::UCS2Char &ch)
            {
    #ifdef BOOST_LITTLE_ENDIAN
                // Refer to the get Logic for an explanation.
                io::bigendian::stream::putShort(stream, (MCTypes::Short &) ch);
    #else
                io::bigendian::stream::putShort(stream, *(((MCTypes::Short *) &ch) + sizeof(MCTypes::UCS2Char) - sizeof(MCTypes::Short));
    #endif
            }
        }
    }
}
