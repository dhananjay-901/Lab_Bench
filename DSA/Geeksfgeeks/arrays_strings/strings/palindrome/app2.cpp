//using single variable 
//since every character only needs to be compared with its corressponding character from the other end, a single loop over the first half of the string is sufficient

#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(string& s){
	int len = s.length();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]) return false;
	}
	return true;
}

int main(){
	string s = "abba";
	cout << boolalpha << ispalindrome << endl;
	return 0;
}