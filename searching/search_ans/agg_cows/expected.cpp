//The minimum distance between cows follows a monotonic property, which makes binary search possible.If we can place all cows with a minimum distance d, then placing them with any smaller distance is also possible because allowing smaller gaps gives us more flexibility and space to place cows closer together. On the other hand, if we can’t place all cows with distance d, then any larger distance also won’t work—since increasing the gap makes placement even harder. So, we apply binary search on the distance range to find the largest minimum distance possible.To check if a distance works, we place the first cow at the first stall and place each next cow only if it’s at least d units away from the last one. If all cows fit, it’s a valid distance.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(vector<int>& arr, int k, int dist){
  int cnt = 1;
  int prev = arr[0];

  for(int i=1;i<arr.size();i++){
    if(arr[i] - prev >= dist){
      prev = arr[i];
      cnt++;
    }
  }
  return (cnt >= k);
}

int aggressivecows(vector<int>& arr, int k){
  sort(arr.begin(), arr.end());
  int res = 0;
  int low = 1;
  int high = arr.back() - arr[0];

  while(low <= high){
    int mid = low + (high - low)/2;

    if(check(arr, k, mid)){
      res = mid;
      low = mid + 1;
    }else{
      high = mid - 1;
    }
  }
  return res;
}

int main(){
  vector<int> arr = {1,2,4,8,9};
  int k = 3;
  int ans = aggressivecows(arr, k);
  cout << ans;
  return 0;
}
