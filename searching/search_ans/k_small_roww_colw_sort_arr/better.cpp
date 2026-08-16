//The idea is to use a max-heap to store and maintain the track of k smallest elements in the heap. If the size of the heap exceeds more than k while inserting the elements , we will pop the top element from max-heap so as to maintain the size of k elements. After successful traversal in mat[][], the top element of the max-heap will be the kth minimum element.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthsmallest(vector<vector<int>>& mat, int k){
  int n = mat.size();

  priority_queue<int> pq;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int curr = mat[i][j];

      pq.push(curr);

      if(pq.size()>k){
        pq.pop();
      }
    }
  }
  return pq.top();
}

int main(){
  vector<vector<int>> mat = {{10,20,30,40},{15,25,35,45},{24,29,37,48},{32,33,39,50}};
  int k = 3;
  int result = kthsmallest(mat, k);
  cout << result << endl;
  return 0;
}
