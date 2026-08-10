#include <iostream>
#include <vector>
using namespace std;

int binarysearch(vector<int>& arr, int low, int high, int x){
  if(high>=low){
    int mid = low+(high-low)/2;
    if(arr[mid] == x){
      return mid;
    }
    if(arr[mid] > x){
      return binarysearch(arr, low, mid-1,x);
    }
    return binarysearch(arr, mid+1, high,x);
  }
  return -1;
}

int main(){
  vector<int> arr = {2,3,4,10,40};
  int query = 10;
  int n = arr.size();
  int result = binarysearch(arr,0,n-1,query);
  if(result == -1) cout << "element is not present in array";
  else cout << "element is present at index" << result;
  return 0;
}
