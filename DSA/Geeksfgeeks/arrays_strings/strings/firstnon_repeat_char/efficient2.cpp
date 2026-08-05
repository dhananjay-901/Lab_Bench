//the above approach can be optimized using a single traversal of the string. the idea is to maintina a visited array of size MAX_CHAR initiliazed to -1 indicating no characters have been seen yet. now we iterate through the string: - if a character seen for the first time, its index is stored in the array. if the character is found again then its array value is set to -2 to represent this character is now repeating. after the string traversal traverse the visited array and check if value in the array is not equal to -1 or -2[means this character is not repeated]. we then find the smallest positive index from these values to find the first non repeating character. if no such index is found, return '$'

#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

char nonrep(const string& s){
	vector<int> vis(MAX_CHAR, -1);
	for(int i=0;i<s.length();++i){
		int index = s[i] - 'a';
		if(vis[index] == -1){
			vis[index] = i;
		}else{
			vis[index] = -2;
		}
	}
	int idx = -1;

	for(int i=0;i<MAX_CHAR; ++i){
		if (vis[i] >= 0 && (idx==-1 || vis[i] < vis[idx])){
			idx = i;
		}
	}
	return (idx==-1)?'$':s[vis[idx]];
}
int main(){
	string s = "aabbcccc";
	cout << nonrep(s) << endl;
	return 0;
}