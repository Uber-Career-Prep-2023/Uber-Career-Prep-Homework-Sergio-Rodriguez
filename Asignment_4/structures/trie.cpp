#include <string>
#include "./trie.h"

TrieNode* Trie::createNode(){
  TrieNode* newNode = new TrieNode;
  newNode->validWord = false;
  for(size_t i = 0; i < ALPHABET_SIZE; i++){
    newNode->children[i] = NULL;
  }
  return newNode;
}

void Trie::insert(TrieNode* root, std::string word){
  TrieNode* curr = root;
  for(size_t i = 0; i < word.size()-1; i++){
    int chr = word[i]-'a';
    if(curr->children[chr] == NULL){
      curr->children[chr] = Trie::createNode();
    }
    curr =  curr->children[chr];
  }
  if(!curr->validWord){
    curr->validWord = true;
  }
  return;
}

bool Trie::isValidWord(TrieNode* root, std::string word){
  TrieNode* curr = root;
  for(size_t i = 0; i < word.size()-1; i++){
    int chr = word[i]-'a';
    if(curr->children[chr] == NULL){
      return false;
    }
    curr =  curr->children[chr];
  }
  return curr->validWord;
}