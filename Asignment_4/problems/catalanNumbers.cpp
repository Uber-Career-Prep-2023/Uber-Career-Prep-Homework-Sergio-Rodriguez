/*
The Catalan numbers are a mathematical sequence of numbers. The nth Catalan number is defined as
(2n)! / (n+1)!n!. Given a non-negative integer n, return the Catalan numbers 0-n.
*/

#include <iostream>
#include <vector>

using namespace std;


#include <iostream>
using namespace std;
 
vector<int> catalanNumbers(int n){
    vector<int> catalan;
    catalan.push_back(1);
    catalan.push_back(1);
    for(int i = 2; i <= n; i++) {
        catalan.push_back(0);
        for(int j = 0; j < i; j++){
            catalan[i] += catalan[j] * catalan[i - j - 1];
        }
    }
    return catalan;
}
 
int main(){
  vector <int> tests = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector <int> result;
  for(auto test : tests){
    result = catalanNumbers(test);
    for(auto it: result){
        cout << it << " ";
    }
    cout << endl;
  }

}