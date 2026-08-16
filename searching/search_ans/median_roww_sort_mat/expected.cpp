//The key idea is that for a number x to be the median in an n x m matrix, there must be exactly (n * m) / 2 elements less than or equal to x. We perform binary search over the range [minElement, maxElement], where minElement and maxElement are the smallest and largest elements in the matrix. At each step, we compute the number of elements less than or equal to the current mid. => If this count is less than or equal to (n * m) / 2, we search in the upper half of the range to increase the candidate value. => Otherwise, we search in the lower half to reduce it

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int median(vector<vector<int>>& mat){
  int n = mat.size();
  int m = mat[0].size();

  int minval = INT_MAX, maxval = INT_MIN;

  for(int i=0;i<n;i++){
    if(mat[i][0] < minval){
      minval = mat[i][0];
    }
    if(mat[i][m-1] > maxval){
      maxval = mat[i][m-1];
    }
  }

  int desired = (n*m+1) / 2;
  int low = minval, high = maxval;

  while(low < high){
    int mid = low + (high - low) / 2;
    int place = 0;

    for(int i=0;i<n;i++){
      place+=upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
    }
    if(place < desired){
      low = mid + 1;
    }
    else{
      high = mid;
    }
  }
  return low;
}

int main(){
  vector<vector<int>> mat = {{1,3,5},{2,6,9},{3,6,9}};
  cout << median(mat) << endl;
  return 0;
}
