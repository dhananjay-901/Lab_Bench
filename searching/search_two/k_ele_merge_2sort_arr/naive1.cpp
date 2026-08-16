//given two sorted arrays a[] of size m and b[] of size n, find the kth smallest element in the combined sorted sequence of all elements from both arrays

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kthelement(vector<int>& a, vector<int>& b, int k ){
  vector<int> arr;
  for(auto i : a){
    arr.push_back(i);
  }
  for(auto i : b){
    arr.push_back(i);
  }

  sort(arr.begin(), arr.end());
  return arr[k-1];
}

int main(){
  vector<int> a = {2,3,6,7,9};
  vector<int> b = {1,4,8,10};
  int k = 5;
  cout << kthelement(a,b,k);
  return 0;
}
