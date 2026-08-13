//the idea is to remove a row or column in each comparison until an element is found start searching from top right corner of the matrix. there are 3 possible cases. x is greater than the current element. this ensures that all the elements in the current row are smaller than the given number as the pointer is already at the right most element and the row is sorted. thus the entire row gets eliminated and continues the search from the next row. x is smaller than the current element. this ensures that all the elements in the current column are greater than the given number. thus the entire coumn gets eliminated and continues the search from the previous column. the column on the immediate left. the given number is equal to the current number this will end the searching

#include <iostream>
#include <vector>

using namespace std;

bool matsearch(vector<vector<int>>& mat, int x){
  int n = mat.size(), m = mat[0].size();
  int i = 0, j = m-1;

  while(i<n && j>=0){
    if(x > mat[i][j]){
      i++;
    }
    else if(x < mat[i][j]){
      j--;
    }
    else{
      return true;
    }
  }
  return false;
}

int main(){
  vector<vector<int>> mat = {{3,30,38},{20,52,54},{35,60,69}};

  int x = 35;
  if(matsearch(mat, x)) cout << "true";
  else  cout << "false";
  return 0;
}
