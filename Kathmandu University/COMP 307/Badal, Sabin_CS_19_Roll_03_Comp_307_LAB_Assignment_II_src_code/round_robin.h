// In File: round_robin.h
#ifndef __ROUND_ROBIN_H
#define __ROUND_ROBIN_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "queue.h"
#include "process.h"
#include <stdbool.h>

extern const int32_t QUANTAM_TIME;
extern int32_t totalCPUTimeUsed;
extern int32_t totalProcessesTerminated;

void calculateIndividualWaitTime(queue *readyQueue);

bool isBrustTimeUp(process *prc);
bool isBrustLessThanQuntTime(process *prc);
int32_t findNoOfProcessesterminated(queue *readyQueue);

void calcWaitTimeIfBrustLessThanQuantTime(process *prc);
void calcWaitTimeIfBrustMoreThanQuantTime(process *prc);
void showChart(queue *readyQueue);

#endif //__ROUND_ROBIN