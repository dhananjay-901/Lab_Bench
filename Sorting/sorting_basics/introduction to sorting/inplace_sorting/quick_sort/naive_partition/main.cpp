 /*naive partition algorithm
Given an array arr[], the task is to partition the array by assuming last element as pivot element. The partition of an array must satisfy the following two conditions:
Elements smaller than or equal to the pivot element appear before pivot in the array. Elements larger than the pivot element appear after pivot in the array. Note: There might be more than one possible partition arrays.*/

//naive approach to partition of an array 
// a simple approach to partition an array is to create a new tmeporary array which will store the rearranged elements. in this approach we first iterate over the original array and add all the elements that are smaller than or equal to the pivot to the temporary array. then we add the pivot element to the temporary array. then we add the pivot element to the temporary array. finall we fill the remaining part of the temporary array with elements that are greater than the pivot. this ensures that the smaller elements come before the pivot and the larget elements come after it. now copy the elements from the temporary array back to the original array.

#include <iostream>
#include <vector>
using namespace std;

void partition(vector<int>& arr){
    int n = arr.size();
    int pivot = arr[n-1];
    vector<int> temp(n);
    int idx = 0;

    for(int i=0; i<n; i++){
        if(arr[i] <= pivot) temp[idx++] = arr[i];
    }

    for(int i=0;i<n;i++){
        if(arr[i] <=pivot) temp[idx++] = arr[i];
    }

    for(int i = 0; i < n;i++){
        if(arr[i] > pivot) temp[idx++] = arr[i];
    }
    arr = temp;
}

int main(){
    vector<int> arr = {5,13,6,9,12,11,8};
    partition(arr);
    for(int num : arr) cout << num << "\n";
    return 0;
}