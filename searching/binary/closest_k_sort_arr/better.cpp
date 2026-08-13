//the idea is to first go through the array to find the last element that is less than or equal to the target value, skipping the target if it's present. then , we use two pointers to choose the k closest elements by comparing their differences, while following the tie breaking rules

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

vector<int> findkclosest(vector<int>& arr, int k, int x){
  int n = arr.size();
  int i = 0;

  while(i<n && arr[i] < x) i++;
  int left = i-1, right = i;

  if(right<n && arr[right] == x) right++;

  vector<int> res;

  while(left>=0 && right<n && res.size() < k){
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

  while(left>=0 && res.size()<k){
    res.push_back(arr[left]);
    left--;
  }
  while(right<n && res.size() < k){
    res.push_back(arr[right]);
    right++;
  }
  return res;
}

int main(){
  vector<int> arr = {1,3,4,10,12};
  int k = 2, x = 4;
  vector<int> res = findkclosest(arr,k,x);
  for(int val : res){
    cout << val << " ";
  }
  cout << endl;
  return 0;
}
