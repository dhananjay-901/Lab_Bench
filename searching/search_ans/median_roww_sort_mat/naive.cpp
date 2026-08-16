//given a row wise sorted matrix mat[][] of size nxm where the number of rows and columns is always odd. return the median of the matrix

//the idea is to first flatten the 2d matrix into a 1d array by collecting all its elements. then the array is sorted to bring all elements into order. since the total number of elements is odd, the median is the middle element of the sorted array

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int median(vector<vector<int>>& mat){
  vector<int> arr;
  for(int i=0;i<mat.size();i++){
    for(int j=0;j<mat[0].size();j++){
      arr.push_back(mat[i][j]);
    }
  }
  sort(arr.begin(), arr.end());
  int mid = arr.size()/2;
  return arr[mid];
}

int main(){
  vector<vector<int>> matrix = {{1,3,5},{2,6,9},{3,6,9}};
  cout << median(matrix) << endl;
  return 0;
}
