//naive method

/*the two pointers technique is a simple yet powerful strategy where you use two indices [pointers] that traverse a data structure - such as array, list or string either toward each other or in the same direction to solve problesm more efficiently

when to use two pointers:
- sorted input : if the array or list is already sorted(or can be sorted), two pointers can efficiently find pairs or ranges.
- pairs or subarrays : when the problem asks about two elements, subarrays or ranges instead of working with single elements.
-Sliding Window Problems: when you need to maintain a window of elements that grows/shrinks based on conditions.
- Linked Lists: detecting Cycles, finding the middle node, or checking palindrome property*/

/*problem - given a sorted array arr [sorted in ascending order] and a target, find it there exists any pair of elements such that their sum is equal to the target*/

#include <iostream>
#include <vector>
using namespace std;

bool twosum(vector<int>& arr, int target){
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j = i + 1; j<n; j++){
            if(arr[i] + arr[j] == target){
                return true;
            }
        }
    }
    return false;
}

int main(void){
    vector<int>  arr = {0,-1,2,-3,1};
    int target = -2;
    cout << ((twosum(arr, target)) ? "true" : "false") << endl;
}