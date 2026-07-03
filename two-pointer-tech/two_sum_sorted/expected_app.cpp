/*The problem can be solved using two pointers technique. We can maintain two pointers, left = 0 and right = n - 1, and calculate their sum S = arr[left] + arr[right]. 

If S = target, then return left and right.
If S < target, then we need to increase sum S, so we will increment left = left + 1.
If S > target, then we need to decrease sum S, so we will decrement right = right - 1.
If at any point left >= right, then no pair with sum = target is found.*/

/*Step-by-step algorithm:

We need to initialize two pointers as left and right with position at the beginning and at the end of the array respectively.
Need to calculate the sum of the elements in the array at these two positions of the pointers.
If the sum equals to target value, return the 1-indexed positions of the two elements.
If the sum comes out to be less than the target, move the left pointer to the right to the increase the sum.
If the sum is greater than the target, move the right pointer to the left to decrease the sum.
Repeat the following steps till both the pointers meet.*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> twosum(vector<int>& arr, int target){
    int left = 0, right = arr.size() - 1;
    while(left < right){
        int current_sum = arr[left] + arr[right];
        if(current_sum == target){
            return {left + 1, right + 1};
        }
        else if(current_sum < target){
            left++;
        }
        else{
            right--;
        }
    }
    return {-1, -1};
}

int main(void){
    vector<int> arr = {2,7,11,15};
    int target = 9;
    vector<int> result = twosum(arr, target);
    for(int num : result) cout << num << "\n";
    return 0;
}