#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxprofit(vector<int>& prices, int k){
	int n = prices.size();
	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1,vector<int>(2,0)));

	for (int i = n-1; i >= 0; i--){
		for(int j=1;j<=k;j++){
			dp[i][j][1] = max(-prices[i] + dp[i+1][j][0], dp[i+1][j][1]);
			dp[i][j][0] = max(prices[i] + dp[i+1][j-1][1], dp[i+1][j][0]);
		}
	}
	return dp[0][k][1];
}

int main(){
	int k = 2;
	vector<int> prices = {10,22,5,80};
	cout << maxprofit(prices, k) << endl;
	return 0; 
}