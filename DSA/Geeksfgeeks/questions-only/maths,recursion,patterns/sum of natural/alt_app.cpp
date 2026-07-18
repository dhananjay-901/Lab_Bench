//alternative approach - in this approach we use recursion to find the sum of first n natural numbers. the function calls itself with n-1 until it reaches the base case of n=1. each calls adds the current value of n to the sum of smaller valyes, effectively building the result in a top down manner.

//alternative approach usnig recursion
#include <iostream>
using namespace std;
int findsum(int n){
    if(n==1) return 1;
    return n+findsum(n-1);
}
int main(){
    int n=5;
    cout << findsum(n);
    return 0;
}