/* Question 2: Given an integer n and a sorted array of 
integers of size n-1 which contains all but one of the 
integers in the range 1-n, find the missing integer.
 
Technique used: Two pointers.
Time complexity: O(n) (Maybe O(log n) with binary search, but not sure about how to implement it)
Space complexity: O(n)

*/

#include <iostream>
#include <vector>

using namespace std;

int missingInteger(vector <int> &vec, int n){
    for(int i = 0; i < vec.size()-1; i++){
      if(vec[i] != (vec[i+1])+1){
        return vec[i]+1;
      }
    }
    return 0;
}

int main(){
  vector <int> test = {1, 2, 3, 4, 5, 6, 7, 8, 10, 11, 12};
  int n = 12;
  cout << missingInteger(test, n);
}
// Time used: 22 min
