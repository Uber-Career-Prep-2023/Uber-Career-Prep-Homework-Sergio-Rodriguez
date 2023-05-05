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

/*Time and space complexity are given by underlying DLL functions*/
