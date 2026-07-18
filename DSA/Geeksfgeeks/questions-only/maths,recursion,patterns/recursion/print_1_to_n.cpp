//given an integer n.print numbers from 1 to n using recursion 
//approach - to solve this problem using recursion, we deine a function that takes an integer n as an argument. the function first checks for a base case n==0 to stop the recursion. if not it makes a recursive call with n-1 ensuring smaller numbers are handled first. after the recursive call returns the function print the current value of n. this process continues until all numbers from 1 up to the given valye are printed in order.

#include <iostream>
using namespace std;

void printnos(int n){
    if(n==0) return;
    printnos(n-1);
    cout << n << " ";
}

int main(){
    int n = 3;
    printnos(n);
    return 0;
}