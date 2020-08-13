/*
Autor:			Pavel
Date Of Update: 05.08.2020
File:			uLogica.h
Description:	Logica contains various of logical functions and techniques to simplify some decisions in the field of automation and decision selection systems
*/

#ifndef ULOGICA_H
#define ULOGICA_H

#include "uGlobal.h"

// Structs
typedef struct __attribute__ ((packed)) {
	uInteger	hysteresisMainValue;
	uInteger	hysteresisTriggerValue;
	uState		hysteresisState;
} uHysteresisData;

typedef struct __attribute__ ((packed)) {
	uInteger	minDisableValue;
	uInteger	minEnableValue;
	uInteger	maxDisableValue;
	uInteger	maxEnableValue;
	uState		hysteresisState;
} uRangeComparator;

typedef struct __attribute__ ((packed)) {
	uInteger	hysteresisMinValue;
	uInteger	hysteresisMaxValue;
	uState		hysteresisState;
} uRangeHysteresis;

// Functions
uState		uLogica_HysteresisCompare(uHysteresisData *data, uInteger value);
uFunction	uLogica_HysteresisInit(uHysteresisData *data, uInteger mainValue, uInteger trigger);

uFunction	uLogica_RangeComparatorInit(uRangeComparator *data, uInteger minDisableValue, uInteger minEnableValue, uInteger maxEnableValue, uInteger maxDisableValue);
uState		uLogica_RangeComparatorCompare(uRangeComparator *data, uInteger value);

uState 		uLogica_RangeHysteresisInit(uRangeHysteresis *data, uInteger min, uInteger max);
uState 		uLogica_RangeHysteresisCompare(uRangeHysteresis *data, uInteger value);

uState 		uLogica_TimeProtectorInit(uProtectorTimer *data, uInteger firstTime, uInteger requestMaxTime, uInteger resetTime);
uState 		uLogica_TimeProtectorCompare(uProtectorTimer *data, uInteger time, uState enabled);
uState 		uLogica_TimeProtectorSet(uProtectorTimer *data, uInteger firstTime, uInteger requestMaxTime);
uFunction	uLogica_TimeProtectorSetStage(uProtectorTimer *data, uState state, uInteger time);
uFunction	uLogica_TimeProtectorPause(uProtectorTimer *data, uState outputState);

#endif /* ULOGICA_H */