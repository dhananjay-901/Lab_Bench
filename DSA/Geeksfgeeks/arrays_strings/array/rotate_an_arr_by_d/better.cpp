//The idea is to use a temporary array of size n, where n is the length of the original array. If we left rotate the array by d positions, the last n - d elements will be at the front and the first d elements will be at the end. Copy the last (n - d) elements of original array into the first n - d positions of temporary array. Then copy the first d elements of the original array to the end of temporary array.  Finally, copy all the elements of temporary array back into the original array.

#include <bits/stdc++.h>
using namespace std;

void rotatearr(vector<int>& arr, int d){
	int n = arr.size();
	d%=n;
	vector<int> temp(n);

	for(int i=0;i<n-d;i++){
		temp[i] = arr[d+i];
	}
	for(int i=0;i<d;i++){
		temp[n-d+i] = arr[i];
	}
	for(int i=0;i<n;i++){
		arr[i] = temp[i];
	}
}

int main(){
	vector<int> arr = { 1,2,3,4,5,6};
	int d = 2;
	rotatearr(arr,d);

	for(int i=0;i<arr.size();i++){
		cout << arr[i] << " ";
	}
	return 0;
}