/*Given two sorted arrays arr1[] of size n and arr2[] of size m. Merge these two arrays.
After the merge, the first n smallest elements of the combined sorted array should be stored in arr1[], and the remaining m largest elements should be stored in arr2[]. After the merging process, both arr1[] and arr2[] must remain sorted in non-decreasing order.*/

/*The idea is to use the two-pointer to merge both sorted arrays into a temporary array in linear time. We compare elements from arr1 and arr2 one by one and append the smaller element to the merged array. After merging, we copy the first n elements back to arr1 and the remaining m elements to arr2.*/

/*Step-by-Step Implementation:

Initialize two pointers: i = 0 for traversing arr1, j = 0 for traversing arr2
Create an empty array merged = []
Merge the elements into merged: While both i < n and j < m:
=> If arr1[i] <= arr2[j], append arr1[i] to merged and increment i
=> Else, append arr2[j] to merged and increment j
Append remaining elements (if any):
=> While i < n, append arr1[i] to merged and increment i
=> While j < m, append arr2[j] to merged and increment j
Distribute the merged elements back:
=> Copy the first n elements of merged to arr1
=> Copy the remaining m elements to arr2*/

#include <iostream>
#include <vector>
using namespace std;

void mergearrays(vector<int>& arr1, vector<int>& arr2){
    int n = arr1.size();
    int m = arr2.size();
    int i = 0, j = 0;
    vector<int> merged;
    while (i < n && j < m) {
        if (arr1[i] <= arr2[j]) {
            merged.push_back(arr1[i++]);
        } else {
            merged.push_back(arr2[j++]);
        }
    }
    while (i < n) merged.push_back(arr1[i++]);
    while(j<m) merged.push_back(arr2[j++]);
    for (int k = 0; k < n; ++k) {
        arr1[k] = merged[k];
    }
    for (int k = 0; k < m; ++k) {
        arr2[k] = merged[n + k];
    }
}

int main(void){
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};

    mergearrays(arr1, arr2);

    for (int num : arr1) cout << num << ' ';
    cout << endl;
    for (int num : arr2) cout << num << ' ';
    cout << endl;

    return 0;
}