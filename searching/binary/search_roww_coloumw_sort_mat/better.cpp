//to optimize the above approach we are going to use the binary search algorithm. the problem specifies that each row in the given matrix is sorted in ascending order. instead of searching each column sequentially we can efficiently apply binary seach on each row to determine if the target is present or not

#include <iostream>
#include <vector>

using namespace std;

bool binarysearch(vector<int>& mat, int target){
  int n = mat.size();
  int low = 0, high = n-1;
  while(low <= high){
    int mid = (low + high)/2;
    if(mat[mid] == target) return true;
    else if(target>mat[mid]) low = mid + 1;
    else high = mid - 1;
  }
  return false;
}

int matsearch(vector<vector<int>>& mat, int x){
  int n = mat.size();

  for(int i=0;i<n;i++){
    if(binarysearch(mat[i], x))  return true;
  }
  return false;
}

int main(){
  vector<vector<int>> mat = {{3,30,38},{20,52,54},{35,60,69}};
  int x = 35;
  if(matsearch(mat, x)) cout << "true";
  else cout << "false";
  return 0;
}
