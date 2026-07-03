/*The idea is to sort the array first and use two pointers, one at the leftmost (smallest) and the other at the rightmost (largest) element. We calculate their sum and check if it's closer to zero than our current best sum. If we find a sum of zero, we return immediately. Otherwise, we adjust the pointers based on whether the sum is positive (move right pointer left) or negative (move left pointer right).

Steps to implement the above idea:

Sort the array in ascending order.
Initialize two pointers: one at the start and one at the end.
Initialize variables to store the closest sum and its absolute difference.
Iterate while left pointer is less than right pointer.
Update the closest sum if the current sum is closer to zero.
Move the left pointer right if the sum is negative; else, move the right pointer left.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int closesttozero(vector<int>& arr){
    sort(arr.begin(), arr.end());
    int i = 0, j = arr.size() - 1;
    int sum = arr[i] + arr[j];

    int diff = abs(sum);
    while(i < j){
        if(arr[i] + arr[j] == 0){
            return 0;
        }
        if(abs(arr[i] + arr[j]) < abs(diff)){
            diff = abs(arr[i] + arr[j]);
            sum = arr[i] + arr[j];
        }
        else if(abs(arr[i] + arr[j])==abs(diff)){
            sum = max(sum, arr[i] + arr[j]);
        }
        if(arr[i] + arr[j] < 0){
            j--;
        }else{
            i++;
        }
    }
    return sum;
}

int main(void){
    vector<int> arr = {0,-8, -6,3};
    cout << closesttozero(arr) << "\n";
    return 0;
}