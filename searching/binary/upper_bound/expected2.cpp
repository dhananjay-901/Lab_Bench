#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int upperbound(vector<int>& arr, int target){
  int index = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
  return index;
}

int main(){
  vector<int> arr = {2,3,7,10,11,11,25};
  int target = 11;
  cout << upperbound(arr,target);
  return 0;

}
