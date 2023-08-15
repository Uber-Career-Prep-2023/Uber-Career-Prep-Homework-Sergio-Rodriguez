/* 
Question 2: Given two strings representing series of keystrokes, determine whether the resulting text is the same. 
Backspaces are represented by the '#' character so "x#" results in the empty string ("").

Time complexity: O(n)
Space complexity: O(n)
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool backspaceStringCompare(string s1, string s2){
    string res1, res2;
    for(char c : s1){
        if(c == '#' && !res1.empty()) res1.pop_back();
        else res1 += c;
    }
    for(char c : s2){
        if(c == '#' && !res2.empty()) res2.pop_back();
        else res2 += c;
    }
    return (res1 == res2);
}

int main(){

    vector<pair<string, string>> tests = {              // Expected output:
        {"abcde", "abcde"},                             // True
        {"Uber Career Prep", "u#Uber Careee#r Prep"},   // True
        {"abcdef###xyz", "abcw#xyz"},                   // True
        {"abcdef###xyz", "abcdefxyz###"},               // False
        {"#######", "####"},                            // False
        {"", "##"}                                      // True
    };

    for(auto test : tests){
        string result = backspaceStringCompare(test.first, test.second) ? "True" : "False";
        cout << result << endl;
    }

    return 0;
}





