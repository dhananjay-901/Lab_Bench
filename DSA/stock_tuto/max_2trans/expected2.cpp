#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int maxprofit(vector<int>& prices){
	int firstbuy = INT_MIN;
	int firstsell = 0;
	int secondbuy = INT_MIN;
	int secondsell = 0;

	for(int i=0;i<prices.size();i++){
		firstbuy = max(firstbuy, -prices[i]);
		firstsell = max(firstsell, firstbuy + prices[i]);
		secondbuy = max(secondbuy, firstsell - prices[i]);
		secondsell = max(secondsell, secondbuy + prices[i]);
	}
	return secondsell;
}

int main(){
	vector<int> prices = {10, 22, 5, 75, 65, 80};
	cout << maxprofit(prices) << endl;
	return 0;
}
