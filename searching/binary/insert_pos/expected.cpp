//the idea is to use binary search instead of scanning the entire array linearly. the thought process ebgins by recognizing that a sorted array allows us to use binary search

#include <iostream>
#include <vector>
using namespace std;

int searchinsertk(vector<int> arr, int k){
  int left = 0, right = arr.size()-1;
  while(left<=right) {
    int mid = left + (right - left)/2;

    if(arr[mid] == k){
      return mid;
    }
    else if(arr[mid] > k){
      right = mid - 1;
    }
    else{
      left = mid + 1;
    }
  }
  return left;
}

int main(){
  vector<int> arr = {1,3,5,6};
  int k = 5;
  cout << searchinsertk(arr, k) << endl;
  return 0;
}
