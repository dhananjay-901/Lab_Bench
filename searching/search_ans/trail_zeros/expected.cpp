//the idea is to use binary search to find the smallest number x such that x has atleast n trailing zeros. we use legendre's formula to count how many 5 divides numbers from 1 to x, since each 5 contributes to a trailing zero. the count of trailing zeros increases monotonically so binary search on the answer space is valid. the first x for which the trailing zeros count is >=n is the required minimum

#include <iostream>
using namespace std;

bool check(int p, int n){
  int count = 0;
  int factor = 5;

  while(factor<=p){
    count+=p/factor;
    factor*=5;
  }
  return (count>=n);
}

int findnum(int n){
  if(n==1) return 5;
  int low = 0;
  int high = 5*n;

  while(low < high){
    int mid = (low + high)/2;

    if(check(mid, n)){
      high = mid;
    }
    else{
      low = mid + 1;
    }
  }
  return low;
}

int main(){
  int n = 6;
  cout << findnum(n) << endl;
  return 0;
}
