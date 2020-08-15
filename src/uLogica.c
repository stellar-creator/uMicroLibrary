/*
Autor:			Stellar Creator
Date Of Update: 05.08.2020
File:			uLogica.c
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