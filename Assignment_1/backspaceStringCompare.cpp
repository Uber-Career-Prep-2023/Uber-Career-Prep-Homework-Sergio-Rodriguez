/* Question 2: Given two strings representing series of keystrokes,
determine whether the resulting text is the same. Backspaces are
represented by the '#' character so "x#" results in the empty string ("").

Technique used: Two pointers.
Time complexity: O(n)
Space complexity: O(n)

*/

#include <iostream>
#include <string>
using namespace std;


bool backspaceStringCompare(string s1, string s2){
    int i = s1.size()-1;
    int j = s2.size()-1;
    int count = 0;
    while(i >= 0 && j >= 0){
        while(s1[i] == '#'){
            count++;
            i--;
        }
        i -= count;
        count = 0;
         while(s2[j] == '#'){
            count++;
            j--;
        }
        j -= count;
        count = 0;
        if(s1[i] != s2[j]){
            return false;
        }
        i--;
        j--;
    }
    return true;
}

int main(){
    string test1 = "abcdef###xyz";
    string test2 = "abcw#xyz";
    string answer = (backspaceStringCompare(test1, test2)) ? "True" : "False";
    cout << answer << endl;
    return 0;
}
// Time used: 33 min.
