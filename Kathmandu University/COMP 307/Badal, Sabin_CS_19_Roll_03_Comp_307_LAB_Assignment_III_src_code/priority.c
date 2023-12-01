// In File: priority.c
/*
    Author: Sabin Badal
    File: priority.c
    Date: 2022-09-10
*/
#include "priority.h"

float calculateAverageWaitingTime(queue *readyQueue)
{

    float totalWaitTime = 0;
    process *currentProcess = readyQueue->head;

    while (currentProcess)
    {
        totalWaitTime += currentProcess->waitTime;
        currentProcess = currentProcess->next;
    }
    return (totalWaitTime) / size(readyQueue);
}

void calculateIndividualWaitTime(queue *readyQueue)
{
    int32_t individualWaitTime = 0;
    process *currentProcess = readyQueue->head;

    while (currentProcess)
    {
        currentProcess->waitTime = individualWaitTime;
        individualWaitTime += currentProcess->brustTime;
        currentProcess = currentProcess->next;
    }
}

void showChart(queue *readyQueue)
{
    process *currentProcess = readyQueue->head;

    printf("Premptive Priority Scheduling\n");
    printf("_____________________________________\n");
    printf("   Process Id    |    Wait Time    \n");
    printf("_____________________________________\n");
    while (currentProcess)
    {
        printf(" %d               | %d                \n", currentProcess->pid, currentProcess->waitTime);
        currentProcess = currentProcess->next;
    }
    printf("_____________________________________\n");
    printf("Average Wait Time: %.4f\n", calculateAverageWaitingTime(readyQueue));
}