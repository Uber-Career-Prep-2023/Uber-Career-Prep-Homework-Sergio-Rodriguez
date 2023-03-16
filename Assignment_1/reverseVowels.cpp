/* QQuestion 2: ReverseVowels
Given a string, reverse the order 
of the vowels in the string.
 
Technique used: Two pointers.
Time complexity: O(n)
Space complexity: O(n)

*/

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

// Function to determine if a character is a vowel
bool isVowel(char c){
    set <char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    return vowels.count(c);
}

string reverseVowels(string s){
    int i = 0;
    int j = s.size()-1;
    // Checking if the i th and size-j th terms are vocals and swap them if so.
    while (i <= j){
        if(isVowel(s[i]) && isVowel(s[j])){
            swap(s[i], s[j]);
        }
        i++;
        j--;
    }
    return s;
}

int main(){
  string test = "aeiou";
  cout << reverseVowels(test) << endl;
}

// Time used: 31 min.
