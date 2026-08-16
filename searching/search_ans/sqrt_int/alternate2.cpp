#include <iostream>
#include <cmath>
using namespace std;

int floorsqrt(int n){
  int res = sqrt(n);
  return res;
}

int main(){
  int n = 11;
  cout << floorsqrt(n);
  return 0;
}
