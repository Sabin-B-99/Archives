// In File: priority.h
/*
    Author: Sabin Badal
    File: priority.h
    Date: 2022-09-10
*/
#ifndef __PRIORITY_H
#define __PRIORITY_H
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "process.h"
#include "queue.h"
void calculateIndividualWaitTime(queue *readyQueue);
float calculateAverageWaitingTime(queue *readyQueue);
void showChart(queue *readyQueue);
#endif //__PRIORITY_H