/* Question 2: Given a sorted array of non-negative integers, 
modify the array by removing duplicates so each element only 
appears once. If arrays are static (aka, not dynamic/resizable) 
in your language of choice, the remaining elements should appear 
in the left-hand side of the array and the extra space in the 
right-hand side should be padded with -1s.
 
Technique used: Two pointers.
Time complexity: O(n)
Space complexity: O(n)

*/

#include <iostream>
#include <vector>

using namespace std;

vector <int> dedupArray(vector <int> &vec){
    for(int i = 0; i < vec.size()-1; i++){
      if(vec[i] == vec[i+1]){
        vec.erase(vec.begin()+i);
        i--;
      }
    }
    return vec;
}

int main(){
  vector <int> test = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
  dedupArray(test);
  for(auto &it: test){
    cout << it << " ";
  }
  cout << endl;
}

// Time used: 17 min.
