/*
 * cligame.cpp
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

#include "cligame.hpp"

#include "../clientstatemachine.hpp"
#include "../../../session/remotesession.hpp"
#include "../../../interfaces/clienteventhandler.hpp"

#include "../../protocol/server/serverpingpkt.hpp"
#include "../../protocol/server/serverlevelbeginpkt.hpp"
#include "../../protocol/server/servermessagepkt.hpp"
#include "../../protocol/server/serverplayerdespawnpkt.hpp"
#include "../../protocol/server/serverplayerdisconnectpkt.hpp"
#include "../../protocol/server/serverplayerdirpkt.hpp"
#include "../../protocol/server/serverplayeroppkt.hpp"
#include "../../protocol/server/serverplayerposdirpkt.hpp"
#include "../../protocol/server/serverplayerpospkt.hpp"
#include "../../protocol/server/serverplayerspawnpkt.hpp"
#include "../../protocol/server/serverplayerteleportpkt.hpp"
#include "../../protocol/server/serversetblockpkt.hpp"

#include "../../minecraftworld.hpp"

#include "../../../utils/mcstring.hpp"

namespace libminecraft
{
    CliGame::CliGame()
    {
    }

    void CliGame::Enter(t_owner &owner) const
    {
        // Notify the client.
        owner.session.listener->onClientWorldEnter();
    }
    void CliGame::Update(t_owner &owner) const
    {
        // Read the next packet...
        // TODO: Replace with the stack instead of the heap (faster).
        // XXX: Memory leak in the event throwing an Exception in interface functions.
        ServerPkt * const packet = owner.session.proto.Read();

        // TODO: Replace with a map.
        switch(packet->type)
        {
        case ServerPkt::PING:
            // A ping packet expects a position/orientation update.
            // We can do this with the actor.
            owner.session.move(owner.session.world.player.x, owner.session.world.player.y, owner.session.world.player.z);
            break;
        case ServerPkt::POS:
        {
            ServerPlayerPosPkt * const pos = (ServerPlayerPosPkt * const) packet;

            Player * const plr = owner.session._world.getPlayer(pos->player_id);

            if (plr != NULL)
            {
                plr->x += pos->delta_x;
                plr->y += pos->delta_y;
                plr->z += pos->delta_z;

                owner.session.listener->onPlayerMove(*plr, pos->delta_x, pos->delta_y, pos->delta_z);
            }
            else
                owner.session.listener->onProtocolWarning("Unknown player id used in move packet");
        }
            break;
        case ServerPkt::POSDIR:
        {
            ServerPlayerPosDirPkt * const posdir = (ServerPlayerPosDirPkt * const) packet;

            Player * const plr = owner.session._world.getPlayer(posdir->player_id);

            if (plr != NULL)
            {
                plr->x += posdir->delta_x;
                plr->y += posdir->delta_y;
                plr->z += posdir->delta_z;
                Player::t_pitch delta_pitch = posdir->pitch - plr->pitch;
                Player::t_yaw delta_yaw = posdir->yaw - plr->yaw;
                plr->pitch = posdir->pitch;
                plr->yaw = posdir->yaw;

                owner.session.listener->onPlayerMoveAndLook(
                        *plr,
                        posdir->delta_x,
                        posdir->delta_y,
                        posdir->delta_z,
                        delta_pitch,
                        delta_yaw);
            }
            else
                owner.session.listener->onProtocolWarning("Unknown player id used in move-look packet");
        }
            break;
        case ServerPkt::DIR:
        {
            ServerPlayerDirPkt * const dir = (ServerPlayerDirPkt * const) packet;

            Player * const plr = owner.session._world.getPlayer(dir->player_id);

            if (plr != NULL)
            {
                Player::t_pitch delta_pitch = dir->pitch - plr->pitch;
                Player::t_yaw delta_yaw = dir->yaw - plr->yaw;

                plr->pitch = dir->pitch;
                plr->yaw = dir->yaw;

                owner.session.listener->onPlayerLook(*plr, delta_pitch, delta_yaw);
            }
            else
                owner.session.listener->onProtocolWarning("Unknown player id used in look packet");
        }
            break;
        case ServerPkt::BLOCK:
        {
            ServerSetBlockPkt * const blockpkt = (ServerSetBlockPkt * const) packet;
            // Check the x, y, and z ccordinates:
            if (blockpkt->x < 0 ||
                blockpkt->y < 0 ||
                blockpkt->z < 0 ||
                blockpkt->x >= owner.session._world.map.x_blocks ||
                blockpkt->y >= owner.session._world.map.y_blocks ||
                blockpkt->z >= owner.session._world.map.z_blocks)
            {
                owner.session.listener->onProtocolWarning("Invalid grid coordinates referenced during block update");
                break;
            }

            if (blockpkt->type > MapCell::OBSIDIAN)
            {
                owner.session.listener->onProtocolWarning("Invalid block type requested during block update");
                break;
            }
            owner.session._world.map.grid.at(blockpkt->x).at(blockpkt->y).at(blockpkt->z).type = MapCell::GetCellType(packet->type);
        }
            break;
        case ServerPkt::TELEPORT:
        {
            ServerPlayerTeleportPkt * const tele = (ServerPlayerTeleportPkt * const) packet;

            Player * plr;

            if (tele->player_id < 0)
                plr = &owner.session._world.player;
            else
            {
                plr = owner.session._world.getPlayer(tele->player_id);
                if (plr == NULL)
                {
                    owner.session.listener->onProtocolWarning("Unknown player id used in teleport packet");
                    break;
                }
            }

            Map::size_plot old_x = plr->x;
            Map::size_plot old_y = plr->y;
            Map::size_plot old_z = plr->z;
            Player::t_pitch old_pitch = plr->pitch;
            Player::t_yaw old_yaw = plr->yaw;

            plr->x = tele->x;
            plr->y = tele->y;
            plr->z = tele->z;
            plr->yaw = tele->yaw;
            plr->pitch = tele->pitch;

            if (tele->player_id < 0)
                owner.session.listener->onClientTeleport(old_x, old_y, old_z, old_pitch, old_yaw);
            else
                owner.session.listener->onPlayerTeleport(*plr, old_x, old_y, old_z, old_pitch, old_yaw);
        }
            break;
        case ServerPkt::MESSAGE:
        {
            ServerMessagePkt * const msgpkt = (ServerMessagePkt * const) packet;

            // Most opensource servers BUTCHERD this with multiworld.
            // We'll leave the lookup to the client.
            owner.session.listener->onMessage(msgpkt->player_id, msgpkt->message);
        }
            break;
        case ServerPkt::SPAWN:
        {
            ServerPlayerSpawnPkt * const spawnpkt = (ServerPlayerSpawnPkt * const) packet;

            Player plr;
            plr.id = spawnpkt->player_id;
            plr.name = MCString::plainMessage(spawnpkt->player_name);
            plr.x = spawnpkt->x;
            plr.y = spawnpkt->y;
            plr.z = spawnpkt->z;
            plr.yaw = spawnpkt->yaw;
            plr.pitch = spawnpkt->pitch;

            if (plr.name.length() != spawnpkt->player_name.length())
                owner.session.listener->onProtocolWarning("Spawned player name contained invalid characters - Fixed");

            // Self spawn.
            if (plr.id == 0xFF)
            {
                owner.session._world.player = plr;
                owner.session.listener->onClientSpawn();
            }
            else
            {
                if (owner.session._world.addPlayer(plr))
                    owner.session.listener->onPlayerSpawn(plr);
                else
                    owner.session.listener->onProtocolWarning("Attempted to spawn player that was already spawned");
            }
        }
            break;
        case ServerPkt::DESPAWN:
        {
            ServerPlayerDespawnPkt * const despawnpkt = (ServerPlayerDespawnPkt * const) packet;

            Player * const plr = owner.session._world.getPlayer(despawnpkt->player_id);

            if (plr != NULL)
            {
                owner.session.listener->onPlayerDespawn(*plr);
                owner.session._world.removePlayer(*plr);
            }
            else
                owner.session.listener->onProtocolWarning("Attempted to despawn a player that wasn't spawned");
        }
            break;

            // SERVERLEVELBEGINPKT.

            // DISCONNECT PACKE

        case ServerPkt::USEROP:
        {
            ServerPlayerOpPkt * const op = (ServerPlayerOpPkt * const) packet;

            MinecraftWorld::t_playertype old_playertype = owner.session._world.playertype;
            owner.session._world.playertype = op->type;

            owner.session.listener->onClientOp(old_playertype);
        }
            break;
        }


        delete packet;

    }
    void CliGame::Exit(t_owner &owner) const
    {
        owner.session.listener->onClientWorldExit();
    }
}
