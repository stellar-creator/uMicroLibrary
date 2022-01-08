/*
Autor:			Stellar Creator
Date Of Update: 06.01.2022
File:			uMath.c
*/

#include <math.h>
#include "uGlobal.h"
#include "uLogica.h"
#include "uMath.h"

// The function is to limit the maximum and minimum values
uInteger32 uConstrain(uInteger32 value, uInteger32 min, uInteger32 max){
    if(value < min) {
    	return min;
    } else if (value > max) {
    	return max;
    } else {
    	return value;
    }
}

// Converting radians to degrees
uFloat uDegrees(double radians) {
    return radians * (180.0 / M_PI);
}

// The function compares the values ​​and assigns them from the resulting range
uInteger32 uMap(uInteger32 value, uInteger32 a_min, uInteger32 a_max, uInteger32 b_min, uInteger32 b_max){
    uint32_t data = ((((value - a_min)*(b_max - b_min))/(a_max - a_min)) + b_min);
    if(data > b_max){
    	data = b_max;
    }
    if(data < b_min){
    	data = b_min;
    }
    return data;
}
