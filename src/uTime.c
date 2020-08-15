/*
Autor:			Stellar Creator
Date Of Update: 14.08.2020
File:			uTime.c
*/

#include "uGlobal.h"
#include "uTime.h"

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