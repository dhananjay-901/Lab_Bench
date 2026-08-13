//Since each row of mat[][] will have m elements, so we can find the row of the element as (mid / m) and the column of the element as (mid % m). Then, we can compare x with arr[mid/m][mid%m] for each mid and complete our binary search.

#include <iostream>
#include <vector>

using namespace std;

bool searchmatrix(vector<vector<int>>& mat, int x){
  int n = mat.size(), m = mat[0].size();

  int low = 0, high = n * m-1;
  while(low <= high){
    int mid = (low+high)/2;

    int row = mid/m;
    int col = mid%m;

    if(mat[row][col] == x) return true;

    if(mat[row][col] < x) low = mid + 1;
    else high = mid - 1;
  }
  return false;
}
int main(){
  vector<vector<int>> mat = {{1,5,9},{14,20,21},{30,34,43}};
  int x = 14;
  if(searchmatrix(mat, x)) cout << "true";
  else cout << "false";
  return 0;
}
