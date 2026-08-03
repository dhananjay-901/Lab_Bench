//the reversal algorithm 
// The idea is based on the observation that if we right rotate the array by d positions, the last d elements will be in the front and first (n - d) elements will be at the end. First reverse all the elements of the array. Then reverse first d elements. Finally, reverse last (n - d) elements to get the final rotated array.

#include <bits/stdc++.h>
using namespace std;

void rotatearr(vector<int>& arr, int d){
	int n = arr.size();i
	d%=n;
	reverse(arr.being(), arr.end());
	reverse(arr.begin(), arr.begin()+d);

	reverse(arr.begin()+d, arr.end());
}

int main(){
	vector<int> arr = {1,2,3,4,5,6};
	int d = 2;
	rotatearr(arr, d);
	for(int i=0;i<arr.size();i++){
		cout << arr[i]<<" ";
	}
	return 0;
}