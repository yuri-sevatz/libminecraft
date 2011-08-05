#include "loading.hpp"

#include "../../remote.hpp"

#include "../../../protocol/server/packet/entityvelocity.hpp"
#include "../../../protocol/server/packet/mobspawn.hpp"
#include "../../../protocol/server/packet/movingobjectspawn.hpp"
#include "../../../protocol/server/packet/playerposdir.hpp"
#include "../../../protocol/server/packet/prechunk.hpp"
#include "../../../protocol/server/packet/spawnpoint.hpp"
#include "../../../protocol/server/packet/time.hpp"


#include "../../../../shared/exception/protocol.hpp"

#include <iostream>

namespace libminecraft
{
    namespace mainline
    {
        namespace session
        {
            namespace remote
            {
                namespace state
                {
                    Loading::Loading()
                    {
                    }

                    void Loading::Enter(t_owner &owner) const
                    {
                        std::cerr << "Loading..." << std::endl;
                    }
                    void Loading::Update(t_owner &owner) const
                    {
                        std::cout << (int) owner.session.proto.next() << std::endl;

                        switch(owner.session.proto.next())
                        {
                        case protocol::server::Packet::SPAWNPOINT:
                            {
                                protocol::server::packet::SpawnPoint spawnpoint;
                                owner.session.proto.read(spawnpoint);
                            break;
                            }
                        case protocol::server::Packet::TIME:
                            {
                                protocol::server::packet::Time timeupdate;
                                owner.session.proto.read(timeupdate);
                            break;
                            }
                        case protocol::server::Packet::MOBSPAWN:
                            {
                                protocol::server::packet::MobSpawn mobspawn;
                                owner.session.proto.read(mobspawn);
                            break;
                            }
                        case protocol::server::Packet::MOVINGOBJECTSPAWN:
                            {
                                protocol::server::packet::MovingObjectSpawn movingobjectspawn;
                                owner.session.proto.read(movingobjectspawn);
                            break;
                            }
                        case protocol::server::Packet::ENTITYVELOCITY:
                            {
                                protocol::server::packet::EntityVelocity entityvelocity;
                                owner.session.proto.read(entityvelocity);
                            break;
                            }
                        case protocol::server::Packet::PRECHUNK:
                            {
                                protocol::server::packet::PreChunk prechunk;
                                owner.session.proto.read(prechunk);
                            break;
                            }
                        case protocol::server::Packet::PLAYERPOSDIR:
                            {
                                protocol::server::packet::PlayerPosDir playerposdir;
                                owner.session.proto.read(playerposdir);
                            break;
                            }
                        default:
                            throw exception::Protocol("Unrecognized Packet Type");
                        }
                    }
                    void Loading::Exit(t_owner &owner) const
                    {

                    }
                }
            }
        }
    }
}
