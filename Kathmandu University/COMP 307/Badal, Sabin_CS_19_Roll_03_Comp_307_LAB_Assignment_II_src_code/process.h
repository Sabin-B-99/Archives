// In File: process.h
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
    int32_t qLeaveTimeLast;
    int32_t remainingBrust;
} process;

process *initalizeProcess(int32_t pid, int32_t brustTime);

#endif //__PROCESS_H