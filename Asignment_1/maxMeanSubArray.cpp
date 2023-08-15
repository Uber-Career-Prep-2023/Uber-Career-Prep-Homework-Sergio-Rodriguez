/* 
Question 1: MaxMeanSubArray
Given an array of integers and an integer, k, find the maximum mean of a subarray of size k. 

Technique used: Fixed-size sliding window.
Time complexity: O(n)
Space complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

float maxMeanSubArray(vector <int> &vec, int k){
    if(k == 0 || k > vec.size()) return 0;
	float sum = 0, maxSum;
	for(int i = 0; i < k; i++){
		sum += vec[i];
	}
	maxSum = sum;
	for(int i = 1; i < vec.size()-k+1; i++){
		sum -= vec[i-1];
		sum += vec[i+k-1];
		maxSum = max(maxSum, sum);
	}
	return maxSum/k;
}

int main(){

	vector<pair<vector<int>, int>> tests = { 			// Expected output:
		{{4, 5, -3, 2, 6, 1}, 2}, 						// 4.5
		{{4, 5, -3, 2, 6, 1}, 3}, 						// 3
		{{1, 1, 1, 1, -1, -1, 2, -1, -1}, 3}, 			// 1
		{{1, 1, 1, 1, -1, -1, 2, -1, -1, 6}, 5}, 		// 1
	};

	for(auto test : tests){
		cout << maxMeanSubArray(test.first, test.second) << endl;
	}

	return 0;

}
