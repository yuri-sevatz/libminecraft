/*
 * clientstatemachine.hpp
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

#ifndef LIBMINECRAFT_CLIENTSTATEMACHINE_HPP
#define LIBMINECRAFT_CLIENTSTATEMACHINE_HPP

#include "../../support/fsm/actionstatemachine.hpp"

// Include all the states...
#include "clistate.hpp"

#include "state/clidisconnected.hpp"
#include "state/cliconnecting.hpp"
#include "state/clinegotiating.hpp"
#include "state/cliloadingmap.hpp"
#include "state/cligame.hpp"

namespace libminecraft
{
    namespace classic
    {
        class RemoteSession;

        class ClientStateMachine : public ActionStateMachine<ClientStateMachine, const CliState>
        {
            // Forward-declare remote session.

        public:
            // Create a container for all states statically for const references.
            // This way, all the states have access to protected/private content.
            static const struct StatesDefs
            {
                CliDisconnected CLI_DISCONNECTED;
                CliConnecting CLI_CONNECTING;
                CliNegotiating CLI_NEGOTIATING;
                CliLoadingMap CLI_LOADINGMAP;
                CliGame CLI_GAME;
            } States;

            ClientStateMachine(RemoteSession & session);

            RemoteSession & session;
        };
    }
}

#endif // LIBMINECRAFT_CLIENTSTATEMACHINE_HPP
