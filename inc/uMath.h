/*
Autor:			Stellar Creator
Date Of Update: 06.01.2022
File:			uMath.h
*/

#ifndef UMATH_H
#define UMATH_H

#include <stdint.h>
#include "uGlobal.h"
#include "uLogica.h"
#include "uMath.h"

// Type of math data
typedef float	uCoordinate;
typedef int16_t	uCoordinate16;
typedef int32_t	uCoordinate32;

// 3D coordinate structure
typedef struct __attribute__ ((packed)) {
	uCoordinate X;
	uCoordinate Y;
	uCoordinate Z;
} uCoordinate3D;

// 3D coordinate structure int16_t
typedef struct __attribute__ ((packed)) {
	uCoordinate16 X;
	uCoordinate16 Y;
	uCoordinate16 Z;
} uCoordinate163D;

// 3D coordinate structure int32_t
typedef struct __attribute__ ((packed)) {
	uCoordinate32 X;
	uCoordinate32 Y;
	uCoordinate32 Z;
} uCoordinate323D;

// Functions
uFloat uDegrees(double radians);
uInteger32 uConstrain(uInteger32 value, uInteger32 min, uInteger32 max);
uInteger32 uMap(uInteger32 value, uInteger32 a_min, uInteger32 a_max, uInteger32 b_min, uInteger32 b_max);

#endif /* UMATH_H */
