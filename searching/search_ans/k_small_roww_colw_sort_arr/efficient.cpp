//This approach uses binary search to iterate over possible solutions. As answer lies in the range from mat[0][0] to mat[n-1][n-1], So we do a binary search on this range and in each  iteration determine the no of elements smaller than or equal to our current middle element.

#include <iostream>
#include <vector>

using namespace std;

int countsmallest(vector<vector<int>>& mat, int x){
  int n = mat.size();
  int count = 0;
  int row = 0;
  int col = n - 1;

  while(row < n && col >= 0){
    if(mat[row][col] <= x){
      count += (col + 1);
      row++;
    }else{
      col--;
    }
  }
  return count;
}

int kthsmallest(vector<vector<int>>& mat, int k){
  int n = mat.size();
  int low = mat[0][0];

  int high = mat[n-1][n-1];
  int ans = 0;

  while(low <= high){
    int mid = low + (high - low) / 2;
    int count = countsmallest(mat, mid);
    if(count < k){
      low = mid + 1;
    }else{
      ans = mid;
      high = mid - 1;
    }
  }
  return ans;
}

int main(){
  vector<vector<int>> mat = {{10,20,30,40},{15,25,35,45},{24,29,34,48},{32,33,39,50}};
  int k = 3;
  int result = kthsmallest(mat, k);
  cout << result << endl;
  return 0;
}
