// In File: process.c
#include "process.h"

process *initalizeProcess(int32_t pid, int32_t brustTime)
{
    process *prc = NULL;
    prc = malloc(sizeof *prc * 1);
    prc->pid = pid;
    prc->brustTime = brustTime;
    prc->waitTime = 0;

    prc->qLeaveTimeLast = 0;
    prc->previous = NULL;
    prc->next = NULL;

    prc->remainingBrust = brustTime;

    return prc;
}
