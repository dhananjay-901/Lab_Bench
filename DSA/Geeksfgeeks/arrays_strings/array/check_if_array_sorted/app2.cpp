#include <iostream>
#include <vector>
using namespace std;

bool issortedhelepr(vector<int>& arr, int n){
	if(n==0 || n==1) return true;
	return arr[n-1] >= arr[n-2] && issortedhelepr(arr, n-1);
}

bool issorted(vector<int>& arr){
	return issortedhelepr(arr, arr.size());
}

int main(){
	vector<int> arr = {10,20,30,40,50,60};
	cout << (issorted(arr)?"true":"false");
	return 0;
}