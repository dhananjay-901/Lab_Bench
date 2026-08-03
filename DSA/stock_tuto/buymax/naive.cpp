//given ana array price[], where price[i] represents the price of a stock on the i+1 day and an integer k representing the amount of money available
// the idea is to process the days one by one and recursively try buying every possible number of stocks on each day. one the i+1 day we can buy from 0 to i+1 stocks as long as the total cost doest not exceeed the remaining amount. for each valid choicem recursively solve the remaining days with the updated budget and return the maximum number of stocks that can be purchased. since the same states are recomputed times, this approach is inefficient for large inputs

#include <bits/stdc++.h>
using namespace std;

int solve(int day, int money, vector<int>& price){
    if(day==price.size()) return 0;
    int ans = 0;

    for(int buy = 0; buy<=day+1;buy++){
        int cost = buy * price[day];
        if(cost <=money){
            ans = max(ans, buy+solve(day + 1, money - cost, price));
        }
    }
    return ans;
}

int buymaxproducts(int k, vector<int>& price){
    return solve(0,k,price);
}
int main(){
    vector<int> price = {10,7,19};
    int k = 45;
    cout << buymaxproducts(k,price);
    return 0;
}
