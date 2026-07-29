//by reversing the string
//a palindrome remains the same even after being reversed. so we can reverse the string and compare it with the original 

#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(string& s){
	return s == string(s.rbegin(), s.rend());
}

int main(){
	string s = "abba";
	cout << boolalpha << ispalindrome(s) << endl;
	return 0;
}