//the idea of kadane's algorithm is to traverse over the array from the left to right and for each element, find the maximum sum among all subarrays ending at that element. the result will be the maximum of all these values.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxsubarraysum(vector<int>& arr){
    int res = arr[0];
    int maxending = arr[0];

    for(int i=1;i<arr.size();i++){
        maxending = max(arr[i], maxending +  arr[i]);
        res = max(res, maxending);
    }
    return res;
}

int main(){
    vector<int> arr = {2,3,-8,7,-1,2,3};
    cout << maxsubarraysum(arr);
    return 0;
}
