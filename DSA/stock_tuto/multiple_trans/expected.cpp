//the idea is that profit only comes when price rise. if the price goes up from tone day to the nest, we can think of it as buying yesterday and selling today. instead of waiting for the exact bottom and top, we simply grab every small upward move. adding these small gains together is the same as if we had bought at each vally and sold at each peak because every rise between them gets counted

#include <bits/stdc++.h>
using namespace std;

int maxprofit(const vector<int>& prices){
	int res = 0;
	for(int i=1;i<prices.size();i++){
		if(prices[i] > prices[i-1])
			res+=prices[i] - prices[i-1];
	}
	return res;
}
int main(){
	vector<int> prices = {100,180,260, 310, 40, 535, 695};
	cout << maxprofit(prices) << endl;
	return 0;
}