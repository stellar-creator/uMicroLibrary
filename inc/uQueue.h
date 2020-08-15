/*
Autor:			Stellar Creator
Date Of Update: 05.08.2020
File:			uQueue.h
*/

#ifndef UQUEUE_H
#define UQUEUE_H

#include "uGlobal.h"

// Structs
typedef struct  {
    uInteger data[64];
    uInteger index;
    uState isReady;
} uQueue;

// Functions
uFunction	uQueueAdd(uQueue *q, uInteger data);
uInteger	uQueueGet(uQueue *q);
uInteger	uQueueIsReady(uQueue *q);

#endif /* UQUEUE_H */