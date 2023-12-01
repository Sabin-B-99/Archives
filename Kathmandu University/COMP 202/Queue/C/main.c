#include <stdio.h>
#include "queue.h"

int main()
{
    queue **Q;
    create_queue(Q);

    for (int i = 0; i < 15; i++)
    {
        enqueue(Q, i * 3);
    }

    print_queue(Q);

    printf("*********** dequeues *************\n");

    dequeue(Q);
    dequeue(Q);
    print_queue(Q);

    printf("*********** equeues *************\n");
    enqueue(Q, 7);

    print_queue(Q);

    printf("*********** Other operations *********\n");
    printf("Current size of stack: %d\n", queue_size(Q));
}