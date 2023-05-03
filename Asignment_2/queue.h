#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "singlyLinkedList.h"

typedef struct Queue Queue;
struct Queue{
	Node* head;
	Node* tail;
};

Queue* queue_init();
int queue_peek(Queue* queue);			// returns the first item in the queue
void queue_enqueue(Queue* queue, int x); 	// adds x to the back of the queue
int queue_dequeue(Queue* queue);		// removes and returns the first item in the queue
bool queue_isEmpty(Queue* queue); 		// returns a boolean indicating whether the queue is empty
void queue_print(Queue* queue);
#endif


/*
Time and space complexity
---------------------------------------------------------
Function		| Time		| Space		|
---------------------------------------------------------
SLL_insertAtFront	|	O(n)	|	O(1)	|
SLL_insertAtBack	|	O(1)	|	O(1)	|
SLL_insertAfter		|	O(1)	|	O(1)	|
SLL_deleteFront		|	O(1)	|	O(1)	|
SLL_deleteBack		|	O(n)	|	O(1)	|
SLL_deleteNode		|	O(n)	|	O(1)	|
SLL_length		|	O(n)	|	O(1)	|
SLL_reverseIterative	|	O(n)	|	O(1)	|
SLL_reverseRecursive	|	O(n)	|	O(n)**	|
---------------------------------------------------------
** Considering that call stack increases linearly for every node
*/
