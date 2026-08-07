//recursive approach 
//process the string recursively by skipping whitespaces determining the sign, and building the number one digit at a time. at each recursive step, check for overflow and stop when a non digit character is encountered or the string ends

#include <iostream>
#include <string>
#include <limits>
using namespace std;

int parsedigit(const string& s, int idx, int res, int sign){
	if(idx >=s.size() || s[idx] < '0' || s[idx] > '9')
		return res * sign;
	int digit = s[idx] - '0';
	if(res > (INT_MAX - digit)/10)
		return sign == 1 ? INT_MAX : INT_MIN;
	return parsedigit(s,idx+1, res*10+digit,sign);
}

int myatoi(string& s){
	int idx = 0;

	while(idx < s.size() && s[idx] == ' ')
		idx++;
	int sign = 1;
	if(idx < s.size() && (s[idx]== '-' || s[idx] == '+')){
		if(s[idx]=='-')
			sign = -1;
		idx++;
	}
	return parsedigit(s,idx,0,sign);
}

int main(){
	string s = "-00123g4";
	cout << myatoi(s) << endl;
	return 0;
}