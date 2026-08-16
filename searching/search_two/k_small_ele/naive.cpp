//given an integer array arr[] and k find the kth smallest element in the given array

//the idea is to sort the given array and return the element at the index k-1;

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kthsmallest(vector<int>& arr, int k){
  sort(arr.begin(), arr.end());
  return arr[k-1];
}

int main(){
  vector<int> arr = {10,5,4,3,48,6,2,33,53,10};
  int k = 4;

  cout << kthsmallest(arr, k);
  return 0;
}
