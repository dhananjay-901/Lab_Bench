//we traverse from the second element. for every element we check if it is smaller than or equal to previous element or not. at any point if we find the previous element greater we return false

#include <iostream>
#include <vector>
using namespace std;

bool issorted(vector<int>& arr){
	for(int i=1;i<arr.size();i++){
		if(arr[i-1]>arr[i])
			return false;
	}
	return true;
}

int main(){
	vector<int> arr = {10,20,30,40,50};
	cout << (issorted(arr)? "true":"false");
	return 0;
}