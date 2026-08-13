//This approach uses binary search on the columns of the matrix to efficiently find a peak element. In each iteration, it selects the middle column and identifies the row that contains the maximum element in that column. This element is then compared with its left and right neighbors. If the current element is greater than or equal to both neighbors, it qualifies as a peak and its position is returned. Otherwise, the search continues in the direction of the larger neighbor (left or right), ensuring movement toward a region that must contain a peak. This process continues until a peak is found.

#include <iostream>
#include <vector>
using namespace std;

vector<int> findpeakgrid(vector<vector<int>>& mat){
  int n = mat.size();
  int m = mat[0].size();

  int low = 0, high = m-1;
  int mini = int(-1e9);

  while(low <= high){
    int mid = (low+high)/2;

    int maxrow = 0;
    for(int i=1;i<n;++i){
      if(mat[i][mid] > mat[maxrow][mid]){
        maxrow = i;
      }
    }

    int left = (mid>0) ? mat[maxrow][mid - 1] : mini;
    int right = (mid+1<m) ? mat[maxrow][mid + 1] : mini;

    if(mat[maxrow][mid] >= left && mat[maxrow][mid] >=right){
      return {maxrow, mid};
    }

    else if(right > mat[maxrow][mid]){
      low = mid + 1;
    }
    else{
      high = mid - 1;
    }
  }
  return {-1,-1};
}

int main(){
  vector<vector<int>> mat = {{10,20,15},{21,30,14},{7,16,32}};
  vector<int> peak = findpeakgrid(mat);
  cout << peak[0] << " " << peak[1] << endl;
  return 0;
}
