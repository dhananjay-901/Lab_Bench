//the idea is to use the fact that the given array is sorted. we can apply binary search to find the index of the element just larger than the target

#include <iostream>
#include <vector>
using namespace std;

int upperbound(vector<int>& arr, int target){
  int low = 0, high = arr.size()-1;
  int res = arr.size();

  while(low <= high){
    int mid = low + (high - low)/2;

    if(arr[mid] > target){
      res = mid;
      high = mid-1;
    }else{
      low = mid + 1;
    }
  }
  return res;
}

int main(){
  vector<int> arr = {2,3,7,10,11,11,25};
  int target = 11;
  cout << upperbound(arr,target);
  return 0;
}
