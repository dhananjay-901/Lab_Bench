//using in built functions 
//the idea is to ues built in reverse method to reverse the string. if built in method for string reversal does not exist, then convert string to array or list and use their built in method for reverse. then convert it back to string.

#include <bits/stdc++.h>
using namespace std;

string reversestring(string &s){
	reverse(s.begin(), s.end());
	return s;
}

int main(){
	string s = "abcdef";
	cout << reversestring(s);
	return 0;
}