/*
 * remotesession.cpp
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


#include "remotesession.hpp"

#include "../interfaces/clienteventhandler.hpp"

#include "../core/protocol/minecraftstream.hpp"
#include "../core/protocol/client/clientmessagepkt.hpp"
#include "../core/protocol/client/clientposdirpkt.hpp"
#include "../core/protocol/client/clientsetblockpkt.hpp"

namespace libminecraft
{
    RemoteSession::RemoteSession(const std::string &hostname,
                                 const std::string &service) : MinecraftSession(_world),
    // Connection attributes.
    stream(hostname, service),
    proto(stream),
    fsm(*this),
    gz_data(std::ios_base::out | std::ios_base::in | std::ios_base::binary)
    {

    }

    void RemoteSession::connect(const std::string &username, const std::string &key)
    {
        this->username = username;
        this->key = key;

        fsm.ChangeState(ClientStateMachine::States.CLI_CONNECTING);

        // Enter the master loop...
        loop();
    }

    void RemoteSession::loop()
    {
        try
        {
            while(true)
                fsm.Update();
        }
        catch (MinecraftException ex)
        {
            listener->onNetworkError(ex.message);
            disconnect(); // Kill the game.
        }
    }

    void RemoteSession::disconnect()
    {
        fsm.ChangeState(ClientStateMachine::States.CLI_DISCONNECTED);
    }

    void RemoteSession::look(Player::t_pitch pitch, Player::t_yaw yaw)
    {
        moveAndLook(_world.player.x, _world.player.y, _world.player.z, pitch, yaw);
    }

    void RemoteSession::move(Map::size_plot x, Map::size_plot y, Map::size_plot z)
    {
        moveAndLook(x, y, z, _world.player.pitch, _world.player.yaw);
    }

    void RemoteSession::moveAndLook(Map::size_plot x, Map::size_plot y, Map::size_plot z, Player::t_pitch pitch, Player::t_yaw yaw)
    {
        _world.player.x = x;
        _world.player.y = y;
        _world.player.z = z;
        _world.player.pitch = pitch;
        _world.player.yaw = yaw;
        ClientPosDirPkt mvpkt;
        mvpkt.x = x;
        mvpkt.y = y;
        mvpkt.z = z;
        mvpkt.yaw = yaw;
        mvpkt.pitch = pitch;
        mvpkt.write(stream);
        mvpkt.write(stream);
        stream.flush();
    }

    void RemoteSession::sendMessage(const std::string & message)
    {
        for (size_t offset = 0; offset < message.length(); offset += MinecraftStream::M_STRING_LEN)
        {
            ClientMessagePkt msgpkt;
            msgpkt.message = message.substr(offset, 64);
            msgpkt.write(stream);
            stream.flush();
        }
    }

    void RemoteSession::setBlock(Map::size_block x, Map::size_block y, Map::size_block z, MapCell::BlockType type)
    {
        assert(world.map.isValidBlock(x, y, z));

        _world.map.grid[x][y][z].type = type;
        ClientSetBlockPkt blkpkt;
        blkpkt.x = x;
        blkpkt.y = y;
        blkpkt.z = z;
        blkpkt.mode = 0x01;
        blkpkt.type = type;
        blkpkt.write(stream);
        stream.flush();
    }

    void RemoteSession::clearBlock(Map::size_block x, Map::size_block y, Map::size_block z)
    {
        assert(world.map.isValidBlock(x, y, z));

        ClientSetBlockPkt blkpkt;
        blkpkt.x = x;
        blkpkt.y = y;
        blkpkt.z = z;
        blkpkt.mode = 0x00;
        blkpkt.type = MapCell::DIRT;
        blkpkt.write(stream);
        stream.flush();
    }
}
