//The idea is to keep track of the largest and second largest element while traversing the array. Initialize largest and secondLargest with -1. Now, for any index i, If arr[i] > largest, update secondLargest with largest and largest with arr[i]. Else If arr[i] < largest and arr[i] > secondLargest, update secondLargest with arr[i].

#include <iostream>
#include <vector>

using namespace std;

int getsecondlargest(vector<int>& arr){
  int n = arr.size();
  int largest = -1, secondLargest = -1;

  for(int i=0;i<n;i++){
    if(arr[i] > largest){
      secondLargest = largest;
      largest = arr[i];
    }

    else if(arr[i] < largest && arr[i] > secondLargest){
      secondLargest = arr[i];
    }
  }
  return secondLargest;
}

int main(){
  vector<int> arr = {12,35,1,10,34,1};
  cout << getsecondlargest(arr);
  return 0;
}
