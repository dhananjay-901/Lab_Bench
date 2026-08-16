//To find the median of the two sorted arrays, a[] and b[] of size n, we need the average of two middle elements of merged sorted array. So, if we divide the merged array into two halves, then the median will be (last element in first half + first element in second half) / 2. The idea is to use Binary Search to find the valid partition in a[] say mid1, such that all elements of a[0...mid1 - 1] will lie in the first half of the merged sorted array. Since, we know that first half of the merged sorted array will have total n elements, the remaining mid2 = (n - mid1) elements will be from b[]. In other words, the first half of the merged sorted array will have all the elements in a[0...mid1 - 1] and b[0...mid2 - 1].

#include <bits/stdc++.h>

using namespace std;

double getmedian(vector<int>& a, vector<int>& b){
  int n = a.size();
  int low = 0, high = n;
  while(low <= high){
    int mid1 = (low + high)/2;
    int mid2 = n - mid1;

    int l1 = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);
    int r1 = (mid1 == n ? INT_MAX : a[mid1]);

    int l2 = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
    int r2 = (mid2==n ? INT_MAX : b[mid2]);

    if(l1 <= r2 && l2 <= r1){
      return (max(l1, l2) + min(r1, r2)) / 2.0;
    }

    if(l1 > r2){
      high = mid1 - 1;
    }
    else{
      low = mid1 + 1;
    }
  }
  return 0;
}

int main(){
  vector<int> a = {1,12,15,26,38};
  vector<int> b = {2,13,17,30,45};

  cout << getmedian(a,b) << endl;
  return 0;
}
