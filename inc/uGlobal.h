/*
Autor:			Pavel
Date Of Update: 05.08.2020
File:			uGlobal.h
Description:	Logica contains various of logical functions and techniques to simplify some decisions in the field of automation and decision selection systems
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

#define uProtector_FirtsStart	(uint8_t) 0x00
#define uProtector_Reset		(uint8_t) 0x01
#define uProtector_InWork		(uint8_t) 0x02
#define uProtector_Pause		(uint8_t) 0x03

#define uDirectionNergative		(uint8_t) 0x00
#define uDirectionPositive		(uint8_t) 0x01

// Type of machine states
typedef uint8_t		uState;
typedef uint8_t		uEvent;
typedef uint8_t		uBit;
typedef void		uFunction;
typedef int			uInteger;

typedef struct __attribute__ ((packed)) {
	uInteger	firstTime;
	uInteger	requestMaxTime;
	uInteger	resetTime;
	uInteger	_lastTimeForReset;
	uInteger	_lastResetTime;
	uInteger	_lastWorkTime;
	uState		wasActivated;
	uState		state;
	uState		pauseState;
} uProtectorTimer;

#endif /* UGLOBAL_H */