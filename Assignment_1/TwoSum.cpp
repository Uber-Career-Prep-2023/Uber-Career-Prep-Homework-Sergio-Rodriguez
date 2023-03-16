/* Question 10: TwoSum
 Given an array of integers and a target integer, k, return the number of pairs of integers 
in the array that sum to k. In each pair, the two items must be distinct elements (come from different indices in the array).
Technique used: Hashing
Time complexity: O(n)
Space complexity: O(n)

*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int twoSum(vector <int> &vec, int k){
 // Look for the frecuency in the array of the number that sums up to k for a given element with a map.
    unordered_map<int, int> elem;
    int count = 0;
    for (int i = 0; i < vec.size(); i++) {
      // If it's already in the map sum its frecuency to the global count, this will take care of the cases where the same
      // element is part of two different pairs.
        if (elem.find(k - vec[i]) != elem.end()) {
            count += elem[k - vec[i]];
        }
        elem[vec[i]]++;
    }
    return count;
}

int main(){
  vector <int> test = {4, 3, 3, 5, 7, 0, 2, 3, 8, 6};
  int k = 6;
  cout << twoSum(test, k) << endl;
}
// Time used: 38 min
