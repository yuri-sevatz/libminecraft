/*
 * myclassicclient.cpp
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

#include "myclassicclient.hpp"

#include <iostream>
#include <sstream>
#include <cstdlib>

#include <stdexcept>

#include <boost/assign/list_of.hpp>

#include <libminecraft/utils/mcstring.hpp>

#include "command/cuboid.hpp"

// Create the command map.
const MyClassicClient::t_commandMap MyClassicClient::commandMap =
    boost::assign::map_list_of
    (".cuboid", &command::Cuboid::fromStream);


MyClassicClient::MyClassicClient(Session & session) : Client(session),
    action(NULL) {

}

void MyClassicClient::onClientSpawn() {
    std::cout << "onClientSpawn()" << std::endl;
}


void MyClassicClient::onMessage(Player::t_id id, const std::string & message) {
    // Remove any silly opensource server color codes.
    // We won't trust the id, since most of them use the wrong one!
    std::string cleaned = MCString::plainMessage(message);

    std::cout << "onMessage(" << (int) id << ", " << cleaned << ")" << std::endl;

    size_t pos = cleaned.find(": ", 0);

    if (pos != std::string::npos) {
        const Player * player = world.getPlayer(cleaned.substr(0, pos));

        if (player && cleaned.length() > pos + 2)
            onPlayerMessage(*player, cleaned.substr(pos + 2, std::string::npos));
    }
}

void MyClassicClient::onPlayerMove(const Player & player, const map::Point & delta_pos) {
    std::cout << "onPlayerMove(" << player.name << ", " << player.position << ")" << std::endl;
}

void MyClassicClient::onPlayerLook(const Player & player, Player::t_yaw delta_yaw, Player::t_pitch delta_pitch) {
    std::cout << "onPlayerLook(" << player.name << ", " << (int) player.yaw << ", " << (int) player.pitch << ")" << std::endl;
}

void MyClassicClient::onPlayerSpawn(const Player & player) {
    std::cout << "onPlayerSpawn(" << player.name << ")" << std::endl;
}

void MyClassicClient::onPlayerDespawn(const Player & player) {
    std::cout << "onPlayerDespawn(" << player.name << ")" << std::endl;
}

void MyClassicClient::onPlayerTeleport(const Player & player, const map::Point & old_pos, Player::t_yaw old_yaw, Player::t_pitch old_pitch) {
    std::cout << "onPlayerTeleport(" << player.name << ", " << player.position << ", " << (int) player.yaw << ", " << (int) player.pitch << ")" << std::endl;
}

void MyClassicClient::onPlayerMoveAndLook(const Player & player, const map::Point & delta_pos, Player::t_yaw delta_yaw, Player::t_pitch delta_pitch) {
    std::cout << "onPlayerMoveAndLook(" << player.name << ", " << player.position << ", " << (int) player.yaw << ", " << (int) player.pitch << ")" << std::endl;
}

void MyClassicClient::onClientKick(const std::string & reason) {
    std::cout << "onClientKick: " << reason << std::endl;
}

void MyClassicClient::onError(const libminecraft::Exception & ex) {
    std::cout << "Error: " << ex.what() << std::endl;
}

void MyClassicClient::onWarning(const char * reason) {
    std::cout << "Warning: " << reason << std::endl;
}

void MyClassicClient::onClientOp(player::Local::t_optype old_playertype) {
    std::cout << "onClientOp: " << self.optype << std::endl;
}

void MyClassicClient::onBlockUpdate(const map::Cell & cell, map::Block::Type type, map::Block::Type old_type) {
    std::cout << "onBlockUpdate(" << cell << ")" << std::endl;
}

void MyClassicClient::onClientTeleport(const map::Point & old_pos, Player::t_yaw old_yaw, Player::t_pitch old_pitch) {
    std::cout << "onClientTeleport()" << std::endl;
}

void MyClassicClient::onClientWorldEnter() {
    std::cout << "onClientWorldEnter()" << std::endl;
}

void MyClassicClient::onClientWorldExit() {
    std::cout << "onClientWorldExit()" << std::endl;
}

void MyClassicClient::onPlayerMessage(const Player & player, std::string message) {
    if (message == ".yourpos")
        std::cerr << world.map.at(self.position).type << std::endl;
    else if (message == ".mypos")
        std::cerr << world.map.at(player.position).type << std::endl;

    processCommand(message);
}

void MyClassicClient::processCommand(const std::string & message) {
    std::cerr << "Checking for commands" << std::endl;

    for(t_commandMap::const_iterator iter = commandMap.begin(); iter != commandMap.end(); iter++) {
        if (message.compare(0, iter->first.length(), iter->first) == 0) {
            std::stringstream ss(message.substr(iter->first.length()), std::ios_base::in);

            std::cerr << "Starting Action..." << std::endl;
            startAction(iter->second(ss));
            if (action)
                std::cerr << iter->first << " command loaded" << std::endl;
            else
                std::cerr << iter->first << " command failed" << std::endl;
            return;
        }
    }
}

void MyClassicClient::startAction(Command * action) {
    std::cout << "Oh Hello" << std::endl;

    if (action) {
        std::cout << "I see" << std::endl;

        stopAction();

        std::cout << "That's very nice" << std::endl;

        this->action = action;
        enableTicks();
    }
}

void MyClassicClient::stopAction() {
    if (action) {
        std::cout << "You like cookies?" << std::endl;

        disableTicks();
        std::cout << "I like them too" << std::endl;
        delete action;
        std::cout << "I took one of yours" << std::endl;
        action = NULL;
    }





}

void MyClassicClient::onTick() {
    if (this->action)
        this->action->tick(*this);
}
