// Given a string, return the string with the order of the space-separated words reversed

#include <string>
#include <iostream>
#include <stack>
using namespace std;

string reverseWords(string s){
	string tmp = "", result = "";
	stack<string> st;
	for(long unsigned int i = 0; i < s.size(); i++){
		while(s[i] != ' ' && s[i] != '\0'){
			tmp += s[i];
			i++;
		}
		st.push(tmp);
		tmp = "";
	}
	while(!st.empty()){
		result += st.top();
		result += " ";
		st.pop();
	}
	return result;
}

int main(){
	string test1 =  "Uber Career Prep";
	string test2 =  "Emma lives in Brooklyn, New York.";
	cout << reverseWords(test1) << "\n";
	cout << reverseWords(test2) << "\n";
}