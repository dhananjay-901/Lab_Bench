//given a sorted array of n uniformly distributed values arr[] write a function to search for a particular element x in the array
#include <bits/stdc++.h>
using namespace std;

int interpolationsearch(int arr[], int low, int high, int x){
  int pos;

  if(low <= high && x>=arr[low] && x <=arr[high]){
    pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (x-arr[low]));

    if(arr[pos] == x) return pos;

    if(arr[pos] < x) return interpolationsearch(arr, pos+1, high, x);
    if(arr[pos] > x) return interpolationsearch(arr, low, pos-1, x);
  }
  return -1;
}

int main(){
  int arr[] = {10,12,13,16,18,19,20,21,22,23,24,33,35,42,47};
  int n = sizeof(arr)/sizeof(arr[0]);

  int x = 18;
  int index = interpolationsearch(arr, 0, n-1,x);
  if(index!=-1) cout << "element found at index" << index;
  else cout << "element not found";
  return 0;
}
