#include "stream.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace protocol
        {
            // static
            void Stream::putString64(std::ostream & stream, const MCTypes::String64 & str)
            {
                // Write Max M_STRING_LEN characters from the string
                stream.write(str.c_str(), std::min(str.length(), (size_t) MCTypes::String64_Max_Length));

                // If the string is less than our theoretical max
                for (unsigned  i = str.length(); i < MCTypes::String64_Max_Length; i++)
                {
                    // Pad with spaces
                    stream.put(0x20);
                }
            }

            // static
            void Stream::getString64(std::istream & stream, MCTypes::String64 & str)
            {
                // Tmp space.
                str.resize(MCTypes::String64_Max_Length);
                stream.read(&*str.begin(), MCTypes::String64_Max_Length);

                // Position of the end of the string
                std::string::reverse_iterator str_end;

                // Find the iterator position of the first non-space character from the right.
                for (str_end = str.rbegin(); str_end != str.rend(); str_end++)
                {
                    // Break on the first space.
                    if (*str_end != ' ')
                        break;
                }

                // str_end points to the last character - convert to forward_iterator.
                // --> it's automatically incremented to one past this position.

                str.erase(str_end.base(), str.end());
            }
        }
    }
}
