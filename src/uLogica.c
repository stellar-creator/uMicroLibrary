/*
Autor:			Pavel
Date Of Update: 05.08.2020
File:			uLogica.c
Description:	Logica contains various of logical functions and techniques to simplify some decisions in the field of automation and decision selection systems
*/

#include "uGlobal.h"
#include "uLogica.h"

uState uLogica_HysteresisCompare(uHysteresisData *data, uInteger value){
	if(value <= data->hysteresisMainValue){
		data->hysteresisState = uEnabled;
	}else{
		if(value > (data->hysteresisMainValue + data->hysteresisTriggerValue))
			data->hysteresisState = uDisabled;
	}

	return (uState) data->hysteresisState;
}

uFunction uLogica_HysteresisInit(uHysteresisData *data, uInteger mainValue, uInteger trigger){
	data->hysteresisMainValue = mainValue;
	data->hysteresisTriggerValue = trigger;
	data->hysteresisState = uDisabled;
}

uFunction uLogica_RangeComparatorInit(uRangeComparator *data, uInteger minDisableValue, uInteger minEnableValue, uInteger maxEnableValue, uInteger maxDisableValue){
	data->minDisableValue = minDisableValue;
	data->minEnableValue = minEnableValue;
	data->maxDisableValue = maxDisableValue;
	data->maxEnableValue = maxEnableValue;
	data->hysteresisState = uDisabled;
}

uState uLogica_RangeComparatorCompare(uRangeComparator *data, uInteger value){
	if (data->hysteresisState == 1 && (value < data->minDisableValue || value > data->maxDisableValue)) {
		data->hysteresisState = uDisabled;
	}else {
		if (data->hysteresisState == 0 && (value >= data->minEnableValue  && value <= data->maxEnableValue)){
			data->hysteresisState = 1;
		}
	}
	return data->hysteresisState;
}

uState uLogica_RangeHysteresisInit(uRangeHysteresis *data, uInteger min, uInteger max){
	data->hysteresisMinValue = min;
	data->hysteresisMaxValue = max;
	data->hysteresisState = uDisabled;	
}

uState uLogica_RangeHysteresisCompare(uRangeHysteresis *data, uInteger value){
	if(value <= data->hysteresisMinValue){
		data->hysteresisState = uEnabled;
	}else{
		if(value > data->hysteresisMaxValue)
			data->hysteresisState = uDisabled;
	}

	return (uState) data->hysteresisState;
}


uState uLogica_TimeProtectorInit(uProtectorTimer *data, uInteger firstTime, uInteger requestMaxTime, uInteger resetTime){
	data->firstTime = firstTime;
	data->requestMaxTime = requestMaxTime;
	data->resetTime = resetTime;
	data->_lastTimeForReset = 0;
	data->_lastWorkTime = 0;
	data->_lastResetTime = 0;
	data->wasActivated = uProtector_FirtsStart;
	data->state = uDisabled;
	data->pauseState = uDisabled;
}

uState uLogica_TimeProtectorSet(uProtectorTimer *data, uInteger firstTime, uInteger requestMaxTime){
	data->firstTime = firstTime;
	data->requestMaxTime = requestMaxTime;
}

uState uLogica_TimeProtectorCompare(uProtectorTimer *data, uInteger time, uState status){
	switch(data->wasActivated){
		case uProtector_FirtsStart:
			if(status == uDisabled){
				if(data->firstTime > time){
					data->state = uEnabled;
				}else{
					data->_lastResetTime = data->firstTime;
					data->state = uDisabled;
					data->_lastTimeForReset = time;
					data->wasActivated = uProtector_Reset; 
				}
			}else{
				data->wasActivated = uProtector_InWork;
			}
		break;

		case uProtector_Reset:
			if( time > (data->_lastTimeForReset + data->resetTime) ){
				data->firstTime = data->_lastResetTime + (data->_lastTimeForReset);
				data->wasActivated = uProtector_FirtsStart;
				data->state = uDisabled;
			}
		break;

		case uProtector_InWork:
			if(status == uEnabled){
				data->_lastWorkTime = time;
				data->state = uEnabled;
			}else{
				if(time > (data->_lastWorkTime + data->requestMaxTime) ){
					data->state = uDisabled;
					data->_lastTimeForReset = time;
					data->wasActivated = uProtector_Reset; 
				}
			}
		break;
		case uProtector_Pause:
			data->wasActivated = uProtector_FirtsStart; 
			data->state = data->pauseState;
		break;
	}
	return data->state;
}

uFunction uLogica_TimeProtectorSetStage(uProtectorTimer *data, uState state, uInteger time){
	if(state == uProtector_Reset){
			data->state = uDisabled;
			data->_lastTimeForReset = time;
			data->wasActivated = uProtector_Reset; 
	}
}

uFunction uLogica_TimeProtectorPause(uProtectorTimer *data, uState outputState){
	data->wasActivated = uProtector_Pause; 
	data->pauseState = outputState; 
}