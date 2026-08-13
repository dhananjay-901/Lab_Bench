//given a 0 based sorted array arr[] of distinct integers and an integer k, find the index of k if it is present, if not return the index where k should be inserted to maintain the sorted order

//the idea is to iterate through the array and find the first position where k is less than or equal to arr[i] current element. we traverse the array linearly checking each element to determine if k should be placed at or before it. if k is larger than all elements it is inserted at the end returning the array size

#include <iostream>
#include <vector>
using namespace std;

int searchinsertl(vector<int> arr, int k){
  for(int i=0;i<arr.size();i++){
    if(arr[i] >= k) return i;
  }

  return arr.size();
}

int main(){
  vector<int> arr = {1,3,5,6};
  int k = 5;
  cout << searchinsertl(arr, k) << endl;
  return 0;
}
