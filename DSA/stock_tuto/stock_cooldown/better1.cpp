#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findprofit(int i, int buy, vector<int>& arr, vector<vector<int>>& dp){
    int n = arr.size();
    if(i>=n) return 0;
    if(dp[i][buy]!=-1) return dp[i][buy];
    if(buy){
        int take = -arr[i] + findprofit(i+1,0,arr,dp);
        int skip = findprofit(i+1,1,arr,dp);
        dp[i][buy] = max(take, skip);
    }else{
        int sell = arr[i] + findprofit(i+2,1, arr, dp);
        int skip = findprofit(i+1,1,arr,dp);
        dp[i][buy] = max(sell, skip);
    }
    return dp[i][buy];
}
int maxprofit(vector<int>& arr){
    int n = arr.size();

    vector<vector<int>> dp(n,vector<int>(2,-1));
    return findprofit(0,1,arr,dp);
}

int main(){
    vector<int> arr = {0,2,1,2,3};
    cout << maxprofit(arr) << endl;
    return 0;
}
