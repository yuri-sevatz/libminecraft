/*
 * abstractstatemachine.hpp
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

#ifndef SUPPORT_ABSTRACTSTATEMACHINE_HPP
#define SUPPORT_ABSTRACTSTATEMACHINE_HPP

// Class o is the "owner" of the state machine.
// Class s is the "state" of the state machine.
// o has no requirements.
// s only requires and Enter() and Exit() method, accepting O as a parameter.
template<class O, class S>
class AbstractStateMachine {
protected:
    O & owner;
    S * current;
    typedef O t_owner;
    typedef S t_state;

public:
    AbstractStateMachine(O & owner, S & state, bool enterFirst = true) :
        owner(owner), current(&state) {
        if (enterFirst)
            current->Enter(owner);
    }

    // Get the current state.
    S & GetState() {
        return *current;
    }

    // Change current state, progress through transitions.
    void ChangeState(S & state) {
        current->Exit(owner);
        current = &state;
        current->Enter(owner);
    }

    // Sets the current state, and skips all state transitions.
    void SetState(S & state) {
        current = &state;
    }
};

#endif // SUPPORT_ABSTRACTSTATEMACHINE_HPP
