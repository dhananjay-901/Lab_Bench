//given an array arr[] denoting the cost of stock on each day and an integer k representing a transation fee. find the maximum total profit if we can buy and sell the stocks any number of times givent hat each transaction costs fee k.

#include <iostream>
#include <vector>
using namespace std;

int maxprofitrec(vector<int>& arr, int ind, int buy, int k){
	int n = arr.size();
	if(ind == n ) return 0;

	int profit;

	if(buy==0){
		profit = max(maxprofitrec(arr, ind+1, 0, k),maxprofitrec(arr, ind+1,1,k)-arr[ind]);
	}
	if(buy==1){
		profit = max(maxprofitrec(arr, ind+1,1,k), arr[ind] - k + maxprofitrec(arr,ind+1,0,k));
	}
	return profit;
}


int maxprofit(vector<int>& arr, int k){
	int n = arr.size();
	return maxprofitrec(arr,0,0,k);
}
int main(){
	vector<int> arr = {6,1,7,2,8,4};
	int k = 2;
	cout << maxprofit(arr,k);
	return 0;
}
