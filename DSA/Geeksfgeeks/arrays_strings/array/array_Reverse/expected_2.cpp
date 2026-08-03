//the idea is to iterate over the first half of the arry and swap each element with its corresponding element from the end. so while iterating over the first half, any element at index i is swapped with the element at index (n-i-1)

#include <bits/stdc++.h>
using namespace std;

void reversearray(vector<int>& arr){
	int n = arr.size();
	for(int i=0;i<n/2;i++){
		swap(arr[i], arr[n-i-1]);
	}
}

int main(){
	vector<int> arr = {1,4,3,2,6,5};
	reversearray(arr);
	for(int i=0;i<arr.size();i++) cout << arr[i] << " ";
	return 0;
}