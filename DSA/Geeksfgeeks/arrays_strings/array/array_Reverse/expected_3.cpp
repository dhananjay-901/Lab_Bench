//idea is to use the in built reverse methods available across different languages 
#include <bits/stdc++.h>
using namespace std;

void reversearray(vector<int>& arr){
	reverse(arr.begin(), arr.end());
}

int main(){
	vector<int> arr = {1,4,3,2,6,5};
	reversearray(arr);
	for(int i=0;i<arr.size();i++) {
		cout << arr[i] << " ";
	}
	return 0;
}