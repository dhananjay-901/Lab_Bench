//the idea is to binary search on answer. our search space would be 0 to largest bloom day of flower, which represent the range in which minimum number of required days will lie. now calculate mid and check if mid days is possible to make m bouqet such that k bloomed adjacent flowers can be selected to make a bouqet. if possible then update the result with mid valye and move towards lesser valus in search space by updating high to mid - 1. otherwise move towards larger values in search space by updating low to mid + 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int>& arr, int k, int m, int days){
  int bouqets = 0;
  int cnt = 0;

  for(int i=0;i<arr.size();i++){
    if(arr[i] <= days){
      cnt += 1;
    }
    else{
      bouqets+=cnt / k;
      cnt = 0;
    }
  }
  bouqets += cnt / k;
  return bouqets >= m;
}

int mindaysbloom(vector<int>& arr, int k, int m){
  int low = 0;
  int high = *max_element(arr.begin(), arr.end());
  int res = -1;

  while(low <= high){
    int mid = (low + high)/2;
    if(check(arr,k,m,mid)){
      res = mid;
      high = mid - 1;
    }else{
      low = mid + 1;
    }
  }
  return res;
}

int main(){
  vector<int> arr = {5,5,5,5,10,5,5};
  int k = 3, m = 2;
  cout << mindaysbloom(arr, k, m);
  return 0;
}
