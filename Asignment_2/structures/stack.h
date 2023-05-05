#ifndef STACK_H
#define STACK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include "singlyLinkedList.h"

typedef struct Stack Stack;
struct Stack{
	Node* head;
	Node* tail;
};

Stack* stack_init();
int stack_top(Stack* stack);			// returns the top item in the stack
void stack_push(Stack* stack, int x);		// adds x to the top of the stack
int stack_pop(Stack* stack);			// removes and returns the top item in the stack
bool stack_IsEmpty(Stack* stack);		// returns a boolean indicating whether the stack is empty

#ifdef __cplusplus
}
#endif

#endif

/*Time and space complexity are given by underlying DLL functions*/
