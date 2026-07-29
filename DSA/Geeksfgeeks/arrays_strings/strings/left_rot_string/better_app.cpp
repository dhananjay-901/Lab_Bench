//the idea is to use a temporary character array of size n(size of original string). if we left rotate the string by d positions, the last n-d elements will be at the front and first d elements will be at the end. 
#include <iostream>
#include <string>
using namespace std;

string rotatestring(string &s, int d){
	int n = s.length();
	d=d%n;
	char temp[n];
	for(int i=0;i<n-d;i++){
		temp[i] = s[d+i];
	}
	for(int i=0;i<d;i++){
		temp[n-d+i] = s[i];
	}
	return string(temp,n);
}

int main(){
	string s = "geeksforgeeks";
	int d = 2;
	string rotatedstring = rotatestring(s,d);
	cout << rotatedstring << endl;
	return 0;
}