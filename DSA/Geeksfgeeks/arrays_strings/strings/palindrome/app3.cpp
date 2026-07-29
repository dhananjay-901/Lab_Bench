//using recursion
//a palindrome has matching characters at equal distances from the beginning and the end. we can recursively compare these pairs until we reach the middle of the string

#include <bits/stdc++.h>
using namespace std;

bool ispalindromeutil(string& s, int left, int right){
	if(left>=right) return true;
	if(s[left]!=s[right]) return false;

	return ispalindromeutil(s,left+1,right-1);
}

bool ispalindrome(string s){
	int left = 0, right = s.length()-1;
	return ispalindromeutil(s,left,right);
}

int main(){
	string s = "abba";
	cout << boolalpha << ispalindrome << endl;
	return 0;
}