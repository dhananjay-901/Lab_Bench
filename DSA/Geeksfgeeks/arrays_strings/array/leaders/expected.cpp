//the idea is to scan all the elements from right to left in an array and keep tracj of the maximum till now. when the maximum changes its values, add it to the result finally reverse the result 

#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int>& arr){
	vector<int> res;
	int n = arr.size();
	int maxright = arr[n-1];
	res.push_back(maxright);

	for(int i=n-2; i>=0;i--){
		if(arr[i] >= maxright){
			maxright = arr[i];
			res.push_back(maxright);
		}
	}

	reverse(res.begin(), res.end());
	return res;
}

int main(){
	vector<int> arr = {16,17,4,3,5,2};
	vector<int> res = leaders(arr);
	for(int x : res){
		cout << x << " ";
	}
	cout << endl;
	return 0;
}