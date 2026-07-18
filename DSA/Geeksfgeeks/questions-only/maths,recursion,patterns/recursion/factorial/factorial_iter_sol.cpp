//given a non negative integers n compute the factorial of the given number. factorial of n is defined as n * (n -1) * (n - 2) * ... * 1. for n=0 the factorial becomes 1

//iterative solution - factorial is comuted by multiplying all integers from 1 to n using a loop. we initialize as variable ans as 1 and update it in each iteration by multiplying with the current number. this approach avoids recursion and uses constant extra space.

#include <iostream>
using namespace std;

int factorial(int n){
    int ans = 1;
    for(int i=2;i<=n;i++){
        ans*=i;
    }
    return ans;
}

int main(){
    int num = 5;
    cout << factorial(num) << endl;
    return 0;
}