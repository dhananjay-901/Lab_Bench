//by applying the logarithm change of base formula it computers logx9y = log(y)/log(x) if the result is an integer it means that y is an exact power of x, and the function returns true. otherwise it returns false

#include <iostream>
#include <cmath>

using namespace std;

bool ispower(int x, int y){
  if(x==1) return y==1;
  if(y==1) return true;
  double res = log(y) / log(x);
  return fabs(res - round(res)) < 1e-10;
}
int main(){
  cout << boolalpha;
  cout << ispower(10,1) << endl;
  cout << ispower(1,20) << endl;
  cout << ispower(2,128) << endl;
  cout << ispower(2,30) << endl;
  return 0;
}
