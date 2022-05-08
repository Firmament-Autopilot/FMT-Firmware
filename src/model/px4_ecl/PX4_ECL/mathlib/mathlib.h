/****************************************************************************
 *
 *   Copyright (C) 2012, 2014 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file mathlib.h
 *
 * Target specific math functions and definitions
 *
 * @author Siddharth Bharat Purohit <siddharthbharatpurohit@gmail.com>
 */
#ifndef MATHLIB_H
#define MATHLIB_H

#ifdef ECL_STANDALONE

#ifndef M_PI_F
#define M_PI_F 3.14159265358979323846f
#endif

#ifndef M_PI_2_F
#define M_PI_2_F (M_PI / 2.0f)
#endif

#ifndef M_PI
#define M_PI 3.141592653589793238462643383280
#endif

namespace math
{
template <typename Type>
static constexpr Type min(Type val1, Type val2)
{
	return (val1 < val2) ? val1 : val2;
}

template <typename Type>
static constexpr Type max(Type val1, Type val2)
{
	return (val1 > val2) ? val1 : val2;
}

template <typename Type>
static constexpr Type constrain(Type val, Type min, Type max)
{
	return (val < min) ? min : ((val > max) ? max : val);
}

template <typename Type>
static constexpr Type radians(Type degrees)
{
	return (degrees / Type(180)) * Type(M_PI);
}

template <typename Type>
static constexpr Type degrees(Type radians)
{
	return (radians * Type(180)) / Type(M_PI);
}

}  // namespace math
#else

#include <mathlib/mathlib.h>

#endif  // ECL_STANDALONE
#endif  // MATHLIB_H
