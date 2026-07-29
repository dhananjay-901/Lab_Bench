//expected approach 
//the main idea is to instead of recalculating the weighted sum from scratch for each rotation, it first computres the total sum of the array and the initial rotation value. then for each subsequent rotation, it derives the new value using a formula based on the previous value and the total sum. and find the maximum value of the sum across all rotations of the array

#include <iostream>
#include <vector>
using namespace std;

int maxsum(vector<int>& arr){
	int n = arr.size();
	int cursum = 0;
	for(int i=0;i<n;i++) cursum+=arr[i];
	int currval = 0;
	for(int i=0;i<n;i++) currval+=i*arr[i];

	int res = currval;

	for(int i=1;i<n;i++){
		int nextval=currval-(cursum-arr[i-1])+arr[i-1]*(n-1);
		currval=nextval;
		res = max(res, nextval);
	}
	return res;
}

int main(){
	vector<int> arr = {8,3,1,2};
	cout << maxsum(arr);
	return 0;
}