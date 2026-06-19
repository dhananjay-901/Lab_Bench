#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//search in sorted array or rotated array
//naive approach is to use linear search iterating through each element 
//the main idea is to find the index of the smallest element [pivot] which is also the number of rotations applied to the sorted array, once the pivot is known the array is split into two sorted sub arrays

class Solution{
    public:
    int binarysearch(vector<int>& arr, int low, int high, int x){
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]==x){
                return mid;
            }
            if(arr[mid]>x){
                high = mid-1;
            }if(arr[mid]<x){
                low = mid+1;
            }
        }
        return -1;
    }

    int findpivot(vector<int>& arr, int low, int high){
        while(low<=high){
            if(arr[low]<arr[high]){
                return low;
            }
            int mid = (low+high)/2;

            if(arr[mid]>arr[high]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }

    int search(vector<int>& arr, int key){
        int n = arr.size();
        int pivot = findpivot(arr, 0, n-1);

        if(arr[pivot]==key){
            return pivot;
        }

        if(pivot == 0){
            return binarysearch(arr, 0, n-1, key);
        }
        if(arr[0]<=key){
            return binarysearch(arr, 0, pivot - 1, key);
        }

        return binarysearch(arr, pivot + 1, n - 1, key);
    }
};

int main(){
    Solution s;
    vector<int> arr = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int key = 3;
    cout << s.search(arr, key);
    return 0;
}