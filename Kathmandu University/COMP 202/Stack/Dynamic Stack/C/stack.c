#include "stack.h"

void create_stack(stack** current_stack){
    *current_stack = NULL;
    *current_stack = (stack*) malloc(sizeof(stack) * 1);
    (*current_stack)->stack_mem_blocks = 10;
    (*current_stack)->stack_elements = (int32_t*) malloc(sizeof(int32_t) * (*current_stack)->stack_mem_blocks);
    (*current_stack)->stack_size = 0;
}

void resize_stack(stack** current_stack){
    if(size(current_stack) == (*current_stack)->stack_mem_blocks){
        (*current_stack)->stack_mem_blocks += 10;
        (*current_stack)->stack_elements = (int32_t*) realloc((*current_stack)->stack_elements ,sizeof(int32_t) * (*current_stack)->stack_mem_blocks);
        (*current_stack)->top = ((*current_stack)->stack_elements + (*current_stack)->stack_size);
    }
}


void delete_stack(stack** current_stack){
    free((*current_stack)->top);
    free((*current_stack)->stack_elements);
    free(current_stack);
}

void print_stack(stack** current_stack){    
    size_t stack_size = size(current_stack);
    for (int i = (stack_size - 1); i >= 0 ; i--)
    {
        if(i == (stack_size - 1)){
            printf("| %d | <-- TOP\n", *(((*current_stack)->stack_elements) + i));
        }else{
            printf("| %d |\n", *(((*current_stack)->stack_elements) + i));
        }
    }
    printf("-----\n");
}

void push(stack** current_stack, int32_t new_elem){
    resize_stack(current_stack);

    *(((*current_stack)->stack_elements) + (*current_stack)->stack_size) = new_elem;
    (*current_stack)->top = ((*current_stack)->stack_elements + (*current_stack)->stack_size);
    (*current_stack)->stack_size++;
}

void pop(stack** current_stack){
    if(size(current_stack) >= 1){
        (*current_stack)->stack_size--;
        (*current_stack)->top = ((*current_stack)->stack_elements + (*current_stack)->stack_size);
    }
}

int is_stack_empty(stack** current_stack){
    if(size(current_stack) == 0){
        return true;
    }
    return false;
}

size_t size(stack** current_stack){
    return ((*current_stack)->stack_size);
}

void top(stack** current_stack, int32_t* top_elem){
     if(!is_stack_empty(current_stack)){
        *top_elem = *((*current_stack)->top);
    }else{
        printf("ERROR: STACK IS EMPTY. NO TOP ELEMENT. Warning: You may get garbage value.\n");
    }
}
