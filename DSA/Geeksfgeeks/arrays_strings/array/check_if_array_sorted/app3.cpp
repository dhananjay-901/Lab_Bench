//using in built methods
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool issorted(vector<int>& arr){
	return (is_sorted(arr.begin(), arr.end()));
}

int main(){
	vector<int> arr = {10,20,30,40,50,60};
	cout << ((issorted(arr))?"true":"false");
	return 0;
}