//this problem involves finding the real valued function a^1/n which can be solved using newton's method. the method begins with a initial guess and iteratively refines the result

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <climits>

using namespace std;

int nthroot(int m, int n){
  if(n==1) return m;

  double xpre = rand()%10 + 1;
  double eps = 1e-3;
  double de1x = INT_MAX;
  double xk;

  while(de1x > eps){
    xk = ((n-1.0) * xpre + (double) m / pow(xpre, n - 1)) / (double) n;
    de1x = abs(xk - xpre);
    xpre = xk;
  }
  return (int)round(xk);
}

int check(int m, int n, int rootcandidate){
  int result = 1;
  for(int i=0;i<n;i++){
    if(abs(result) > INT_MAX / abs(rootcandidate)){
      return -1;
    }
    result *= rootcandidate;
  }
  return (result == m) ? rootcandidate : -1;
}

int main(){
  int n = 3, m = 27;
  int nthrootvalue = nthroot(m,n);
  int verifiedvalue = check(m,n, nthrootvalue);
  cout << verifiedvalue << endl;
  return 0;
}
