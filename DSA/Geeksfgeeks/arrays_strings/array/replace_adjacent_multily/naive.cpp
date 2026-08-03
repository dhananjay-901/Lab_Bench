//naive approach - the idea is to use a temporary array to store the updated values. this avoids losing the original values while computing the product for each element. after processing all elements, copy the temporary array back to the original array

#include <iostream>
#include <vector>
using namespace std;

void updatearray(vector<int>& arr){
	int n = arr.size();
	vector<int> temp(n);

	for(int i=0;i<n;i++){
		int prev = (i==0)?1:arr[i-1];
		int next = (i==n-1)?1:arr[i+1];
		temp[i] = prev * arr[i] * next;
	}
	arr = temp;
}
int main(){
	vector<int> arr = {2,4,5};
	updatearray(arr);
	for(auto it:arr) cout << it << " ";
	return 0;
}
