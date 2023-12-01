// In File: queue.h
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
#endif