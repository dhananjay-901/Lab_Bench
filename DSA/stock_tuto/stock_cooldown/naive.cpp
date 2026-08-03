#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findprofit(int i, int buy, vector<int>& arr){
    int n = arr.size();
    if(i>=n) return 0;
    if(buy){
        int take = -arr[i] + findprofit(i+1,0,arr);
        int skip = findprofit(i+1,1,arr);
        return max(take, skip);
    }else{
        int sell = arr[i] + findprofit(i+2,1,arr);
        int skip = findprofit(i+1,0,arr);
        return max(sell, skip);
    }
}

int maxprofit(vector<int>& arr){
    return findprofit(0,1,arr);
}

int main(){
    vector<int> arr = {0,2,1,2,3};
    cout << maxprofit(arr) << endl;
    return 0;
}
