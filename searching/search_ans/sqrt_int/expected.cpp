//the square of a number increases as the number increases so the square root of n must lie in a sorted monotonic range. if a number's square is more than n, the square root must be smaller. if its less than or equal to n the square root could be that number or rgeater because of this pattern, we can apply binary search in the range 1 to n efficiently find the square root

#include <iostream>

using namespace std;

int floorsqrt(int n){
  int low = 1, high = n;
  int res = 1;

  while(low <= high){
    int mid = low + (high - low)/2;

    if(mid*mid <= n){
      res = mid;
      low = mid + 1;
    }else{
      high = mid - 1;
    }
  }
  return res;
}

int main(){
  int n = 11;
  cout << floorsqrt(n);
  return 0;
}
