//the idea is use two pointers, one pointer will start from start of s1 and another will start from of s2. if the current character of both the indexes are same then increment both pointers otherwise increment the pointer which is pointer to s2
#include <iostream>
#include <string>
using namespace std;

bool issubseq(string& s1, string& s2){
	int m = s1.length(), n = s2.length();

	if(m>n) return false;

	int i=0,j=0;
	while(i<m && j<n){
		if(s1[i] == s2[j])
			i++;
		j++;
	}
	return i == m;
}

int main(){
	string s1 = "gksrek";
	string s2 = "geeksforgeeks";
	issubseq(s1,s2) ? cout << "true" : cout << "false";
	return 0;
}