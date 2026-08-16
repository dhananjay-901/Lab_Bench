//the idea is similar to kth smallest element using max heap. we generate all vlaues of the form ixj and maintain a max heap of size k. if the current element is smaller than the largest element in our heap, we replace the largest element with the current one. at the end the max heap root contains kth smalelst values

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthsmallest(int n, int m, int k){
  priority_queue<int> pq;

  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(pq.size() < k){
        pq.push(i*j);
      }
      else if(i*j < pq.top()){
        pq.pop();
        pq.push(i*j);
      }
    }
  }
  return pq.top();
}

int main(){
  int n = 2, m = 3, k = 5;
  cout << kthsmallest(n,m,k);
  return 0;
}
