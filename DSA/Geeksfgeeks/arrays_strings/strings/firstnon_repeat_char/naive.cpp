//given a string s of lowercase english letters, the task is to find the first non repeating character. if there is no such character return "$"

//the idea is to use two nested loops, the outer loop for picking an element and the inner loop for finding another occurence of the picked character in the string. as soon as we find a character which has only one occurence in the input string, return it. if all characters have multiple occurences return '$'

#include <bits/stdc++.h>
using namespace std;

char nonrep(string& s){
	int n = s.length();
	for(int i=0;i<n;i++){
		bool found = false;

		for(int j=0;j<n;++j){
			if(i!=j && s[i] == s[j]){
				found = true;
				break;
			}
		}
		if(!found)
			return s[i];
	}
	return '$';
}

int main(){
	string s = "racecar";
	cout << nonrep(s) << endl;
	return 0;
}