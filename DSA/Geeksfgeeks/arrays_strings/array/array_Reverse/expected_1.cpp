//the idea is to maintain two pointers left and right such that left points at the beginning of the array and right points to the end of the array. while left pointer is less than the right pointer swap the elements at these two positions. after each swap increment the left pointer and decrement the right pointer to move towards the center of the array. this will swap all the elements in the first half with their corresponding element in the second half.

#include <iostream>
#include <vector>
using namespace std;

void reversearray(vector<int>& arr){
	int left = 0, right = arr.size()-1;
	while(left<right){
		swap(arr[left], arr[right]);
		left++;
		right--;
	}
}

int main(){
	vector<int> arr = {1,4,3,2,6,5};

	reversearray(arr);
	for(int i=0;i<arr.size();i++) cout << arr[i] << " ";
		return 0;
}