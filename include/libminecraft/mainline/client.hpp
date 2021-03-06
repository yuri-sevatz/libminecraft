/*
 * client.hpp
 * This file is part of LibMinecraft.
 *
 * Created by Yuri Sevatz on 11/2011.
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

#ifndef LIBMINECRAFT_MAINLINE_CLIENT_HPP
#define LIBMINECRAFT_MAINLINE_CLIENT_HPP

#include <libminecraft/minecraft_export.h>

#include "session.hpp"
#include "game/player.hpp"

#include <string>

namespace libminecraft {
namespace mainline {
using namespace game;

// The main client interface.  Implement this to respond to events in the minecraft world.
class MINECRAFT_EXPORT Client {

    /*
     * Local Variables
     */
public:

    // Your self
    const game::Player & self;

    /*
    // Your world
    const game::World & world;

    // Information pertaining to the server.
    const session::Info & server;
    */

    /*
     * Constructors
     */

protected:
    // Build your event handler around a session,
    // so that it can respond to events.
    Client(Session & session);

    /*
     * "You" Functions
     */

public:
    /*
    // You enter a new world.
    // Note: You don't yet have a position.  Wait until ClientSpawn().
    virtual void onClientWorldEnter() = 0;

    // You spawn in the world.
    virtual void onClientSpawn() = 0;

    // You are teleported.
    // Old position and old direction provided for convenience.
    virtual void onClientTeleport(Map::size_plot old_x, Map::size_plot old_y, Map::size_plot old_z, Player::t_yaw old_yaw, Player::t_pitch old_pitch) = 0;

    // You are leaving the world.
    // Note: The world will be destroyed after execution of this function.
    virtual void onClientWorldExit() = 0;

    // You are being kicked from the server.
    // Note: The world will be destroyed after execution of this function.
    virtual void onClientKick(const std::string & reason) = 0;
    */

    /*
     * Global Functions
     */

    /*
    // A block is updated on the map
    virtual void onBlockUpdate(map::Cell::BlockType type, map::Cell::BlockType old_type, Map::size_block x, Map::size_block y, Map::size_block z) = 0;

    // When an message is received.
    // Note: You can do player lookup manually based on the id if you so choose.
    //       Also consider parsing for a [name:] field, since 90% of opensource
    //       servers fail at setting the sending player's id properly.
    virtual void onMessage(Player::t_id id, const std::string & message) = 0;

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
    // virtual void onTick() = 0;


    /*
     * Other Player Functions
     */
    /*
    // Another player spawns
    virtual void onPlayerSpawn(const Player & player) = 0;

    // Another player looks
    // Old direction provided for convenience.
    virtual void onPlayerLook(const Player & player, Player::t_yaw delta_yaw, Player::t_pitch delta_pitch) = 0;

    // Another player moves
    // Deltas provided for convenience.
    virtual void onPlayerMove(const Player & player, Map::size_plot delta_x, Map::size_plot delta_y, Map::size_plot delta_z) = 0;

    // Another player moves and looks
    // Deltas and old direction provided for convenience.
    virtual void onPlayerMoveAndLook(const Player & player, Map::size_plot delta_x, Map::size_plot delta_y, Map::size_plot delta_z, Player::t_yaw delta_yaw, Player::t_pitch deltas_pitch) = 0;

    // Another player teleports.
    // Old position and old direction provided for convenience.
    virtual void onPlayerTeleport(const Player & player, Map::size_plot old_x, Map::size_plot old_y, Map::size_plot old_z, Player::t_yaw old_yaw, Player::t_pitch old_pitch) = 0;

    // Another player despawns
    virtual void onPlayerDespawn(const Player & player) = 0;
    */

    /*
     * Error Functions
     */

    // When the network connection is terminated for unknown reasons.
    // This can occur at any time.
    // Note: The world will be destroyed after execution of this function.
    virtual void onNetworkError(const char * reason) = 0;

    // When an error in the protocol communicated by the server occurs
    // This can occur at any time - usually due to updates or improper client/server protocol.
    // Note: The world will be destroyed after execution of this function.
    virtual void onProtocolError(const char * reason) = 0;

    // When a login error occues.
    // This will only occur when first connecting to a server,
    // possibly due to invalid login credentials.
    virtual void onLoginError(const char * reason) = 0;

    // When a warning is provided.
    // This can occur at any time.  The explanation for the warning is provided.
    // Usually this is due to opensource server software incorrect implementation.
    virtual void onProtocolWarning(const char * reason) = 0;

protected:
    /*
    // Enable game world ticks
    void enableTicks();

    // Disable game world ticks
    void disableTicks();

    // Set a block.
    void setBlock(Map::size_block x, Map::size_block y, Map::size_block z, map::Cell::BlockType type);

    // Clear a block.
    void clearBlock(Map::size_block x, Map::size_block y, Map::size_block z);

    // Move.
    void move(Map::size_plot x, Map::size_plot y, Map::size_plot z);

    // Look.
    void look(Player::t_pitch pitch, Player::t_yaw yaw);

    // Move and look.
    void moveAndLook(Map::size_plot x, Map::size_plot y, Map::size_plot z, Player::t_pitch pitch, Player::t_yaw yaw);

    // Send a message.
    void sendMessage(const std::string & message);

    // Terminate the connetion.
    // XXX: Disabled until internal threading/socketing design is reevaluated under various use cases.
    //void disconnect();
    */

private:
    Client(); // Disabled default constructor

    // The pointer to the session object.
    // This allows our client interaction abstraction, so that it can become an "actor" and a listener to any session interface.
    Session & _session;
};

/*
inline void Client::enableTicks()
{
    return _session.enableTicks();
}

inline void Client::disableTicks()
{
    return _session.disableTicks();
}

inline void Client::setBlock(Map::size_block x, Map::size_block y, Map::size_block z, map::Cell::BlockType type)
{
    return _session.setBlock(x, y, z, type);
}

inline void Client::clearBlock(Map::size_block x, Map::size_block y, Map::size_block z)
{
    return _session.clearBlock(x, y, z);
}

inline void Client::move(Map::size_plot x, Map::size_plot y, Map::size_plot z)
{
    return _session.move(x, y, z);
}

inline void Client::look(Player::t_pitch pitch, Player::t_yaw yaw)
{
    return _session.look(pitch, yaw);
}

inline void Client::sendMessage(const std::string & message)
{
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

#endif // LIBMINECRAFT_MAINLINE_CLIENT_HPP
