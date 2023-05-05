#include <stdlib.h>
#include <stdio.h>
#include "doublyLinkedList.h"

Node* DLL_insertAtFront(Node* head, int val)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->next = head;
	newNode->data = val;
	newNode->prev = NULL;
	if(head != NULL){
		head->prev = newNode;
	}
	return newNode;
}

void DLL_insertAtBack(Node* head, int val)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
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
	Node* newNode = (Node*)malloc(sizeof(Node));
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
	if(head == NULL){
		return NULL;
	}
	Node* newHead = head->next;
	if(newHead != NULL){
		newHead->prev = NULL;
	}
	head->next = NULL;
	free(head);
	return newHead;
}

void DLL_deleteBack(Node* head)
{
	Node* currentNode = head;
	if(currentNode == NULL){
		return;
	}
	if(currentNode->next == NULL){
		free(head);
		return;
	}
	while(currentNode->next->next != NULL){
		currentNode = currentNode->next;
	}
	currentNode->next->prev = NULL;
	free(currentNode->next);
	currentNode->next = NULL;
}

Node* DLL_deleteNode(Node* head, Node* loc)
{
	if(head == NULL || loc == NULL){
		return head;
	}
	if(head == loc){
		head = head->next;
		if(head != NULL){
			head->prev = NULL;
		}
		loc->next = NULL;
		free(loc);
		return head;
	}
	Node* currentNode = head;
	while(currentNode != NULL && currentNode->next != loc){
		currentNode = currentNode->next;
	}
	if(currentNode == NULL){
		return head;
	}
	currentNode->next = loc->next;
	if(loc->next != NULL){
		loc->next->prev = currentNode;
	}
	loc->next = NULL;
	loc->prev = NULL;
	free(loc);
	return head;
}

size_t DLL_length(Node* head)
{
	size_t length = 0;
	Node* currentNode = head;
	while(currentNode != NULL){
		currentNode = currentNode->next;
		length++;
	}
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

Node* DLL_reverseRecursive(Node* head) 
{
	if(head == NULL || head->next == NULL){
		return head;
	}
	Node* newHead = DLL_reverseRecursive(head->next);
	head->next->next = head;
	head->prev = head->next;
	head->next = NULL;
	return newHead;
}

void DLL_printer(Node* head)
{
	Node* currentNode = head;
	while(currentNode != NULL){
		printf("%d ", currentNode->data);
		currentNode = currentNode->next;
	}
}

