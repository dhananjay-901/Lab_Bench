//The maximum number of pages (page limit) that a student can be allocated has a monotonic property: If at a page limit p, books cannot be allocated to all k students, then we need to reduce the page limit to ensure more students receive books. If at a page limit p, we can allocate books to more than k students, then we need to increase the page limit so that fewer students are allocated books. Therefore, we can apply binary search to minimize the maximum pages a student can be allocated. To check the number of students that can be allotted books for any page limit, we start assigning books to the first student until the page limit is reached, then move to the next student.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool check(vector<int>& arr, int k, long long pagelimit){
  int cnt = 1;
  long long pagesum = 0;

  for(int i=0;i<arr.size();i++){
    if(pagesum + arr[i] > pagelimit){
      cnt++;
      pagesum = arr[i];
    }else{
      pagesum+=arr[i];
    }
  }
  return (cnt <= k);
}

int findpages(vector<int>& arr, int k){
  if(k>arr.size()) return -1;
  long long lo = *max_element(arr.begin(), arr.end());
  long long hi = accumulate(arr.begin(), arr.end(), 0LL);

  int res = -1;

  while(lo <= hi){
    long long mid = lo + (hi - lo) / 2;
    if(check(arr, k, mid)){
      res = (int)mid;
      hi = mid - 1;
    }else{
      lo = mid + 1;
    }
  }
  return res;
}

int main(){
  vector<int> arr = {12,34,67,90};
  int k = 2;
  cout << findpages(arr, k) << endl;
  return 0;
}
