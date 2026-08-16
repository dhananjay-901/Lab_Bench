//given an array arr[] and an integer k, the task is to find k largest elements in the given array elements in the output should be in decreasing order.
//the idea is to sort the input array in descending order, so the first k elements in the array will be the k largest elements

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> klargest(vector<int>& arr, int k){
  sort(arr.begin(), arr.end(), greater<int>());

  vector<int> res(arr.begin(), arr.begin() + k);

  return res;
}

int main(){
  vector<int> arr = {1,23,12,9,30,2,50};
  int k = 3;
  vector<int> res = klargest(arr, k);
  for(int ele : res){
    cout << ele << " ";
  }
  return 0;
}
