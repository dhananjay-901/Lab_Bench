//instead of generating all n x m elements, we define the search range from 1 to n x m and use binary search to find valye where exactly k elements in the table are smaller than or equal to it. we count smaller values than the current mid value. if the count is more than k. we go the right half, else we go the left half. to count valyes less than or equal to a given number x in the multiplication table, we iterate through each row i from 1 to n and count how many elements in that row are less than or equal to x. for each row i, the elements are i, 2xi, 3xi so there are min(x/i,m) such elements in row i

#include <iostream>
#include <algorithm>

using namespace std;

int count(int val, int n, int m){
  int cnt = 0;
  for(int i=1;i<=n;i++){
    cnt += min(val / i, m);
  }
  return cnt;
}

int kthsmallest(int n, int m, int k){
  int l = 1, h = n*m;
  while(l < h){
    int mid = (l+h)/2;
    if(count(mid, n, m) < k){
      l = mid + 1;
    }else{
      h = mid;
    }
  }
  return l;
}

int main(){
  int n = 2, m = 3, k = 5;
  cout << kthsmallest(n,m,k);
  return 0;
}
