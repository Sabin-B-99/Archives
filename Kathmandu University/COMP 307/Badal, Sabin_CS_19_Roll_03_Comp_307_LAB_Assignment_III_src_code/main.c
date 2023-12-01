// In File: main.c
/*
    Author: Sabin Badal
    File: main.c
    Date: 2022-09-10
*/
// Compile with: gcc main.c process.c queue.c process.h queue.h priority.h priority.c

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "process.h"
#include "priority.h"

// void testSort(queue *Q);

int main()
{
    queue *readyQueue = createQueue();

    process *prc1 = initalizeProcess(1, 53, 3);
    process *prc2 = initalizeProcess(2, 17, 1);
    process *prc3 = initalizeProcess(3, 68, 3);
    process *prc4 = initalizeProcess(4, 24, 2);
    process *prc5 = initalizeProcess(5, 21, 3);

    enqueue(readyQueue, prc1);
    enqueue(readyQueue, prc2);
    enqueue(readyQueue, prc3);
    enqueue(readyQueue, prc4);
    enqueue(readyQueue, prc5);

    orderByPrioity(readyQueue);
    // testSort(readyQueue);

    calculateIndividualWaitTime(readyQueue);
    showChart(readyQueue);
}

// void testSort(queue *Q)
// {
//     process *currentProcess = Q->head;
//     for (size_t i = 0; i < Q->size; i++)
//     {
//         printf("Process Id: %d, Brust Time: %d\n", currentProcess->pid, currentProcess->brustTime);
//         currentProcess = currentProcess->next;
//     }
// }