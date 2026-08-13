//the idea for this approach is to compare the index and element on that index of the sorted array. if the difference between the index and element on that index is greater than 1 then the missing element is index+1. if the difference between the index and the element for all index is 1 then the missing element is namespace

#include <iostream>
#include <vector>
using namespace std;

int missingnumber(vector<int>& arr){
  int n = arr.size();

  for(int i=0;i<n-1;i++){
    if(arr[i]!=i+1) return i+1;
  }
  return n;
}

int main(){
  vector<int> arr = {1,2,3,4,6,7,8};
  cout << missingnumber(arr);
  return 0;
}
