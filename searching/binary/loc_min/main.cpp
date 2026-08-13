//Given an array arr[0 .. n-1] of n distinct integers. The task is to find a local minimum in the array. An element arr[x] is considered a local minimum if it is smaller than both of its adjacent elements, meaning arr[x] < arr[x - 1] and arr[x] < arr[x + 1] for indices where 1 <= x <= n - 2. For corner elements, arr[0] is a local minimum if arr[0] < arr[1], and arr[n - 1] is a local minimum if arr[n - 1] < arr[n - 2].

//The idea is to use Binary search, to efficiently find the smallest index of a local minimum. The thought process begins with the observation that if the middle element is a local minimum, we store it and continue searching on the left for a smaller index. If the left neighbor is smaller, a local minimum must exist on the left, so we move left. Otherwise, we move right. This ensures an O(log n) solution by always reducing the search space by half, guaranteeing we find the smallest index where the local minimum condition holds.

#include <bits/stdc++.h>
using namespace std;

int findlocalmin(vector<int>& arr){
  int l = 0, r = arr.size()-1;

  int ans = -1;
  while(l<=r){
    int mid = l + (r-l)/2;
    if((mid==0 || arr[mid] < arr[mid - 1]) && (mid==arr.size()-1 || arr[mid] < arr[mid+1])){
      ans = mid;
      r = mid - 1;-
    }
    else if(mid > 0 && arr[mid-1] < arr[mid]){
      r = mid - 1;
    }
    else{
      l = mid + 1;
    }
  }
  return ans;
}

int main(){
  vector<int> arr = {9,6,3,14,5,7,4};
  cout << findlocalmin(arr) << endl;
  return 0;
}
