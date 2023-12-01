/*
    Author: Sabin Badal
    File: main.c
    Date: 2022-08-20
**/
#include "fcfs.h"
#include "fcfs_calc.h"
#include "queue.h"
#include <stdio.h>

int main()
{
    process *prc1 = getInitializedProcess(1, 3, true);
    process *prc2 = getInitializedProcess(2, 7, true);
    process *prc3 = getInitializedProcess(3, 9, true);
    process *prc4 = getInitializedProcess(4, 11, true);
    process *prc5 = getInitializedProcess(5, 1, true);

    queue *readyQueue = create_queue();
    enqueue(readyQueue, prc1);
    enqueue(readyQueue, prc2);
    enqueue(readyQueue, prc3);
    enqueue(readyQueue, prc4);
    enqueue(readyQueue, prc5);

    showReportChart(readyQueue);
    return 0;
}