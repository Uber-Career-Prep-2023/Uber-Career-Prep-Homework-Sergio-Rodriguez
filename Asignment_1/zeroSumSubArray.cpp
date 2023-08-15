/*
Question 3: ZeroSumSubArrays
Given an array of integers, count the number of subarrays that sum to zero.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Generating prefix sums. If two prefixes are equal then a subarray sum equals 0. If multiple
// prefixes are equal, the number of distinct pairs between them is given by n(n-1)/2

int zeroSumSubArray(vector<int> vec){
    unordered_map<int, int> freq;
    int count = 0, prefix = 0;
    for(auto it : vec){
        prefix += it;
        if(prefix == 0) count++;
        freq[prefix]++;
    }
    for(auto it : freq) count += (it.second*it.second-1)/2;
    return count;
}

int main(){
    vector<vector<int>> tests = {           // Expected output:
        {4, 5, 2, -1, -3, -3, 4, 6, -7},    // 2
        {1, 8, 7, 3, 11, 9},                // 0
        {8, -5, 0, -2, 3, -4},              // 2
        {1, -1, 1, -1}                      // 4
    };

    for(auto test : tests){
        cout << zeroSumSubArray(test) << endl;
    }
}

