//aive approach - in each iteration shift the elements by one position to the left in a circular fashion first element becomes the last. perform this operation d times to rotate the elements to the elft by d positions 

#include <bits/stdc++.h>
using namespace std;

void rotatearr(vector<int>& arr, int d){
	int n = arr.size();
	for(int i=0;i<d;i++){
		int first = arr[0];
		for(int j=0;j<n-1;j++){
			arr[j]=arr[j+1];
		}
		arr[n-1] = first;
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
