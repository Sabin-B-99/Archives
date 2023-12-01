/*
    Author: Sabin Badal
    File: fcfs.h
    Date: 2022-08-20
**/

#ifndef __FCFS_H
#define __FCFS_H
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct pcb
{
    int32_t id;
    int64_t brustTime;
    int64_t waitTime;
    size_t memUsed;
    bool processStateReady;
} process;

process *getInitializedProcess(int32_t prcId, int64_t brustTime, bool ready);

#endif //__FCFS_H