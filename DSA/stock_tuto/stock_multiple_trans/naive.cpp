//given an array prices  representing stock prices, find the maximum total profit that can be earned by buying and selling the stock any number of times.
#include <iostream>
#include <vector>
using namespace std;

int maxprofitrec(vector<int>& price, int start, int end){
    int res = 0;
    for(int i=start;i<end;i++){
        for(int j=i+1;j<=end;j++){
            if(price[j] > price[i]){
                int curr = (price[j] - price[i]) + maxprofitrec(price, start, i-1) + maxprofitrec(price, j+1, end);
                res = max(res, curr);
            }
        }
    }
    return res;
}

int maxprofit(vector<int>& prices){
    return maxprofitrec(prices, 0, prices.size() - 1);
}

int main(){
    vector<int> prices = {100,180, 260, 310, 40, 535, 695};
    cout << maxprofit(prices);
    return 0;
}
