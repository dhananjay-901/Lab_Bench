//the main idea is to use quickselect to find the kth largest element by picking a pivot and partioning the array so that all elements greater than the pivot are on the left and smaller ones on the right. if the pivot ends up at index k-1 it is the kth largest element. otherwise we recursively search only in the left or right part that contains the kth largest element

#include <iostream>
#include <vector>

using namespace std;

int partitiion(vector<int>& arr, int left, int right){
  int pivot = arr[right];
  int i = left;

  for(int j=left; j<right;j++){
    if(arr[j] <= pivot){
      swap(arr[i] , arr[j]);
      i++;
    }
  }
  swap(arr[i], arr[right]);
  return i;
}

int quickselect(vector<int>& arr, int left, int right, int k){
  if(left <= right){
    int pivotindex = partitiion(arr, left, right);
    if(pivotindex == k) return arr[pivotindex];
    else if(pivotindex > k){
      return quickselect(arr, left, pivotindex - 1, k);
    }else{
      return quickselect(arr, pivotindex + 1, right, k);
    }
  }
  return -1;
}

int kthsmallest(vector<int>& arr, int k){
  return quickselect(arr, 0, arr.size()-1, k-1);
}

int main(){
  vector<int> arr = {10,5,4,3,48,6,2,33,53,10};
  int k = 4;
  cout << kthsmallest(arr, k);
  return 0;
}
