//the idea is to use mathematical formula sqrt h = pow(e, 1/2 log n)

#include <iostream>
#include <cmath>

using namespace std;

int floorsqrt(int n){
  int res = exp(0.5 * log(n));

  if((res + 1) * (res + 1) <= n){
    res++;
  }
  return res;
}

int main(){
  int n = 11;
  cout << floorsqrt(n);
  return 0;
}
