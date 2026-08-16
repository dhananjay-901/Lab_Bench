//given an integer n, find the smallest positive integer x such that the factorial of x contains at least n trailing zeros

//in this approach we use a while loop to iterate over each number starting from 1. for each number we count the number of trailing zeros in its factorial by continously dividing it by 5 and adding the result to the answer until the number becomes less than 5. once the count of trailing zeros becomes greater than or equal to n, we return the current number as the answer

#include <iostream>

using namespace std;

int findnum(int n){
  int num = 1;
  int cnt = 0;

  while(true){
    int temp = num;

    while(temp % 5 == 0){
      cnt++;
      temp/=5;
    }

    if(cnt >= n){
      return num;
    }
    num++;
  }
}

int main(){
  int n = 6;
  cout << findnum(n) << endl;
  return 0;
}
