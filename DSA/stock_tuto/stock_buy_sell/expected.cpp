//expected approach - one traversal solution - in order to maximuse the profit, we need to minimise the cost price and maximise the selling price. so at every step, we keep track of the minimum buy price of stock encountered so far. for every price we subtract with the minimum so far and if we get more profit than the current result we update the result
//
#include <iostream>
#include <vector>
using namespace std;

int maxprofit(vector<int>& prices){
    int minsofar = prices[0], res = 0;
    for(int i=1;i<prices.size();i++){
        minsofar = (min(minsofar,prices[i]));
        res = max(res, prices[i] - minsofar);
    }
    return res;
}


int main(){
    vector<int> prices = {7,10,1,3,6,9,2};
    cout << maxprofit(prices) << endl;
    return 0;
}
