//given a sorted array arr[] and number target find the upper bound  of the target in this given array. the upper bound of a number is defined as the smallest index in the sorted array where the element is greater than the given number

//the idea is to use linear search. we compare each element of the given array with the target with the target and find the first index where the element is greater than target

#include <iostream>
#include <vector>
using namespace std;

int upperbound(vector<int>& arr, int target){
  int n = arr.size();
  for(int i=0;i<n;i++){
    if(arr[i] > target){
      return i;
    }
  }
  return n;
}
int main(){
  vector<int> arr = {2,3,7,10,11,11,25};
  int target = 11;
  cout << upperbound(arr, target);
  return 0;
}
