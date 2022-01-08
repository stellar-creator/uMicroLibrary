/*
Autor:			Stellar Creator
Date Of Update: 05.08.2020
File:			uGlobal.h
*/

#ifndef UGLOBAL_H
#define UGLOBAL_H

#include <stdint.h>

// Macroses
#define _uSetBit(x,y)			x |= (1 << y)
#define _uClearBit(x,y)			x &= ~(1 << y)
#define _uToggleBit(x,y)		x ^= (1 << y)
#define _uGetBit(x,y,z)			z = !((x >> y) & 1)
#define _uShift(x)				(1 << x)

#define uDisabled				(uint8_t) 0x00
#define uEnabled				(uint8_t) 0x01

#define uState_Done				(uint8_t) 0x00
#define uState_Ready			(uint8_t) 0x01
#define uState_InProcess		(uint8_t) 0x02
#define uState_Unknown			(uint8_t) 0x03
#define uState_Error			(uint8_t) 0x04
#define uState_Init				(uint8_t) 0x05
#define uState_Prepare			(uint8_t) 0x06

#define uProtector_FirtsStart	(uint8_t) 0x00
#define uProtector_Reset		(uint8_t) 0x01
#define uProtector_InWork		(uint8_t) 0x02
#define uProtector_Pause		(uint8_t) 0x03

#define uDirectionNegative		(uint8_t) 0x00
#define uDirectionPositive		(uint8_t) 0x01

// Type of machine states
typedef uint8_t		uState;
typedef uint8_t		uEvent;
typedef uint8_t		uBit;
typedef uint8_t		uData;;
typedef uint8_t		uRegister;
typedef void		uFunction;
typedef int			uInteger;
typedef int16_t		uInteger16;
typedef int32_t		uInteger32;
typedef int32_t		uSize;
typedef uint8_t		uAddress;
typedef float		uFloat;

#endif /* UGLOBAL_H */
