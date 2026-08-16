//given an integer arr[] which denotes the positions of stalls. all the positions are distinct. there are k aggressive cows.

//the idea is to place k cows such that the minimum distance between any two is maximized. we sort the array and try all possible distance from 1 to maximum gap between stalls. for each distance we check if cows can be placed by assigning the first cow to the first stall and placing the next cow only if the gap from the last placed cow is at least that distance. if the placement is possible we update our anwer the largest such distance is returned

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
  int mindist = 1;
  int maxdist = arr.back()-arr[0];


  for(int i=mindist;i<=maxdist;i++){
    if(check(arr,k,i)) res = i;
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
