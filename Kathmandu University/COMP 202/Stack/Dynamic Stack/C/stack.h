#ifndef __STACK_H_
#define __STACK_H_
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack
{
    size_t stack_size;
    int32_t *top;
    int32_t *stack_elements;
    int32_t stack_mem_blocks;
} stack;

void create_stack(stack **);
void resize_stack(stack **);
void delete_stack(stack **);
void print_stack(stack **);

void push(stack **, int32_t);
void pop(stack **);
int is_stack_empty(stack **);
size_t size(stack **);
void top(stack **, int32_t *);

#endif //__STACK_H