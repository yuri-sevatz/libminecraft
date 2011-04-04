/*
 * myminecraftclient.cpp
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

#include "myminecraftclient.hpp"

#include <iostream>
#include <sstream>

#include <libminecraft/utils/mcstring.hpp>


MyMinecraftClient::MyMinecraftClient(MinecraftSession & session) : ClientEventHandler(session)
{
    followtarget = NULL;
}

void MyMinecraftClient::onClientSpawn()
{
    std::cout << "onClientSpawn()" << std::endl;
}


void MyMinecraftClient::onMessage(Player::t_id id, const std::string & message)
{
    std::cout << "onMessage(" << (unsigned int) id << ", " << message << ")" << std::endl;

    // Remove any silly opensource server color codes.
    // We won't trust the id, since most of them use the wrong one!
    std::string cleaned = MCString::plainMessage(message);

    size_t pos = cleaned.find(": ", 0);

    if (pos != std::string::npos)
    {
        const Player * player = self.world.getPlayer(cleaned.substr(0, pos));
        if (player && cleaned.length() > pos + 2)
            onPlayerMessage(*player, cleaned.substr(pos + 2, std::string::npos));
    }
}

void MyMinecraftClient::onPlayerMove(const Player & player, Map::size_plot delta_x, Map::size_plot delta_y, Map::size_plot delta_z)
{
    if (followtarget != NULL && &player == followtarget)
    {
        self.move(self.world.player.x + delta_x, self.world.player.y + delta_y, self.world.player.z + delta_z);
    }
}

void MyMinecraftClient::onPlayerLook(const Player & player, Player::t_yaw delta_yaw, Player::t_pitch delta_pitch) { }

void MyMinecraftClient::onPlayerSpawn(const Player & player)
{
    std::cout << "onPlayerSpawn(" << player.name << ")" << std::endl;
}

void MyMinecraftClient::onPlayerDespawn(const Player & player)
{
    std::cout << "onPlayerDespawn(" << player.name << ")" << std::endl;
}

void MyMinecraftClient::onPlayerTeleport(const Player & player, Map::size_plot old_x, Map::size_plot old_y, Map::size_plot old_z, Player::t_yaw old_yaw, Player::t_pitch old_pitch)
{
    if (followtarget != NULL && &player == followtarget)
        onPlayerMove(player, player.x - old_x, player.y - old_y, player.z - old_z);
}

void MyMinecraftClient::onPlayerMoveAndLook(const Player & player, Map::size_plot delta_x, Map::size_plot delta_y, Map::size_plot delta_z, Player::t_yaw delta_yaw, Player::t_pitch deltas_pitch)
{
    // We'll just forward the message to our implementation.
    onPlayerMove(player, delta_x, delta_y, delta_z);
}

void MyMinecraftClient::onClientKick(const std::string & reason)
{
    std::cout << "onClientKick: " << reason << std::endl;
}

void MyMinecraftClient::onNetworkError(const char * reason)
{
    std::cout << "NetworkError: " << reason << std::endl;
}

void MyMinecraftClient::onProtocolError(const char * reason)
{
    std::cout << "ProtocolError: " << reason << std::endl;
}

void MyMinecraftClient::onProtocolWarning(const char * reason)
{
    std::cout << "ProtocolWarning: " << reason << std::endl;
}

void MyMinecraftClient::onLoginError(const char * reason)
{
    std::cout << "LoginError: " << reason << std::endl;
}

void MyMinecraftClient::onClientOp(MinecraftWorld::t_playertype old_playertype)
{
    std::cout << "onClientOp: " << self.world.playertype << std::endl;
}

void MyMinecraftClient::onBlockUpdate(MapCell::BlockType type, MapCell::BlockType old_type, Map::size_block x, Map::size_block y, Map::size_block z)
{
    std::cout << "onBlockUpdate(" << x << "," << y << "," << z << ")" << std::endl;
}

void MyMinecraftClient::onClientTeleport(Map::size_plot old_x, Map::size_plot old_y, Map::size_plot old_z, Player::t_yaw old_yaw, Player::t_pitch old_pitch)
{
    std::cout << "onClientTeleport()" << std::endl;
}

void MyMinecraftClient::onClientWorldEnter()
{
    std::cout << "onClientWorldEnter()" << std::endl;
}

void MyMinecraftClient::onClientWorldExit()
{
    std::cout << "onClientWorldExit()" << std::endl;
}

void MyMinecraftClient::onPlayerMessage(const Player & player, std::string message)
{
    processCommand(player, message);
}

void MyMinecraftClient::processCommand(const Player & player, const std::string & message)
{
    if (message == ".pos")
    {
        std::stringstream ret;

        ret << "(" << self.world.player.x << ","
                << (self.world.player.y - Map::EYE_HEIGHT) << ","
                << self.world.player.z << ")";

        std::cout << ret.str() << std::endl;

        self.sendMessage(ret.str());
    }
    else if (message == ".mypos")
    {
        std::stringstream ret;

        ret << "(" << player.x << ","
                << (player.y - Map::EYE_HEIGHT) << ","
                << player.z << ")";

        std::cout << ret.str() << std::endl;

        self.sendMessage(ret.str());
    }
    else if (message == ".followme")
    {
        followtarget = &player;
    }
    else if (message == ".stop")
    {
        followtarget = NULL;
    }
    else if (message == ".exorcist")
    {
        //self.sendMessage("I am the exorcist - watch me turn my head upside down.");
        self.look(Player::PITCH_INVERT, self.world.player.yaw);
    }
    else if (message == ".lookfront")
    {
        self.look(Player::PITCH_NORMAL, self.world.player.yaw);
    }
    else if (message == ".looksky")
    {
        self.look(Player::PITCH_UP, self.world.player.yaw);
    }
    else if (message == ".lookfeet")
    {
        self.look(Player::PITCH_DOWN, self.world.player.yaw);
    }
    else if (message == ".lookeast")
    {
        self.look(self.world.player.pitch, Player::YAW_EAST);
    }
    else if (message == ".lookwest")
    {
        self.look(self.world.player.pitch, Player::YAW_WEST);
    }
    else if (message == ".looknorth")
    {
        self.look(self.world.player.pitch, Player::YAW_NORTH);
    }
    else if (message == ".looksouth")
    {
        self.look(self.world.player.pitch, Player::YAW_SOUTH);
    }
    else if (message.substr(0, 9) == ".message ")
    {
        self.sendMessage(message.substr(9, std::string::npos));
    }
    else if (message == ".findme")
    {
        std::stringstream ret;

        ret << "Moving to: (" << player.x << ","
                << (player.y - Map::EYE_HEIGHT) << ","
                << player.z << ")";

        std::cout << ret.str() << std::endl;

        //self.sendMessage(ret.str());

        self.move(player.x, player.y, player.z);
    }
    else if (message == ".flagme")
    {
        std::stringstream ret;

        Map::size_block x = Map::toBlock(player.x);
        Map::size_block y = Map::toBlock(player.y - Map::EYE_HEIGHT) - 1;
        Map::size_block z = Map::toBlock(player.z);

        if (!self.world.map.isValidBlock(x, y, z))
            return;

        ret << "Flagging: (" << x << ","
                << y << ","
                << z << ")";

        std::cout << ret.str() << std::endl;

        self.sendMessage(ret.str());

        self.move(player.x, player.y, player.z);

        const MapCell::BlockType t_type = self.world.map.grid[x][y][z].type;

        if (t_type != MapCell::BLANK && t_type != MapCell::WATER && t_type != MapCell::LAVA)
        {
            std::cout << "(Cleared)" << std::endl;
            self.clearBlock(x, y, z);
        }

        self.setBlock(x, y, z, MapCell::BRICK);
    }
    else if (message == ".mapinfo")
    {
        std::stringstream ret;

        ret << "Blocks: (" << self.world.map.x_blocks << ","
                << self.world.map.y_blocks << ","
                << self.world.map.z_blocks << ")";

        std::cout << ret.str() << std::endl;
        self.sendMessage(ret.str());
        ret.flush();
        ret << "Plot: (" << self.world.map.x_plot << ","
                << self.world.map.y_plot << ","
                << self.world.map.z_plot << ")";

    }
    else if (message == ".exit")
    {
        self.disconnect();
    }
}
