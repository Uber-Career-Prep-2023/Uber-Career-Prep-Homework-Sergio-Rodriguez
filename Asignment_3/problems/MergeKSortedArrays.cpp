// Given an array of k sorted arrays, merge the k arrays into a single sorted array.

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>> vec){
	priority_queue<int> pq;
	vector<int> result;
	for(auto & i : vec){
		for(auto & j : i){
			pq.push(j*-1);
		}
	}
	while(!pq.empty()){
		result.push_back(pq.top()*-1);
		pq.pop();
	}
	return result;
}

int main(){
	vector<vector<int>> test1 = {{1, 2, 3, 4, 5}, {1, 3, 5, 7, 9}};
	vector<int> merged1 = mergeKSortedArrays(test1);
	vector<vector<int>> test2 = {{1, 4, 7, 9}, {2, 6, 7, 10, 11, 13, 15}, {3, 8, 12, 13, 16}};
	vector<int> merged2 = mergeKSortedArrays(test2);
	for(auto & i : merged1){
		cout << i << " ";
	}
	cout << "\n";
	for(auto & i : merged2){
		cout << i << " ";
	}
	cout << "\n";
	return 0;
}