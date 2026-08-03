// in the max one transaction allowed problem the goal is to maximise the profit by performing at most one transaction that is one buy and one sell.

//given an array prices[] of non negative integers representing the prices of the stocks on different days, return the maximum profit possible by buying and sellingg the stocks on different days when at most one transaction is allowed.
//

#include <bits/stdc++.h>
using namespace std;

int maxprofit(vector<int>& prices){
    int n = prices.size();
    int res = 0;

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            res = max(res, prices[j] - prices[i]);
        }
    }
    return res;
}
int main(){
    vector<int> prices = {7,10,1,3,6,9,2};
    cout << maxprofit(prices) << endl;
    return 0;
}
