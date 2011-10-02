/*
 * ingame.cpp
 * This file is part of LibMinecraft.
 *
 * Created by Yuri Sevatz on 03/2011.
 * Copyright (c) 2011 Yuri Sevatz. All rights reserved
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

#include "ingame.hpp"

#include "../connection.hpp"
#include "../../remote.hpp"
#include "../../../client.hpp"

#include "../../../protocol/server/packet/ping.hpp"
#include "../../../protocol/server/packet/levelbegin.hpp"
#include "../../../protocol/server/packet/message.hpp"
#include "../../../protocol/server/packet/playerdespawn.hpp"
#include "../../../protocol/server/packet/disconnect.hpp"
#include "../../../protocol/server/packet/playerdir.hpp"
#include "../../../protocol/server/packet/playerop.hpp"
#include "../../../protocol/server/packet/playerposdir.hpp"
#include "../../../protocol/server/packet/playerpos.hpp"
#include "../../../protocol/server/packet/playerspawn.hpp"
#include "../../../protocol/server/packet/playerteleport.hpp"
#include "../../../protocol/server/packet/setblock.hpp"

#include "../../../game/world.hpp"

#include "../../../../utils/mcstring.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace session
        {
            namespace remote
            {
                namespace state
                {

                    // Configure a player's spawn from a spawn packet.
                    // Also notifies the owner's listener.
                    void InGame::configurePlayerFromSpawnPacket(t_owner &owner, game::Player & player, const protocol::server::packet::PlayerSpawn & spawnpkt)
                    {
                        player.id = spawnpkt.player_id;
                        player.name = MCString::plainMessage(spawnpkt.player_name);
                        player.x = spawnpkt.x;
                        player.y = spawnpkt.y;
                        player.z = spawnpkt.z;
                        player.pitch = spawnpkt.pitch;
                        player.yaw = spawnpkt.yaw;

                        if (player.name.length() != spawnpkt.player_name.length())
                            owner.session.listener().onProtocolWarning("Spawned player name contained invalid characters - Fixed");
                    }

                    InGame::InGame()
                    {
                    }

                    void InGame::Enter(t_owner &owner) const
                    {
                        // Notify the client.
                        owner.session.listener().onClientWorldEnter();
                    }
                    void InGame::Update(t_owner &owner) const
                    {
                        // Read the next packet...
                        // TODO: Replace with a map.
                        switch(owner.proto.next())
                        {
                        case protocol::server::Packet::PING:
                            {
                                protocol::server::packet::Ping pingpkt;
                                owner.proto.read(pingpkt);
                            }
                            break;
                        case protocol::server::Packet::POS:
                            {
                                protocol::server::packet::PlayerPos pos;
                                owner.proto.read(pos);

                                Player * const plr = owner._world.getPlayer(pos.player_id);

                                if (plr != NULL)
                                {
                                    plr->x += pos.delta_x;
                                    plr->y += pos.delta_y;
                                    plr->z += pos.delta_z;

                                    owner.session.listener().onPlayerMove(*plr, pos.delta_x, pos.delta_y, pos.delta_z);
                                }
                                else
                                    owner.session.listener().onProtocolWarning("Unknown player id used in move packet");
                            }
                            break;
                        case protocol::server::Packet::POSDIR:
                            {
                                protocol::server::packet::PlayerPosDir posdir;
                                owner.proto.read(posdir);

                                Player * const plr = owner._world.getPlayer(posdir.player_id);

                                if (plr != NULL)
                                {
                                    plr->x += posdir.delta_x;
                                    plr->y += posdir.delta_y;
                                    plr->z += posdir.delta_z;
                                    Player::t_pitch delta_pitch = posdir.pitch - plr->pitch;
                                    Player::t_yaw delta_yaw = posdir.yaw - plr->yaw;
                                    plr->pitch = posdir.pitch;
                                    plr->yaw = posdir.yaw;

                                    owner.session.listener().onPlayerMoveAndLook(
                                            *plr,
                                            posdir.delta_x,
                                            posdir.delta_y,
                                            posdir.delta_z,
                                            delta_pitch,
                                            delta_yaw);
                                }
                                else
                                    owner.session.listener().onProtocolWarning("Unknown player id used in move-look packet");
                            }
                            break;
                        case protocol::server::Packet::DIR:
                            {
                                protocol::server::packet::PlayerDir dir;
                                owner.proto.read(dir);

                                Player * const plr = owner._world.getPlayer(dir.player_id);

                                if (plr != NULL)
                                {
                                    Player::t_pitch delta_pitch = dir.pitch - plr->pitch;
                                    Player::t_yaw delta_yaw = dir.yaw - plr->yaw;

                                    plr->pitch = dir.pitch;
                                    plr->yaw = dir.yaw;

                                    owner.session.listener().onPlayerLook(*plr, delta_pitch, delta_yaw);
                                }
                                else
                                    owner.session.listener().onProtocolWarning("Unknown player id used in look packet");
                            }
                            break;
                        case protocol::server::Packet::BLOCK:
                            {
                                protocol::server::packet::SetBlock blockpkt;
                                owner.proto.read(blockpkt);
                                // Check the x, y, and z ccordinates:
                                if (blockpkt.x < 0 ||
                                    blockpkt.y < 0 ||
                                    blockpkt.z < 0 ||
                                    blockpkt.x >= owner._world.map.x_blocks ||
                                    blockpkt.y >= owner._world.map.y_blocks ||
                                    blockpkt.z >= owner._world.map.z_blocks)
                                {
                                    owner.session.listener().onProtocolWarning("Invalid grid coordinates referenced during block update");
                                    break;
                                }

                                if (blockpkt.type < map::Cell::BLANK || blockpkt.type > map::Cell::OBSIDIAN)
                                {
                                    owner.session.listener().onProtocolWarning("Invalid block type requested during block update");
                                    break;
                                }
                                map::Cell::BlockType old_type = owner._world.map.grid.at(blockpkt.x).at(blockpkt.y).at(blockpkt.z).type;
                                map::Cell::BlockType type = map::Cell::GetCellType(blockpkt.type);
                                owner._world.map.grid.at(blockpkt.x).at(blockpkt.y).at(blockpkt.z).type = type;

                                owner.session.listener().onBlockUpdate(type, old_type, blockpkt.x, blockpkt.y, blockpkt.z);
                            }
                            break;
                        case protocol::server::Packet::TELEPORT:
                            {
                                protocol::server::packet::PlayerTeleport tele;
                                owner.proto.read(tele);

                                Player * plr;

                                if (tele.player_id < 0)
                                    plr = &owner._self;
                                else
                                {
                                    plr = owner._world.getPlayer(tele.player_id);
                                    if (plr == NULL)
                                    {
                                        owner.session.listener().onProtocolWarning("Unknown player id used in teleport packet");
                                        break;
                                    }
                                }

                                Map::size_plot old_x = plr->x;
                                Map::size_plot old_y = plr->y;
                                Map::size_plot old_z = plr->z;
                                Player::t_pitch old_pitch = plr->pitch;
                                Player::t_yaw old_yaw = plr->yaw;

                                plr->x = tele.x;
                                plr->y = tele.y;
                                plr->z = tele.z;
                                plr->yaw = tele.yaw;
                                plr->pitch = tele.pitch;

                                if (tele.player_id < 0)
                                    owner.session.listener().onClientTeleport(old_x, old_y, old_z, old_pitch, old_yaw);
                                else
                                    owner.session.listener().onPlayerTeleport(*plr, old_x, old_y, old_z, old_pitch, old_yaw);
                            }
                            break;
                        case protocol::server::Packet::MESSAGE:
                            {
                                protocol::server::packet::Message msgpkt;
                                owner.proto.read(msgpkt);

                                // Most opensource servers BUTCHERD this with multiworld.
                                // We'll leave the lookup to the client.
                                owner.session.listener().onMessage(msgpkt.player_id, msgpkt.message);
                            }
                            break;
                        case protocol::server::Packet::SPAWN:
                            {
                                protocol::server::packet::PlayerSpawn spawnpkt;
                                owner.proto.read(spawnpkt);

                                if (spawnpkt.player_id == -1)
                                {
                                    configurePlayerFromSpawnPacket(owner, owner._self, spawnpkt);
                                    owner.session.listener().onClientSpawn();
                                }
                                else
                                {
                                    Player entity;
                                    configurePlayerFromSpawnPacket(owner, entity, spawnpkt);

                                    // Omit the player if it is already in the entity database.
                                    Player * const addedPlayer = owner._world.addPlayer(entity);
                                    if (!addedPlayer)
                                    {
                                        owner.session.listener().onProtocolWarning("Attempted to spawn player that was already spawned");
                                        break;
                                    }
                                    owner.session.listener().onPlayerSpawn(*addedPlayer);
                                }
                            }
                            break;
                        case protocol::server::Packet::DESPAWN:
                            {
                                protocol::server::packet::PlayerDespawn despawnpkt;
                                owner.proto.read(despawnpkt);

                                Player * const plr = owner._world.getPlayer(despawnpkt.player_id);

                                if (plr != NULL)
                                {
                                    owner.session.listener().onPlayerDespawn(*plr);
                                    owner._world.removePlayer(*plr);
                                }
                                else
                                    owner.session.listener().onProtocolWarning("Attempted to despawn a player that wasn't spawned");
                            }
                            break;

                            // SERVERLEVELBEGINPKT.

                        case protocol::server::Packet::DISCONNECT:
                            {
                                protocol::server::packet::Disconnect kconn;
                                owner.proto.read(kconn);

                                owner.session.listener().onClientKick(kconn.reason);
                            }
                            break;
                        case protocol::server::Packet::USEROP:
                            {
                                protocol::server::packet::PlayerOp op;
                                owner.proto.read(op);

                                player::Local::t_optype old_optype = owner._self.optype;
                                owner._self.optype = op.type;

                                owner.session.listener().onClientOp(old_optype);
                            }
                            break;
                        }
                    }
                    void InGame::Exit(t_owner &owner) const
                    {
                        owner.session.listener().onClientWorldExit();
                    }
                }
            }
        }
    }
}
