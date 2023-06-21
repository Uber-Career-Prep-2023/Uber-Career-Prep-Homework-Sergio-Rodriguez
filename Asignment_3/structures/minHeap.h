#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <map>
#include <set>
#include <array>
#include <climits>
#define MAX_SIZE INT_MAX/4096

class Heap {
private:
	std::array<int, MAX_SIZE> arr; 	// the underlying array (Set to fixed size for simplicity)
	int n_elems = 0;				// number of elements in the heap
	void heap_helper(int x);		// recursive helper function for heap ordering preservation

public:
	int top(); 					// returns the min (top) element in the heap
	void insert(int x); 		// adds int x to the heap in the appropriate position
	void remove(int x); 		// removes element x in the heap
	void print();				// prints the heap
};

#endif
