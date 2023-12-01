#include <stdio.h>
#include "stack.h"
#include <stdbool.h>

int main(){
    stack** s;
    create_stack(s);

    for (int i = 0; i < 15; i++)
    {
        push(s, i*3);
    }

    print_stack(s);

    printf("*********** Pops *************\n");

    pop(s);
    pop(s);
    print_stack(s);

    printf("*********** Push *************\n");
    push(s, 7);

    print_stack(s);


    printf("*********** Other operations *********\n");
    printf("Current size of stack: %d\n", size(s));
    int32_t top_elem;
    top(s, &top_elem);
    printf("Top element of stack currently: %d\n", top_elem);
    
    printf("****************** Check if stack is empty ***********\n");
    if(is_stack_empty(s) == true){
        printf("Stack is empty.\n");
    }else{
        printf("Stack is not empty\n");
    }

    printf("Emptying the stack ...\n");
    while (is_stack_empty(s) != true)
    {
        pop(s);
    }

    printf("*********** After emptying *********\n");
    printf("Current size of stack: %d\n", size(s));
    int32_t top_elem_Again;
    top(s, &top_elem_Again);
    printf("Top element of stack currently: %d\n", top_elem_Again);
    
    printf("****************** After emptying: Checking if stack is empty ***********\n");
    if(is_stack_empty(s) == true){
        printf("Stack is empty.\n");
    }else{
        printf("Stack is not empty\n");
    }
    
    delete_stack(s);
}