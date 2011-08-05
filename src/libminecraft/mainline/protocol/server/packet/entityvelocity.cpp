#include "entityvelocity.hpp"

#include "../../stream.hpp"

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
                    EntityVelocity::EntityVelocity()
                    {
                    }

                    void EntityVelocity::read(std::istream &stream)
                    {
                        Stream::getInt(stream, entity_id);
                        Stream::getShort(stream, dx);
                        Stream::getShort(stream, dy);
                        Stream::getShort(stream, dz);
                    }

                    void EntityVelocity::write(std::ostream &stream) const
                    {
                        Stream::putInt(stream, entity_id);
                        Stream::putShort(stream, dx);
                        Stream::putShort(stream, dy);
                        Stream::putShort(stream, dz);
                    }

                    void EntityVelocity::toReadable(std::ostream &os) const
                    {
                        os << "Entity_Id: " << entity_id << "\n";
                        os << "Delta X: " << dx << "\n";
                        os << "Delta Y: " << dy << "\n";
                        os << "Delta Z: " << dz << std::endl;
                    }
                }
            }
        }
    }
}
