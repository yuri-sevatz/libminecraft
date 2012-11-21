/*
 * client.hpp
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

#ifndef LIBMINECRAFT_CLASSIC_CLIENT_HPP
#define LIBMINECRAFT_CLASSIC_CLIENT_HPP

#include "session.hpp"

#include "game/world.hpp"
#include "game/player/local.hpp"
#include "game/map.hpp"
#include "game/map/cell.hpp"

#include "../shared/exception/login.hpp"
#include "../shared/exception/map.hpp"
#include "../shared/exception/network.hpp"
#include "../shared/exception/protocol.hpp"

#include <string>

namespace libminecraft {
namespace classic {
using namespace game;

// The main client interface.  Implement this to respond to events in the minecraft world.
class Client {

    /*
     * Local Variables
     */
private:
    // The pointer to the session object.
    // This allows our client interaction abstraction, so that it can become an "actor" and a listener to any session interface.
    Session & _session;
public:
    // Yourself
    const player::Local & self;

    // Your world
    const game::World & world;

    // Information pertaining to the server.
    const session::Info & server;

    /*
     * Constructors
     */

protected:
    // Build your event handler around a session,
    // so that it can respond to events.
    Client(Session & session);
private:
    Client(); // Disabled default constructor

    /*
     * "You" Functions
     */

public:
    // You enter a new world.
    // Note: You don't yet have a position.  Wait until ClientSpawn().
    virtual void onClientWorldEnter() = 0;

    // You spawn in the world.
    virtual void onClientSpawn() = 0;

    // Your op status is updated.
    virtual void onClientOp(player::Local::t_optype old) = 0;

    // You are teleported.
    // Old position and old direction provided for convenience.
    virtual void onClientTeleport(const map::Point & old_pos, Player::t_yaw old_yaw, Player::t_pitch old_pitch) = 0;

    // You are leaving the world.
    // Note: The world will be destroyed after execution of this function.
    virtual void onClientWorldExit() = 0;

    // You are being kicked from the server.
    // Note: The world will be destroyed after execution of this function.
    virtual void onClientKick(const std::string & reason) = 0;

    /*
     * Global Functions
     */

    // A block is updated on the map
    virtual void onBlockUpdate(const map::Cell & cell, map::Block::Type type, map::Block::Type old_type) = 0;

    // When an message is received.
    // Note: You can do player lookup manually based on the id if you so choose.
    //       Also consider parsing for a [name:] field, since 90% of opensource
    //       servers fail at setting the sending player's id properly.
    virtual void onMessage(Player::t_id id, const MCTypes::String64 & message) = 0;

    /* Because some of the opensource servers out there are actually so bad
       that we actually can't depend on using the id to provide the correct sender.
       Use previous function instead */
    // virtual void onPlayerMessage(const Player & player, std::string message) = 0;

    // A recurring update takes place.
    // These take place only while you are still in a game world.  They stop when exiting the world.
    // Can be used for anything from rendering to movement to concurrent work.
    //
    // TODO: Add time since last update
    //
    virtual void onTick() = 0;

    /*
     * Other Player Functions
     */

    // Another player spawns
    virtual void onPlayerSpawn(const Player & player) = 0;

    // Another player looks
    // Old direction provided for convenience.
    virtual void onPlayerLook(const Player & player, Player::t_yaw delta_yaw, Player::t_pitch delta_pitch) = 0;

    // Another player moves
    // Deltas provided for convenience.
    virtual void onPlayerMove(const Player & player, const map::Point & delta_pos) = 0;

    // Another player moves and looks
    // Deltas and old direction provided for convenience.
    virtual void onPlayerMoveAndLook(const Player & player, const map::Point & delta_pos, Player::t_yaw delta_yaw, Player::t_pitch delta_pitch) = 0;

    // Another player teleports.
    // Old position and old direction provided for convenience.
    virtual void onPlayerTeleport(const Player & player, const map::Point & old_pos, Player::t_yaw old_yaw, Player::t_pitch old_pitch) = 0;

    // Another player despawns
    virtual void onPlayerDespawn(const Player & player) = 0;

    /*
     * Error Functions
     */

    /**
      * An error occurs while libminecraft is running
      *
      * Types of errors:
      *     -Login:     When you have not been authorized to login.  This can only occur between worlds.
      *                 Possible reasons include invalid login credentials and incomplete 3rd party verification.
      *                 Note: You will never receive this error while your client is in a game World.
      *
      *     -Map:       The map was compressed or transferred incorrectly.  This can only occur between worlds.
      *                 Note: You will never receive this error while your client is in a game World.
      *
      *     -Network:   Connection is terminated for unknown network-related reasons.  This can occur at any time.
      *
      *     -Protocol:  Error in the minecraft protocol communicated by the server occurs.  Can occur at any time.
      *
      * *CAUTION*:  The world will be deallocated after completion of this function, and control will return to
      *             the session's owner.
      */
    virtual void onError(const libminecraft::Exception & ex) = 0;

    /**
      * A warning has occured.
      *
      * This is provided for diagnostic purposes.  The reason for the warning is provided.
      * Usually this is due to non-standard server protocol/logic/state implementation.
      */
    virtual void onWarning(const char * reason) = 0;

public:
    // Enable game world ticks
    void enableTicks();

    // Disable game world ticks
    void disableTicks();

    // Set a block.
    void setBlock(const map::Cell & cell, map::Block::Type type);

    // Clear a block.
    void clearBlock(const map::Cell & cell);

    // Move.
    void move(const map::Point & position);

    // Look.
    void look(Player::t_pitch pitch, Player::t_yaw yaw);

    // Move and look.
    void moveAndLook(const map::Point & p, Player::t_pitch pitch, Player::t_yaw yaw);

    // Send a message.
    void sendMessage(const std::string & message);

    // Terminate the connetion.
    // XXX: Disabled until internal threading/socketing design is reevaluated under various use cases.
    //void disconnect();
};

inline void Client::enableTicks() {
    return _session.enableTicks();
}

inline void Client::disableTicks() {
    return _session.disableTicks();
}

inline void Client::setBlock(const map::Cell & cell, map::Block::Type type) {
    return _session.setBlock(cell, type);
}

inline void Client::clearBlock(const map::Cell & cell) {
    return _session.clearBlock(cell);
}

inline void Client::move(const map::Point & pos) {
    return _session.move(pos);
}

inline void Client::moveAndLook(const map::Point & pos, Player::t_pitch pitch, Player::t_yaw yaw) {
    return _session.moveAndLook(pos, pitch, yaw);
}

inline void Client::look(Player::t_pitch pitch, Player::t_yaw yaw) {
    return _session.look(pitch, yaw);
}

inline void Client::sendMessage(const std::string & message) {
    return _session.sendMessage(message);
}

/*
inline void Client::disconnect()
{
    return _session.disconnect();
}
*/
}
}

#endif // LIBMINECRAFT_CLASSIC_CLIENT_HPP
