// In File: queue.h
/*
    Author: Sabin Badal
    File: queue.h
    Date: 2022-09-10
*/
#ifndef __QUEUE_H
#define __QUEUE_H
#include "process.h"
#include <stdlib.h>
typedef struct queue
{
    process *head;
    process *tail;

    size_t size;
} queue;

queue *createQueue();
void enqueue(queue *Q, process *prc);
void dequeue(queue *Q);
size_t size(queue *Q);

void makeQueueCircular(queue *Q);

void orderByPrioity(queue *Q);
process *processAt(queue *Q, int32_t index);
#endif