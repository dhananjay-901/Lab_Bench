//find the root of a number using newton's method

//given a integer n and a tolerance level l, the task is to find the square root of that number using newton's method

#include <bits/stdc++.h>
using namespace std;

double squareroot(double n, float l){
  double x = n;
  double root;
  int count = 0;
  while(1){
    count++;
    root = 0.5 * (x + (n/x));
    if(abs(root-x) < 1) break;
    x = root;
  }
  return root;
}

int main(){
  double n = 327;
  float l = 0.00001;
  cout << squareroot(n,l) << endl;
  return 0;
}
