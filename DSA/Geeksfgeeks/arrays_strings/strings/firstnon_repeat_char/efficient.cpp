//the approach is to either use an array of size max_char to store the frequencies of each character. traverse the input string twice: first traversal is to count the frequency of each character. second traversal to find the first character in string with a frequency of one

#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

char nonrep(const string& s){
	vector<int> freq(MAX_CHAR, 0);
	for(char c:s){
		freq[c-'a']++;
	}

	for(char c:s){
		if(freq[c-'a'] == 1)
			return c;
	}
	return '$';
}

int main(){
	string s = "geeksforgeeks";
	cout << nonrep(s) << endl;
	return 0;
}