//given a positive integer n, find its square root if n is not a perfect square then return floort of sqrt n

#include <iostream>

using namespace std;

int floorsqrt(int n){
  int res = 1;
  while(res*res <= n){
    res++;
  }
  return res - 1;
}

int main(){
  int n = 11;
  cout << floorsqrt(n);
  return 0;
}
