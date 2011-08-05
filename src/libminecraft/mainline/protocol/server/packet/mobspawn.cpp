#include "mobspawn.hpp"

#include "../../stream.hpp"

#include "../../../../shared/exception/protocol.hpp"

#include <iostream>

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
                    MobSpawn::MobSpawn()
                    {
                    }

                    void MobSpawn::read(std::istream &stream)
                    {
                        Stream::getInt(stream, entity_id);
                        Stream::getByte(stream, type);
                        Stream::getInt(stream, x);
                        Stream::getInt(stream, y);
                        Stream::getInt(stream, z);
                        Stream::getByte(stream, yaw);
                        Stream::getByte(stream, pitch);

                        while(true)
                        {
                            unsigned char md_type = static_cast<unsigned char>(Stream::getByte(stream));

                            if (md_type == 127)
                                break;

                            std::cerr << "MD_TYPE = " << (int) ((md_type) >> 5) << "(" << (int) (md_type & 0x1f) << ")" << std::endl;

                            switch(md_type >> 5)
                            {
                            case 0:
                                std::cerr << "Byte" << " => " << (int) Stream::getByte(stream) << std::endl;
                                break;
                            case 1:
                                std::cerr << "Short" << " => " << (int) Stream::getShort(stream) << std::endl;
                                break;
                            case 2:
                                std::cerr << "Int" << " => " << Stream::getInt(stream) << std::endl;
                                break;
                            case 3:
                                std::cerr << "Float" << " => " << Stream::getFloat(stream) << std::endl;
                                break;
                            case 4:
                                std::wcerr << "String" << " => " << Stream::getUCS2String(stream) << std::endl;
                                break;
                            case 5:
                                std::cerr << "Short, Byte, Short:" << std::endl;
                                std::cerr << "\t" << " => " << (int) Stream::getShort(stream) << std::endl;
                                std::cerr << "\t" << " => " << (int) Stream::getByte(stream) << std::endl;
                                std::cerr << "\t" << " => " << (int) Stream::getShort(stream) << std::endl;
                                break;
                            case 6:
                                std::cerr << "Int, Int, Int:" << std::endl;
                                std::cerr << "\t" << " => " << Stream::getInt(stream) << std::endl;
                                std::cerr << "\t" << " => " << Stream::getInt(stream) << std::endl;
                                std::cerr << "\t" << " => " << Stream::getInt(stream) << std::endl;
                                break;
                            default:
                                throw exception::Protocol("Unrecognized Metadata Type");
                            }
                        }
                    }

                    void MobSpawn::write(std::ostream &stream) const
                    {
                        Stream::putInt(stream, entity_id);
                        Stream::putByte(stream, type);
                        Stream::putInt(stream, x);
                        Stream::putInt(stream, y);
                        Stream::putInt(stream, z);
                        Stream::putByte(stream, yaw);
                        Stream::putByte(stream, pitch);

                        throw exception::Protocol("Can't Write Metadata");
                    }

                    void MobSpawn::toReadable(std::ostream &os) const
                    {
                        os << "Entity ID: " << entity_id << "\n";
                        os << "Type: " << (int) type << "\n";
                        os << "X: " << x << "\n";
                        os << "Y: " << y << "\n";
                        os << "Z: " << z << "\n";
                        os << "Yaw: " << (int) yaw << "\n";
                        os << "Pitch: " << (int) pitch << std::endl;
                    }
                }
            }
        }
    }
}
