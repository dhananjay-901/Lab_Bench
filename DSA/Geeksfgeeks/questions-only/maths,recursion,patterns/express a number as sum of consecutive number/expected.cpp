//the idea is that a number can be written as the sum of consecutive positive numbers if it is not power of 2. so we simple check whether n is a power of 2 using bit manipulation

/*Why a Power of 2 cannot be expressed?
The idea is based on the fact that every sum of consecutive integers must have at least one odd factor greater than 1. Let us see the proof.
Sum of k consecutive numbers 𝑘(2𝑎 + k - 1) / 2 = n
The above equation can be written as k(2a + k - 1) = 2n.
If k is even, then (k-1) is odd. Adding 2a (Which is even) to an odd number results in an odd number. Thus, one of these factors must be odd and the other must be even.
Why all other numbers can be expressed?
Every odd number n can be written as (2m + 1) which can be written as m + (m+1) which is sum of two consecutive.*/

//expected approach 
#include <iostream>
using namespace std;

bool issumoconsecutive(int n){
    if(n==1) return true;
    if((n&(n-1))==0) return false;
    return true;
}
int main(){
    int n = 10;
    cout << ((issumoconsecutive(n)==true)?"true":"false") <<" ";
}