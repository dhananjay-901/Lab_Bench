//the idea is that in a perfectly consecutive sequence starting from 1, the difference between each element and its index is always 1. when a number is missing this difference stays 1 before the missing number and becomes 2 after it. by using binary search, we find the point where this shift occurs. the missing number is one more than the element just before the shift

#include <iostream>
#include <vector>
using namespace std;

int missingnumber(vector<int>& arr){
  int n = arr.size();

  if(arr[0] != 1) return 1;
  if(arr[n-1] != (n+1)) return n+1;

  int low = 0, high = n-1;
  int mid;

  while((high - low) > 1){
    mid = (low+high)/2;
    if((arr[low] - low) != (arr[mid]- mid)){
      high = mid;
    }
    else if((arr[high] - high) != (arr[mid] - mid)){
      low = mid;
    }
  }
  return (arr[low] + 1);
}

int main(){
  vector<int> arr = {1,2,3,4,6,7,8};
  cout << missingnumber(arr);
}
