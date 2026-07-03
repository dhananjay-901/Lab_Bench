/*initially we sort the input array so that we can apply two pointer technique. then run two nested loops for first and second element in the array. inside the second nested loop, we simply use 2 sum solution to find the remaining two elements. if the sum of four elements is less than the required sum, the move the left pointer to increase the sum, otherwise if the sum of four elements in more than the required sum, then move the right pointer to decrease the sum.*/

#include <bits/stdc++.h>
using namespace std;

bool check4sum(vector<int>& arr, int target){
    int n = arr.size();

    sort(arr.begin(), arr.end());

    for(int i = 0 ; i < n-3; i++){
        for(int j = i+1; j < n-2;j++){
            int l = j+1;
            int r = n-1;
            while(l < r){
                int sum = arr[i] + arr[j]+arr[l]+arr[r];
                if(sum==target){
                    return true;
                }else if(sum < target){
                    l++;
                }else{
                    r--;
                }
            }
        }
    }
    return false;
}

int main(){
    vector<int> arr = {1,1,1,1,1};
    int target = 4;
    cout << (check4sum(arr,target)? "true":"false");
    return 0;
}