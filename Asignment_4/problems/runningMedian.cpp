/* 
You will be given a stream of numbers, one by one. After each new number, return the median of the numbers so far.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<float> runningMedian(vector<float> vec){

    vector<float> result;
    priority_queue<int> upper, lower;

    for(auto it: vec){

      int curr;
      lower.push(it);
      curr = lower.top();
      upper.push(-curr);

      if(upper.size() > lower.size()){
        curr = upper.top();
        upper.pop();
        lower.push(-curr);
      }

      if(upper.size() != lower.size()){
        result.push_back(lower.top());
      } else {
        result.push_back((lower.top() - upper.top())/2);
      }
      
    }

    return result;
}

int main(){
  vector <float> test = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
  vector <float> result = runningMedian(test);
  for(auto &it: result){
    cout << it << " ";
  }
  cout << endl;
}