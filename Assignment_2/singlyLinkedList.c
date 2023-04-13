#include <stdlib.h>
#include <stdio.h>
#include "singlyLinkedList.h"


Node* SLL_insertAtFront(Node* head, int val)
{
	Node* newNode = malloc(sizeof(Node));
	newNode->next = head;
	newNode->data = val;
	return newNode;
}

void SLL_insertAtBack(Node* head, int val)
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

void SLL_insertAfter(Node* loc, int val)
{
	Node* newNode = malloc(sizeof(Node));
	newNode->next = loc->next;
	loc->next = newNode;
	newNode->data = val;
}

Node* SLL_deleteFront(Node* head)
{
	Node* newHead = head->next;
	head->next = NULL;
	free(head);
	return newHead;
}

void SLL_deleteBack(Node* head)
{
	Node* currentNode = head;
	if(currentNode->next == NULL){
		free(head);
		return;
	}
	while(currentNode->next->next != NULL){
		currentNode = currentNode->next;
	}
	currentNode->next->next = NULL;
	free(currentNode->next);
	currentNode->next = NULL;
}

Node* SLL_deleteNode(Node* head, Node* loc)
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

size_t SLL_length(Node* head)
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

Node* SLL_reverseIterative(Node* head)
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

// Node* reverseRecursive(Node* head) 
// {

// }

void SLL_printer(Node* head)
{
	Node* currentNode = head;
	while(currentNode != NULL){
		printf("[%d]->", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("NULL\n");
	printf("Size: %zu\n\n", SLL_length(head));
}

