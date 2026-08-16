//the idea is to increase the value very quickly using repeated squaring instead of normal multiplication allowing it to reach close to y in fewer steps. if the valye becomes equal to y, it returns true. if it goes beyond y a binary search is used to check different possible powers of x and find if any of them exactly equals to y

#include <iostream>
#include <cmath>

using namespace std;

bool ispower(int x, int y){
  if(x==1) return (y==1);

  if(y==1) return true;
  int pow = x, i = 1;
  while(pow < y){
    pow *= pow;
    i*=2;
  }

  if(pow == y) return true;

  int low = x, high = pow;
  while(low <= high){
    int mid = low + (high - low)/2;
    int exponent = (int)(log(mid) / log(x));
    int result = (int)powl(x, exponent);

    if(result == y) return true;
    if(result < y) low = mid + 1;
    else  high = mid - 1;
  }
  return false;
}

int main(){
  cout << boolalpha;
  cout << ispower(10,1) << endl;
  cout << ispower(1,20) << endl;
  cout << ispower(2,128) << endl;
  cout << ispower(2,30) << endl;
  return 0;
}
