//given an array of positive integers arr[] of size n, the task is to find second largest distinct element in the array

//the idea is to sort the array in non descending order. now we know that the largest element will be at index n-1. so starting from index n-2, traverse the remaining array in reverse order. as soon as we encounter an element which is not equal to the largest element, return it as the second largest element in the array. if all the elements are equal to the largest element, return -1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getsecondlargest(vector<int>& arr){
  int n = arr.size();
  sort(arr.begin(), arr.end());

  for(int i=n-2;i>=0;i--){
    if(arr[i] != arr[n-1]){
      return arr[i];
    }
  }
  return -1;
}

int main(){
  vector<int> arr = {12,35,1,10,34,1};
  cout << getsecondlargest(arr);
  return 0;
}
