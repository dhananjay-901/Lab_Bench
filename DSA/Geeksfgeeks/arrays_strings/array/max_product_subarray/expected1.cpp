//the main idea is to traveres the array while keeping track of both the maximum and minimum product ending at each index. a zero resets the product since any subarray containing it has product zero, while a negative number can turn a minimum product into a maximum one. by maintaining both values, we can correctly compute the maximum product subarray in a single pass.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxproduct(vector<int>& arr){
    int n = arr.size();
    int currmax = arr[0];
    int currmin = arr[0];
    int maxprod = arr[0];

    for(int i=1;i<n;i++){
        int temp = max({arr[i], arr[i] * currmax, arr[i] * currmin});

        currmin = min({arr[i], arr[i]*currmax, arr[i]*currmin});

        currmax = temp;
        maxprod = max(maxprod, currmax);
    }
    return maxprod;
}

int main(){
    vector<int> arr = {-2,6,-3,-10,0,2};
    cout << maxproduct(arr);
    return 0;
}
