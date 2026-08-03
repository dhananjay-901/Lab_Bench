#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxprofit(vector<int>& arr){
	int n = arr.size();
	vector<vector<int>> dp(n+2, vector<int>(2,0));
	for(int i=n-1;i>=0;i--){
		dp[i][1] = max(-arr[i] + dp[i+1][0], dp[i+1][1]);
		dp[i][0] = max(arr[i] + dp[i+2][1], dp[i+1][0]);
	}
	return dp[0][1];
}

int main(){
	vector<int> arr = {0,2,1,2,3};
	cout << maxprofit(arr) << endl;
	return 0;
}