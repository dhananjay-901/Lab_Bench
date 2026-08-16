//The core idea is to use binary search on the answer—specifically, on the eating speed x. For a given speed x, we can compute how many hours it would take to eat all the piles. This function is monotonic because -  As x increases, the total time required decreases or stays the same. Therefore, if a certain speed x allows completion within k hours, any higher speed will also work. This monotonic behavior allows us to apply binary search to efficiently find the minimum valid speed.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int>& arr, int mid, int k){
  int totalhours = 0;
  for(int i=0;i<arr.size();i++){
    totalhours += (arr[i] + mid - 1)/mid;
  }
  return totalhours <= k;
}

int kokoeat(vector<int>& arr, int k){
  int low = 1;
  int high = *max_element(arr.begin(), arr.end());
  int res = high;

  while(low <= high){
    int mid = low + (high - low) / 2;

    if(check(arr,mid, k)){
      res = mid;
      high = mid - 1;
    }else{
      low = mid + 1;
    }
  }
  return res;
}

int main(){
  vector<int> arr = {5,10,3};
  int k = 4;
  cout << kokoeat(arr, k) << endl;
  return 0;
}
