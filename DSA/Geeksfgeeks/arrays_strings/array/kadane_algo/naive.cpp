//given an integer array arr[] find the subarray(containing at least one element) which has the maximum possible sum, and return that sum
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxsubarraysum(vector<int>& arr){
    int res = arr[0];
    for(int i=0;i<arr.size();i++){
        int currsum=0;
        for(int j=i;j<arr.size();j++){
            currsum = currsum + arr[j];
            res = max(res, currsum);
        }
    }
    return res;
}

int main(){
    vector<int> arr = {2,-3,-8,7,-1,2,3};
    cout << maxsubarraysum(arr);
    return 0;
}
