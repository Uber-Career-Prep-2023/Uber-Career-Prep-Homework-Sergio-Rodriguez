/* 

Question 6: DedupSortedList. Given a sorted singly linked list, remove any 
	duplicates so that no value appears more than once.
Time used: 11 min (solving), 24 min (after writing test cases)
Technique used: Linked list fixed-distance two-pointer
Time complexity: 0(n)
Asumptions: List is in ascending order and there aren't any cycles.

*/

#include <stdlib.h>
#include <stdio.h>
#include "../structures/singlyLinkedList.h"

void dedupSortedList(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* currentNode = head;
    while (currentNode->next != NULL) {
        if (currentNode->data == currentNode->next->data) {
            Node* dupNode = currentNode->next;
            currentNode->next = dupNode->next;
            free(dupNode);
            continue;
        }
        currentNode = currentNode->next;
    }
    return;
}

int main(void){

	//Case 1:
	Node* head = SLL_insertAtFront(NULL, 1);
	SLL_insertAtBack(head, 2);
	SLL_insertAtBack(head, 2);
	SLL_insertAtBack(head, 4);
	SLL_insertAtBack(head, 5);
	SLL_insertAtBack(head, 5);
	SLL_insertAtBack(head, 5);
	SLL_insertAtBack(head, 10);
	SLL_insertAtBack(head, 10);
	SLL_printer(head);
	printf("\n");
	dedupSortedList(head);
	SLL_printer(head);
	printf("\n");

	//Case 2:
	Node* head2 = SLL_insertAtFront(NULL, 8);
	SLL_insertAtBack(head2, 8);
	SLL_insertAtBack(head2, 8);
	SLL_insertAtBack(head2, 8);
	SLL_printer(head2);
	printf("\n");
	dedupSortedList(head2);
	SLL_printer(head2);
	printf("\n");

	return 0;
}