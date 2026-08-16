#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int kthelement(vector<int>& a, vector<int>& b, int k){
  int n = a.size(), m = b.size();

  if(n>m) return kthelement(b,a,k);

  int low = max(0,k-m), high = min(k,n);
  while(low <= high){
    int mid1 = (low + high) / 2;
    int mid2 = k - mid1;

    int l1 = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);
    int r1 = (mid1 == n ? INT_MAX : a[mid1]);

    int l2 = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
    int r2 = (mid2 == m ? INT_MAX : b[mid2]);

    if(l1 <= r2 && l2 <= r1){
      return max(l1,l2);
    }

    if(l1 > r2){
      high = mid1 - 1;
    }
    else low = mid1 + 1;
  }
  return 0;
}

int main(){
  vector<int> a = {2,3,6,7,9};
  vector<int> b = {1,4,8,10};
  int k = 5;
  cout << kthelement(a,b,k);
  return 0;
}
