//the idea is to traverse the array from left to right and find local minima where price starts rising and then a local maxima (where price stops rising). compute the difference between two and add to the result.

#include <iostream>
#include <vector>
using namespace std;

int maxprofit(vector<int>& prices){
    int n = prices.size();
    int lmin = prices[0];
    int lmax = prices[0];
    int res = 0;

    int i = 0;
    while(i < n-1){
        while(i<n-1 && prices[i]>=prices[i+1]) {i++;}
        lmin = prices[i];
        while(i<n-1 && prices[i]<=prices[i+1]) {i++;}
        lmax = prices[i];
        res = res + (lmax - lmin);
    }
    return res;
}

int main(){
    vector<int> prices = {100,180, 260, 310, 40, 535, 695};
    cout << maxprofit(prices);
    return 0;
}
