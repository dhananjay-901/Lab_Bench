//the idea is to iterate through the entire matrix mat[][] and compare each element with x. if an element matches the x, we will return true. otherwise at the end of the traversal we will return true

#include <iostream>
#include <vector>

using namespace std;

bool searchmatrix(vector<vector<int>>& mat, int x){
  int n = mat.size();
  int m = mat[0].size();

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(mat[i][j] == x) return true;
    }
  }
  return false;
}

int main(){
  vector<vector<int>> mat = {
    {1,5,9},{14,20,21},{30,34,43}
  };

  int x = 14;
  cout << (searchmatrix(mat,x) ? "true" : "false") << endl;
  return 0;
}
