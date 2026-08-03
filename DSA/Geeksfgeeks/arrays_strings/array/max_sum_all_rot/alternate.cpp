//alternate approach - we know for an array the maximum sum will be when the array is sorted in ascending order. in case of a sorted rotated array, we can rotate the array to make it in ascending order. so in this case, the pivot element is needed to be found following which the maximum sum can be calculated.

#include <iostream>
#include <vector>
using namespace std;

int findpivot(vector<int>& arr){
	int n = arr.size();
	for(int i=0;i<n;i++){
		if(arr[i]>arr[i+1]%n) return i;
	}
	return 0;
}

int maxsum(vector<int>& arr){
	int n = arr.size();
	int res = 0;
	int pivot = findpivot(arr);
	int diff =  n-1 - pivot;

	for(int i=0;i<n;i++){
		res = res + ((i+diff)%n*arr[i]);
	}
	return res;
}

int main(){
	vector<int> arr = {8,3,1,2};
	cout << maxsum(arr);
	return 0;
}