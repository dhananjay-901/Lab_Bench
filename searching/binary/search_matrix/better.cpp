//to search efficiently we first use binary search to find the row where the target x might be located. this is done by comparing x with the first element of the middle row in each step. once the possible row is identified, we then perform a second binary search within that row to check if x is present

#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int>& arr, int x){
  int low = 0, high = arr.size()-1;
  while(low <= high){
    int mid = (low+high)/2;

    if(x == arr[mid]) return true;
    if(x < arr[mid]) high = mid-1;
    else low = mid + 1;
  }
  return false;
}

bool searchmatrix(vector<vector<int>>& mat, int x){
  int n = mat.size(), m = mat[0].size();
  int low = 0, high = n-1;
  int row = -1;

  while(low <= high){
    int mid = (low + high)/2;

    if(x == mat[mid][0]) return true;
    if(x>mat[mid][0]){
      row = mid;
      low = mid + 1;
    }
    else high = mid - 1;
  }
  if(row == -1) return false;
  return search(mat[row], x);
}

int main(){
  vector<vector<int>> mat = {{1,5,9},{14,20,21},{30,34,43}};
  int x = 14;

  if(searchmatrix(mat,x)) cout << "true";
  else cout << "false";
  return 0;
}
