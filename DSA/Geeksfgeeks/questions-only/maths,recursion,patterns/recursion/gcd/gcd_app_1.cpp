//given two positive integers a and b the task is to find the gcd of the two numbers. note the gcd greatest common divisor or hcf highest common factor of two numbers is the largest number that divides both of them.
//using loop - the idea is to find the minimum of the two numbers and find its highest factor which is also a factor of the other number

#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(a==0|b==0) return max(a,b);
    int result = min(a,b);
    while(result > 0){
        if(a%result == 0 && b%result == 0) break;
        result--;
    }
    return result;
}

int main(){
    int a = 20, b = 28;
    cout << gcd(a,b);
    return 0;
}