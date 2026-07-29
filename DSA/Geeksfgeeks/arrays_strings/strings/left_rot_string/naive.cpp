//the idea is to store the first character in a variable and shift all the remaining characters to the left by one position, then place the first character at the end of the string. this process is repeated d times.

#include <iostream>
#include <string>
using namespace std;

void rotatestring(string& s, int d){
	int n = s.size();
	for(int i=0;i<d;i++){
		int first=s[0];
		for(int j=0;j<n-1;j++) s[j] = s[j+1];
		s[n-1]= first;
	}
}

int main(){
	string s = "geeksforgeeks";
	int d = 2;
	rotatestring(s,d);
	cout << s << endl;
	return 0;
}
