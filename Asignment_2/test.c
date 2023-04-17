#include <stdio.h>
#include "binarySearchTree.h"

int main(void){
	Node* root = BST_init(32);
	BST_printer(root);
	BST_insert(root, 16);
	BST_printer(root);
	BST_insert(root, 48);
	BST_printer(root);
	BST_insert(root, 8);
	BST_printer(root);
	BST_insert(root, 24);
	BST_printer(root);
	BST_insert(root, 40);
	BST_printer(root);
	BST_insert(root, 56);
	BST_printer(root);
	return 0;
}