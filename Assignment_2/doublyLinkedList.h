#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdlib.h>

typedef struct Node Node;
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

Node* DLL_insertAtFront(Node* head, int val); 	// Creates new Node with data val at front; returns new head
void DLL_insertAtBack(Node* head, int val); 	// Creates new Node with data val at end
void DLL_insertAfter(Node* loc, int val); 	// Creates new Node with data val after Node loc
Node* DLL_deleteFront(Node* head); 		// Removes first Node; returns new heade
void DLL_deleteBack(Node* head); 		// Removes last Node
Node* DLL_deleteNode(Node* head, Node* loc); 	// Deletes Node loc; returns head
size_t DLL_length(Node* head); 			// Returns length of the list
Node* DLL_reverseIterative(Node* head); 	// Reverses the linked list iteratively
Node* DLL_reverseRecursive(Node* head); 	// Reverses the linked list recursively
void DLL_printer(Node* head); 			// Prints the list in a fancy way

#endif

/*

Time and space complexity
---------------------------------------------------------
Function		| Time		| Space		|
---------------------------------------------------------
DLL_insertAtFront	|	O(n)	|	O(1)	|
DLL_insertAtBack	|	O(1)	|	O(1)	|
DLL_insertAfter		|	O(1)	|	O(1)	|
DLL_deleteFront		|	O(1)	|	O(1)	|
DLL_deleteBack		|	O(n)	|	O(1)	|
DLL_deleteNode		|	O(n)	|	O(1)	|
DLL_length		|	O(n)	|	O(1)	|
DLL_reverseIterative	|	O(n)	|	O(1)	|
DLL_reverseRecursive	|		|		|
---------------------------------------------------------

*/ 
