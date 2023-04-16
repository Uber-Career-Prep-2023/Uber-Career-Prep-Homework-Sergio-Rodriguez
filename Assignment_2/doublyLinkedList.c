#include <stdlib.h>
#include <stdio.h>
#include "doublyLinkedList.h"

Node* DLL_insertAtFront(Node* head, int val)
{
	Node* newNode = malloc(sizeof(Node));
	newNode->next = head;
	newNode->data = val;
	newNode->prev = NULL;
	return newNode;
}

void DLL_insertAtBack(Node* head, int val)
{
	Node* newNode = malloc(sizeof(Node));
	Node* currentNode = head;
	while(currentNode->next != NULL){
		currentNode = currentNode->next;
	}
	currentNode->next = newNode;
	newNode->next = NULL;
	newNode->prev = currentNode;
	newNode->data = val;
}

void DLL_insertAfter(Node* loc, int val)
{
	Node* newNode = malloc(sizeof(Node));
	newNode->next = loc->next;
	if(loc->next != NULL){
		loc->next->prev = newNode;
	}
	loc->next = newNode;
	newNode->data = val;
	newNode->prev = loc;
}

Node* DLL_deleteFront(Node* head)
{
	Node* newHead = head->next;
	newHead->prev = NULL;
	head->next = NULL;
	free(head);
	return newHead;
}

void DLL_deleteBack(Node* head)
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
	currentNode->next->prev = NULL;
	free(currentNode->next);
	currentNode->next = NULL;
}

Node* DLL_deleteNode(Node* head, Node* loc)
{
	Node* currentNode = head;
	while(currentNode->next != loc){
		currentNode = currentNode->next;
	}
	loc->next->prev = currentNode;
	currentNode->next = loc->next;
	loc->next = NULL;
	loc->prev = NULL;
	free(loc);
	return head;
}

size_t DLL_length(Node* head)
{
	size_t length = 1;
	if(head->next == NULL){
		return length;
	}
	Node* currentNode = head;
	do{
		currentNode = currentNode->next;
		length++;
	}while(currentNode->next != NULL);
	return length;
}

Node* DLL_reverseIterative(Node* head)
{
	Node* prevNode = NULL;
	Node* currentNode = head;
	Node* nextNode = NULL;
	while (currentNode != NULL) {
		nextNode = currentNode->next;
		currentNode->next = prevNode;
        	currentNode->prev = nextNode;
        	prevNode = currentNode;
        	currentNode = nextNode;
	}
    head = prevNode;
    return head;
}

// Node* reverseRecursive(Node* head) 
// {

// }

void DLL_printer(Node* head)
{
	Node* currentNode = head;
	printf("NULL<->");
	while(currentNode != NULL){
		printf("%d<->", currentNode->data);
		currentNode = currentNode->next;
	}
	printf("NULL\n");
	printf("Size: %zu\n\n", DLL_length(head));
}

