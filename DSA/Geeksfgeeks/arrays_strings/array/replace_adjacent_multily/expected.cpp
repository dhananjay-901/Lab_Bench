//the idea is to update the array in place while keeping track of the previous original element using a variable prev.

#include <iostream>
#include <vector>
using namespace std;

void updatearray(vector<int>& arr){
	int n = arr.size();
	int prev = 1;
	for(int i = 0; i < n; i++){
	    int curr = arr[i];
		int next = (i == n - 1) ? 1 : arr[i + 1];
		arr[i] = prev * curr * next;
		prev = curr;
	}
}

int main(){
    vector<int> arr = {2,4,5};
    updatearray(arr);
    for(auto it : arr){
        cout << it << " ";
    }
    return 0;
}
