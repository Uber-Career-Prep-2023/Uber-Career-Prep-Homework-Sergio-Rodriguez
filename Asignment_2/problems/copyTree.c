/* 

Question 4: CopyTree: Given a binary tree, create a deep copy. Return the root of the new tree.
Time used: 8 min (solving), 27 min (after writing test cases).
Technique used: Preorder traversal.
Time complexity: O(n)
Asumptions: "deep copy" means an exact copy of the tree at a different memory location.

*/

#include <stdlib.h>
#include <stdio.h>
#include "../structures/binarySearchTree.h"

Node* copyTree(Node* root){
	if(root == NULL){
		return root;
	}
	Node* newRoot = (Node*)malloc(sizeof(Node));
	if (newRoot == NULL) {
        	exit(1);
    	}
	newRoot->data = root->data;
	newRoot->left = copyTree(root->left);
	newRoot->right = copyTree(root->right);
	return newRoot;
}

int main(void){

	// Case 1: A normal tree
	Node* root = BST_insert(NULL, 64);
	BST_insert(root, 32);
	BST_insert(root, 96);
	BST_insert(root, 48);
	BST_insert(root, 16);
	BST_insert(root, 80);
	BST_insert(root, 112);
	BST_printer(root);
	printf("\n");
	Node* test1 = copyTree(root);
	BST_printer(test1);
	printf("\n");

	// Case 2: tree is NULL
	Node* test2 = copyTree(NULL);
	BST_printer(test2);
	return 0;
}