#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    
    vector<int> postfix(n, 0);
    int maxPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        maxPrice = max(maxPrice, prices[i]);
        postfix[i] = max(postfix[i + 1], maxPrice - prices[i]);
    }
    int minPrice = prices[0], res = postfix[0];
    for (int i = 1; i < n; i++) {
        minPrice = min(minPrice, prices[i]);
        int first = prices[i] - minPrice;
        res = max(res, first + postfix[i]);
    }
    return res;
}

int main() {
    vector<int> prices = {10, 22, 5, 75, 65, 80};
    cout << maxProfit(prices);
    return 0;
}
