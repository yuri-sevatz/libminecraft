/*
 * minecraftsession.cpp
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

#include "minecraftsession.hpp"

namespace libminecraft
{
    MinecraftSession::MinecraftSession(const std::string &hostname,
                                       const std::string &service) :
    // Connection attributes.
    stream(hostname, service),
    proto(stream),
    fsm(*this)
    {

    }

    void MinecraftSession::Connect(const std::string &username, const std::string &key)
    {
        this->username = username;
        this->key = key;

        fsm.ChangeState(ClientStateMachine::States.CLI_CONNECTING);

        // Enter the master loop...
        MasterLoop();
    }

    void MinecraftSession::MasterLoop()
    {
        while(true)
            fsm.Update();

        // XXX: Catch application exceptions - convert them into API events.
    }

    bool MinecraftSession::IsOp()
    {
        return is_op;
    }

}
