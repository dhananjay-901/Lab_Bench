//the idea is as iterate through the array we keep track of the k largest elements at each step. to do this we use a min heap. first we insert the initial k elements into the min heap. after that for each next element, we compare it with the top of the heap. since the top element of the min heap is the smallest among the k elements. if the current element is larger than the top, it means the top element is no longer one of the k largest elements. in this case we remove the top and insert the larger element. after completing the entire traversal, the heap will contain exactly the k largest elements of the array

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> klargest(vector<int>& arr, int k){
  priority_queue<int, vector<int>, greater<int>> minH(arr.begin(), arr.begin() + k);

  for(int i=k;i<arr.size();i++){
    if(minH.top() < arr[i]){
      minH.pop();
      minH.push(arr[i]);
    }
  }
  vector<int> res;

  while(!minH.empty()){
    res.push_back(minH.top());
    minH.pop();
  }

  reverse(res.begin(), res.end());
  return res;
}

int main(){
  vector<int> arr = {1,23,12,9,30,2,50};
  int k = 3;
  vector<int> res = klargest(arr,k);
  for(int ele : res){
    cout << ele << " ";
  }
  return 0;
}
