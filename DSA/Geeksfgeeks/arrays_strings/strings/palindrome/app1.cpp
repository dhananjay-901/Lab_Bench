//given a string s the task is to check if it is a pallindrome or not.
//a pallindrome reads the same from both ends. by comparing the characets from the beginning and the end simultaneously, we can quickly determine whether the string is a palindrome.

#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(string& s){
	int left = 0;
	int right = s.length()-1;
	while(left < right){
		if(s[left]!=s[right]) return false;
		left++;
		right--;
	}
	return true;
}

int main(){
	string s = "abba";
	cout << boolalpha << ispalindrome << endl;
	return 0;
}
