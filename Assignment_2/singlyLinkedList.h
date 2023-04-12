#include <stdlib.h>
#include <stdio.h>

// A Single linked list node
typedef struct Node Node;
struct Node {
    int data;
    struct Node* next;
};

Node* insertAtFront(Node* head, int val) // creates new Node with data val at front; returns new head [ Time: O(1), Space: 0(1) ]
{
	Node* newNode = malloc(sizeof(Node));
	newNode->next = head;
	newNode->data = val;
	return newNode;
}

void insertAtBack(Node* head, int val) // creates new Node with data val at end [ Time: O(n), Space: 0(1) ]
{
	Node* newNode = malloc(sizeof(Node));
	Node* currentNode = head;
	while(currentNode->next != NULL){
		currentNode = currentNode->next;
	}
	currentNode->next = newNode;
	newNode->next = NULL;
	newNode->data = val;
}

void insertAfter(Node* loc, int val) // creates new Node with data val after Node loc [ Time: O(1), Space: 0(1) ]
{
	Node* newNode = malloc(sizeof(Node));
	newNode->next = loc->next;
	loc->next = newNode;
	newNode->data = val;
}

Node* deleteFront(Node* head) // removes first Node; returns new head [ Time: O(1), Space: 0(1) ]
{
	Node* newHead = head->next;
	head->next = NULL;
	free(head);
	return newHead;
}

void deleteBack(Node* head) // removes last Node [ Time: O(n), Space: 0(1) ]
{
	Node* currentNode = head;
	if(head->next == NULL){
		deleteFront(head);
	}
	while(currentNode->next->next != NULL){
		currentNode = currentNode->next;
	}
	currentNode->next->next = NULL;
	free(currentNode->next);
	currentNode->next = NULL;
}

Node* deleteNode(Node* head, Node* loc) // deletes Node loc; returns head (Assuming loc and head are distinct nodes) [ Time: O(n), Space: 0(1) ]
{
	Node* currentNode = head;
	while(currentNode->next != loc){
		currentNode = currentNode->next;
	}
	currentNode->next = loc->next;
	loc->next = NULL;
	free(loc);
	return head;
}

size_t length(Node* head) // returns length of the list [ Time: O(n), Space: 0(1) ]
{
	size_t length = 1;
	if(head->next == NULL){
		return length;
	}
	Node* currentNode = head;
	do{
		currentNode = currentNode->next;
		length++;
	} while(currentNode->next != NULL);
	return length;
}

Node* reverseIterative(Node* head) // reverses the linked list iteratively [ Time: O(n), Space: 0(1) ]
{
	Node* prevNode = NULL;
	Node* currentNode = head;
	Node* nextNode = NULL;
	while (currentNode != NULL) {
		nextNode = currentNode->next;
        	currentNode->next = prevNode;
        	prevNode = currentNode;
        	currentNode = nextNode;
    	}
    	head = prevNode;
    	return head;
}

// Helpers
void printer(Node* head)
{
	Node* currentNode = head;
	while(currentNode != NULL){
		printf("[%d]->", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("NULL\n");
	printf("Size: %zu\n\n", length(head));
}

/* TODO
Node* reverseRecursive(Node* head) // reverses the linked list recursively (Hint: you will need a helper function)
{

}
*/
