//The idea is based on the observation that if we left rotate the string by d positions, the last (n – d) elements will be at the front and the first d elements will be at the end. Reverse the substring containing the first d elements of the string. Reverse the substring containing the last (n – d) elements of the string. Finally, reverse all the elements of the string.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void rotatestring(string& s, int d){
	int n = s.size();
	d%=n;
	reverse(s.begin(), s.begin()+d);
	reverse(s.begin() + d, s.end());
	reverse(s.begin(), s.end());
}
int main(){
	string s = "geeksforgeeks";
	int d = 2;
	rotatestring(s,d);
	cout << s << endl;
	return 0;
}