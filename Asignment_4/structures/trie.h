#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <vector>

const int ALPHABET_SIZE = 26;

typedef struct TrieNode {
   struct TrieNode* children[ALPHABET_SIZE];                        // a (resizable or fixed size) array of size 26
   bool validWord;                                                  // boolean to indicate if this node marks the end of a word
} TrieNode;

class Trie {
public:
    struct TrieNode* root;
    TrieNode* createNode();                                         // creates a node
    void insert(TrieNode* root, std::string word);                  // adds a word to the trie
    bool isValidWord(TrieNode* root, std::string word);             // returns a boolean indicating whether word is in the trie
};

#endif

/*

Time and space complexity
-----------------------------------------------------------------
Function				| Time				| Space				|
-----------------------------------------------------------------
Trie::insert			|	O(n)		    |		O(n)		|
Trie::isValidWord		|	O(n)		    |		O(n)		|
Trie::remove			|	O(n)	    	|		O(n)		|
-----------------------------------------------------------------

*/