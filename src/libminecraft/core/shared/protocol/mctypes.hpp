/*
 * mctypes.hpp
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

#ifndef LIBMINECRAFT_MCTYPES_HPP
#define LIBMINECRAFT_MCTYPES_HPP

#include "../../../support/java/jtypes.hpp"

#include <string>

namespace libminecraft
{
    class MCTypes
    {
    public:
        typedef JTypes::jbool Bool;
        typedef JTypes::jbyte Byte;
        static const Byte BYTE_MIN = JTypes::JBYTE_MIN;
        static const Byte BYTE_MAX = JTypes::JBYTE_MAX;
        typedef JTypes::jshort Short;
        static const Short SHORT_MIN = JTypes::JSHORT_MIN;
        static const Short SHORT_MAX = JTypes::JSHORT_MAX;
        typedef JTypes::jint Int;
        static const Int INT_MIN = JTypes::JINT_MIN;
        static const Int INT_MAX = JTypes::JINT_MAX;
        typedef JTypes::jlong Long;
        static const Long LONG_MIN = JTypes::JLONG_MIN;
        static const Long LONG_MAX = JTypes::JLONG_MAX;
        typedef JTypes::jfloat Float;
        typedef JTypes::jdouble Double;
        typedef std::string String;
    };
}

#endif // LIBMINECRAFT_MCTYPES_HPP
