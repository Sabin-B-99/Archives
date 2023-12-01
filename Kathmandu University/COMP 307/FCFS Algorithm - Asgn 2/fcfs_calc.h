/*
    Author: Sabin Badal
    File: fcfs_calc.h
    Date: 2022-08-20
**/
#ifndef __FCFS_CALC_H
#define __FCFS_CALC_H

#include "fcfs.h"
#include <time.h>
#include "queue.h"

float calculateAverageWaitingTime(queue *readyQueue);

void calculateIndividualWaitingTime(queue *readyQueue);

void showReportChart(queue *readyQueue);
#endif //__FCFS_CALC_H