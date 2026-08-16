//Given 2 sorted arrays a[] and b[], each of size n, the task is to find the median of the array obtained after merging a[] and b[].

//the idea is to concantenate both the arrays into a new array sort the new array and return middle of the new sorted arrays

#include <bits/stdc++.h>

using namespace std;

double getmedian(vector<int>& a, vector<int>& b){
  vector<int> c(a.begin(), a.end());
  c.insert(c.end(), b.begin(), b.end());

  sort(c.begin(), c.end());

  int n = c.size();
  int mid1 = n / 2;
  int mid2 = mid1 - 1;

  return (c[mid1] + c[mid2]) / 2.0;
}

int main(){
  vector<int> a = {1,12,15,26,38};
  vector<int> b = {2,13,17,30,45};

  cout << getmedian(a,b) << endl;
  return 0;
}
