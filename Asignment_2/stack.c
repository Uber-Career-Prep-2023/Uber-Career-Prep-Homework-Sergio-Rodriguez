#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "singlyLinkedList.h"
#include "stack.h"

Stack* stack_init(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->head = NULL;
    stack->tail = NULL;
    return stack;
}

int stack_top(Stack* stack){
    if(stack_IsEmpty(stack)){
        exit(1);
    }
    return stack->head->data;
}

void stack_push(Stack* stack, int x){
    stack->head = SLL_insertAtFront(stack->head, x);
    if(stack->tail == NULL){
        stack->tail = stack->head;
    }
}

int stack_pop(Stack* stack){
    if(stack_IsEmpty(stack)){
        exit(1);
    }
    int popped = stack->head->data;
    stack->head = SLL_deleteFront(stack->head);
    if(stack->head == NULL){
        stack->tail = NULL;
    }
    return popped;
}

bool stack_IsEmpty(Stack* stack){
    return stack->head == NULL;
}
