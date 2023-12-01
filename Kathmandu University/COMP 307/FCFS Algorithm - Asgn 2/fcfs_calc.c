/*
    Author: Sabin Badal
    File: fcfs_calc.c
    Date: 2022-08-20
**/

#include "fcfs_calc.h"

float calculateAverageWaitingTime(queue *readyQueue)
{

    float avgWaitTime = 0;
    process *begin = readyQueue->head;
    process *end = readyQueue->tail;

    while (begin <= end)
    {
        avgWaitTime += begin->waitTime;
        begin++;
    }

    return (avgWaitTime) / queue_length(readyQueue);
}

void calculateIndividualWaitingTime(queue *readyQueue)
{
    int64_t individualWaitTime = 0;
    process *begin = readyQueue->head;
    process *end = readyQueue->tail;

    while (begin <= end)
    {
        begin->waitTime = individualWaitTime;
        individualWaitTime += begin->brustTime;
        begin++;
    }
}

void showReportChart(queue *readyQueue)
{

    process *begin = readyQueue->head;
    process *end = readyQueue->tail;

    calculateIndividualWaitingTime(readyQueue);
    printf("_________________________________\n");
    printf("Process Id| Individual Wait Time\n");
    printf("_________________________________\n");
    while (begin <= end)
    {
        printf("%d         | %d                \n", begin->id, begin->waitTime);
        printf("_________________________________\n");
        begin++;
    }

    printf(" Average wait time: %f\n", calculateAverageWaitingTime(readyQueue));
}
