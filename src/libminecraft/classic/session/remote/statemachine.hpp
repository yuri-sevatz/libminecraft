/*
 * statemachine.hpp
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

#ifndef LIBMINECRAFT_CLASSIC_SESSION_REMOTE_STATEMACHINE_HPP
#define LIBMINECRAFT_CLASSIC_SESSION_REMOTE_STATEMACHINE_HPP

#include "../../../support/fsm/actionstatemachine.hpp"

#include "state.hpp"

// Include all the states...
#include "state/connecting.hpp"
#include "state/disconnected.hpp"
#include "state/ingame.hpp"
#include "state/loadingmap.hpp"
#include "state/negotiating.hpp"

namespace libminecraft
{
    namespace classic
    {
        namespace session
        {
            // Forward-declare remote session.
            class Remote;
            
            namespace remote
            {
                class StateMachine : public ActionStateMachine<StateMachine, const State>
                {
                public:
                    // Create a container for all states statically for const references.
                    // This way, all the states have access to protected/private content.
                    static const struct StatesDefs
                    {
                        state::Disconnected DISCONNECTED;
                        state::Connecting CONNECTING;
                        state::Negotiating NEGOTIATING;
                        state::LoadingMap LOADINGMAP;
                        state::InGame INGAME;
                    } States;

                    StateMachine(Remote & session);

                    Remote & session;
                };
            }
        }
    }
}

#endif // LIBMINECRAFT_CLASSIC_SESSION_REMOTE_STATEMACHINE_HPP
