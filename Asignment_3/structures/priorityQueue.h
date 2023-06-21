#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <map>
#include <set>
#include <array>
#include <climits>
#include <unordered_map>
#include <string>

#define MAX_SIZE INT_MAX/4096

class PriorityQueue {
private:
  std::array<int, MAX_SIZE> arr;  
  int n_elems = 0; 
  void PriorityQueue_helper(int x);  
  std::unordered_map <int, std::string> strings; // hash table with weights as keys and stored strings as values

public:
  std::string top();   
  void insert(std::string s, int x); 
  void remove(int x);
  void print(); 
};

// This is just a copy-paste of MIN_HEAP_H with negated signedness at insertion and retrieval, effectively making the structure a max heap instead
#endif
