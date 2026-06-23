#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*merge sort is popular sorting algorithm known for its efficiency and stability. It follows the Divide and Conquer approach. It works by recursively dividing the input array into two halves, recursively sorting the two halves and finally merging them back together to obtain the sorted array.*/

/*here is a step by step explaination of how merge sort works:

1. divide - divide the list array recursively into two halves until it can no more be divided.
2. conquer - each subarray is sorted individually using the merge sort algorithm.
3. merge - the sorted subarrays are merged back together in sorted order. the process continues until all elements from both subarrays have been merged.*/

class Solution{
    public:
    void merge(vector<int>& arr, int left, int mid, int right){
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<int> L(n1), R(n2);

        for(int i=0;i<n1;i++){
            L[i] = arr[left+i];
        }
        for(int j=0;j<n2;j++){
            R[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0;
        int k = left;

        while(i<n1 && j<n1){
            if(L[i]<=R[j]){
                arr[k] = L[i];
                i++;
            }else{
                arr[k] = R[j];
            }
            k++;
        }

        while(i<n1){
            arr[k]=L[i];
            i++;
            k++;
        }

        while(j<n2){
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void mergesort(vector<int>& arr, int left, int right){
        if(left>=right){
            return;
        }

        int mid = left + (right - left)/2;
        mergesort(arr, left, mid);
        mergesort(arr, mid + 1, right);
        merge(arr,left,mid,right);
    }
};

int main(void){
    vector<int> arr = {38,27,43,10};
    int n = arr.size();
    Solution s;
    s.mergesort(arr, 0, n-1);
    for(int i = 0; i<arr.size();i++){
        cout << arr[i]<<"\n";
    }
    return 0;
}