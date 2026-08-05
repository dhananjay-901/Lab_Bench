//given an array and number k, find the largest sum of contihour array in the modified array which is formed by repeated the given array k times.

//this is expected approach

#include <bits/stdc++.h>
using namespace std;

int maxsubarraysumrepeated(vector<int>& arr, int k){
    int n = arr.size();
    int maxsofar = INT_MIN, maxendinghere = 0;

    for(int i=0;i<n*k;i++){
        maxendinghere += arr[i%n];

        maxsofar = max(maxsofar, maxendinghere);

        if(maxendinghere < 0) maxendinghere = 0;
    }
    return maxsofar;
}

int main(){
    vector<int> arr = {10,20,-30,-1};
    int k = 3;
    cout << maxsubarraysumrepeated(arr, k) << endl;
    return 0;
}
