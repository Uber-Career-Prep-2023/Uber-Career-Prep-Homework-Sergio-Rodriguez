#include "./priorityQueue.h"
#include <cstdlib>
#include <array>
#include <iostream>
#include <string>

void PriorityQueue::PriorityQueue_helper(int x){
    int curr = x;
    if (2*x + 1 < n_elems && arr[2*x + 1] < arr[x])
        curr = 2*x + 1;
    if (2*x + 2 < n_elems && arr[2*x + 2] < arr[curr])
        curr = 2*x + 2;
    if (curr != x)
    {
        std::swap(arr[x], arr[curr]);
        PriorityQueue_helper(curr);
    }
}

std::string PriorityQueue::top(){
	if (n_elems == 0){
    	return "\0";
    } else if (n_elems == 1) {
        n_elems--;
        return strings[arr[0]];
    }
    int minimum = arr[0];
    arr[0] = arr[n_elems-1];
    n_elems--;
    PriorityQueue_helper(0);
    return strings[minimum];
}

void PriorityQueue::insert(std::string s, int x){
	x = -1*x;
	if(n_elems == MAX_SIZE){
		exit(1);
	}
	strings[x] = s;
	n_elems++;
	int index = n_elems-1;
	arr[index] = x;
	while (index != 0 && arr[(index-1)/2] > arr[index])
	{
		std::swap(arr[index], arr[(index-1)/2]);
		index = (index-1)/2;
	}
}

void PriorityQueue::remove(int x){
	arr[x] = INT_MIN;
    while (x != 0 && arr[x-1/2] > arr[x])
    {
       std::swap(arr[x], arr[x-1/2]);
       x = x-1/2;
    }
    top();
}

void PriorityQueue::print(){
	for(int i=0; i<n_elems;i++){
		std::cout << strings[arr[i]] << " ";
	}
	std::cout << "\n";
}

/*
testing
int main(){
	PriorityQueue new_PriorityQueue;
	new_PriorityQueue.insert("quack", 4);
	new_PriorityQueue.insert("world!", 18);
	new_PriorityQueue.insert("Hello,", 28);
	new_PriorityQueue.insert("Eber Cerear PrUp", 28);
	new_PriorityQueue.insert("Uber Career Prep", 34);
	new_PriorityQueue.print();
	std::cout << new_PriorityQueue.top() << "\n";
	new_PriorityQueue.print();
	new_PriorityQueue.remove(28);
	new_PriorityQueue.print();
}
*/