//The idea is to keep track of the largest and second largest element while traversing the array. Initialize largest and secondLargest with -1. Now, for any index i, If arr[i] > largest, update secondLargest with largest and largest with arr[i]. Else If arr[i] < largest and arr[i] > secondLargest, update secondLargest with arr[i].

#include <iostream>
#include <vector>

using namespace std;

int single(vector<int>& arr){
  int n = arr.size();
  int low = 0, high = n-1;
  while(low<high){
    int mid = low+(high-low)/2;
    if(mid%2==1) mid--;
    if(arr[mid] == arr[mid+1]){
      low = mid+2;
    }else{
      high = mid;
    }
  }
  return arr[low];
}

int main(){
  vector<int> arr = {1,1,2,2,3,4,4};
  cout << single(arr) << "\n";
  return 0;
}
