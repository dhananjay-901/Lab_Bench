//The idea is to use the partitioning step of QuickSort to find the k largest elements in the array, without sorting the entire array. When sorting the element in the descending order, the partitioning step rearranges the elements in a way that all elements greater than or equal to a chosen pivot (usually the last element) are placed on its left, and all elements lesser than the pivot are on its right. And pivot element in its correct sorted position.After each partition, we compare the number of elements in the leftpart of the array (which contains all elements greater than or equal to the pivot) with k: Number of elements in the left = k, it means all elements in the left part (including pivot) are the k largest elements. Number of elements in the left > k, it means that k largest elements exist in the left subarray only, so we recursively search in the left subarray. Number of elements in the left < k, it means that the k largest elements include the entire left part of the array along with some elements from the right part. Therefore we reduce k by the number of elements already covered on the left side and search in the right subarray.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& arr, int left, int right){
  int pivot = arr[right];
  int i = left;

  for(int j=left;j<right;j++){
    if(arr[j] >= pivot){
      swap(arr[i], arr[j]);
      i++;
    }
  }
  swap(arr[i], arr[right]);
  return i;
}

void quickselect(vector<int>& arr, int left, int right, int k){
  if(left <= right){
    int pivotidx = partition(arr, left, right);
    int leftcnt = pivotidx - left + 1;
    if(leftcnt == k){
        return;
    }
    if(leftcnt > k){
        quickselect(arr, left, pivotidx - 1, k);
    }
    else{
      quickselect(arr, pivotidx + 1, right, k - leftcnt);
    }
  }
}

vector<int> klargest(vector<int>& arr, int k){
  int n = arr.size();
  quickselect(arr, 0, n-1, k);
  vector<int> res(arr.begin(), arr.begin() + k);

  sort(res.begin(), res.end(), greater<int>());
  return res;
}

int main(){
  vector<int> arr = {1,23,12,9,30,2,50};
  int k = 3;
  vector<int> res = klargest(arr, k);
  for(int ele : res){
    cout << ele << " ";
  }
  return 0;
}
