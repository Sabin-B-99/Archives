#include "linkedlist.h"

LinkedList* createHead(int32_t dat){
    LinkedList* head = (LinkedList*) malloc(sizeof(LinkedList) * 1);
    head->dat = dat;
    head->next = NULL;
}

LinkedList* insert(LinkedList* head, int32_t dat){
   LinkedList* newNode = (LinkedList*) malloc(sizeof(LinkedList) * 1);
   newNode->dat = dat;
   newNode->next = head;
   return newNode;
}

size_t size(LinkedList* head){
    size_t list_size = 0;
    LinkedList* traversalNode = head;
    while (traversalNode != NULL)
    {
        list_size++;
        traversalNode = traversalNode->next;
    }
    free(traversalNode);
    return list_size;
}

void printLinkedList(LinkedList* head){
    LinkedList* traversalNode = head;
    while (traversalNode != NULL)
    {
        printf("%d --> ", traversalNode->dat);
        traversalNode = traversalNode->next;
    }
    printf("NULL\n");
    free(traversalNode);
}

bool find(LinkedList* head, int32_t dat){
    LinkedList* traversalNode = head;
    while (traversalNode != NULL)
    {
        if(traversalNode->dat == dat){
            return true;
        }
        traversalNode = traversalNode->next;
    }
    free(traversalNode);
    return false;    
}

LinkedList* delete(LinkedList* head, int32_t dat){
    LinkedList* prev = NULL;
    LinkedList* current = head;

    if(current->dat == dat){
        head = head->next;
        free(current);
        return head;
    }

    while (current != NULL)
    {
        if(current->dat == dat){
            prev->next = current->next;
            free(current);
            return head;
        }
        prev = current;
        current = current->next;
    }
    return NULL;    
}



