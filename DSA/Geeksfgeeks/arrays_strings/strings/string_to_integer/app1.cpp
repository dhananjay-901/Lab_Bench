//given a string s convert it into integer format without utilizing any built in functions
//iterative approach

//traverse the string from left to right skipping whitespaces, handling the optional sign, and building the number digit by digit. at each step ensure the valeu stays with in 32 bit integer limits to avoid overflow

#include <iostream>
#include <climits>
using namespace std;

int myatoi(string& s){
	int sign = 1, res = 0, idx = 0;
	while(idx <s.size() && s[idx] == ' '){
		idx++;
	}
	if(idx < s.size() && s[idx] == '-' || s[idx] == '+'){
		if(s[idx++] == '-')
			sign = -1;
	}
	while(idx < s.size() && s[idx] >= '0' && s[idx] <= '9'){
		if(res > INT_MAX/10 || (res == INT_MAX/10 && s[idx] - '0' > 7)){
			return sign == 1 ? INT_MAX : INT_MIN;
		}
		res = 10 * res + (s[idx++] - '0');
	}
	return res * sign;
}

int main(){
	string s = " -0012g4";
	cout << myatoi(s);
	return 0;
}