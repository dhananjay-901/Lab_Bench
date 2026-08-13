//the idea is based on that observation that in a perfect sequence without missing number the ith element should be i+1. if any number is missing then arr[i] becomes greater than i+1 and the number of missing elements before arr[i] is arr[i] - (i+1). so at each index where arr[i] > k + i indicates that kth missing number is before that index and equal k+i. if no such index is found it means the kth missing number lies beyond the last element and is simply k+n

#include <iostream>
#include <vector>

using namespace std;

int kthmissing(vector<int>& arr, int k){
  int n = arr.size();
  for(int i=0;i<n;i++){
    if(arr[i] > (k+i)){
      return (k+i);
    }
  }
  return k+n;
}

int main(){
  vector<int> arr = {2,3,4,7,11};
  int k = 5;

  cout << kthmissing(arr, k);
  return 0;
}
