/*
    Author: Sabin Badal
    File: fcfs.c
    Date: 2022-08-20
**/

#include "fcfs.h"

process *getInitializedProcess(int32_t prcId, int64_t brustTime, bool ready)
{
    process *prc = NULL;
    prc = malloc(sizeof *prc * 1);
    prc->id = prcId;
    prc->brustTime = brustTime;
    prc->processStateReady = ready;
    return prc;
}
