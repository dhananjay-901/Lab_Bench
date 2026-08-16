//the idea is to insert all elements from both sorted arrays into a min heap which automatically keeps the smallest elements at the top. then by removing the smallest element k - 1 times and the kth smallest element will be at the top of the heap. this approach ensures the elements are processed in sorted order without full array sorting

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthelement(vector<int>& a, vector<int>& b, int k){
  priority_queue<int, vector<int>, greater<int>> pq;

  for(auto i : a){
    pq.push(i);
  }
  for(auto i : b){
    pq.push(i);
  }

  while(k-- > 1){
    pq.pop();
  }
  return pq.top();
}

int main(){
  vector<int> a = {2,3,6,7,9};
  vector<int> b = {1,4,8,10};
  int k = 5;
  cout << kthelement(a,b,k);
  return 0;

}
