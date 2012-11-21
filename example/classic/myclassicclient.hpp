/*
 * myclassicclient.hpp
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

#ifndef MYCLASSICCLIENT_HPP
#define MYCLASSICCLIENT_HPP

#include <libminecraft/classic/client.hpp>

#include "command.hpp"

using namespace libminecraft;
using namespace libminecraft::classic;

namespace command {
class Cuboid;
}

class MyClassicClient : private Client {
    friend class command::Cuboid;

public:
    MyClassicClient(Session & session);

    // The current action
    Command * action;

    /*
     * "You" Functions
     */

    // You enter a new world.
    // Note: You don't yet have a position.  Wait until ClientSpawn().
    void onClientWorldEnter();

    // You spawn in the world.
    void onClientSpawn();

    // Your op status is updated.
    // Old playertype provided for convenience.
    void onClientOp(player::Local::t_optype old_op_status);

    // You are teleported.
    // Old position and old direction provided for convenience.
    void onClientTeleport(const map::Point & old_pos, Player::t_yaw old_yaw, Player::t_pitch old_pitch);

    // You are leaving the world.
    // Note: The world will be destroyed after execution of this function.
    void onClientWorldExit();

    // You are being kicked from the server.
    // Note: The world will be destroyed after execution of this function.
    void onClientKick(const std::string & reason);

    /*
     * Global Functions
     */

    // A block is updated on the map
    void onBlockUpdate(const map::Cell & cell, map::Block::Type type, map::Block::Type old_type);

    // When an message is received.
    // Note: You can do player lookup manually based on the id if you so choose.
    //       Also consider parsing for a [name:] field, since 90% of opensource
    //       servers fail at setting the sending player's id properly.
    void onMessage(Player::t_id id, const std::string & message);

    /* Because some of the opensource servers out there are actually so bad
       that we actually can't depend on using the id to provide the correct sender.
       Use previous function instead */
    // virtual void onPlayerMessage(const Player & player, std::string message);

    // A recurring update takes place.
    // These take place only while you are still in a game world.  They stop when exiting the world.
    // Can be used for anything from rendering to movement to concurrent work.
    //
    // TODO: Add time since last update
    //
    void onTick();

    /*
     * Other Player Functions
     */

    // Another player spawns
    void onPlayerSpawn(const Player & player);

    // Another player looks
    // Old direction provided for convenience.
    void onPlayerLook(const Player & player, Player::t_yaw delta_yaw, Player::t_pitch delta_pitch);

    // Another player moves
    // Deltas provided for convenience.
    void onPlayerMove(const Player & player, const map::Point & delta_pos);

    // Another player moves and looks
    // Deltas and old direction provided for convenience.
    void onPlayerMoveAndLook(const Player & player, const map::Point & delta_pos, Player::t_yaw delta_yaw, Player::t_pitch delta_pitch);

    // Another player teleports.
    // Old position and old direction provided for convenience.
    void onPlayerTeleport(const Player & player, const map::Point & old_pos, Player::t_yaw old_yaw, Player::t_pitch old_pitch);

    // Another player despawns
    void onPlayerDespawn(const Player & player);

    /*
     * Error Functions
     */

    void onError(const libminecraft::Exception & ex);

    void onWarning(const char * reason);

    void onPlayerMessage(const Player & player, std::string message);

    void processCommand(const std::string & message);

    void startAction(Command * action);

    void stopAction();

private:
    MyClassicClient(const MyClassicClient &);

    typedef std::map<std::string, Command * ( *)(std::istream &)> t_commandMap;
    static const t_commandMap commandMap;
};

#endif // MYCLASSICCLIENT_HPP
