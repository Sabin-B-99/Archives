// In File: round_robin.c
#include "round_robin.h"
const int32_t QUANTAM_TIME = 28;
int32_t totalCPUTimeUsed = 0;
int32_t totalProcessesTerminated = 0;

void calculateIndividualWaitTime(queue *readyQueue)
{
    makeQueueCircular(readyQueue);
    process *currentProcess = NULL;
    currentProcess = readyQueue->head;

    process *lastExectedProcess = NULL;

    while (totalProcessesTerminated != readyQueue->size)
    {
        bool dontNeedQTime = isBrustTimeUp(currentProcess);
        if (!dontNeedQTime)
        {
            if (isBrustLessThanQuntTime(currentProcess))
            {

                calcWaitTimeIfBrustLessThanQuantTime(currentProcess);
            }
            else
            {
                calcWaitTimeIfBrustMoreThanQuantTime(currentProcess);
            }
            lastExectedProcess = currentProcess;
        }
        // printf("************* DEBUG *****************\n");
        // printf("Prc ID: %d, Brust Time: %d, Wait Time: %d, Leave Time: %d, Remaining Brust %d\n", currentProcess->pid, currentProcess->brustTime, currentProcess->waitTime, currentProcess->qLeaveTimeLast, currentProcess->remainingBrust);
        // printf("Total CPU Time used till now %d\n", totalCPUTimeUsed);
        // printf("************************************\n");

        currentProcess = currentProcess->next;
        totalProcessesTerminated = findNoOfProcessesterminated(readyQueue);

        /*  For edge case:
            there is only one process left to be executed but has more brust time remaining
            than quantam time
            Example:
            |P1|P2|P3|P4|P5|P3|P4|P5|P3|P5|P5|P5|P5|

            In Gantt Chart above process: P5 repates
            towards the end. But we need to calculate wait
            time for it only once if it is the only remaining process
            in the queue.
        */
        if (currentProcess == lastExectedProcess)
        {
            break;
        }
    }
}

bool isBrustTimeUp(process *prc)
{
    if (prc->remainingBrust <= 0)
    {
        return true;
    }

    return false;
}

bool isBrustLessThanQuntTime(process *prc)
{
    if (prc->remainingBrust < QUANTAM_TIME)
    {
        return true;
    }
    return false;
}

void calcWaitTimeIfBrustLessThanQuantTime(process *prc)
{
    prc->waitTime += (totalCPUTimeUsed - prc->qLeaveTimeLast);

    int32_t cpuUsedCurrentRound = prc->remainingBrust;
    prc->remainingBrust -= prc->remainingBrust;

    totalCPUTimeUsed += cpuUsedCurrentRound;
    prc->qLeaveTimeLast = totalCPUTimeUsed;
}

void calcWaitTimeIfBrustMoreThanQuantTime(process *prc)
{
    prc->waitTime += (totalCPUTimeUsed - prc->qLeaveTimeLast);

    int32_t cpuUsedCurrentRound = QUANTAM_TIME;
    prc->remainingBrust -= QUANTAM_TIME;

    totalCPUTimeUsed += cpuUsedCurrentRound;
    prc->qLeaveTimeLast = totalCPUTimeUsed;
}

int32_t findNoOfProcessesterminated(queue *readyQueue)
{
    process *currentProcess = readyQueue->head;
    int32_t totalTerminated = 0;

    for (size_t i = 0; i < readyQueue->size; i++)
    {
        if (currentProcess->remainingBrust <= 0)
        {
            totalTerminated++;
            currentProcess = currentProcess->next;
        }
    }
    return totalTerminated;
}

void showChart(queue *readyQueue)
{
    float totalWaitTime = 0;

    process *currentProcess = NULL;
    currentProcess = readyQueue->head;

    printf("Round Robin Scheduling\n");
    printf("_____________________________________\n");
    printf("   Process Id    |    Wait Time    \n");
    printf("_____________________________________\n");
    for (size_t i = 0; i < readyQueue->size; i++)
    {
        printf(" %d               | %d                \n", currentProcess->pid, currentProcess->waitTime);
        totalWaitTime += currentProcess->waitTime;
        currentProcess = currentProcess->next;
    }
    printf("_____________________________________\n");
    printf("Average Wait Time: %.4f\n", (totalWaitTime / readyQueue->size));
}