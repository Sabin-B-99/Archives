#include <stdio.h>
#include "linkedlist.h"

int main(){
    LinkedList* intList = createHead(3);
    
    intList =  insert(intList, 8);

    intList = insert(intList, 2);

    printLinkedList(intList);    
    for (size_t i = 0; i < 5; i++)
    {
        intList = insert(intList, i*4);
    }

    printLinkedList(intList);

    printf("Size of the Linked List: %d\n", size(intList));
    
    // printf("Enter a number to search in the list\n");

    // int32_t num_to_search_for = 0;
    // scanf("%d", &num_to_search_for);

    // if(find(intList, num_to_search_for)){
    //     printf("%d is in the list.\n", num_to_search_for);
    // }else{
    //     printf("%d is not in the list.\n", num_to_search_for);
    // }

    intList = delete(intList, 8);
    printLinkedList(intList);
}