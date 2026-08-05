//we keep a running product while traversing the array and reset it to 1 whenever we encounter 0. the issue occurs when there is an odd number of negative elements, making the product negative. since the subarray must be contigour we can only exclude the fist or last negative element. traversing from both the start and the end allows us to handle both cases and find the maximum product subarray.

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int maxproduct(vector<int>& arr){
    int n = arr.size();
    int maxprod = INT_MIN;
    int lefttoright = 1;
    int righttoleft = 1;

    for(int i=0;i<n;i++){
        if(lefttoright == 0) lefttoright = 1;
        if(righttoleft == 0) righttoleft = 1;

        lefttoright *= arr[i];
        int j=n-i-1;
        righttoleft *=arr[j];
        maxprod = max({lefttoright, righttoleft, maxprod});
    }
    return maxprod;
}

int main(){
    vector<int> arr = {-2,6,-3,-10,0,2};
    cout << maxproduct(arr) << endl;
    return 0;
}
