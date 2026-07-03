//two sum - pair sum in sorted array

/*Given a 1-based indexed integer array arr[] that is sorted in non-decreasing order, along with an integer target. find two elements in the array such that their sum is equal to target. If such a pair exists, return the indices of the two elements in increasing order. If no such pair exists, return*/

//naive approach
/*the idea is to check every possible pair of elements using two nested loops. if any pair adds up to the target we return their 1-based indices immediately*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> twosum(vector<int>& arr, int target){
    int n = arr.size();
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n;j++){
            int sum = arr[i] + arr[j];
            if(sum == target){
                return {i + 1, j + 1};
            }
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