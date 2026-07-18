//given a integer n. print numbers from n to 1 using recursion
//the idea is to use recursion to print numbers in decreasing order. we first check the base case; if n becomes 0 we stop further recursive calls. otherwise we first print the current number n and then make recursive function call with n-1. this way the function keeps reducing the problem size until it reaches the base case.

#include <iostream>
using namespace std;

void printnos(int n){
    if(n==0) return;
    cout << n << " ";
    printnos(n-1);
}

int main(){
    int n=3;
    printnos(n);
    return 0;
}