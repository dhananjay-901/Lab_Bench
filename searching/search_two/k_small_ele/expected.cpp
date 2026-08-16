//the idea is to maintain a max heap of size k while iterating through the array. the heap always contains the k smallest elements seen so far. if the heap size exceeds k, remove the largest element. at the end the heap holds the k smallest elements

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthsmallest(vector<int>& arr, int k){
  priority_queue<int> pq;

  for(int i=0;i<arr.size();i++){
    pq.push(arr[i]);

    if(pq.size() > k){
      pq.pop();
    }
  }
  return pq.top();
}

int main(){
  vector<int> arr = {10,5,4,3,48,6,2,33,53,10};
  int k = 4;
  cout << kthsmallest(arr, k);
  return 0;
}
