//The idea is to use binary search (lower_bound and upper_bound) to find the first and last positions where the element x appears in the sorted array. Once we know all the positions where x occurs, we simply check how many of those lie within the given index range [l, r]. If there's no overlap between the index range of occurrences and the query's [l, r], we return 0. Otherwise, we return the number of overlapping positions, which is right - left + 1.

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> countxinrange(vector<int>& arr, vector<vector<int>>& queries){
  vector<int> result;
  int n = arr.size();

  for(auto& query : queries){
    int l = query[0];
    int r = query[1];
    int x = query[2];

    int left = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

    if(left == n || arr[left] != x){
      result.push_back(0);
      continue;
    }

    int right = upper_bound(arr.begin(), arr.end(), x) - arr.begin();

    right--;

    left = max(left, l);
    right = min(right, r);

    if(left > right){
      result.push_back(0);
    }
    else{
      result.push_back(right - left + 1);
    }
  }
  return result;
}

int main(){
  vector<int> arr = {1,2,2,4,5,5,5,8};
  vector<vector<int>> queries = {{0,7,5},{1,2,2},{0,3,7}};
  vector<int> res = countxinrange(arr, queries);

  for(int count : res){
    cout << count << " ";
  }
  cout << endl;
  return 0;
}
