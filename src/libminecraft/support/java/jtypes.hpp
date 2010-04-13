/*
 * jtypes.hpp
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

#ifndef SUPPORT_JAVA_JTYPES_HPP
#define SUPPORT_JAVA_JTYPES_HPP

#include <inttypes.h>
#include <string>

// C++ compatible Java types
// Based on the recommendation from:
// http://gcc.gnu.org/java/papers/native++.html
class JTypes
{
public:
    typedef bool jbool;
    typedef int8_t jbyte;
    typedef int16_t jshort;
    typedef int32_t jint;
    typedef int64_t jlong;

    // These two definitions MIGHT be wrong if not conforming to:
    typedef float jfloat; // Single-precision 32-bit IEEE 754 floating point
    typedef double jdouble; // Double-precision 64-bit IEEE 754 floating point

    typedef wchar_t jchar;
    typedef std::wstring jstring;
};

#endif // SUPPORT_JAVA_JTYPES_HPP
