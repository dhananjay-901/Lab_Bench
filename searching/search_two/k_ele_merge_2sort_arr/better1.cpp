//The basic idea here is to merge the given two arrays into a single sorted array and then simply return the element at the kth position. This approach is straightforward because it directly uses the merging process of two sorted arrays, similar to the merge step in the merge sort algorithm.

#include <iostream>
#include <vector>

using namespace std;

int kthelement(vector<int>& a, vector<int>& b, int k){
  int n = a.size(), m = b.size();

  vector<int> arr(n+m);
  int i=0, j=0, d=0;
  while(i<n && j<m){
    if(a[i] < b[j]){
      arr[d++] = a[i++];
    }else{
      arr[d++] = b[j++];
    }
  }

  while(i < n){
    arr[d++] = b[i++];
  }
  while(j < m){
    arr[d++] = b[j++];
  }
  return arr[k-1];
}

int main(){
  vector<int> a = {2,3,6,7,8};
  vector<int> b = {1,4,8,10};
  int k = 5;
  cout << kthelement(a,b,k);
  return 0;
}
