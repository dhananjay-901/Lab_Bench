/*To check if a pair with a given sum exists in the array, we first sort the array. Then for each element, we compute the required complement (i.e., target - arr[i]) and perform binary search on the remaining subarray (from index i+1 to end) to find that complement.

Step By Step Implementation:

Sort the array in non-decreasing order. 
Loop through each element arr[i] from index 0 to n-2. 
For each arr[i], calculate complement = target - arr[i]. 
Perform binary search for complement in the subarray from index i+1 to n-1. 
If the complement is found, return true. 
If the loop completes without finding any valid pair, return false.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binarySearch(vector<int> &arr, int left, int right, int target){
    while (left <= right){
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return true;
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}
bool twoSum(vector<int> &arr, int target){
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++){
        int complement = target - arr[i];
        if (binarySearch(arr, i + 1, 
                    arr.size() - 1, complement))
            return true;
    }
    return false;
}

int main(){
    vector<int> arr = {0, -1, 2, -3, 1};
    int target = -2;
    if (twoSum(arr, target))
        cout << "true";
    else
        cout << "false";
    return 0;
}