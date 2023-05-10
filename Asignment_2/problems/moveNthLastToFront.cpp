/* 

Question 7: MoveNthLastToFront. Given a singly linked list, move the nth from 
	the last element to the front of the list.
Time used: 17 min (solving), 29 min (after writing test cases) 
Technique used: Linked list linear traversal
Time complexity: O(n)
Asumptions: There aren't any cycles.

*/

#include <stdlib.h>
#include <stdio.h>
#include "../structures/singlyLinkedList.h"

Node* moveNthLastToFront(Node* head, int k){
	size_t lenght = SLL_length(head);
	if(head == NULL || lenght < k){
		return NULL;
	}
	Node* currentNode = head;
	for(size_t i = 0; i < lenght-k-1; i++){
		currentNode = currentNode->next;
	}
	Node* nthLast = currentNode->next;
	currentNode->next = nthLast->next;
	nthLast->next = head;
	return nthLast;
}

int main(void){
	// Case 1:
	Node* head = SLL_insertAtFront(NULL, 15);
	SLL_insertAtBack(head, 2);
	SLL_insertAtBack(head, 8);
	SLL_insertAtBack(head, 7);
	SLL_insertAtBack(head, 20);
	SLL_insertAtBack(head, 9);
	SLL_insertAtBack(head, 11);
	SLL_insertAtBack(head, 6);
	SLL_insertAtBack(head, 19);
	SLL_printer(head);
	printf("\n");
	head = moveNthLastToFront(head, 2);
	SLL_printer(head);
	printf("\n");

	// Case 2:
	Node* head2 = SLL_insertAtFront(NULL, 15);
	SLL_insertAtBack(head2, 2);
	SLL_insertAtBack(head2, 8);
	SLL_insertAtBack(head2, 7);
	SLL_insertAtBack(head2, 20);
	SLL_insertAtBack(head2, 9);
	SLL_insertAtBack(head2, 11);
	SLL_insertAtBack(head2, 6);
	SLL_insertAtBack(head2, 19);
	SLL_printer(head2);
	printf("\n");
	head2 = moveNthLastToFront(head2, 7);
	SLL_printer(head2);
	printf("\n");
	return 0;
}