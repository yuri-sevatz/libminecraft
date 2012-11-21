/*
 * actionstatemachine.hpp
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

#ifndef SUPPORT_ACTIONSTATEMACHINE_HPP
#define SUPPORT_ACTIONSTATEMACHINE_HPP

#include "abstractstatemachine.hpp"

// Action State Machine.
// A state machine with an associated action.

// ** Include all template requirements from AbstractStateMachine
// S now requires an Update() method be defined, accepting O as a parameter.
template<class O, class S>
class ActionStateMachine : public AbstractStateMachine<O,S> {
public:
    ActionStateMachine(O & owner, S & state, bool enterFirst = true) :
        AbstractStateMachine<O,S>(owner, state, enterFirst) {

    }

    void Update() {
        this->current->Update(this->owner);
    }
};

#endif // SUPPORT_ACTIONSTATEMACHINE_HPP
