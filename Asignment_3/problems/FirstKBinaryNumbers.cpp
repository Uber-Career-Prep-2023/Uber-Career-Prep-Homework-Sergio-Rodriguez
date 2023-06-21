#include <queue>
#include <string>
#include <iostream>
using namespace std;
 
vector<string> firstKBinaryNumbers(int n){
    vector<string> v;
    queue<string> gen;
    string curr, res;
    gen.push("1");
    for(int i = 0; i < n; i++){
        curr = gen.front();
        gen.pop();
        res = curr;
        gen.push(curr + "0");
        gen.push(res + "1");
        v.push_back(curr);
    }
    return v;
}
 
int main()
{
    int n = 10;
    vector<string> result = firstKBinaryNumbers(n);
    for(int i = 0; i < n; i++){
        cout << result[i] << endl;
    }
    return 0;
}