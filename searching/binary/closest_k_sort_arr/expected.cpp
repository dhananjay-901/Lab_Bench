//the idea is to first us binary search to quickly find the last element in the array that as is less than or equal to the target(skipping the target itself if it exists). then we use a two pointers approach to select the k closest elements following the tie breaking rules

#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> findkclosest(vector<int>& arr,int k, int x){
  int n = arr.size();
  int i = 0;

  int low, high =n-1, pos = -1;

  while(low <= high){
    int mid = (low + high)/2;
    if(arr[mid] < x){
      pos = mid;
      low = mid + 1;
    }else{
      high = mid - 1;
    }
  }
  int left = pos, right = pos+1;

  if(arr[right] == x) right++;

  vector<int> res;

  while(left >= 0 && right < n && res.size() < k){
    int leftdiff = abs(arr[left] - x);
    int rightdiff = abs(arr[right] - x);

    if(leftdiff < rightdiff){
      res.push_back(arr[left]);
      left--;
    }else{
      res.push_back(arr[right]);
      right++;
    }
  }

  while(left>=0 && res.size() < k){
    res.push_back(arr[left]);
    left--;
  }

  while(right < n && res.size() < k){
    res.push_back(arr[right]);
    right++;
  }
  return res;
}

int main(){
  vector<int> arr = {1,3,4,10,12};
  int k = 2, x = 4;

  vector<int> res = findkclosest(arr, k, x);
  for(int val : res) cout << val << " ";
  cout << endl;
  return 0;
}
