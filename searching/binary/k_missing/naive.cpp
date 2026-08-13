//given a sorted arrat of distinct positive integers arr[] and an integer k find the kth positive integer that is missing from the array

//the idea is to insert all elements of the array into a set for constant time lookups. then we iterate starting from 1, checking whether each number is missing from the set. for every number not found we increment a counter. once we reach the k th missing number we return it as the result

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int kthmissing(vector<int>& arr, int k){
  unordered_set<int> s(arr.begin(), arr.end());

  int count = 0, curr = 0;

  while(count < k){
    curr++;

    if(s.find(curr) == s.end()){
      count++;
    }
  }
  return curr;
}

int main(){
  vector<int> arr = {2,3,4,7,11};
  int k = 5;
  cout << kthmissing(arr, k);
  return 0;
}
