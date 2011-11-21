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

                            //std::cerr << "MD_TYPE = " << (int) ((md_type) >> 5) << "(" << (int) (md_type & 0x1f) << ")" << std::endl;

                            switch(md_type >> 5)
                            {
                            case 0:
                            {
                                MCTypes::Byte byte = Stream::getByte(stream);
                                //std::cerr << "Byte" << " => " << (int) byte  << std::endl;
                            }
                                break;
                            case 1:
                            {
                                MCTypes::Short shrt = Stream::getShort(stream);
                                //std::cerr << "Short" << " => " << (int) shrt << std::endl;
                            }
                                break;
                            case 2:
                            {
                                MCTypes::Int integer = Stream::getInt(stream);
                                //std::cerr << "Int" << " => " << integer << std::endl;
                            }
                                break;
                            case 3:
                            {
                                MCTypes::Float flt = Stream::getFloat(stream);
                                //std::cerr << "Float" << " => " << flt << std::endl;
                            }
                                break;
                            case 4:
                            {
                                MCTypes::UCS2String string = Stream::getUCS2String(stream);
                                //std::wcerr << "String" << " => " << string << std::endl;
                            }
                                break;
                            case 5:
                            {
                                //std::cerr << "Short, Byte, Short:" << std::endl;
                                MCTypes::Short shortA = Stream::getShort(stream);
                                //std::cerr << "\t" << " => " << (int) shortA << std::endl;
                                MCTypes::Byte byte = Stream::getByte(stream);
                                //std::cerr << "\t" << " => " << (int) byte << std::endl;
                                MCTypes::Short shortB = Stream::getShort(stream);
                                //std::cerr << "\t" << " => " << (int) shortB << std::endl;
                            }
                                break;
                            case 6:
                            {
                                //std::cerr << "Int, Int, Int:" << std::endl;
                                MCTypes::Int intA = Stream::getInt(stream);
                                //std::cerr << "\t" << " => " << intA << std::endl;
                                MCTypes::Int intB = Stream::getInt(stream);
                                //std::cerr << "\t" << " => " << intB << std::endl;
                                MCTypes::Int intC = Stream::getInt(stream);
                                //std::cerr << "\t" << " => " << intC << std::endl;
                            }
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
