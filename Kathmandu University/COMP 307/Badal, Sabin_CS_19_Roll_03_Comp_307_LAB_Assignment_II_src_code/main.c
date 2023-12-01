/*
    Author: Sabin Badal
    Date: 2022-09-08
    File: main.c
*/

// Compile with: gcc main.c process.c round_robin.c queue.c process.h round_robin.h queue.h
// Note: If you want to change the quantam time. Go to "round_robin.c" file and edit line  No 2
#include <stdio.h>
#include "process.h"
#include "queue.h"
#include "round_robin.h"

int main()
{
    queue *readyQueue = createQueue();

    process *prc1 = initalizeProcess(1, 14);
    process *prc2 = initalizeProcess(2, 18);
    process *prc3 = initalizeProcess(3, 68);
    process *prc4 = initalizeProcess(4, 72);
    process *prc5 = initalizeProcess(5, 15);

    enqueue(readyQueue, prc1);
    enqueue(readyQueue, prc2);
    enqueue(readyQueue, prc3);
    enqueue(readyQueue, prc4);
    enqueue(readyQueue, prc5);

    calculateIndividualWaitTime(readyQueue);
    showChart(readyQueue);
}
