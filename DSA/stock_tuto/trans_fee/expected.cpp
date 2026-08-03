#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxprofit(vector<int>& arr, int k){
    int n = arr.size();
    int nostock = 0, inhand = 0;
    for(int i=n-1;i>=0;i--){
        int newstock = max(nostock, inhand - arr[i]);
        int newhand = max(inhand, arr[i] - k +nostock);

        nostock = newstock;
        inhand = newhand;
    }
    return nostock;
}

int main(){
    vector<int> arr = {6,1,7,2,8,4};
    int k = 2;
    cout << maxprofit(arr,k) << endl;
    return 0;
}
