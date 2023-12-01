#ifndef __QUEUE_H
#define __QUEUE_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct queue
{
    int32_t *head;
    int32_t *tail;
    int32_t *q_elems;
    size_t size;
    size_t q_allocated_memsize;
} queue;

void create_queue(queue **Q);
void delete_queue(queue **Q);
void resize_queue(queue **Q);
void print_queue(queue **Q);

void enqueue(queue **Q, int32_t elem);
void dequeue(queue **Q);
size_t queue_size(queue **Q);

#endif //__QUEUE_H