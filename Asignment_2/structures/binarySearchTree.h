#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

typedef struct Node Node;
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

bool BST_contains(Node* root, int val); 	// returns a boolean indicating whether val is present in the BST
Node* BST_insert(Node* root, int val); 		// creates a new Node with data val in the appropriate location
Node*  BST_delete(Node* root, int val); 	// deletes the Node with data val, if it exists
int BST_min(Node* root);			// returns the minimum value in the BST
int BST_max(Node* root);			// returns the maximum value in the BST
void BST_printer(Node* root);			// Prints BST using inorder traversal	

#ifdef __cplusplus
}
#endif

#endif

/*

Time and space complexity
-----------------------------------------------------------------
Function		| Time			| Space		|
-----------------------------------------------------------------
BST_contains		|	O(log n)*	|	O(1)**	|
BST_insert		|	O(log n)*	|	O(1)**	|
BST_delete		|	O(log n)*	|	O(1)**	|
BST_min			|	O(log n)*	|	O(1)**	|
BST_max			|	O(log n)*	|	O(1)**	|
-----------------------------------------------------------------
*Amortized: complexity may degrade up to O(n) if every node has only one child,
effectively rendering the tree a linked list.

**Becomes O(n) taking into account function call stack growth.

*/