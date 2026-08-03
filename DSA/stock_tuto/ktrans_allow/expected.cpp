#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxprofit(vector<int>& prices, int k){
	int n = prices.size();
	vector<vector<int>> ahead(k+1, vector<int>(2,0)), curr(k+1, vector<int>(2,0));

	for(int i=n;i>=0;i--){
		for(int t=1;t<=k;t++){
			curr[t][1] = max(-prices[i] + ahead[t][0], ahead[t][1]);
			curr[t][0] = max(prices[i] + ahead[t-1][1]. ahead[t][0]);
		}
		ahead = curr;
	}
	return ahead[k][1];
}
int main(){
    int k = 2;
    vector<int> prices = {10,22,5,80};
    cout << maxprofit(prices, k) << endl;
    return 0;
}
