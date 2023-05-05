#include <stdlib.h>
#include <stdio.h>
#include "singlyLinkedList.h"

Node* SLL_insertAtFront(Node* head, int val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->next = head;
    newNode->data = val;
    return newNode;
}

void SLL_insertAtBack(Node* head, int val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->next = NULL;
    newNode->data = val;
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* currentNode = head;
    while(currentNode->next != NULL){
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
}

void SLL_insertAfter(Node* loc, int val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(1);
    }
    newNode->next = loc->next;
    newNode->data = val;
    loc->next = newNode;
}

Node* SLL_deleteFront(Node* head)
{
    if (head == NULL) {
        return NULL;
    }
    Node* newHead = head->next;
    free(head);
    return newHead;
}

void SLL_deleteBack(Node* head)
{
    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
        free(head);
        return;
    }
    Node* currentNode = head;
    while(currentNode->next->next != NULL){
        currentNode = currentNode->next;
    }
    free(currentNode->next);
    currentNode->next = NULL;
}

Node* SLL_deleteNode(Node* head, Node* loc)
{
    if (head == NULL || loc == NULL) {
        return NULL;
    }
    Node* currentNode = head;
    while(currentNode->next != loc){
        currentNode = currentNode->next;
    }
    currentNode->next = loc->next;
    free(loc);
    return head;
}

size_t SLL_length(Node* head)
{
    size_t length = 0;
    for (Node* currentNode = head; currentNode != NULL; currentNode = currentNode->next) {
        length++;
    }
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

Node* reverseRecursive(Node* head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

void SLL_printer(Node* head)
{
    Node* currentNode = head;
    while(currentNode != NULL){
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
}
