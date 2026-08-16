//in a row of flowers, each flower blooms on a specific days. given an integer array arr[] where arr[i] denotes the day on which the flower at position i blooms. to make a bouqet you need to collect k adjacent flowers that have already bloomed. each flower can be used in at most one bouqet

//the idea is to iterate over all possible days of starting from 0 to largest bloom day. to find whether it is possible to make m bouqets in d days. we traverse the array arr[] and check if there is atleast m contigous subarrays of size k such that each subarray has elements  <= d

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check(vector<int>& arr, int k, int m, int days){
  int bouqets = 0;
  int cnt = 0;

  for(int i=0;i<arr.size();i++){
    if(arr[i] <= days){
      cnt+=1;
    }else{
      bouqets +=cnt/k;
      cnt=0;
    }
  }
  bouqets+=cnt/k;
  return bouqets>=m;
}

int mindaysbloom(vector<int>& arr, int k, int m){
  int maxdays = *max_element(arr.begin(), arr.end());

  for(int d = 0; d <=maxdays; d++){
    if(check(arr,k,m,d)) return d;
  }
  return -1;
}

int main(){
  vector<int> arr = {5,5,5,5,10,5,5};
  int k = 3, m = 2;
  cout << mindaysbloom(arr,k,m);
  return 0;
}
