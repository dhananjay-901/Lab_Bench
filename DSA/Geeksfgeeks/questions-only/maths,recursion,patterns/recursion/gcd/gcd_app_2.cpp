//approach 2 - eucliean algorithm using subtraction
//the ieda of this algorithm is the gcd of two numbers doesn't change if the smaller number is subracted number is subracted from the bigger number. this is euclidiean algorithm by subtraction. it is a process of repeat subtraction, carrying the result forward each time until the result is equal to any one number being subtracted.

#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(a==0) return b;
    if(b==0) return a;

    if(a==b) return a;

    if(a>b) return gcd(a-b,b);
    return gcd(a,b-a);
}

int main(){
    int a = 20, b=28;
    cout << gcd(a,b);
    return 0;
}