/*
 * cuboid.cpp
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

#include "cuboid.hpp"

#include "../myclassicclient.hpp"

#include <iostream>

namespace command {
Cuboid::Cuboid(const Map::point & start,
               const Map::point & finish,
               map::Block::Type type) :
    Command(),
    begin(std::min(start.x, finish.x), std::min(start.y, finish.y), std::min(start.z, finish.z)),
    end(std::max(start.x, finish.x), std::max(start.y, finish.y), std::max(start.z, finish.z)),
    iter(begin.x, begin.y, begin.z),
    type(type) {

}

Cuboid::~Cuboid() {

}

Command * Cuboid::fromStream(std::istream & stream) {
    std::cerr << "Parsing Cuboid Command..." << std::endl;

    Map::point begin;
    Map::point end;

    int type;

    stream >> begin.x;
    stream >> begin.y;
    stream >> begin.z;
    stream >> end.x;
    stream >> end.y;
    stream >> end.z;
    stream >> type;

    if (stream.fail())
        return NULL;

    // XXX: Can throw exception
    map::Block::Type blockType(map::Block::getBlockType(type));

    return new Cuboid(begin, end, blockType);
}

void Cuboid::tick(MyClassicClient & client) {
    std::cerr << "I am at: " << map::Cell(client.self.position) << std::endl;
    std::cerr << "Moving to: " << iter << std::endl;

    client.move(iter);

    std::cerr << "Placing Block at: " << iter << std::endl;
    std::cerr << "Which is a: " << client.world.map.at(iter).type << std::endl;

    if(client.world.map.isClearableBlock(iter)) {
        client.clearBlock(iter);
    }
    if (client.world.map.isSetableBlock(iter)) {
        client.setBlock(iter, type);
    }

    if (++iter.x > end.x || iter.x <= begin.x) {
        if (++iter.y > end.y || iter.y <= begin.y) {
            if (++iter.z > end.z || iter.z <= begin.z) {
                client.stopAction();
                return;
            }
            iter.y = begin.y;
        }
        iter.x = begin.x;
    }
}

}
