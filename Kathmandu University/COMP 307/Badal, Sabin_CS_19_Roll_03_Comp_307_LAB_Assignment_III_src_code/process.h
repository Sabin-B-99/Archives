// In File: process.h
/*
    Author: Sabin Badal
    File: process.h
    Date: 2022-09-10
*/
#ifndef __PROCESS_H
#define __PROCESS_H
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct process
{
    int32_t pid;
    int32_t brustTime;
    int32_t waitTime;
    struct process *previous;
    struct process *next;
    int32_t priority;
} process;

process *initalizeProcess(int32_t pid, int32_t brustTime, int32_t priority);
void swapProcesses(process *prcI, process *prcII);

#endif //__PROCESS_H