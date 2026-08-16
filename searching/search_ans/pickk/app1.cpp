//given an array arr[] of integers select k elements such that the minimum absolute difference between any two of the selected elements is as large as possible. out of all possible combinations of k elements from the array, choose the one where the smallest absoulte difference between any pair of selected elements is the maximum possible across all combinations

//The idea is to use top-down DP with memoization to explore all combinations of selecting k elements from the sorted array. Sorting helps ensure that differences are non-negative and simplifies computing abs(arr[i] - arr[prev]) as just arr[i] - arr[prev]. The DP state dp[i][remk][prev] stores the maximum achievable minimum absolute difference when starting from index i, having selected remk elements so far, and the last selected index as prev. At each step, we either skip the current element or take it and update the minimum difference. We return the maximum of the two choices. This is a DP problem due to optimal substructure and overlapping subproblems, which we avoid recomputing using memoization.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int helper(int i, int remk, int prev, vector<int>& arr, int k, vector<vector<vector<int>>>& memo){
  if(remk == k) return INT_MAX;

  if(i == arr.size()) return -1;

  if(memo[i][remk][prev+1] != -2) return memo[i][remk][prev+1];

  int skip = helper(i+1, remk, prev, arr, k, memo);
  int diff = (prev == -1) ? INT_MAX : abs(arr[i] - arr[prev]);
  int next = helper(i+1, remk + 1,i, arr, k, memo);
  int take = (next == -1) ? -1 : min(diff, next);

  return memo[i][remk][prev + 1] = max(skip, take);
}

int maxmindiff(vector<int>& arr, int k){
  sort(arr.begin(), arr.end());
  int n = arr.size();

  vector<vector<vector<int>>> memo(n+1, vector<vector<int>>(k+1, vector<int>(n+1,-2)));

  return helper(0,0,-1, arr, k, memo);
}

int main(){
  vector<int> arr = {1,4,9,0,2,13,3};
  int k = 4;
  cout << maxmindiff(arr, k) << endl;
  return 0;
}
