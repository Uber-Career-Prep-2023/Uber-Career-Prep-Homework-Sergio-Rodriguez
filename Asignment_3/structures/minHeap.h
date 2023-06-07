#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <map>
#include <set>
#include <vector>

class Heap {
    private:
      vector<int> arr; 		// the underlying array

    public:
      int top(); 		// returns the min (top) element in the heap
      void insert(int x); 	// adds int x to the heap in the appropriate position
      void remove(); 		// removes the min (top) element in the heap
}

#endif
