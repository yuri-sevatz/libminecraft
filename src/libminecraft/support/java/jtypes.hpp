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

#include <stdint.h>
#include <string>

// C++ compatible Java types
// Based on the recommendation from:
// http://gcc.gnu.org/java/papers/native++.html
class JTypes
{
public:
    typedef bool jbool;
    typedef int8_t jbyte;
    static const jbyte JBYTE_MAX = 0x7f;
    static const jbyte JBYTE_MIN = (-JBYTE_MAX - 1);
    typedef int16_t jshort;
    static const jshort JSHORT_MAX = 0x7fff;
    static const jshort JSHORT_MIN = (-JSHORT_MAX - 1);
    typedef int32_t jint;
    static const jint JINT_MAX = 0x7fffffffL;
    static const jint JINT_MIN = (-JINT_MAX - 1L) ;
    typedef int64_t jlong;
    static const jlong JLONG_MAX = 0x7fffffffffffffffLL;
    static const jlong JLONG_MIN = (-JLONG_MAX - 1LL) ;

    // These two definitions MIGHT be wrong if not conforming to:
    typedef float jfloat; // Single-precision 32-bit IEEE 754 floating point
    typedef double jdouble; // Double-precision 64-bit IEEE 754 floating point

    typedef uint16_t jchar;
    typedef std::basic_string<jchar> jstring;
};

#endif // SUPPORT_JAVA_JTYPES_HPP
