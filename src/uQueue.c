/*
Autor:          Stellar Creator
Date Of Update: 14.08.2020
File:           uQueue.c
*/

#include "uGlobal.h"
#include "uQueue.h"

#define uMaxQueueSize 128

#ifndef uMaxQueueSize
#error 'Please set macros \'uMaxQueueSize\', now macros isn\'t set. This value is maximum size of queue.'
#endif

uFunction uQueueAdd(uQueue *q, uInteger data){
    if(q->index > uMaxQueueSize){
    	q->index = 0;
    }
	q->data[q->index] = data;
    q->index++;
}

uInteger uQueueGet(uQueue *q){
    uInteger backfeed = 0;
    if(q->index > 0){
        backfeed = q->data[q->index - 1];
        q->data[q->index - 1] = 0;
        q->index--;
    }else{
        backfeed = 0;
    }
    return backfeed;
}

uInteger uQueueIsReady(uQueue *q){
    if(q->index > 0){
    	return uState_Ready;
    }else{
    	return uState_Done;
    }
}
