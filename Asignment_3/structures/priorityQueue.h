#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <string>
#include <climits>

class PriorityQueue {
    private:
      std::array < std::pair <std::string, int>, INT_MAX> arr;    // the underlying array
      int size = -1;                                              // size of arr

    public:
      int top();                                          // returns the highest priority (first) element in the PQ
      void insert(std::string x, int weight);             // adds string x to the PQ with priority weight
      void remove();                                      // removes the highest priority (first) element in the PQ
};

#endif
