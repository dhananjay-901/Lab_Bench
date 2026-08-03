#include <bits/stdc++.h>
using namespace std;

int maxprofone(vector<int>& prices, int idx){
	int minsofar = prices[idx], res = 0;
	for(int i=idx+1;i<prices.size();i++){
		minsofar=min(minsofar, prices[i]);
		res = max(res,prices[i] - minsofar);
	}
	return res;
}

int maxprofit(vector<int>& prices){
	int n = prices.size();
	int minsofar = prices[0], res = 0;
	for(int i=1;i<n;i++){
		if(prices[i]>minsofar){
			int curr = prices[i] - minsofar + maxprofone(prices, i+1);
			res = max(res, curr);
		}else{
			minsofar = min(minsofar, prices[i]);
		}
	}
	return res;
}

int main(){
	vector<int> prices = {10,22,5,75,65,80};
	cout << maxprofit(prices) << endl;
	return 0;
}