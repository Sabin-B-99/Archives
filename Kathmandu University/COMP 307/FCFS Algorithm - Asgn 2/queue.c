/*
    Author: Sabin Badal
    File: queue.c
    Date: 2022-08-20
**/

#include "queue.h"

queue *create_queue()
{
    queue *Q = malloc(sizeof *Q * 1);
    Q->length = 0;
    Q->q_memsize = 10;

    (Q->q_elements) = (process *)malloc(sizeof(process) * Q->q_memsize);

    return Q;
}

void *resizeQueue(queue *Q)
{
    if (queue_length(Q) == Q->q_memsize)
    {
        Q->q_memsize += 10;
        Q = realloc(Q, sizeof *Q * Q->q_memsize);
    }
}

void enqueue(queue *Q, process *elem)
{
    // resizeQueue(Q);

    cpy_in_queue(Q->q_elements, elem);

    if (Q->length == 0)
    {
        Q->head = Q->q_elements;
    }
    Q->tail = Q->q_elements;
    Q->q_elements++;
    Q->length++;
}

void dequeue(queue *Q)
{
    if (queue_length(Q) >= 1)
    {
        Q->head++;
        Q->length--;
    }
}

size_t queue_length(queue *Q)
{
    return Q->length;
}

void cpy_in_queue(process *prc, process *prcToBeCopied)
{
    prc->id = prcToBeCopied->id;
    prc->brustTime = prcToBeCopied->brustTime;
    prc->waitTime = prcToBeCopied->waitTime;
    prc->memUsed = prcToBeCopied->memUsed;
    prc->processStateReady = prcToBeCopied->processStateReady;
}