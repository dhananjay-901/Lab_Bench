//This approach applies a modified version of binary search directly to the entire rotated array. At every iteration, the middle element is checked against the key. If it’s not the key, we determine whether the left half or right half is sorted by comparing values at arr[lo] and arr[mid]. If the left half is sorted and the key lies within its range, we adjust hi = mid - 1; otherwise, we shift lo = mid + 1. If the right half is sorted and the key lies within its range, we move lo = mid + 1; else, hi = mid - 1.

#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& arr, int key){
  int low = 0,high = arr.size() - 1;

  while(low <= high){
    int mid = low + (high - low)/2;

    if(arr[mid] == key){
      return mid;
    }
    if(arr[mid] >= arr[low]){
      if(key>=arr[low] && key < arr[mid]){
        high = mid - 1;
      }
      else low = mid + 1;
    }
    else{
      if(key> arr[mid] && key <= arr[high]){
        low = mid + 1;
      }else{
        high = mid - 1;
      }
    }
  }
  return -1;
}

int main(){
  vector<int> arr = {5,6,7,8,9,10,1,2,3};
  int key = 3;
  cout << search(arr, key) << endl;
  return 0;
}
