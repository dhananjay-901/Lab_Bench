//the idea is to compare the key with middle 3 elements, if present then return the index if not present then compare the key with middle element to decide whether to do in left half or right half. comparing with middle element is enough as all the elements after mid+2 must be greater than element mid and all elements before mid-2 must be smaller than mid element.

#include <bits/stdc++.h>
using namespace std;

int findtarget(vector<int>& arr, int target){
  int l=0,r=arr.size()-1;
  while(r>=l){
    int mid = l + (r-l)/2;

    if(arr[mid] == target) return mid;
    if(mid > l && arr[mid - 1] == target) return mid - 1;
    if(mid < r && arr[mid + 1] == target) return mid + 1;

    if(arr[mid] > target){
      r = mid - 2;
    }else{
      l = mid + 2;
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
