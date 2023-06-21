#include "./minHeap.h"
#include <cstdlib>
#include <array>
#include <iostream>

void Heap::heap_helper(int x){
    int curr = x;
    if (2*x + 1 < n_elems && arr[2*x + 1] < arr[x])
        curr = 2*x + 1;
    if (2*x + 2 < n_elems && arr[2*x + 2] < arr[curr])
        curr = 2*x + 2;
    if (curr != x)
    {
        std::swap(arr[x], arr[curr]);
        heap_helper(curr);
    }
}

int Heap::top(){
	if (n_elems == 0){
    	return INT_MAX;
    } else if (n_elems == 1) {
        n_elems--;
        return arr[0];
    }
    int minimum = arr[0];
    arr[0] = arr[n_elems-1];
    n_elems--;
    heap_helper(0);
    return minimum;
}

void Heap::insert(int x){
	if(n_elems == MAX_SIZE){
		exit(1);
	}
	n_elems++;
	int index = n_elems-1;
	arr[index] = x;
	while (index != 0 && arr[(index-1)/2] > arr[index])
	{
		std::swap(arr[index], arr[(index-1)/2]);
		index = (index-1)/2;
	}
}

void Heap::remove(int x){
	arr[x] = INT_MIN;
    while (x != 0 && arr[x-1/2] > arr[x])
    {
       std::swap(arr[x], arr[x-1/2]);
       x = x-1/2;
    }
    top();
}

void Heap::print(){
	for(int i=0; i<n_elems;i++){
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

/*

testing
int main(){
	Heap new_heap;
	new_heap.insert(4);
	new_heap.insert(18);
	new_heap.insert(28);
	new_heap.insert(28);
	new_heap.insert(34);
	new_heap.print();
	std::cout << new_heap.top() << "\n";
	new_heap.print();
	new_heap.remove(28);
	new_heap.print();
}

*/