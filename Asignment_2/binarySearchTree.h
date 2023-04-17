#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <stdbool.h>

typedef struct Node Node;
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

Node* BST_init(int val);			// initializes a new root with value val
bool BST_contains(Node* root, int val); 	// returns a boolean indicating whether val is present in the BST
Node* BST_insert(Node* root, int val); 		// creates a new Node with data val in the appropriate location
Node*  BST_delete(Node* root, int val); 	// deletes the Node with data val, if it exists
int BST_min(Node* root);			// returns the minimum value in the BST
int BST_max(Node* root);			// returns the maximum value in the BST
void BST_printer(Node* root);

#endif

/*

Time and space complexity
-----------------------------------------------------------------
Function		| Time			| Space		|
-----------------------------------------------------------------
BST_init		|	O(1)		|	O(1)	|
BST_contains		|	O(log n)*	|	O(1)	|
BST_insert		|	O(log n)*	|	O(1)	|
BST_delete		|	O(log n)*	|	O(1)	|
BST_min			|	O(log n)*	|	O(1)	|
BST_max			|	O(log n)*	|	O(1)	|
-----------------------------------------------------------------
*Amortized: complexity may degrade up to O(n) if every node has one child,
rendering the tree effectively a linked list
+/