/*
Autor:			Stellar Creator
Date Of Update: 14.08.2020
File:			uTime.h
*/

#ifndef UTIME_H
#define UTIME_H

#include "uTime.h"

// Structs
typedef struct __attribute__ ((packed)) {
	uInteger	firstTime;
	uInteger	requestMaxTime;
	uInteger	resetTime;
	uInteger	_lastTimeForReset;
	uInteger	_lastResetTime;
	uInteger	_lastWorkTime;
	uInteger	_firstTime;
	uState		wasActivated;
	uState		state;
	uState		pauseState;
} uProtectorTimer;

uState 		uLogica_TimeProtectorInit(uProtectorTimer *data, uInteger firstTime, uInteger requestMaxTime, uInteger resetTime);
uState 		uLogica_TimeProtectorCompare(uProtectorTimer *data, uInteger time, uState enabled);
uState 		uLogica_TimeProtectorSet(uProtectorTimer *data, uInteger firstTime, uInteger requestMaxTime);
uFunction	uLogica_TimeProtectorSetStage(uProtectorTimer *data, uState state, uInteger time);
uFunction	uLogica_TimeProtectorPause(uProtectorTimer *data, uState outputState);

#endif /* UTIME_H */