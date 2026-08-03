//the idea is to create a 2d array memo of order n*2 where element memo[i][0] stores the maximum profit from day i to n-1 when no previous stock is pending and memo[i][1] stores maximum profit from day i to n-1 where there is previous stock remaining. for each recursive call, check if the sub array is already computed. if so return the stored valye else proceed as in above approach

#include <iostream>
#include <vector>
using namespace std;

int maxprofitrec(vector<int>& arr, int ind, int buy, int k, vector<vector<int>>& memo){
    int n = arr.size();
    if(ind == n) return 0;
    if(memo[ind][buy] != -1) return memo[ind][buy];

    int profit;
    if(buy==0){
        profit = max(maxprofitrec(arr,ind+1,0,k,memo),maxprofitrec(arr, ind+1,1,k,memo)-arr[ind]);
    }
    if(buy==1){
        profit = max(maxprofitrec(arr,ind+1,1,k,memo), arr[ind] - k + maxprofitrec(arr,ind + 1, 0, k,memo));
    }
    return memo[ind][buy] = profit;
}

int maxprofit(vector<int>& arr, int k){
    int n = arr.size();
    vector<vector<int>> memo(n, vector<int>(2,-1));
    return maxprofitrec(arr,0,0,k,memo);
}

int main(){
    vector<int> arr = {6,1,7,2,8,4};
    int k = 2;
    cout << maxprofit(arr, k) << endl;
    return 0;
}
