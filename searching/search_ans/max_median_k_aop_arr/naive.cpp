//given an array arr[] of positive integers and a value of k, you can perform at most k operations in each operation you may increment any one element of the array by 1. find the maximum median that can be achieved after performing at most k suck operations

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ispossible(vector<int>& arr,int target, int k){
    int n = arr.size();
    int used = 0;

    if(n%2==1){
        for(int i=n/2;i<n;++i){
            if(arr[i] < target) used+= (target - arr[i]);
            if(used > k) break;
        }
    }else{
        if(arr[n/2] <= target){
            used+=(target - arr[n/2]);
            used+=(target - arr[n/2-1]);
        }else{
            used+= (2*target - (arr[n/2] + arr[n/2-1]));
        }

        for(int i=n/2+1;i<n;++i){
            if(arr[i] < target) used+=(target - arr[i]);
            if(used > k) break;
        }
    }
    return used <= k;
}

int maximizemedian(vector<int>& arr, int k){
    int n = arr.size();
    sort(arr.begin(), arr.end());

    int inimedian = arr[n/2];
    if(n%2==0) {
        inimedian += arr[n/2-1];
        inimedian /= 2;
    }
    int best = inimedian;

    for(int target = inimedian; target <= inimedian + k; ++target){
        if(ispossible(arr, target, k)) best = target;
    }
    return best;
}

int main(){
    vector<int> arr = {1,3,4,5};
    int k = 3;
    int result = maximizemedian(arr, k);
    cout << result << endl;
    return 0;
}
