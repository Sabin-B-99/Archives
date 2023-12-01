/*
    Author: Sabin Badal
    File: queue.h
    Date: 2022-08-20
**/

#ifndef __QUEUE_H
#define __QUEUE_H
#include "fcfs.h"

typedef struct cpuQueue
{
    process *head;
    process *tail;
    process *q_elements;
    size_t length;
    size_t q_memsize;
} queue;

queue *create_queue();
void *resizeQueue(queue *Q);
void enqueue(queue *Q, process *elem);
void dequeue(queue *Q);
size_t queue_length(queue *Q);

void cpy_in_queue(process *prc, process *prcToBeCopied);

#endif //__QUEUE_H