//given an array arr[] and an integer k, find the array after reversing every subset of consecutive k elements in place. if the last subarray has fewer than k elements, reverse it as it is. modify the array is place, do not return anything

#include <iostream>
#include <vector>
using namespace std;

void reverseingroups(vector<int>& arr, int k){
	int n = arr.size();

	for(int i=0;i<n;i+=k){
		int left = i;
		int right = min(i+k-1, n-1);
		while(left <right){
			swap(arr[left++], arr[right--]);
		}
	}
}

int main(){
	vector<int> arr = {1,2,3,4,5,6,7,8};
	int k = 3;
	reverseingroups(arr, k);
	for(int num : arr)
		cout << num << " ";
	return 0;
}