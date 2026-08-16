//give two positive numbers x and y check if u is a power of x or not

//this idea is to start from 1 and repeatedly multiplying it by x. if the value becomes equal to y, then u is a power of x and if it exceeds y without matching then it is not. this method relies on simple multiplication and avoids using logrithms or recursion

#include <iostream>
using namespace std;

bool ispower(int x, int y){
  if(x==1) return (y==1);
  int pow = 1;
  while(pow < y) pow *= x;
  return (pow == y);
}

int main(){
  cout << boolalpha;
  cout << ispower(10,1) <<endl;
  cout << ispower(1,20) << endl;
  cout << ispower(2,128) <<endl;
  cout << ispower(2,30) <<endl;
  return 0;
}
