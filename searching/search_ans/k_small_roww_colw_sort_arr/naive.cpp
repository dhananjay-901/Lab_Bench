//given an nxn matrix mat[][] where each row and column is sorted in non decreasing order, find the kth smallest element where k lies in the range [1, n^2]

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int kthsmallest(vector<vector<int>>& mat, int k){
  int n = mat.size();
  vector<int> arr;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      arr.push_back(mat[i][j]);
    }
  }
  sort(arr.begin(), arr.end());
  return arr[k-1];
}

int main(){
  vector<vector<int>> mat = {{10,20,30,40},{15,25,35,45},{24,29,37,48},{32,33,39,50}};
  int k = 3;
  int result = kthsmallest(mat, k);
  cout << result << endl;
  return 0;
}
