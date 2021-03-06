#include "loading.hpp"

#include <libminecraft/mainline/session/remote.hpp>
#include "../connection.hpp"

#include "../../../protocol/server/packet/abilities.hpp"
#include "../../../protocol/server/packet/entityvelocity.hpp"
#include "../../../protocol/server/packet/gamestate.hpp"
#include "../../../protocol/server/packet/itemspawn.hpp"
#include "../../../protocol/server/packet/mobspawn.hpp"
#include "../../../protocol/server/packet/movingobjectspawn.hpp"
#include "../../../protocol/server/packet/playerlistitem.hpp"
#include "../../../protocol/server/packet/playerposdir.hpp"
#include "../../../protocol/server/packet/prechunk.hpp"
#include "../../../protocol/server/packet/spawnpoint.hpp"
#include "../../../protocol/server/packet/time.hpp"


#include <libminecraft/shared/exception/protocol.hpp>

#include <iostream>

namespace libminecraft {
namespace mainline {
namespace session {
namespace remote {
namespace state {
Loading::Loading() {
}

void Loading::Enter(t_owner & owner) const {
    std::cerr << "Loading..." << std::endl;
}
void Loading::Update(t_owner & owner) const {
    std::cout << "Next Packet: 0x" << std::hex << (short) (owner.proto.next() & 0x00ff) << std::endl;

    switch(owner.proto.next()) {
    case protocol::server::Packet::SPAWNPOINT: {
        protocol::server::packet::SpawnPoint spawnpoint;
        owner.proto.read(spawnpoint);
        break;
    }
    case protocol::server::Packet::TIME: {
        protocol::server::packet::Time timeupdate;
        owner.proto.read(timeupdate);
        break;
    }
    case protocol::server::Packet::MOBSPAWN: {
        protocol::server::packet::MobSpawn mobspawn;
        owner.proto.read(mobspawn);
        break;
    }
    case protocol::server::Packet::MOVINGOBJECTSPAWN: {
        protocol::server::packet::MovingObjectSpawn movingobjectspawn;
        owner.proto.read(movingobjectspawn);
        break;
    }
    case protocol::server::Packet::ENTITYVELOCITY: {
        protocol::server::packet::EntityVelocity entityvelocity;
        owner.proto.read(entityvelocity);
        break;
    }
    case protocol::server::Packet::PRECHUNK: {
        protocol::server::packet::PreChunk prechunk;
        owner.proto.read(prechunk);
        break;
    }
    case protocol::server::Packet::PLAYERPOSDIR: {
        protocol::server::packet::PlayerPosDir playerposdir;
        owner.proto.read(playerposdir);
        break;
    }
    case protocol::server::Packet::ITEMSPAWN: {
        protocol::server::packet::ItemSpawn itemSpawn;
        owner.proto.read(itemSpawn);
        break;
    }
    case protocol::server::Packet::GAMESTATE: {
        protocol::server::packet::GameState gameState;
        owner.proto.read(gameState);
        break;
    }
    case protocol::server::Packet::ABILITIES: {
        protocol::server::packet::Abilities abilities;
        owner.proto.read(abilities);
        break;
    }
    case protocol::server::Packet::PLAYERLISTITEM: {
        protocol::server::packet::PlayerListItem playerListItem;
        owner.proto.read(playerListItem);
        break;
    }
    default:
        throw exception::Protocol("Unrecognized Packet Type");
    }
}
void Loading::Exit(t_owner & owner) const {

}
}
}
}
}
}
