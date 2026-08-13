//this approach applies a modified version of binary search directly to the entire rotated array. at every iteration the middle element is checked against the key. if it's not the key we determine whether the left half or right half is sorted by comparing values at arr[low] and arr[mid]. if the left half is sorted and key lies within its range we adjust high = mid - 1; otherwise we shift low = mid + 1. if the right half is sorted and key lies within its range, we move low = mid + 1, else high = mid -1

#include <iostream>
#include <vector>
using namespace std;

bool search(vector<int>& arr, int key){
  int l =0;
  int r = arr.size() - 1;

  while(l<=r){
    int mid = l + (r-l)/2;

    if(arr[mid] == key)  return true;
    if(arr[l] == arr[mid] && arr[mid] == arr[r]){
      l++;
      r--;
      continue;
    }

    if(arr[l] <= arr[mid]){
      if(arr[l]<=key && key<arr[mid]){
        r = mid-1;
      }else{
        l = mid + 1;
      }
    }else{
      if(arr[mid] < key && key<=arr[r]){
        l = mid + 1;
      }else{
        r = mid - 1;
      }
    }
  }
  return false;
}

int main(){
  vector<int> arr = {3,3,3,1,2,3};
  int key = 3;
  if(search(arr, key)) cout << "true" << endl;
  else cout << "false" << endl;
  return 0;
}
