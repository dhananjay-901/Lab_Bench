//Given a 2D matrix mat[][], identify any peak element within the matrix. An element is considered a peak if it is greater than or equal to its four immediate neighbors: top, bottom, left, and right. For corner and edge elements, any missing neighbors are treated as having a value of negative infinity. The idea is to iterate through each element in the matrix and check whether it is greater than or equal to all its valid neighbors (top, bottom, left, and right). The first such element found is returned as a peak.

#include <iostream>
#include <vector>

using namespace std;

vector<int> findpeakgrid(vector<vector<int>>& mat){
  int n = mat.size();
  int m = mat[0].size();

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int curr = mat[i][j];
      bool ispeak = true;

      if(i>0 && mat[i-1][j] > curr){
        ispeak = false;
      }
      if(i+1 < n && mat[i+1][j] > curr){
        ispeak = false;
      }

      if(j>0 && mat[i][j-1] > curr){
        ispeak = false;
      }

      if(j+1<m && mat[i][j+1] > curr){
        ispeak = false;
      }

      if(ispeak){
        return {i,j};
      }
    }
  }
  return {-1,-1};
}

int main(){
  vector<vector<int>> mat = {{10,20,15},{21,30,14},{7,16,32}};
  vector<int> peak = findpeakgrid(mat);
  cout << peak[0] << " " << peak[1] <<endl;
  return 0;
}
