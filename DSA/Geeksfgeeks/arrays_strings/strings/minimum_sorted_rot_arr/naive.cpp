//given a sorted array of distinct elements arr[] of size n that is rotated at some unknown point, the task is to find the minimum element in it.

#include <iostream>
#include <vector>
using namespace std;

int findmin(vector<int>& arr){
	int res = arr[0];
	for(int i=1;i<arr.size();i++) res=min(res, arr[i]);
	return res;
}
int main(){
	vector<int> arr = {5,6,1,2,3,4};
	int n = arr.size();
	cout << findmin << endl;
	return 0;
}
