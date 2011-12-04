/*
 * cuboid.hpp
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

#ifndef ACTION_CUBOID_HPP
#define ACTION_CUBOID_HPP

#include "../command.hpp"
#include <libminecraft/classic/game/map.hpp>

namespace command
{

class Cuboid : public Command
{
public:
    Cuboid(const Map::point & start,
           const Map::point & finish,
           map::Block::Type type);

    virtual ~Cuboid();

    const Map::point begin;
    const Map::point end;

    map::Cell iter;

    map::Block::Type type;

    virtual void tick(MyClassicClient & client);

    static Command * fromStream(std::istream & stream);
};

}

#endif // ACTION_CUBOID_HPP
