/* Question 1: MaxMeanSubArray
Given an array of integers and 
an integer, k, find the maximum 
mean of a subarray of size k. 

Technique used: Linear traversing.
Time complexity: O(n)
Space complexity: O(n)

*/

#include <iostream>
#include <vector>
using namespace std;

float maxMeanSubArray(vector <int> &vec, int k){
    float maxMean = 0;
    int maxSum = 0;
    // if k is greater than the size of the array return 0
    if(vec.size() < k){
      return 0;
    }
    // Calculate the sum of the first subarray of size k
    for(int i = 0; i < k; i++){
      maxSum += vec[i];
    }
    // Calculate the sum of the subsecuent subarrays by substracting
    // the first element of the prior subarray and adding the next 
    // element in the array
    for(int j = 1; j < vec.size()-k-1; j++){
      if(maxSum < maxSum - vec[j-1] + vec[j+(k-1)]){
        maxSum = maxSum - vec[j-1] + vec[j+(k-1)];
      }
    }
    maxMean = (float)maxSum/k;
    return maxMean;
}

int main(){
  vector <int> test = {4, 5, -3, 2, 6, 1};
  int k = 2;
  cout << maxMeanSubArray(test, k) << endl;
}

// Time used: 19 min.
