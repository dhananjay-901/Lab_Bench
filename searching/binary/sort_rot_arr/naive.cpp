//given a sorted and rotated array of distinct elements, find the index of given array in the array. if the key is not present in the array then return - 1

//a simple approach is to iterate through the array and check for each element if ti matches the target thenr eturn the index, otherwise return -1. to know more about the implementation

#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& arr, int key){
  for(int i=0;i<arr.size();i++){
    if(arr[i] == key) return i;
  }
  return -1;
}

int main(){
  vector<int> arr = {5,6,7,8,9,10,1,2,3};
  int key = 3;
  int index = search(arr, key);
  cout << index << endl;
  return 0;
}
