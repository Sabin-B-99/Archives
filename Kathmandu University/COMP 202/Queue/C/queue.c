#include "queue.h"

void create_queue(queue **Q)
{
    *Q = NULL;
    *Q = (queue *)malloc(sizeof(queue) * 1);
    (*Q)->q_allocated_memsize = 10;
    (*Q)->q_elems = (int32_t *)malloc(sizeof(int32_t) * (*Q)->q_allocated_memsize);
    (*Q)->size = 0;
    (*Q)->head = NULL;
    (*Q)->tail = NULL;
}

void delete_queue(queue **Q)
{
    free((*Q)->head);
    free((*Q)->tail);
    free((*Q)->q_elems);
    free(Q);
}

void resize_queue(queue **Q)
{
    if (queue_size(Q) == (*Q)->q_allocated_memsize)
    {
        (*Q)->q_allocated_memsize += 10;
        (*Q)->q_elems = (int32_t *)realloc((*Q)->q_elems, sizeof(int32_t) * (*Q)->q_allocated_memsize);
        (*Q)->head = (*Q)->q_elems;
        (*Q)->tail = ((*Q)->head + (*Q)->size);
    }
}

void print_queue(queue **Q)
{
    int32_t *begin = (*Q)->head;
    int32_t *end = (*Q)->tail;

    int iteration = 0;
    while (begin != end)
    {
        if (iteration == 0)
        {
            printf("|%d| <-- Head\n", *begin);
        }
        else
        {
            printf("|%d|\n", *begin);
        }
        begin++;
        iteration++;
    }
    printf("|%d| <-- Tail\n", *end);
}

void enqueue(queue **Q, int32_t elem)
{
    resize_queue(Q);
    if ((*Q)->size == 0)
    {
        (*Q)->head = (*Q)->q_elems;
    }
    (*Q)->tail = ((*Q)->head + (*Q)->size);
    *((*Q)->tail) = elem;
    (*Q)->size++;
}

void dequeue(queue **Q)
{
    if (queue_size(Q) >= 1)
    {
        (*Q)->head++;
        (*Q)->size--;
    }
}

size_t queue_size(queue **Q)
{
    return (*Q)->size;
}