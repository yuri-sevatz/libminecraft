/*
 * mctypes.hpp
 * This file is part of LibMinecraft.
 *
 * Created by Yuri Sevatz on 04/2011.
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

#ifndef LIBMINECRAFT_CLASSIC_MCTYPES_HPP
#define LIBMINECRAFT_CLASSIC_MCTYPES_HPP

#include <libminecraft/minecraft_export.h>

#include "../shared/mctypes.hpp"
#include <string>

namespace libminecraft {
namespace classic {
class MINECRAFT_EXPORT MCTypes : public libminecraft::MCTypes {
public:
    static const size_t String64_Max_Length = 64;
    typedef std::string String64;
};
}
}

#endif // LIBMINECRAFT_CLASSIC_MCTYPES_HPP
