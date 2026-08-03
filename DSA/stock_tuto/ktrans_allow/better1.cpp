#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int maxprofitutil(int i, int k, int buy, vector<int>& prices, vector<vector<vector<int>>>& dp){
    if(k<=0 || size_t(i) >= prices.size()) return 0;

    if(dp[i][k][buy]!=-1) return dp[i][k][buy];
    int res = 0;
    if(buy){
        res = max(-prices[i] + maxprofitutil(i+1,k,0,prices,dp),maxprofitutil(i+1,k,1,prices,dp));
    }else{
        res = max(prices[i] + maxprofitutil(i+1,k-1,1,prices, dp), maxprofitutil(i+1,k,0,prices,dp));
    }
    return dp[i][k][buy] = res;
}

int maxprofit(vector<int>& prices, int k){
    int n = prices.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1, vector<int>(2,-1)));
    return maxprofitutil(0,k,1,prices,dp);
}
int main(){
    vector<int> prices = {10, 22, 5, 80};
    int k = 2;
    cout << maxprofit(prices, k);
    return 0;
}
