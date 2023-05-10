/* 

Question 5: IsBST. Given a binary tree, determine if it is a binary search tree.

Time used: 14 min (solving), 31 min (after writing test cases)
Technique used: Inorder traversal
Time complexity: O(n)
Asumptions: For simplicity trees are free of duplicates.

*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "../structures/binarySearchTree.h"

bool isBST(Node* root){
	if(root == NULL){
		return true;
	}
	if((root->left != NULL && root->left->data > root->data) || 
		(root->right != NULL && root->right->data < root->data)){
		return false;
	} else {
		return isBST(root->left) && isBST(root->right);
	}
}

int main(void){
	// Case 1: A normal BST
	Node* test1 = BST_insert(NULL, 10);
	BST_insert(test1, 8);
	BST_insert(test1, 16);
	BST_insert(test1, 9);
	BST_insert(test1, 13);
	BST_insert(test1, 17);
	BST_insert(test1, 20);
	if(isBST(test1)){
		printf("true\n");
	} else {
		printf("false\n");
	}

	// Case 2: A binary tree that isn't a BST
	Node* test2 = BST_insert(NULL, 10);
	BST_insert(test2, 8);
	BST_insert(test2, 16);
	BST_insert(test2, 9);
	BST_insert(test2, 13);
	// Fabricating a non-BST node
	Node* nonBSTparent = BST_insert(test2, 17);
	nonBSTparent->left = (Node*)malloc(sizeof(Node));
	if (nonBSTparent == NULL) {
        	exit(1);
    	}
	nonBSTparent->left->data = 15;
	if(isBST(test2)){
		printf("true\n");
	} else {
		printf("false\n");
	}
	return 0;
}
