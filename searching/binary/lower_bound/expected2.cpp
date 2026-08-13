#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lowerbound(vector<int>& arr, int target){
  int index = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
  return index;
}
int main(){
  vector<int> arr = {2,3,7,10,11,11,25};
  int target = 9;
  cout << lowerbound(arr, target);
  return 0;
}
