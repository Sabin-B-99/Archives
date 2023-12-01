// In File: queue.c
#include "queue.h"
queue *createQueue()
{
    queue *Q = NULL;
    Q = malloc(sizeof *Q * 1);
    Q->size = 0;

    Q->head = NULL;
    Q->tail = NULL;

    return Q;
}

void enqueue(queue *Q, process *prc)
{
    if (Q->size == 0)
    {
        Q->head = prc;
        Q->tail = prc;
    }
    else
    {
        prc->previous = Q->tail;
        (Q->tail)->next = prc;
        prc->next = NULL;
        Q->tail = prc;
    }

    Q->size++;
}

void dequeue(queue *Q)
{
    process *atFrontOfQ = NULL;
    atFrontOfQ = Q->head;

    process *secondAtQ = NULL;
    secondAtQ = Q->head->next;

    if (secondAtQ)
    {
        Q->head = secondAtQ;
    }

    free(atFrontOfQ);
    Q->size--;
}

size_t size(queue *Q)
{
    return Q->size;
}

void makeQueueCircular(queue *Q)
{
    process *currentHead = Q->head;
    process *currentTail = Q->tail;
    if (Q)
    {
        currentHead->previous = currentTail;
        currentTail->next = currentHead;
    }
}
