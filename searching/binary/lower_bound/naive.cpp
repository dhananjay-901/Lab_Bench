//given a sorted array arr[] and a number target, find the lower bound of the target in this given array. the lower bound of a number is defined as the smallest index in the sorted array where the element is greater than or equal to the target

//the idea is to use linear search

#include <iostream>
#include <vector>
using namespace std;

int lowerbound(vector<int>& arr, int target){
  int n = arr.size();

  for(int i=0;i<n;i++){
    if(arr[i] >= target) return i;
  }
  return n;
}

int main(){
  vector<int> arr = {2,3,7,10,11,11,25};
  int target = 9;
  cout << lowerbound(arr, target) << endl;
  return 0;
}
