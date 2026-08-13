//given a sorted integer array arr[] consisting of distinct elements where some elements where some elements of the array are moved to either of the adjacent position

//naive approach - a idea is to linearly search the given key in array arr[]. to do so run a loop starting from index 0 to n-1 and for each index i check arr[i] == target if so print the index i else move to the next index. at last if no such index is found print -1

#include <bits/stdc++.h>
using namespace std;

int findtarget(vector<int>& arr, int target){
  for(int i=0;i<arr.size();i++){
    if(arr[i] == target){
      return i;
    }
  }
  return -1;
}

int main(){
  vector<int> arr = {10,3,40,20,50,80,70};
  int target = 40;

  cout << findtarget(arr, target);
  return 0;
}
