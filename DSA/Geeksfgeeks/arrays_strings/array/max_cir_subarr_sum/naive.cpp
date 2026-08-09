//given a circular array arr[] find the maximum sum of any non empty subarray a circular array allows wrappiong from the end back to the beginning
//the idea is to considerevery element as the beginning of the subarray and calculate the maximum possible sum which includes both circular and linear subarrays from that element

#include <iostream>
#include <vector>
using namespace std;

int maxcircularsum(vector<int>& arr){
    int n = arr.size();
    int res = arr[0];
    for(int i=0;i<n;i++){
        int currsum = 0;
        for(int j = 0;j<n;j++){
            int idx = (i+j)%n;
            currsum = currsum + arr[idx];
            res = max(res, currsum);
        }
    }
    return res;
}

int main(){
    vector<int> arr = {8,-8,9,-9,10,-11,12};
    cout << maxcircularsum(arr);
    return 0;
}
