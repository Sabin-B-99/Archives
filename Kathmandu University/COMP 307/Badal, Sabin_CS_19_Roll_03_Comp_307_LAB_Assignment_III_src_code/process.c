// In File: process.c
/*
    Author: Sabin Badal
    File: process.c
    Date: 2022-09-10
*/
#include "process.h"

process *initalizeProcess(int32_t pid, int32_t brustTime, int32_t priority)
{
    process *prc = NULL;
    prc = malloc(sizeof *prc * 1);
    prc->pid = pid;
    prc->brustTime = brustTime;
    prc->waitTime = 0;

    prc->previous = NULL;
    prc->next = NULL;

    prc->priority = priority;

    return prc;
}

void swapProcesses(process *prcI, process *prcII)
{
    process *swapHelperPrc = initalizeProcess(prcI->pid, prcI->brustTime, prcI->priority);
    swapHelperPrc->waitTime = prcI->waitTime;

    prcI->pid = prcII->pid;
    prcI->brustTime = prcII->brustTime;
    prcI->waitTime = prcII->waitTime;
    prcI->priority = prcII->priority;

    prcII->pid = swapHelperPrc->pid;
    prcII->brustTime = swapHelperPrc->brustTime;
    prcII->waitTime = swapHelperPrc->waitTime;
    prcII->priority = swapHelperPrc->priority;

    free(swapHelperPrc);
}
