#include <string>
#include <climits>
#include "./priorityQueue.h"

int PriorityQueue::top(){
    int upperBound = INT_MIN;
    int index = -1;
    for (int i = 0; i <= size; i++) {
        if (upperBound == arr[i].second && index > -1 && arr[index].first < arr[i].first){
            upperBound = arr[i].second;
            index = i;
        }
        else if (upperBound < arr[i].second) {
            upperBound = arr[i].second;
            index = i;
        }
    }
    return index;
}

void PriorityQueue::insert(std::string value, int weight){
    size++;
    arr[size].first = value;
    arr[size].second = weight;
}
 
void PriorityQueue::remove()
{
    int index = top();
    for (int i = index; index < size; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
}
 
