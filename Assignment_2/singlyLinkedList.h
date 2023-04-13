#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int data;
    struct Node* next;
};

Node* SLL_insertAtFront(Node* head, int val); 	// Creates new Node with data val at front; returns new head
void SLL_insertAtBack(Node* head, int val); 	// Creates new Node with data val at end
void SLL_insertAfter(Node* loc, int val); 	// Creates new Node with data val after Node loc
Node* SLL_deleteFront(Node* head); 		// Cemoves first Node; returns new head
void SLL_deleteBack(Node* head); 		// Cemoves last Node
Node* SLL_deleteNode(Node* head, Node* loc); 	// Celetes Node loc; returns head
size_t SLL_length(Node* head); 			// Ceturns length of the list
Node* SLL_reverseIterative(Node* head); 	// Ceverses the linked list iteratively
Node* SLL_reverseRecursive(Node* head); 	// Ceverses the linked list recursively
void SLL_printer(Node* head); 			// Crints the list in a fancy way

#endif

/*

Time and space complexity
---------------------------------------------------------
Function		| Time		| Space		
---------------------------------------------------------
SLL_insertAtFront	|	O(n)	|	O(1)	|
SLL_insertAtBack	|	O(1)	|	O(1)	|
SLL_insertAfter		|	O(1)	|	O(1)	|
SLL_deleteFront		|	O(1)	|	O(1)	|
SLL_deleteBack		|	O(n)	|	O(1)	|
SLL_deleteNode		|	O(n)	|	O(1)	|
SLL_length		|	O(n)	|	O(1)	|
SLL_reverseIterative	|	O(n)	|	O(1)	|
SLL_reverseRecursive	|		|		|
---------------------------------------------------------

*/ 
