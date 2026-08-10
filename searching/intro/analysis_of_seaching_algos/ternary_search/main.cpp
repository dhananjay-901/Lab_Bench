//ternary search is a divide and conquer search algorithm used to find the position of a target value within an increasing or decreasing function or in  a unimodel array
//given a sorted array arr and a integer x, determine whether x is present in the array using ternary search

#include <iostream>
#include <vector>
using namespace std;

bool ternarysearch(vector<int>& arr, int x){
  int l = 0;
  int r = arr.size()-1;

  while(l<=r){
    int mid1 = l+(r-l)/3;
    int mid2 = r-(r-l)/3;

    if(arr[mid1] == x || arr[mid2] == x){
      return true;
    }

    if(x < arr[mid1]){
      r = mid1-1;
    }else if(x > arr[mid2]){
      l = mid2 + 1;
    }else{
      l = mid1 + 1;
      r = mid2 - 1;
    }
  }
  return false;
}

int main(){
  vector<int> arr = {1,2,3,4,6};
  int x = 6;
  cout << (ternarysearch(arr,x) ? "true":"false") << endl;
  arr = {1,3,4,5,6};
  x = 2;
  cout << (ternarysearch(arr,x) ? "true":"false") << endl;
  return 0;
}
