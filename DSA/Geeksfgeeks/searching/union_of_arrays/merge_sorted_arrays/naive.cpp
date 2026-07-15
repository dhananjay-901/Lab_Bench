/*Given two sorted arrays arr1[] of size n and arr2[] of size m. Merge these two arrays.
After the merge, the first n smallest elements of the combined sorted array should be stored in arr1[], and the remaining m largest elements should be stored in arr2[]. After the merging process, both arr1[] and arr2[] must remain sorted in non-decreasing order.

The idea is to combine both sorted arrays into a single temporary array, then sort this combined array to get all elements in non-decreasing order. Once sorted, the first n smallest elements are copied back into arr1, and the remaining m largest elements are placed into arr2.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void mergearrays(vector<int>& arr1, vector<int>& arr2){
    int n = arr1.size();
    int m = arr2.size();

    vector<int> merged(n+m);

    for(int i = 0; i < n; ++i){
        merged[i] = arr1[i];
    }
    for(int j = 0; j < m ; ++j){
        merged[n+j] = arr2[j];
    }

    sort(merged.begin(), merged.end());

    for(int i = 0; i < n; ++i){
        arr1[i] = merged[i];
    }
    for(int j = 0; j < m; ++j){
        arr2[j] = merged[n+j];
    }
}

int main(void){
    vector<int> arr1 = {1,3,5,7};
    vector<int> arr2 = {2,4,6,8};
    mergearrays(arr1, arr2);

    for(int num:arr1){
        cout << num << "\n";
    }
    for(auto num:arr2){
        cout << num << "\n";
    }
    return 0;
}