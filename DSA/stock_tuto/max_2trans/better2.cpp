//to avoid repeated calculations while exploring all possibilites, we can use memoization, where the result of each state (i,k,buy) is stored and resued whenever the same state is encountered again, this eliminating overlapping subproblems and improving efficiency 
#include <bits/stdc++.h>
using namespace std;

int maxprofitrec(int i, int k, int buy, vector<int>& prices, vector<vector<vector<int>>>& dp){
	if(i==prices.size() || k==0) return 0;

	if(dp[i][k][buy]!=-1) return dp[i][k][buy];

	int profit = 0;

	if(buy == 1){
		profit = max(-prices[i] + maxprofitrec(i + 1,k ,0, prices, dp), maxprofitrec(i+1,k,1,prices,dp));
	}

	else{
		profit = max(prices[i] + maxprofitrec(i+1, k-1, 1, prices, dp), maxprofitrec(i+1, k,0, prices, dp));
	}
	return dp[i][k][buy] = profit;
}

int maxProfit(vector<int>& prices){
	int n = prices.size();
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(3, vector<int>(2,-1)));
	return maxprofitrec(0,2,1,prices,dp);
}

int main(){
	vector<int> prices = {10, 22, 5, 75, 65, 80};
	cout << maxProfit(prices);
	return 0;
}