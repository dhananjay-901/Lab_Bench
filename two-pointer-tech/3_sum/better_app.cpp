/*The idea is to traverse every element arr[i] in a loop. For every arr[i], use the hashing based solution of 2 Sum Problem to check if there is a pair with sum equal to given sum - arr[i].

Step by Step Approach:

Iterate through the array, fixing the first element (arr[i]) for the triplet.
For each arr[i], use a Hash Set to store potential second elements and run another loop inside it for j from i+1 to n-1.
Inside a nested loop, check if given sum - arr[i] - arr[j] is present in the hash set. If yes, then print the triplet.
If no triplet is found in the entire array, the function returns false.*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool hastriplesum(vector<int>& arr, int target){
    int n = arr.size();
    for(int i=0; i < n-2; i++){
        unordered_set<int> st;
        for(int j = i+1; j<n;j++){
            int second = target - arr[i] - arr[j];
            if(st.find(second) != st.end()){
                return true;
            }
            st.insert(arr[j]);
        }
    }
    return false;
}

int main(void){
    vector<int> arr = {1,4,45,6,10,8};
    int target = 13;
    if(hastriplesum(arr,target)) cout << "true";
    else cout << "false";
    return 0;
}