//given an array arr[] consisting of positive, negative and zero values, find the maximum product that can be obtained from any contigous subarray of arrp[]
//the idea is to traverse over every contigous subarray, find the product of each of these subarrays and return the maximum product among all the subarrays

#include <iostream>
#include <vector>
using namespace std;

int maxproduct(vector<int>& arr){
    int n = arr.size();
    int maxprod = arr[0];

    for(int i=0;i<n;i++){
        int mul = 1;
        for(int j=i;j<n;j++){
            mul*=arr[j];
            maxprod = max(maxprod, mul);
        }
    }
    return maxprod;
}

int main(){
    vector<int> arr = {-2,6,-3,-10,0,2};
    cout << maxproduct(arr) << endl;
    return 0;
}
