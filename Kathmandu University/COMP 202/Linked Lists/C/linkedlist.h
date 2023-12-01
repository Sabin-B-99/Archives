#ifndef LINKEDLIST_C_
#define LINKEDLIST_C_
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct llnode
{
    int32_t dat;
    struct llnode* next;
}LinkedList;


LinkedList* createHead(int32_t dat);
LinkedList* insert(LinkedList* head, int32_t dat);
size_t size(LinkedList* head);
void printLinkedList(LinkedList* head);
bool find(LinkedList* head, int32_t dat);
LinkedList* delete(LinkedList* head, int32_t dat);

#endif //LINKEDLIST_C_