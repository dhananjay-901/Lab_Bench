//stock buy and sell - max one transaction allowed
//
// given an array pieces of non negative integers, representing the prices of the stocks on different days, return the maximum profit possible by buying and selling the stocks on different days when at most one transaction is allowed. here one transaction means 1 buy +1 sell. if it is not possible to make a profit then return 0

//the idea is to use two nested loops to explore all the possible ways to buy and sell stock. the outer loop decides the day to buy the stock and the inner loop decides the day to sell the stock. the maximum difference between the selling price and buying price between every pair of days will be our answer
//
//
#include <iostream>
#include <vector>
using namespace std;

int maxprofit(vector<int>& prices){
    int n = prices.size();
    int res = 0;

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            res = max(res,prices[j] - prices[i]);
        }
    }
    return res;
}

int main(){
    vector<int> prices = {7,10,1,3,6,9,2};
    cout << maxprofit(prices) << endl;
    return 0;
}
