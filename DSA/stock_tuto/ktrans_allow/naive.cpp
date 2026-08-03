#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxprofitutil(int i, int k, int buy, vector<int>& prices){
	if(k<=0 || i>=prices.size()) return 0;
	int res = 0;

	if(buy){
		res = max(maxprofitutil(i+1,k,0, prices) - prices[i], maxprofitutil(i+1,k,1,prices));
	}else{
		res = max(prices[i] + maxprofitutil(i+1,k-1,1,prices), maxprofitutil(i+1,k,0,prices));
	}
	return res;
}

int maxprofit(vector<int>& prices, int k){
	return maxprofitutil(0,k,1,prices);
}

int main(){
	int k=2;
	vector<int> prices = {10,22,5,80};
	cout << maxprofit(prices, k);
	return 0;
}