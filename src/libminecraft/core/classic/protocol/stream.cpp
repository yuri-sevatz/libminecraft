#include "stream.hpp"

namespace libminecraft
{
    namespace classic
    {
        // static
        void Stream::putString(std::ostream & stream, const MCTypes::String & str)
        {
            // Write Max M_STRING_LEN characters from the string
            stream.write(str.c_str(), std::min(str.length(), (size_t) MCTypes::MAX_STRING_LENGTH));

            // If the string is less than our theoretical max
            for (unsigned  i = str.length(); i < MCTypes::MAX_STRING_LENGTH; i++)
            {
                // Pad with spaces
                stream.put(0x20);
            }
        }

        // static
        void Stream::getString(std::istream & stream, MCTypes::String & str)
        {
            // Tmp space.
            str.resize(MCTypes::MAX_STRING_LENGTH);
            stream.read(&*str.begin(), MCTypes::MAX_STRING_LENGTH);

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
