//naive approach
//the idea is to find the sum of all the elements of the array for each possible rotation and store the maximum of them as answer. To do so, use nested loops, where the outer loop marks the starting point of the array, and the inner loop iterates through each of the element, and store the sum of i * arr[i]. Check if the maximum sum is greater than the current sum then update the maximum sum.

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int maxsum(vector<int>& arr){
	int n = arr.size();
	int res =  INT_MIN;

	for(int i=0;i<n;i++){
		int sum = 0;
		for(int j=0;j<n;j++){
			int index = (i+j)%n;
			sum+=j * arr[index];
		}
		res = max(res,sum);
	}
	return res;
}

int main(){
	vector<int> arr = {8,3,1,2};
	cout << maxsum(arr);
	return 0;
}
