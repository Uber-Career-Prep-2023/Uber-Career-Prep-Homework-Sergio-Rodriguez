/* 
Question 2: ReverseVowels
Given a string, reverse the order of the vowels in the string.
 
Technique used: Forward/backward two-pointer.
Time complexity: O(n)
Space complexity: O(1)
*/

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

bool isVowel(char c){
    set <char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    return vowels.count(c);
}

string reverseVowels(string s){
    size_t fwd = 0, bwd = s.size()-1;
    while(fwd < bwd){
        while(!isVowel(s[fwd]) && fwd < bwd){
            fwd++;
        }
        while(!isVowel(s[bwd]) && fwd < bwd){
            bwd--;
        }
        swap(s[fwd], s[bwd]);
        fwd++;
        bwd--;
    }
    return s;
}

int main(){

    vector<string> tests = {    // Expected output:
        "Uber Career Prep",     // eber Ceraer PrUp
        "xyz",                  // xyz 
        "flamingo",             // flominga
        "aeiou"                 // uoiea
    };

    for(auto test : tests){
        cout << reverseVowels(test) << endl;
    }

    return 0;
}