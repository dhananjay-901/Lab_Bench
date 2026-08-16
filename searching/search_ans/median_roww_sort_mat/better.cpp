//The idea is to use a min-heap–like structure to efficiently find the median without flattening or sorting the entire matrix. Since each row is already sorted, we start by inserting the first element of each row into a heap (simulated with a sorted map). Then we repeatedly extract the smallest element and push the next element from the same row, simulating the merging of sorted rows. This continues until we reach the median position. It avoids full sorting and leverages the sorted rows for efficiency.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int median(vector<vector<int>>& mat){
  int rows = mat.size();
  int cols = mat[0].size();

  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
  int medianindex = (rows * cols)/2;
  int count = 0, result = -1;

  for(int i=0;i<rows;i++){
    minheap.push({mat[i][0],i,0});
  }

  while(count <= medianindex){
    vector<int> top = minheap.top();
    minheap.pop();

    int val = top[0], row = top[1], col = top[2];
    result = val;
    count++;

    if(col+1 < cols){
      minheap.push({mat[row][col+1], row, col+1});
    }
  }
  return result;
}

int main(){
  vector<vector<int>> matrix = {{1,3,5},{2,6,9},{3,6,9}};
  cout << median(matrix) << endl;
  return 0;
}
