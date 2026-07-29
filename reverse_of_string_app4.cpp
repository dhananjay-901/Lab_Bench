//using stack 
//the idea is to use stack for reversing a string because stack follow last in first out principle. this means the last character you add is the first one you will take out. so when we push all the characters of a string into the stack, the last character becomes the first one to pop

#include <bits/stdc++.h>
using namespace std;
string reversestring(string& s){
	stack<char> st;
	for(int i=0;i<s.size();i++){
		st.push(s[i]);
	}
	for(int i=0;i<s.size();i++){
		s[i] = st.top();
		st.pop();
	}
	return s;
}

int main(){
	string s = "abcdef";
	cout << reversestring(s);
	return 0; 
}