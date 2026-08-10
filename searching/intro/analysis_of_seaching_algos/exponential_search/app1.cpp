#include <bits/stdc++.h>
using namespace std;

int binarysearch(vector<int>& arr,int l, int r, int x);

int exponentialsearch(vector<int>& arr, int n, int x){
  if(arr[0] == x) return 0;
  int i = 1;
  while(i<n && arr[i] <= x) i=i*2;
  return binarysearch(arr, i/2,min(i,n-1),x);
}

int binarysearch(vector<int>& arr, int l, int r, int x){
  if(r>=l){
    int mid = l + (r-1)/2;

    if(arr[mid] == x) return mid;

    if(arr[mid] > x) return binarysearch(arr, l, mid - 1, x);
    return binarysearch(arr, mid+1,r,x);
  }
  return -1;
}

int main(){
  vector<int> arr = {2,3,4,10,40};
  int n = arr.size();
  int x = 10;
  int result = exponentialsearch(arr,n,x);
  (result == -1) ? cout << "element is not present in array" : cout << "element is present at index" << result;
  return 0;
}
