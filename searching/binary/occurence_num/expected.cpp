//since the array is already sorted we can use binary search to findd the occurences of a given target. first we find the index of the first occurence lower bound of target and then the index of first element greater than the target upper bound. the difference between these two indices will give the total number of occurences of the target

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countfreq(vector<int>& arr, int target){
  int l = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
  int r = upper_bound(arr.begin(), arr.end(), target) - arr.begin();

  return r-l;
}

int main(){
  vector<int> arr = {1,2,2,2,2,3,4,7,8,8};
  int target = 2;
  cout << countfreq(arr, target);
  return 0;
}
