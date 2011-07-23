/*
 * ingame.hpp
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

#ifndef LIBMINECRAFT_CLASSIC_SESSION_REMOTE_STATE_INGAME_HPP
#define LIBMINECRAFT_CLASSIC_SESSION_REMOTE_STATE_INGAME_HPP

#include "../state.hpp"

namespace libminecraft
{
    namespace classic
    {
        // Forward-declare classes for private methods.
        namespace game { class Player; }
        namespace protocol { namespace server { namespace packet { class PlayerSpawn; } } }

        namespace session
        {
            namespace remote
            {
                namespace state
                {
                    class InGame : public State
                    {
                    public:
                        InGame();
                        virtual void Enter(t_owner &owner) const;
                        virtual void Update(t_owner &owner) const;
                        virtual void Exit(t_owner &owner) const;

                    private:
                        static void configurePlayerFromSpawnPacket(t_owner & owner, game::Player & player, const protocol::server::packet::PlayerSpawn & spawnpkt);
                    };
                }
            }
        }
    }
}

#endif // LIBMINECRAFT_CLASSIC_SESSION_REMOTE_STATE_INGAME_HPP
