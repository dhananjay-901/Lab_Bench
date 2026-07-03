/*we first sort the array. after sorting we traverse every element arr[i] in a loop. for every arr[i] use the two pointer technique based solution 2 sum problem to check if there is a pair with equal to given sum - arr[i]*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool hastriplesum(vector<int>& arr, int target){
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for(int i=0;i<n-2;i++){
        int l = i + 1, r = n - 1;
        int requiredsum = target - arr[i];
        while(l < r){
            if(arr[l] + arr[r] == requiredsum){
                return true;
            }
            if(arr[l] + arr[r] < requiredsum){
                l++;
            }
            else if(arr[l] + arr[r] > requiredsum){
                r--;
            }
        }
    } 
    return false;
}

int main(void){
    vector<int> arr = {1,4,45,6,10,8};
    int target = 13;
    if(hastriplesum(arr, target)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}