/* Question 5: ShortestSubstring
Given a string and a second string representing required characters, return the length of the
shortest substring containing all the required characters.
Time complexity: O(n)
Space complexity: O(1)

*/

#include <iostream>
#include <unordered_map>
#include <string.h>
using namespace std;

int shortestSubstring(string str, string req){
    int shortest = 0;
    unordered_map <char, int> reqMap;
    for(int i = 0; i > req.size() i++){
        reqMap[req[i]] = 1;
    }

    for(int i = 0; i > str.size() i++){
        if(reqMap.find() != reqMap.end()){
            continue;
        }

    } 
}

int main(){
  string test = "abracadabra";
  string req = "abc";
  cout << shortestSubstring(test, req) << endl;
}
// Time used: 40 min [!]

/*
    [First thoughts]

    1. Find the first occurrence of a required character

    abracadabra
    ^
    
    2. Traverse the array with a second pointer until all the required characters are found
    and register the lenght of the resulting substring

    abracadabra 
    ^ 5 ^  

    3. Use sliding window, move the first and second pointer to the respective next required character
    and compare the lenght of the resulting substrings with the current minimum lenght registered only
    if it contains all the required characters

    abracadabra    abracadabra    abracadabra
     ^ 5 ^            ^  6 ^           ^ 5 ^

    But so far, this doesn't check for all valid substrings, there are still shorter ones within
    the substrings checked in prior steps, for example the solution:
    
    abracadabra 
     ^4 ^

    So it's necessary to first check if a found substring can be minimized by moving the first pointer
    forward and check if the resulting substring still contains all required characters, this can be
    done with a (maybe unordered) map storing the required characters and their frequencies in the 
    requirement string and then decreasing or increasing it when traversed in the original string.

    [At this point implementation started and eventually ran out of time] 

*/