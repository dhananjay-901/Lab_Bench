//in the previous approach we used linear search to find the first index where arr[i] > k + i. since the input array is sortedm once we have found the index i such that arr[i] > k+i then for all indices j(j>i), arr[j] will also be greater than k+j. so we can optimize the previous approach using binary search to find the index i so that the k th missing elements is k+i

#include <iostream>
#include <vector>

using namespace std;

int kthmissing(vector<int>& arr, int k){
  int low = 0, high = arr.size()-1;
  int res = arr.size() + k;

  while(low <= high){
    int mid = (low + high)/2;
    if(arr[mid] > mid + k){
      res = mid + k;
      high = mid - 1;
    }else{
      low = mid + 1;
    }
  }
  return res;
}

int main(){
  vector<int> arr = {2,3,4,7,11};
  int k = 5;
  cout << kthmissing(arr, k);
  return 0;
}
