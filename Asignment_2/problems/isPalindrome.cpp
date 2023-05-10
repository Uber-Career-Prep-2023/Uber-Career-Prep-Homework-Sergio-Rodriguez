/* 

Question 8: IsPalindrome. Given a doubly linked list, determine if it is a palindrome.
Time used: 23 min (solving), 38 min (after writing test cases)
Technique used: Doubly linked list forward-backward two-pointer
Time complexity: 0(n)
Asumptions: Empty lists are palindromes.

*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../structures/doublyLinkedList.h"

bool isPalindrome(Node* head) {
	if(head == NULL){
		return true;
	}
	Node* forwardNode = head;
	Node* backwardsNode = head;
	while(backwardsNode->next != NULL){
		backwardsNode = backwardsNode->next;
	}
	while(forwardNode != backwardsNode && forwardNode->next != backwardsNode){
		if(forwardNode->data != backwardsNode->data){
			return false;
		} else{
			forwardNode = forwardNode->next;
			backwardsNode = backwardsNode->prev;
		}
	}
	return true;
}

int main(void){

	//Case 1:
	Node* head = DLL_insertAtFront(NULL, 1);
	DLL_insertAtBack(head, 2);
	DLL_insertAtBack(head, 2);
	DLL_insertAtBack(head, 4);
	DLL_insertAtBack(head, 5);
	DLL_insertAtBack(head, 5);
	DLL_insertAtBack(head, 5);
	DLL_insertAtBack(head, 10);
	DLL_insertAtBack(head, 10);
	DLL_printer(head);
	printf("\n");
	if(isPalindrome(head)){
		printf("true\n");
	} else {
		printf("false\n");
	}
	printf("\n");

	//Case 2:
	Node* head2 = DLL_insertAtFront(NULL, 8);
	DLL_insertAtBack(head2, 8);
	DLL_insertAtBack(head2, 8);
	DLL_insertAtBack(head2, 8);
	DLL_printer(head2);
	printf("\n");
	if(isPalindrome(head2)){
		printf("true\n");
	} else {
		printf("false\n");
	}
	printf("\n");

	return 0;
}