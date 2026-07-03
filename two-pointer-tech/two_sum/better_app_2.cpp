/*The idea is to use the two-pointer technique but for using the two-pointer technique, the array must be sorted. Once the array is sorted then we can use this approach by keeping one pointer at the beginning (left) and another at the end (right) of the array. 

Check the sum of the elements at these two pointers:

If the sum equals the target, we’ve found the pair.
If the sum is less than the target, move the left pointer to the right to increase the sum.
If the sum is greater than the target, move the right pointer to the left to decrease the sum.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool twoSum(vector<int> &arr, int target){
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;
    while (left < right){
        int sum = arr[left] + arr[right];
        if (sum == target)
            return true;
        else if (sum < target)
            left++; 
        else
            right--; 
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