/*
 * levelchunk.cpp
 * This file is part of LibMinecraft.
 *
 * Created by Yuri Sevatz on 11/2010.
 * Copyright (c) 2010 Yuri Sevatz. All rights reserved
 *
 * LibMinecraft is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * LibMinecraft is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with LibMinecraft.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "levelchunk.hpp"

#include "../../stream.hpp"
#include <iostream>

namespace libminecraft
{
    namespace classic
    {
        namespace protocol
        {
            namespace server
            {
                namespace packet
                {
                    LevelChunk::LevelChunk()
                    {

                    }

                    void LevelChunk::read(std::istream &stream)
                    {
                        MCTypes::Short length;
                        Stream::getShort(stream, length);

                        // We support the theoretical max offered by the protocol,
                        // with the size indicated by a SHORT_MAX.
                        if (length < 0)
                            throw exception::Protocol("Invalid chunk size detected while receiving map");

                        // Make room for length bytes.
                        data.resize(length);

                        // Save the data.
                        stream.read((char *) &(data.front()), length);

                        // Ignore the trailing characters in the byte array.
                        if (length < MAX_CHUNK_SIZE)
                            stream.ignore(MAX_CHUNK_SIZE - length);

                        // Read the percentage complete...
                        Stream::getByte(stream, percent);
                    }

                    void LevelChunk::write(std::ostream &stream) const
                    {
                        // Write the theoretical max supported by the protocol.
                        MCTypes::Short length = std::min((size_t) MCTypes::Short_Max, data.size());
                        Stream::putShort(stream, length);
                        
                        stream.write((const char *) &(data.front()), length);
                        
                        if (length < MAX_CHUNK_SIZE)
                        {
                            do
                            {
                                stream.put(0x00);
                            } while(++length != MAX_CHUNK_SIZE);
                        }
                        
                        Stream::putByte(stream, percent);
                    }

                    void LevelChunk::toReadable(std::ostream &os) const
                    {
                        os << "Length: " << data.size() << "\n";
                        os << "Percent: " << (int) percent << std::endl;
                    }
                }
            }
        }
    }
}
