//given two integers n and m, find the nth root of m. then the root of m is an integer x such that x^n = m. if no such integer exists return -1

#include <iostream>
#include <vector>

using namespace std;

int power(int base, int expo, int limit){
  int result = 1;
  for(int i=0;i<expo;i++){
    result*=base;
    if(result > limit){
      return result;
    }
  }
  return result;
}

int nthroot(int n, int m){
  if(m==0) return 0;
  if(n==1) return m;

  int low = 1, high = m;

  while(low <= high){
    int mid = (low + high)/2;
    int val = power(mid, n, m);

    if(val == m) return mid;
    else if(val < m) low = mid + 1;
    else high = mid - 1;
  }
  return -1;
}

int main(){
  int n = 3,m = 27;
  int result = nthroot(n, m);
  cout << result << endl;
  return 0;
}
