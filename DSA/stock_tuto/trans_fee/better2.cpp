#include <iostream>
#include <vector>
using namespace std;

int maxprofit(vector<int>& arr, int k){
    int n = arr.size();

    vector<vector<int>> dp(n+1, vector<int>(2,0));
    for(int ind = n-1;ind>=0;ind--){
        for(int buy = 0;buy<=1;buy++){
            int profit;
            if(buy==0){
                profit = max(dp[ind+1][0],dp[ind+1][1]-arr[ind]);
            }
            if(buy==1){
                profit = max(dp[ind+1][1],arr[ind] - k + dp[ind + 1][0]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][0];
}
int main(){
    vector<int> arr = {6,1,7,2,8,4};
    int k = 2;
    cout << maxprofit(arr,k) << endl;
    return 0;
}
