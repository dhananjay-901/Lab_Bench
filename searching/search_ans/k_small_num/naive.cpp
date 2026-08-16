//given three integers n,m,k consider a multiplcation table of size mx n where value at each cell. that is the cell at row i and column j contains the product of i and j. the approach generates all values in the nxm multiplication table by computing ixj for every call stores them in a list and sorts the list. after sorting the kth smallest element is simply the element at index k-1. this is a brute force method and works well for small sizes

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int kthsmallest(int n, int m, int k){
  vector<int> arr;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      arr.push_back(i*j);
    }
  }
  sort(arr.begin(), arr.end());
  return arr[k-1];
}

int main(){
  int n = 2, m = 3, k = 5;
  cout << kthsmallest(n,m,k);
  return 0;
}
