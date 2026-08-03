//given an array arr[] of the size N the task is to rotate the array by d position to the left.

#include <algorithm> // for reverse function 
#include <iostream> // for input and output function
#include <vector> //for vector container 
using namespace std;

void rotatearray(vector<int>& arr, int k){
	int n = arr.size();
	k%=n;

	reverse(arr.begin(), arr.end());
	reverse(arr.begin(), arr.begin()+k);
	reverse(arr.begin()+k, arr.end());
}
int main(){
	vector<int> arr = {1,2,3,4,5};
	int k = 2;
	rotatearray(arr,k);
	for(int i:arr){
		cout << i << " ";
	} 
	return 0;
}
