//given an array arr[] where arr[i] represents the number of pages in ith book and an integer k denoting the total number of students allocate all books to the students such that each student gets at least one book, books are allocated in a contigous sequence, the maximum number of pages assigned to any student is minimized
//the approach is to search for the minimum possible value of the maximum number of pages that can be assigned to any student. the lowest possible page limit is the maximum number of pages in a single book, since that book must be assigned to some student. the highest possible page limit is the total number of pages across all books, which would happen if one student if one student gets all the books

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool check(vector<int>& arr, int k, long long pagelimit){
  int cnt = 1;
  long long pagesum = 0;

  for(int i=0;i<arr.size();i++){
    if(pagesum +  arr[i] > pagelimit){
      cnt++;
      pagesum = arr[i];
    }
    else{
      pagesum += arr[i];
    }
  }
  return (cnt <= k);
}

int findpages(vector<int>& arr, int k){
  if (k>arr.size()) return -1;
  long long minpagelimit = *max_element(arr.begin(), arr.end());
  long long maxpagelimit = accumulate(arr.begin(), arr.end(), 0LL);

  for(long long i = minpagelimit;i<=maxpagelimit;i++){
    if(check(arr,k,i)){
      return (int)i;
    }
  }
  return -1;
}

int main(){
  vector<int> arr = {12,34,67,90};
  int k = 2;
  cout << findpages(arr, k);
  return 0;
}
