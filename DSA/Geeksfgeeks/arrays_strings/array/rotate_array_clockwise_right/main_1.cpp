//rotate an array - clockwise or right
//Rotations in the array is defined as the process of rearranging the elements in an array by shifting each element to a new position. This is mostly done by rotating the elements of the array clockwise or counterclockwise.

//right rotation - clockwise
//rotate one by one - at each iteration, shift the elements by one position to the right in a circular fashion (the last element becomes the first) perform this operation d times to rotate the elements to the right by d positions

#include <bits/stdc++.h>
using namespace std;

void rotatearr(vector<int>& arr, int d){
	int n = arr.size();
	for(int i=0;i<d;i++){
		int last = arr[n-1];
		for(int j=n-1;j>0;j--){
			arr[j]=arr[j-1];
		}
		arr[0] = last;
	}
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
