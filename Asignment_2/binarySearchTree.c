#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "binarySearchTree.h"

bool BST_contains(Node* root, int val)
{
	if(root == NULL){
		return false;
	} else if(root->data == val){
		return true;
	} else if (root->data > val){
		return BST_contains(root->left, val);
	} else {
		return BST_contains(root->right, val);
	}
} 

Node* BST_insert(Node* root, int val)
{
	if(root == NULL){
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->data = val;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	} else if (root->data > val){
		root->left = BST_insert(root->left, val);
	} else {
		root->right = BST_insert(root->right, val);
	}
	return root;
}

Node* BST_delete(Node* root, int val)
{	
	if (root == NULL){
	    return root;
	}
	if (val < root->data){
		root->left = BST_delete(root->left, val);
	} else if (val > root->data){
		root->right = BST_delete(root->right, val);
	} else {
		if (root->left == NULL || root->right == NULL){
			free(root);
			return NULL;
		}
		root->data = BST_min(root->right);
		root->right = BST_delete(root->right, BST_min(root->right));
    	}
   	return root;
}

int BST_min(Node* root)
{
	Node* currentNode = root;
	while(currentNode->left != NULL){
		currentNode = currentNode->left;
	}
	return currentNode->data;
}

int BST_max(Node* root)
{
	Node* currentNode = root;
	while(currentNode->right != NULL){
		currentNode = currentNode->right;
	}
	return currentNode->data;
}

void BST_printer(Node* root)
{
	if (root == NULL){
		return;
	}
    	BST_printer(root->left);
   	printf("%d ", root->data);
    	BST_printer(root->right);
}