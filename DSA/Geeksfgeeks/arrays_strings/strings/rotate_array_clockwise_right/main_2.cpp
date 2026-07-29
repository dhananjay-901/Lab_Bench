//using temporary array 
//The idea is to use a temporary array of size n, where n is the length of the original array. If we right rotate the array by d positions, the last d elements will be in the beginning and the first (n - d) elements will be at the end. Copy the last d elements of the original array into the first d positions of the temporary array Then copy the first n - d elements of the original array to the end of temporary array. Finally, copy all the elements of temporary array back into the original array.

#include <bits/stdc++.h>
using namespace std;

void rotatearr(vector<int>& arr, int d){
	int n = arr.size();
	d%=n;
	vector<int> temp(n);

	for(int i=0;i<d;i++) temp[i] = arr[n-d+i];
	for(int i=0;i<n-d;i++) temp[i+d] = arr[i];
	for(int i=0;i<n;i++) arr[i] = temp[i];
}

int main(){
	vector<int> arr = {1,2,3,4,5,6};
	int d = 2;
	rotatearr(arr,d);
	for(int i=0;i<arr.size();i++){
		cout << arr[i] << " ";
	}
	return 0;
}