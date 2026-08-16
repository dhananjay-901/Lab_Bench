//The idea is to simulate the process of merging two sorted arrays, similar to the merge step in merge sort, but only until the k-th element is reached. We use two pointers, one for each array, and at each step, we choose the smaller of the two current elements to move forward. This way, we don't need to fully merge both arrays. We only track the last selected element, which will be the k-th smallest.

#include <iostream>
#include <Vector>

using namespace std;

int kthelement(vector<int>& a, vector<int>& b, int k){
  int n = a.size(), m = b.size();

  int last = 0;
  int i=0, j=0;

  for(int d =0l;d<k;++d){
    if(i<n){
      if(j<m && a[i] > b[j]){
        last = b[j];
        j++;
      }
      else{
        last = a[i];
        i++;
      }
    }
    else if(j < m){
      last = b[j];
      j++;
    }
  }
  return last;
}

int main(){
  vector<int> a = {2,3,6,7,9};
  vector<int> b = {1,4,8,10};
  int k = 5;
  cout << kthelement(a,b,k) << endl;
  return 0;
}
