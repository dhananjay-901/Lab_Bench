//factorial is defined recursively as n!. we define a base case where if n equals 0 to 1, the function returns 1. otherwise the function calls itself with minus 1, breaking the problem into smaller subproblems until reaching the base case

#include <iostream>
using namespace std;

int factorial(int n){
    if(n==0||n==1) return 1;
    return n*factorial(n-1);
}
int main(){
    int num=5;
    cout << factorial(num) << endl;
    return 0;
}