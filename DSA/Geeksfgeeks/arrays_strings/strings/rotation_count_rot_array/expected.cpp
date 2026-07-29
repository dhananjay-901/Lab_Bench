//binary search -- the idea is to use binary search to quickly locate the smalelst element, which reveals the rotation count.

#include <iostream>
#include <vector>
using namespace std;

int findrotation(vector<int>& arr){
	int low = 0, high = arr.size()-1;

	while(low<=high){
		if(arr[low]<=arr[high]) return low;

		int mid = (low+high)/2;

		if(arr[mid]>arr[high]) low = mid + 1;
		else high = mid; 
	}
	return low;
}

int main(){
	vector<int> arr = {15,18,2,3,6,12};
	cout << findrotation(arr) << endl;
	return 0;
}