//given a 2d integer matrix mat[][] of a size n x m where every row and column is sorted in increasing order and a number x, return true if the element x is present in the matrix otherwise return false

//the simple idea is to traverse the complete matrix and search for the target element if the target element is found, return true. otherwise return false

#include <iostream>
#include <vector>

using namespace std;

bool matsearch(vector<vector<int>>& mat, int x){
  int n = mat.size(), m = mat[0].size();

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(mat[i][j] == x){
        return true;
      }
    }
  }
  return false;
}

int main(){
  vector<vector<int>> mat = {{3,30,38},{20,52,54},{35,60,69}};
  int x = 35;
  if(matsearch(mat,x)) cout << "true";
  else cout << "false";
  return 0;
}
