//expected approach 
//The array is sorted and then rotated, so it consists of two sorted parts, with the minimum element located at the rotation point. Using Binary Search, we can efficiently narrow down the part that contains the minimum by checking whether the current range is already sorted and by comparing the middle element with the last element.

#include <iostream>
#include <vector>
using namespace std;

int findmin(vector<int>& arr){
	int low = 0, high = arr.size()-1;

	while(low < high){
		if(arr[low]<arr[high]) return arr[low];
		int mid = (low+high)/2;
		if(arr[mid]>arr[high]) low = mid + 1;
		else high = mid;
	}
	return arr[low];
}

int main(){
	vector<int> arr = {5,6,1,2,3,4};
	cout << findmin(arr);
	return 0;
}