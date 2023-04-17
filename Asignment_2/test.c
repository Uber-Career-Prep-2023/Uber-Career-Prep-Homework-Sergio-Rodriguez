#include <stdio.h>
#include <stdlib.h>
#include "binarySearchTree.h"

int main(){
	Node* root = BST_insert(NULL, 32);
	while(true){
		int opt;
		int data;
		printf("\n[1] Insert  [2] Delete  [3] Query  [4] Print  ->  ");
		scanf("%d", &opt);
		switch(opt){
		case 1:
			printf("-> ");
			scanf("%d", &data);
			BST_insert(root, data);
			BST_printer(root);
			printf("\n");
			break;
		case 2:
			printf("-> ");
			scanf("%d", &data);
			BST_delete(root, data);
			BST_printer(root);
			printf("\n");
			break;
		case 3:
			printf("-> ");
			scanf("%d", &data);
			if(BST_contains(root, data)){
				printf("true\n");
			} else { 
				printf("false\n");
			}
			break;
		case 4:
			BST_printer(root);
			printf("\n");
			break;
		default:
			printf("Invalid option: %d\n", opt);
			break;
		}
	}
	return 0;
}