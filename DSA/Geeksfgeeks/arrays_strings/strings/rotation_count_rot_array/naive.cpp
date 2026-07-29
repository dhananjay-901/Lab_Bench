//rotation count in rotated sorted array
//Given a sorted array arr[] (in strictly increasing order) that has been right-rotated k times. A right rotation means the last element is moved to the first position, and the remaining elements are shifted one position to the right. Find the value of k the number of times the array was right-rotated from its originally sorted form.

//the idea is that in a rigth rotated sorted array, the smallest element marks the point of rotation. by scanning through the array to find this smallest element, its index directly gives the number of rotations performed

#include <iostream>
#include <vector>
using namespace std;

int findrotation(vector<int>& arr){
	int main=arr[0], minindex = 0;
	for(int i=0;i<arr.size();i++){
		if(min>arr[i]){
			min = arr[i];
			minindex = i;
		}
	}
	return minindex;
}

int main(){
	vector<int> arr = {15,18,2,3,6,12};
	cout << findrotation(arr);
	return 0;
}
